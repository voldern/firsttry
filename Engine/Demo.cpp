#include "Demo.h"

namespace Engine
{
    Demo::Demo()
    {
        // Setup window and graphics device
        // OpenGL 2.0 and CG shader
        printf("Initializing window and graphics device\n");
        this->window = Frontend::CreatePlatformWindow(800, 600, "Test", 1);
        this->device = Frontend::Graphics::CreateDeviceGL2CG(window, Frontend::Graphics::DepthStencilFormatD24S8, 0, 0);

        // Setup sound
        printf("Initializing sound\n");
        this->sound = Frontend::Sound::CreateDevice(window);

    }
}
