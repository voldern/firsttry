#ifndef TEST_SCENE_H_INCLUDED
#define TEST_SCENE_H_INCLUDED

#include "../engine/Scene.h"

using namespace Frontend;

namespace FirstTry
{
  class TestScene: public FirstEngine::Scene
  {
  public:
    TestScene(Frontend::Utils::Simple::SimpleSetup &engine) : FirstEngine::Scene(engine) {}
    void run() {
      this->engine->GetGraphicsDevice()->Clear(Graphics::ClearBuffersAll, 0, 0, 0, 0, 1, 0);
    }
  };
}

#endif // TEST_SCENE_H_INCLUDED
