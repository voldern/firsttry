#include "FirstTry/FirstTry.h"
#include "FirstTry/Scenes/Intro.h"

int main()
{
    try
    {
        printf("Starting FirstTry\n");

        FirstTry::FirstTry FirstTry;

        printf("Loading scenes\n");

        FirstTry::Scene::Intro introScene(FirstTry);
        FirstTry.scenes.push_back(&introScene);

        FirstTry.init();
        FirstTry.run();
    }
    catch(Frontend::Exception e)
    {
        printf("Frontend exception: %s\n", e.GetMessage().CharStringCopy());
    }

    return 0;
}
