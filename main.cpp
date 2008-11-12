#include <OpenFrontend2.h>
#include <Frontend2Utils.h>
#include <Frontend2Graphics.h>
#include <iostream>

using namespace Frontend;

int main()
{
    Utils::Application FirstTry;

    FirstTry.SetGraphicsBackend(Graphics::OpenFrontendGL2CG());
    FirstTry.SetResolution(800, 600);
    FirstTry.SetExitOnEsc(true);
    FirstTry.SetHandleInput(true);
    FirstTry.SetNativeBorder(false);
    FirstTry.SetTitle("FirstTry");

    FirstTry.Start();

    try
    {
        Utils::RAudioStream oggStream("Data/sound.ogg");
        Utils::Audio::Outlet outlet(oggStream, FirstTry.GetSoundDevice());
        outlet.Play();

        while(FirstTry.Update())
        {
            FirstTry.GetGraphicsDevice()->Clear(Frontend::Graphics::ClearBuffersAll, 0, 0, 1, 0, 1, 0);
        }
    }
    catch(Frontend::Exception e)
    {
        FirstTry.HandleException(e);
    }

    return 0;
}
