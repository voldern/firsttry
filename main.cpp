#include "FirstTry/FirstTry.h"

int main()
{
    try
    {
        printf("Starting FirstTry\n");

        FirstTry::FirstTry FirstTry;
        FirstTry.run();
    }
    catch(Frontend::Exception e)
    {
        printf("Frontend exception: %s\n", e.GetMessage().CharStringCopy());
    }

    return 0;
}
