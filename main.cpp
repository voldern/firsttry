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
        while(FirstTry.Update())
        {

        }
    }
    catch(Frontend::Exception e)
    {
        FirstTry.HandleException(e);
    }

    return 0;
}
