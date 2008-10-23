#ifndef INTRO_SCENE_H_INCLUDED
#define INTRO_SCENE_H_INCLUDED

#include "../FirstTry.h"
#include "../../Engine/Scene.h"

namespace FirstTry
{
    namespace Scene
    {
        class IntroScene: public Engine::Scene
        {
        private:
            //FirstTry::FirstTry demo;
            // error: 'FirstTry' in namespace 'FirstTry' does not name a type
        public:
            IntroScene()
            {
                //this->demo = demo;
            }

            void draw()
            {

            }
        };
    }
}

#endif // INTRO_SCENE_H_INCLUDED
