#ifndef ENGINE_DEMO_H_INCLUDED
#define ENGINE_DEMO_H_INCLUDED

#include <Frontend2.h>
#include <Frontend2Graphics.h>
#include <OpenFrontend2.h>
#include <iostream>

namespace Engine
{
    class Demo
    {
    protected:
        // Window
        Frontend::Window* window;

        // Graphics device
        Frontend::Graphics::Device* device;

        // Sound device
        Frontend::Sound::Device* sound;

        // Is the demo finished?
        bool done;

        // Should the demo run in fullscreen?
        bool fullscreen;

        // The caption of the window
        Frontend::String caption;

        // Should the demo run in debug mode?
        bool debug;

        // Should the camera be in free roam mode?
        bool freeRoam;

        // Window height and width
        int width;
        int height;

        // Start time of the demo
        float startTime;

        // Current time into the demo
        float time;

        // Music to play
        Frontend::String music;

        void init();

    public:
        Demo();

        // Abscract function that the inherited class needs to implement
        virtual void run() = 0;

        //
        float extraTime;

        // Get current time into the demo
        float getTime()
        {
            return this->time;
        }


        int getWidth()
        {
            return this->width;
        }

        int getHeight()
        {
            return this->height;
        }
    };
}

#endif // ENGINE_DEMO_H_INCLUDED
