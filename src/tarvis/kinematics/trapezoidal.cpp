#include "trapezoidal.hpp"

namespace tarvis
{
#ifdef trapezoidalVector
    std::vector<Trapezoidal *> Trapezoidal::allTrapezoidals = {};
#endif
    Trapezoidal::Trapezoidal(double CV, double CM, double max, double min, std::function<void(double)> callback) :
        changeVal(CV), cb(callback), changeMsec(CM), max(max), min(min), prevMsec(pros::millis()), task([&]() {
            callback(calculate());
            task.delay_until(&prevMsec, changeMsec);
        })
    {
        task.suspend(); // suspend until user is ready to start calculating
#ifdef trapezoidalVector
        allTrapezoidals.push_back(this);
#endif
    }
    Trapezoidal::Trapezoidal(double CV, std::function<void(double)> callback) :
        changeVal(CV), cb(callback), changeMsec(okapi::motorUpdateRate), max(1), min(-1), prevMsec(pros::millis()),
        task([&]() {
            callback(calculate());
            task.delay_until(&prevMsec, changeMsec);
        })
    {
        task.suspend(); // suspend until user is ready to start calculating
#ifdef trapezoidalVector
        allTrapezoidals.push_back(this);
#endif
    }

#ifdef trapezoidalVector
    void Trapezoidal::startAll()
    {
        for (auto &&t : allTrapezoidals)
        {
            t->start();
        }
    }
    void Trapezoidal::resumeAll()
    {
        for (auto &&t : allTrapezoidals)
        {
            t->resume();
        }
    }
    void Trapezoidal::suspendAll()
    {
        for (auto &&t : allTrapezoidals)
        {
            t->suspend();
        }
    }
#endif
    void Trapezoidal::start()
    {
        instant(0);
        task.resume();
    }
    void Trapezoidal::resume() { task.resume(); }
    void Trapezoidal::suspend() { task.suspend(); }

    double Trapezoidal::calculate()
    {
        if (valRequested > valOutput) valOutput += changeVal;
        else if (valRequested < valOutput)
            valOutput -= changeVal;
        // limit Val
        if (valOutput > max) valOutput = max;
        if (valOutput < min) valOutput = min;
        if (valOutput < gMax && valOutput > gMin)
        {
            if (valOutput > (gMin + gMax) / 2.0) valOutput = vAtGateMax;
            else
                valOutput = vAtGateMin;
        }
        return valOutput;
    }
    double Trapezoidal::calculate(double cv)
    {
        changeVal = cv;
        return calculate();
    }

    void Trapezoidal::request(int val) { valRequested = val; }
    void Trapezoidal::instant(int val)
    {
        request(val);
        valOutput = val;
    }

    double Trapezoidal::output() { return valOutput; }

    double Trapezoidal::getRequested() { return valRequested; }
    int Trapezoidal::getChangeMsec() { return changeMsec; }

    double Trapezoidal::getMax() { return max; }
    double Trapezoidal::getMin() { return min; }

    void Trapezoidal::setTolorance(double maxGate, double minGate, double valueAtGateMax, double valueAtGateMin)
    {
        gMax = maxGate;
        gMin = minGate;
        vAtGateMax = valueAtGateMax;
        vAtGateMin = valueAtGateMin;
    }

} // namespace tarvis