#include <Frontend2.h>
#include <Frontend2Utils.h>
#include <Frontend2Graphics.h>
#include <iostream>

using namespace Frontend;

int main()
{
    try
    {
        Utils::Application FirstTry;
    }
    catch(Frontend::Exception e)
    {
        printf("Frontend exception: %s\n", e.GetMessage().CharStringCopy());
    }

    return 0;
}
