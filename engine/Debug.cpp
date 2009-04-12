#include <OpenFrontend2.h>
#include <Frontend2Utils.h>
#include "Debug.h"
#include "Demo.h"

using namespace Frontend;

namespace FirstEngine
{
    Debug::Debug(Demo *demo)
    {
        this->demo = demo;

        // Set defaults
        if (this->demo->GetHandleInput())
            this->enableControls = true;
        else
            this->enableControls = false;

        this->enableTimeline = false;
        this->enableInfo = true;

        Utils::RBitmapFont font("RadisSans-medium.ttf:40");
        text = new Utils::Simple::SimpleText(demo->GetGraphicsDevice(), font, 100);
    }

    void Debug::DisplayInfo()
    {
        String output = String::Format("%1.0f FPS %1.2f sec", demo->GetFPS(), demo->GetTime());

        demo->GetFramebuffer()->Lock();
        demo->GetState()->RenderTarget.Push(demo->GetFramebuffer());

        text->DrawText(demo->GetState(), Math::Vector2i(5, 5), Math::Vector4(1, 1, 1, 1), output);

        demo->GetState()->RenderTarget.Pop();
        demo->GetFramebuffer()->Unlock();
    }

    void Debug::ForwardTime(float step)
    {
        demo->GetStdOut()->WriteTextLine("Forwarding");
    }

    void Debug::RewindTime(float step)
    {
        demo->GetStdOut()->WriteTextLine("Rewinding");
    }

    void Debug::DisplayTimeline()
    {
    }

    void Debug::FreeRoam()
    {
    }

    void Debug::Run()
    {
        // Check for option modifiers
        if (enableControls && demo->GetHandleInput()) {
            if (demo->GetKeyboard()->KeyTrigger('I')) {
                if (enableInfo)
                    enableInfo = false;
                else
                    enableInfo = true;
                        
            }

            if (demo->GetKeyboard()->KeyTrigger('T')) {
                if (enableTimeline)
                    enableTimeline = false;
                else
                    enableTimeline = true;
            }

            if (demo->GetKeyboard()->KeyTrigger('C')) {
                if (enableControls)
                    enableControls = false;
                else
                    enableControls = true;
            }

        }

        if (enableTimeline)
            DisplayTimeline();

        if (enableInfo)
            DisplayInfo();

        if (enableControls) {
            FreeRoam();
      
            // Rewind og forward time
            if (demo->GetKeyboard()->KeyDown(GUI::KeyRightArrow))
                ForwardTime(1.5f);
            if (demo->GetKeyboard()->KeyDown(GUI::KeyLeftArrow))
                RewindTime(1.5f);
        }
    }

}
