#ifndef FIRSTTRY_DEMO_H_INCLUDED
#define FIRSTTRY_DEMO_H_INCLUDED

#include "../Engine/Demo.h"

namespace FirstTry
{
    class Demo: public Engine::Demo
    {
    public:
        // Runs the demo
        void run();
    };
}

#endif // FIRSTTRY_DEMO_H_INCLUDED
