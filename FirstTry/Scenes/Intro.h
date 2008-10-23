#ifndef INTRO_SCENE_H_INCLUDED
#define INTRO_SCENE_H_INCLUDED

#include "../FirstTry.h"
#include "../../Engine/Scene.h"

namespace FirstTry
{
    namespace Scene
    {
        class Intro: public Engine::Scene
        {
        private:
            class FirstTry::FirstTry demo;

        public:
            Intro(class FirstTry::FirstTry demo)
            {
                this->demo = demo;
                this->length = 50;
            }

            void load()
            {
                std::cout << "Loading intro scene!\n";
            }

            void draw()
            {
                //std::cout << "Scene 1\n";
            }
        };
    }
}

#endif // INTRO_SCENE_H_INCLUDED
