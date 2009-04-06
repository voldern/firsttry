#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <OpenFrontend2.h>
#include <Frontend2Utils.h>
#include "Demo.h"

namespace FirstEngine {
  class Scene
  {
  protected:
    FirstEngine::Demo *engine;

  public:
    Scene(FirstEngine::Demo &engine);
    virtual void run() = 0;
  };
}

#endif // FIRST_SCENE_H_INCLUDED
