#include "Scene.h"
#include "Demo.h"

namespace FirstEngine 
{
  Scene::Scene(FirstEngine::Demo &demo)
  {
    this->demo = &demo;
  }
}
