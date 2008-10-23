#ifndef INTRO_SCENE_H_INCLUDED
#define INTRO_SCENE_H_INCLUDED

#include "../FirstTry.h"

namespace FirstTry
{
    class IntroScene
    {
    private:
        FirstTry::FirstTry* demo;

    public:
        Intro(FirstTry::FirstTry* demo)
        {
            this->demo = demo;
        }

        void draw()
        {

        }
    };
}

#endif // INTRO_SCENE_H_INCLUDED
