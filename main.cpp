#include <OpenFrontend2.h>
#include <Frontend2Utils.h>

using namespace Frontend;
using namespace Frontend::Utils;
using namespace Frontend::Utils::Simple;
int main(int argc, char** argv)
{
  SimpleSetup setup(GUI::CreateNativeWindowManager(), Graphics::OpenFrontendGL2CG());
  setup.SetResolution(800, 600);
  setup.SetTitle("Hello Frontend");
  setup.Start();
    
  while (setup.Update())
    {
      setup.GetGraphicsDevice()->Clear(Graphics::ClearBuffersAll, 1, 0, 0, 0, 1, 0);
    }
}
