#include <OpenFrontend2.h>
#include <Frontend2Utils.h>
#include "Scene.h"

namespace FirstEngine 
{
  Scene::Scene(Frontend::Utils::Simple::SimpleSetup &engine)
  {
    this->engine = &engine;
  }
}
