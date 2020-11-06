#include "tarvis/system.hpp"
namespace tarvis
{
    std::vector<System *> System::systems = {};
    System::System() { systems.push_back(this); }
    void System::userCallstacks()
    {
        for (auto &&ucs : systems)
        {
            ucs->userCallstack();
        }
    }
    void System::autonCallstacks()
    {
        for (auto &&acs : systems)
        {
            acs->autonCallstack();
        }
    }
    void System::autonInits()
    {
        userDeInits();
        for (auto &&ai : systems)
        {
            ai->autonInit();
        }
    }
    void System::autonDeInits()
    {
        for (auto &&adi : systems)
        {
            adi->autonDeInit();
        }
    }

    void System::userInits()
    {
        autonDeInits();
        for (auto &&ui : systems)
        {
            ui->userInit();
        }
    }
    void System::userDeInits()
    {
        for (auto &&udi : systems)
        {
            udi->userDeInit();
        }
    }

} // namespace tarvis