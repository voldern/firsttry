#include <Frontend2.h>
#include <Frontend2Graphics.h>
#include <OpenFrontend2.h>
#include <iostream>

using namespace Frontend;
using namespace Frontend::Graphics;

int main() {
    try
    {
        // Setup window and render device
        // OpenGL 2.0 and CG Shader
        Window* window = CreatePlatformWindow(800, 600, "Test", 1);
        Device* device = CreateDeviceGL2CG(window, DepthStencilFormatD24S8, 0, 0);

        // Setup sound
        Sound::Device* sound = Sound::CreateDevice(window);
        Sound::Buffer* soundBuffer = sound->CreateBuffer(2097152, 2, 16, 44100);
        soundBuffer->SetVolume(50);
        printf("Volume %f\n", soundBuffer->GetVolume());

        while (device->Update())
        {
            device->Clear(ClearBuffersAll, 0, 0, 1, 0, 1, 0);
        }
    }
    catch (Exception e)
    {
        printf("Frontend Exception: %s\n", e.GetMessage().CharStringCopy());
    }

    return 0;
}
