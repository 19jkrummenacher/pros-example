#pragma once
#include "main.h"
namespace tarvis
{
//     #define trapezoidalVector
    class Trapezoidal
    {
      private:
        double changeVal; // the amout of Val change per calculation
        int changeMsec;   // the amount of time inbetween calculations
        double max;       // maximum value
        double min;       // minimum value

        double valRequested = 0; // val that was requested
        double valOutput = 0;    // val that was calculated

        double gMax = 0;       // max gate
        double gMin = 0;       // min gate
        double vAtGateMax = 0; // max val
        double vAtGateMin = 0; // min val

        uint32_t prevMsec;
        pros::Task task;

        std::function<void(double)> cb;
#ifdef trapezoidalVector
        static std::vector<Trapezoidal *> allTrapezoidals;
#endif
      public:
        Trapezoidal(
            double CV, double CM = okapi::motorUpdateRate, double max = 1, double min = -1,
            std::function<void(double)> callback = [](double output) {});
        Trapezoidal(double CV, std::function<void(double)> callback);

#ifdef trapezoidalVector
        static void startAll();
        static void resumeAll();
        static void suspendAll();
#endif
        void start();
        void resume();
        void suspend();
        /**
         * @brief calculates the output value based on requested value
         *
         * @return double output()
         */
        double calculate();
        /**
         * @brief calculates the output value based on requested value
         * @example changing the acc of the drive
         *
         * @param changeValue the value the output changes by
         * @return double output()
         */
        double calculate(double changeValue);

        void request(int val);
        void instant(int val);

        double output();

        double getRequested();
        int getChangeMsec();
        double getMax();
        double getMin();
        void setTolorance(double maxGate, double minGate, double maxVal, double minVal);
    };
} // namespace tarvis