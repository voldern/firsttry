#ifndef TEST_SCENE_H_INCLUDED
#define TEST_SCENE_H_INCLUDED

#include "../engine/Scene.h"
#include "../engine/Demo.h"

using namespace Frontend;
using namespace Frontend::Utils;
using namespace Frontend::Utils::Simple;

namespace FirstTry
{
    class Demo;

    class TestScene: public FirstEngine::Scene
    {
    private:
        RScene *level;
        RProgram *shader;
        SimpleRenderer *renderer;
    public:
    TestScene(FirstEngine::Demo &demo): FirstEngine::Scene(demo)
        {
            this->level = new RScene("level.DAE");
            this->shader = new RProgram("shader.cg");

            this->renderer = new SimpleRenderer(this->demo->GetGraphicsDevice());
            this->renderer->SetProgram(*this->shader);
            this->renderer->GetCamera()->SetPosition(Math::Vector3(0, 0, 5));
        }

        void run() 
        {
            demo->GetFramebuffer()->Lock();
            demo->GetState()->RenderTarget.Push(demo->GetFramebuffer());
            
            demo->GetFramebuffer()->Clear(Graphics::ClearBuffersAll, 0.3, 0.35, 0.65, 0, 1, 0);
            demo->GetGraphicsDevice()->Clear(Graphics::ClearBuffersAll, 0.3, 0.35, 0.65, 0, 1, 0);

            float walkSpeed = 50.0f;
            float turnSpeed = 0.2f;
            float frameTime = demo->GetFrameTime();

            if (demo->GetHandleInput()) {
                // Shift to get super speed!
                if (demo->GetKeyboard()->KeyDown(GUI::KeyShift)) walkSpeed = 500.0f;

                // Navigate with WASD
                if (demo->GetKeyboard()->KeyDown('W')) this->renderer->GetCamera()->Move(frameTime * walkSpeed);
                if (demo->GetKeyboard()->KeyDown('S')) this->renderer->GetCamera()->Move(-frameTime * walkSpeed);
                if (demo->GetKeyboard()->KeyDown('A')) this->renderer->GetCamera()->Strafe(-frameTime * walkSpeed);
                if (demo->GetKeyboard()->KeyDown('D')) this->renderer->GetCamera()->Strafe(frameTime * walkSpeed);
      
                // Navigate with the mouse
                Math::Vector2i mouseDelta = demo->GetMouse()->Lock(demo->GetWindow());
                this->renderer->GetCamera()->Turn(mouseDelta.x * turnSpeed);
                this->renderer->GetCamera()->Pitch(- mouseDelta.y * turnSpeed);
            }

            this->renderer->Render(demo->GetState(), *this->level);
            
            demo->GetState()->RenderTarget.Pop();
            demo->GetFramebuffer()->Unlock();
        }
    };
}

#endif // TEST_SCENE_H_INCLUDED
