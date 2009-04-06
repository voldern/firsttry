#include "Demo.h"
#include <OpenFrontend2.h>
#include <Frontend2Utils.h>

using namespace Frontend;
using namespace Frontend::Utils;

namespace FirstEngine {

    Demo::Demo(GUI::WindowManager *windowManager, Graphics::Device::Factory *graphicsBackend)
    {
        this->windowManager = windowManager;
        this->graphicsBackend = graphicsBackend;

        // Default settings
        this->title = "FirstEngine";
        this->windowStyle = GUI::WindowStyleCaption;
        this->started = false;
        this->graphicsDevice = 0;
        this->fullscreenDisplay = 0;
        this->window = 0;
        this->fileSystem = 0;
        this->stdOut = new IO::StdOut();
        this->stdIn = new IO::StdIn();
        this->proxy = 0;
        this->multiSamples = 0;
        this->graphicsFlags = 0;
        this->resolution = Math::Vector2i(800, 600);
        this->depthStencilFormat = Graphics::DepthStencilFormatD24S8;
        this->time = 0.0;
        this->frameTime = 0.001;
        this->fps = 1000.0;
        this->exitOnEsc = false;
    }
    
    /*
     * Setters
     */

    void Demo::SetTitle(String title)
    {
        if (started) throw Exception("Demo::SetTitle(): Can not change title while Demo is running");
        this->title = title;
    }

    void Demo::SetWindowStyle(GUI::WindowStyle windowStyle)
    {
        if (started) throw Exception("Demo::SetNativeBorder(): Can not change border while Demo is running");
        this->windowStyle = windowStyle;
    }

    void Demo::SetGraphicsFlags(int flags)
    {
        if (started) throw Exception("Demo::SetGraphicsFlags(): Can not change graphics flags while Demo is running");
        this->graphicsFlags = flags;
    }
			
    void Demo::SetFullscreenDisplay(Display* display)
    {
        if (started) throw Exception("Demo::SetFullscreenDisplay(): Can not change graphics flags while Demo is running");
        this->fullscreenDisplay = display;
        if (display) SetWindowStyle(GUI::WindowStyleNone);
    }

    void Demo::SetVerticalSync(bool vsync)
    {
        if (started) throw Exception("Demo::SetVerticalSync(): Can not change graphics flags while Demo is running");

        if (vsync) 
            this->graphicsFlags |= Graphics::DeviceFlagVerticalSync;
        else 
            this->graphicsFlags &= ~Graphics::DeviceFlagVerticalSync;
    }

    void Demo::SetShowCursor(bool showCursor)
    {
        if (showCursor) 
            windowManager->ShowCursor();
        else 
            windowManager->HideCursor();
    }

    void Demo::SetMultiSamples(int ms)
    {
        if (started) throw Exception("Demo::SetMultiSamples(): Can not change multi sample level while Demo is running");
        this->multiSamples = ms;
    }

    void Demo::SetFileSystemRoot(String root)
    {
        if (started) throw Exception("Demo::SetFileSystemRoot(): Can not change file system root while Demo is running");
        this->fileSystem = new IO::StdFileSystem(root);
    }

    void Demo::SetFileSystem(IO::FileSystem* fs)
    {
        if (started) throw Exception("Demo::SetFileSystem(): Can not change file system while Demo is running");
        this->fileSystem = fs;
        this->fileSystem->AddRef();
    }

    void Demo::SetResolution(int width, int height)
    {
        if (started) throw Exception("Demo::SetResolution(): Can not change resolution while Demo is running");
        this->resolution = Math::Vector2i(width, height);
    }

    void Demo::SetDepthStencilFormat(Graphics::DepthStencilFormat dsFmt)
    {
        if (started) throw Exception("Demo::SetDepthStencilFormat(): Can not change depth/stencil format while Demo is running");
        this->depthStencilFormat = dsFmt;
    }

    void Demo::SetExitOnEsc(bool exit)
    {
        this->exitOnEsc = exit;
    }

    /**
     * Getters
     */

    Graphics::Device* Demo::GetGraphicsDevice()
    {
        if (!started) throw Exception("Demo::GetGraphicsDevice(): Can not get graphics device before Demo is started");
        if (!graphicsDevice) throw Exception("Demo::GetGraphicsDevice(): No graphics device present");
        return graphicsDevice;
    }

    GUI::Window* Demo::GetWindow()
    {
        if (!started) throw Exception("Demo::GetWindow(): Can not get window before Demo is started");
        return window;
    }

    IO::FileSystem* Demo::GetFileSystem()
    {
        if (!fileSystem) throw Exception("Demo::GetFileSystem(): No file system is set");
        return fileSystem;
    }

    IO::Stream* Demo::GetStdOut()
    {
        return stdOut;
    }

    IO::Stream* Demo::GetStdIn()
    {
        return stdIn;
    }

    ResourceProxy* Demo::GetResourceProxy()
    {
        if (!started) throw Exception("Demo::GetResourceProxy(): Can not get proxy before Demo is started");
        return proxy;
    }

    FramebufferProxy* Demo::GetFramebufferProxy()
    {
        if (!started) throw Exception("Demo::GetFramebufferProxy(): Can not get proxy before Demo is started");
        return fproxy;
    }

    Math::Vector2i Demo::GetResolution()
    {
        return resolution;
    }

    String Demo::GetTitle()
    {
        return title;
    }

    double Demo::GetTime()
    {
        return time;
    }

    double Demo::GetFrameTime()
    {
        return frameTime;
    }

    double Demo::GetFPS()
    {
        return fps;
    }

    ProbeProxy* Demo::GetProbeProxy()
    {
        if (!started) throw Exception("Demo::GetProbeProxy(): Can not get probe proxy before Demo is started");
        return probeProxy;
    }

    ProfileProxy* Demo::GetProfileProxy()
    {
        if (!started) throw Exception("Demo::GetProfileProxy(): Can not get profile proxy before Demo is started");
        return profileProxy;
    }

    State* Demo::GetState()
    {
        if (!started) throw Exception("Demo::GetState(): Can not get state before Demo is started");
        return state;
    }

    Keyboard* Demo::GetKeyboard()
    {
        if (!started) throw Exception("Demo::GetState(): Can not get keyboard before Demo is started");
        return keyboard;
    }

    Mouse* Demo::GetMouse()
    {
        if (!started) throw Exception("Demo::GetState(): Can not get mouse before Demo is started");
        return mouse;
    }

    void Demo::Start()
    {
        window = windowManager->CreateWindow(windowStyle);
        window->SetSize(resolution.x, resolution.y);
        window->SetCaption(title);
      
        if (fullscreenDisplay) {
            int settings = fullscreenDisplay->FindSettings(resolution.x, resolution.y, 32, 0);
            if (settings == -1) throw Exception("Resolution not supported on target display");
            fullscreenDisplay->SelectSettings(settings);
        }
            
        // Create graphics device
        graphicsDevice = graphicsBackend->CreateDevice(window, depthStencilFormat, multiSamples, graphicsFlags);

        // Set up IO
        if (!fileSystem) fileSystem = new IO::StdFileSystem(".");

        // Set up probe proxy
        probeProxy = new ProbeProxy();

        // Set up profiling proxy
        profileProxy = new ProfileProxy();

        // Set up proxy
        proxy = new DefaultResourceProxy();
        proxy->SetGraphicsDevice(graphicsDevice);
        proxy->SetFileSystem(fileSystem);

        // Set up framebufferproxy
        fproxy = new FramebufferProxy(graphicsDevice);

        // Set up timer
        timer = new Timer();

        // Set up keyboard and mouse
        this->keyboard = new Keyboard(window);
        this->mouse = new Mouse(window);

        // Set up state
        state = new State();
        state->Resolution.Push(resolution);
        state->GraphicsDevice.Push(graphicsDevice);

        // Done
        started = true;		
    }

    bool Demo::Update()
    {
        // Check if we should exit
        if (exitOnEsc == true && keyboard->KeyDown(GUI::KeyEsc))
            return false;

        time = timer->GetTime();
        frameTime = timer->GetInterval();
        fps = timer->GetFPS();
        graphicsDevice->Update();
        return windowManager->Update();
    }

    void Demo::HandleException(Exception e)
    {
        windowManager->ShowMessageDialog(0, e.GetMessage(), "FirstEngine Exception", GUI::DialogButtonsOK, GUI::DialogHintError);
    }
} // Namespace FirstEngine