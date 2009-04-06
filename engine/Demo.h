#ifndef DEMO_H_INCLUDED
#define DEMO_H_INCLUDED

#include <OpenFrontend2.h>
#include <Frontend2Utils.h>

using namespace Frontend;
using namespace Frontend::Utils;

namespace FirstEngine {
    class Demo: public Object
    {
      protected:
        Graphics::Device::Factory *graphicsBackend;
        Math::Vector2i resolution;
        Graphics::DepthStencilFormat depthStencilFormat;
    
        String title;
        GUI::WindowStyle windowStyle;
        int graphicsFlags;
        int multiSamples;
        Display *fullscreenDisplay;
        bool vsync;

        Managed<GUI::WindowManager> windowManager;
        Managed<GUI::Window> window;
        Managed<Graphics::Device> graphicsDevice;
        Managed<IO::FileSystem> fileSystem;
        Managed<IO::Stream> stdOut;
        Managed<IO::Stream> stdIn;
        Managed<ResourceProxy> proxy;
        Managed<FramebufferProxy> fproxy;
        Managed<ProbeProxy> probeProxy;
        Managed<ProfileProxy> profileProxy;
        Managed<Timer> timer;
        Managed<Keyboard> keyboard;
        Managed<Mouse> mouse;
        double time, frameTime, fps;
    
        Managed<State> state;
        bool showCursor;
        bool started;

        bool handleInput;
        bool exitOnEsc;
    
      public:
        /**
         * Creates a Demo and initialized default values for all settings.
         * @param windowManager The window manager to use (i.e. OpenFrontend's GUI::CreateNativeWindowManager()).
         * @param backedn The Graphics::Device::Factory (graphics backend) to use (i.e. Graphics::OpenFrontendGL2CG())
         */
        Demo(GUI::WindowManager *windowManager, Graphics::Device::Factory *graphicsBackend);

        void HandleException(Exception e);
    
        // Setters
        void SetTitle(String title);
        void SetWindowStyle(GUI::WindowStyle windowStyle);
        void SetGraphicsFlags(int flags);
        void SetFullscreenDisplay(Display* display);
        void SetVerticalSync(bool vsync);
        void SetMultiSamples(int multiSamples);
        void SetFileSystemRoot(String root);
        void SetFileSystem(IO::FileSystem* fs);
        void SetResolution(int width, int height);
        void SetDepthStencilFormat(Graphics::DepthStencilFormat dsFmt);
        void SetShowCursor(bool showCursor);
        void SetExitOnEsc(bool exit);
        void SetHandleInput(bool handle);

        // Getters
        GUI::WindowManager* GetWindowManager() { return windowManager; }
        Graphics::Device* GetGraphicsDevice();
        GUI::Window* GetWindow();
        IO::FileSystem* GetFileSystem();
        IO::Stream* GetStdOut();
        IO::Stream* GetStdIn();
        ResourceProxy* GetResourceProxy();
        FramebufferProxy* GetFramebufferProxy();
        Timer* GetTimer();
        ProbeProxy* GetProbeProxy();
        ProfileProxy* GetProfileProxy();
        Math::Vector2i GetResolution();
        String GetTitle();
        int GetMultiSamples() { return multiSamples; }
        State* GetState();
        Keyboard* GetKeyboard();
        Mouse* GetMouse();

        double GetTime();
        double GetFrameTime();
        double GetFPS();

        /**
         * Starts the application.
         * Should be called after all the config has been done through
         * using the Set-function.
         */
        void Start();

        /**
         * Should be called by your mainloop.
         * When returning false should exit your mainloop.
         */
        bool Update();
    
    };
}

#endif // DEMO_H_INCLUDED
