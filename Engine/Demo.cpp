#include "Demo.h"

namespace Engine
{
    Demo::Demo()
    {
        // Setting variables to default values
        done = false;
        fullscreen = false;
        verticalSync = false;
        caption = "Frontend window";
        debug = false;
        freeRoam = false;
        width = 800;
        height = 600;
        startTime = 0;
    }

    void Demo::init()
    {
        // Setup flags that will be used to create the device
        int flags = 0;
        if (this->fullscreen) flags += 1;
        if (this->verticalSync) flags += 2;

        // Setup window and graphics device
        // OpenGL 2.0 and CG shader
        printf("Initializing window and graphics device\n");
        this->window = Frontend::CreatePlatformWindow(this->width, this->height, this->caption, 1);
        this->device = Frontend::Graphics::CreateDeviceGL2CG(window, Frontend::Graphics::DepthStencilFormatD24S8, 0, flags);

        // Setup sound
        printf("Initializing sound\n");
        this->sound = Frontend::Sound::CreateDevice(window);

        // Setup keyboard input
        printf("Initializing keyboard\n");
        Frontend::Input::Context* inputContext = Frontend::Input::CreateContext(window);
        this->keyboard = inputContext->GetKeyboard();
    }
}
