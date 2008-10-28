#include "FirstTry/FirstTry.h"
#include "FirstTry/Scenes/Intro.h"

int main()
{
    try
    {
        FirstTry::FirstTry FirstTry;

        FirstTry::Scene::Intro* introScene = new FirstTry::Scene::Intro(FirstTry, 50);
        FirstTry.scenes.Add(introScene);

        printf("Starting FirstTry\n");
        FirstTry.init();
        FirstTry.run();
    }
    catch(Frontend::Exception e)
    {
        printf("Frontend exception: %s\n", e.GetMessage().CharStringCopy());
    }

    return 0;
}
