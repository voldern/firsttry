#include "FirstTry.h"
#include <iostream>

namespace FirstTry
{
    FirstTry::FirstTry()
    {
        this->debug = true;
        this->caption = "FirstTry";
    }

    void FirstTry::run()
    {
        printf("Starting main loop\n");
        while (this->device->Update())
        {
            this->device->Clear(Frontend::Graphics::ClearBuffersAll, 0, 0, 1, 0, 1, 0);
        }
    }
}
