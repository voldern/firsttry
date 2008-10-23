#ifndef ENGINE_DEMO_H_INCLUDED
#define ENGINE_DEMO_H_INCLUDED

#include <Frontend2.h>
#include <Frontend2Graphics.h>
#include <OpenFrontend2.h>
#include <iostream>
#include "Scene.h"

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

        // Keyboard interface
        Frontend::Input::Keyboard* keyboard;

        // Is the demo finished?
        bool done;

        // Should the demo run in fullscreen?
        bool fullscreen;

        // Should the demo run with vertical sync enabled?
        bool verticalSync;

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

    public:
        Demo();

        // This function initializes the window, sound, graphics device and etc
        virtual void init();

        // Abscract function that the inherited class needs to implement
        // This is where the main loop should live
        virtual void run() = 0;

        // Vector with all the scenes
        Frontend::Array<Engine::Scene*> scenes;

        // This variable holds the extra time we are in the future or the past
        // It's mainly used to reel / rewind
        float extraTime;

        // Get current time into the demo
        float getTime()
        {
            return this->time;
        }

        // Get width and height
        int getWidth()
        {
            return this->width;
        }

        int getHeight()
        {
            return this->height;
        }

        // Are we running in debug mode?
        bool debugMode()
        {
            return this->debug;
        }
    };
}

#endif // ENGINE_DEMO_H_INCLUDED
