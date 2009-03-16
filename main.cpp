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
    SimpleSetup setup(GUI::CreateNativeWindowManager(), Graphics::OpenFrontendGL2CG());
  
    try
    {
        IO::StdOut().WriteTextLine("Setting up enviroment");
 
        setup.SetResolution(1024, 768);
        setup.SetTitle("Hello Frontend");
        setup.SetFileSystemRoot("data");
        setup.Start();

        Keyboard keyboard(setup.GetWindow());

        double startTime = setup.GetTime();
        IO::StdOut().WriteTextLine("Starting main loop");

        // Load the scenes
        FirstTry::TestScene firstScene(setup);

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
            firstScene.run();
        }
    }
    catch (Exception e)
    {
        setup.HandleException(e);
    }

    return 1;
}
