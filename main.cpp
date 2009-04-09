#include <OpenFrontend2.h>
#include <Frontend2Utils.h>
#include <vector>

#include "engine/Scene.h"
#include "engine/Demo.h"
#include "scenes/TestScene.h"

using namespace Frontend;
using namespace Frontend::Utils;

int main(int argc, char** argv)
{
    FirstEngine::Demo setup(GUI::CreateNativeWindowManager(), Graphics::OpenFrontendGL2CG());

    try {
        setup.GetStdOut()->WriteTextLine("Setting up enviroment");

        setup.SetResolution(1024, 768);
        setup.SetFileSystemRoot("data");
        setup.SetHandleInput(true);
        setup.SetExitOnEsc(true);
        setup.SetEnableDebug(true);
        setup.Start();

        double startTime = setup.GetTime();
        setup.GetStdOut()->WriteTextLine("Starting main loop");

        // Load the scenes
        FirstTry::TestScene firstScene(setup);

        while (setup.Update()) {
            // Clear the screen
            setup.GetGraphicsDevice()->Clear(Graphics::ClearBuffersAll, 1, 0, 0, 0, 1, 0);
      
            if (setup.GetKeyboard()->KeyDown('F'))
                IO::StdOut().WriteTextLine((Frontend::String)setup.GetFPS());
      
            // Run the test scene
            firstScene.run();
        }
    }
    catch (Exception e) {
        setup.HandleException(e);
    }

    return 0;
}
