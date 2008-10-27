#ifndef FIRSTTRY_H_INCLUDED
#define FIRSTTRY_H_INCLUDED

#include "../Engine/Demo.h"
//#include "FirstTry/Scenes/Intro.h"

namespace FirstTry
{
    class FirstTry: public Engine::Demo
    {
    public:
        FirstTry();
        // Runs the demo
        void run();
    };
}

#endif // FIRSTTRY_H_INCLUDED
