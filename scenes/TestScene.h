#ifndef TEST_SCENE_H_INCLUDED
#define TEST_SCENE_H_INCLUDED

#include "../engine/Scene.h"
#include "../engine/Demo.h"

using namespace Frontend;
using namespace Frontend::Utils;
using namespace Frontend::Utils::Simple;

namespace FirstTry
{
  class TestScene: public FirstEngine::Scene
    {
    private:
      RScene *level;
      RProgram *shader;
      SimpleRenderer *renderer;

      Keyboard *keyboard;
      Mouse *mouse;
    public:
    TestScene(FirstEngine::Demo &engine) : FirstEngine::Scene(engine)
        {
          this->level = new RScene("level.DAE");
          this->shader = new RProgram("shader.cg");

          this->renderer = new SimpleRenderer(this->engine->GetGraphicsDevice());
          this->renderer->SetProgram(*this->shader);
          this->renderer->GetCamera()->SetPosition(Math::Vector3(0, 0, 5));

          // Setup input
          this->keyboard = new Keyboard(this->engine->GetWindow());
          this->mouse = new Mouse(this->engine->GetWindow());
        }

      void run() 
      {
        this->engine->GetGraphicsDevice()->Clear(Graphics::ClearBuffersAll, 0.3, 0.35, 0.65, 0, 1, 0);

        float walkSpeed = 50.0f;
        float turnSpeed = 0.2f;
        float frameTime = this->engine->GetFrameTime();

        // Shift to get super speed!
        if (this->keyboard->KeyDown(GUI::KeyShift)) walkSpeed = 500.0f;

        // Navigate with WASD
        if (this->keyboard->KeyDown('W')) this->renderer->GetCamera()->Move(frameTime * walkSpeed);
        if (this->keyboard->KeyDown('S')) this->renderer->GetCamera()->Move(-frameTime * walkSpeed);
        if (this->keyboard->KeyDown('A')) this->renderer->GetCamera()->Strafe(-frameTime * walkSpeed);
        if (this->keyboard->KeyDown('D')) this->renderer->GetCamera()->Strafe(frameTime * walkSpeed);
      
        // Navigate with the mouse
        Math::Vector2i mouseDelta = this->mouse->Lock(this->engine->GetWindow());
        this->renderer->GetCamera()->Turn(mouseDelta.x * turnSpeed);
        this->renderer->GetCamera()->Pitch(- mouseDelta.y * turnSpeed);

        this->renderer->Render(this->engine->GetState(), *this->level);
      }
    };
}

#endif // TEST_SCENE_H_INCLUDED
