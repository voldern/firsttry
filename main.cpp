#include <OpenFrontend2.h>
#include <Frontend2Utils.h>
#include <vector>

#include "engine/Scene.h"
#include "scenes/TestScene.h"

using namespace Frontend;
using namespace Frontend::Utils;
using namespace Frontend::Utils::Simple;

int main(int argc, char** argv)
{
  IO::StdOut().WriteTextLine("Setting up enviroment");
  SimpleSetup setup(GUI::CreateNativeWindowManager(), Graphics::OpenFrontendGL2CG());
  setup.SetResolution(800, 600);
  setup.SetTitle("Hello Frontend");
  setup.Start();

  Keyboard keyboard(setup.GetWindow());

  double startTime = setup.GetTime();
  IO::StdOut().WriteTextLine("Starting main loop");
  while (setup.Update())
    {
      // Clear the screen
      setup.GetGraphicsDevice()->Clear(Graphics::ClearBuffersAll, 1, 0, 0, 0, 1, 0);
      
      // Check if the user has pressed ESC, in that case terminate the program successfully
      if (keyboard.KeyDown(GUI::KeyEsc))
          return 1;

      // Display FPS if the user presses F (F1 untill I figure out how to check against ASCII keys)
      if (keyboard.KeyDown(GUI::KeyF1))
        IO::StdOut().WriteTextLine((Frontend::String)setup.GetFPS());
      
      // Run the test scene
      FirstTry::TestScene firstScene(setup);
      firstScene.run();
    }

  return 1;
}
