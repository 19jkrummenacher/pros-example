#pragma once
#include <vector>
namespace tarvis
{
    class System
    {
      public:
        virtual void userCallstack() = 0;
        virtual void autonCallstack() = 0;
        virtual void userInit() = 0;
        virtual void autonInit() = 0;
        virtual void autonDeInit() = 0;
        virtual void userDeInit() = 0;

        static std::vector<System *> systems;
        static void userCallstacks();
        static void autonCallstacks();
        static void autonInits();
        static void autonDeInits();
        static void userInits();
        static void userDeInits();
        System();
    };
} // namespace tarvis