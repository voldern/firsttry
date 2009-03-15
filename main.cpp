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

  Keyboard keyboard(setup.GetWindow());
    
  while (setup.Update())
    {
      // Clear the screen
      setup.GetGraphicsDevice()->Clear(Graphics::ClearBuffersAll, 1, 0, 0, 0, 1, 0);
      
      // Check if the user has pressed ESC, in that case terminate the program successfully
      if (keyboard.KeyDown(GUI::KeyEsc))
          return 1;
      
      // Setup the scenes
      
      // Run all the scenes in order
    }

  return 1;
}
