#include <OpenFrontend2.h>
#include <Frontend2Utils.h>

using namespace Frontend;

int main(int argc, char **argv)
{
  Utils::Simple::SimpleSetup setup(GUI::CreateNativeWindowManager(), Graphics::OpenFrontendGL2CG());
  setup.SetResolution(800, 600);
  setup.SetTitle("FirstTry");
  setup.Start();

  while (setup.Update()) 
    {
      // Loop
    }

  return 0;
}
