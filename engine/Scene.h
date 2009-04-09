#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <OpenFrontend2.h>
#include <Frontend2Utils.h>
#include "Demo.h"

namespace FirstEngine {
  class Scene
  {
  protected:
    FirstEngine::Demo *demo;

  public:
    Scene(FirstEngine::Demo &demo);
    virtual void run() = 0;
  };
}

#endif // FIRST_SCENE_H_INCLUDED
