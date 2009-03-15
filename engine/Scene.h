#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <OpenFrontend2.h>
#include <Frontend2Utils.h>

namespace FirstEngine {
  class Scene
  {
  protected:
    Frontend::Utils::Simple::SimpleSetup *engine;

  public:
    Scene(Frontend::Utils::Simple::SimpleSetup &engine);
    virtual void run() = 0;
  };
}

#endif // FIRST_SCENE_H_INCLUDED
