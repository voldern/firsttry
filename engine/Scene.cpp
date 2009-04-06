#include "Scene.h"
#include "Demo.h"

namespace FirstEngine 
{
  Scene::Scene(FirstEngine::Demo &engine)
  {
    this->engine = &engine;
  }
}
