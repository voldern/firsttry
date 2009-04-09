#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include <OpenFrontend2.h>
#include <Frontend2Utils.h>
#include "Demo.h"

namespace FirstEngine
{
  class Demo;

  class Debug: public Frontend::Object
  {
  private:
    Demo *demo;
    Frontend::Utils::Simple::SimpleText *text;
    
    bool enableControls;
    bool enableTimeline;
    bool enableInfo;

    void DisplayInfo();
    void ForwardTime(float step);
    void RewindTime(float step);
    void DisplayTimeline();
    void FreeRoam();    
  public:
    Debug(Demo *demo);

    void Run();
  };
}

#endif // DEBUG_H_INCLUDED
