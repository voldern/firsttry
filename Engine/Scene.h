#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

namespace Engine
{
    class Scene
    {
    protected:
        // Scene length in seconds
        float length;
    public:
        Scene()
        {
            length = 0;
        }
        // This function should load all the heavy duty stuff that the scenen needs
        virtual void load() = 0;

        // This function should run/draw the scene
        virtual void draw() = 0;

        float getLength()
        {
            return length;
        }
    };
}

#endif // SCENE_H_INCLUDED
