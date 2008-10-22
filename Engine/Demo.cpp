#include "Demo.h"

namespace Engine
{
    Demo::Demo()
    {
        // Setting variables to default values
        done = false;
        fullscreen = false;
        caption = "Frontend window";
        debug = false;
        freeRoam = false;
        width = 800;
        height = 600;
        startTime = 0;
    }

    void Demo::init()
    {
        // Setup window and graphics device
        // OpenGL 2.0 and CG shader
        printf("Initializing window and graphics device\n");
        this->window = Frontend::CreatePlatformWindow(this->width, this->height, this->caption, 1);
        this->device = Frontend::Graphics::CreateDeviceGL2CG(window, Frontend::Graphics::DepthStencilFormatD24S8, 0, 0);

        // Setup sound
        printf("Initializing sound\n");
        this->sound = Frontend::Sound::CreateDevice(window);
    }
}
