#include "FirstTry.h"
#include <iostream>

namespace FirstTry
{
    FirstTry::FirstTry()
    {
        this->debug = true;
        this->fullscreen = false;
        this->caption = "FirstTry";
    }

    void FirstTry::run()
    {
        // Loading all the scenes
        for (int i = 0; i < this->scenes.size(); i++) {
            this->scenes[i]->load();
        }

        printf("Starting main loop\n");
        while (this->device->Update() && !this->done)
        {
            this->device->Clear(Frontend::Graphics::ClearBuffersAll, 0, 0, 1, 0, 1, 0);

            // Loop over all the scenes and run them
            for (int i = 0; i < this->scenes.size(); i++) {
                    this->scenes[i]->draw();
            }
        }
    }
}
