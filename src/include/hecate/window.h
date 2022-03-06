#ifndef HECATE_WINDOW
#define HECATE_WINDOW

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <hecate/render_manager.h>
#include <hecate/square.h>
#include <hecate/topbar.hpp>
#include <hecate/leftbar.hpp>
#include <hecate/branchbox.hpp>
#include <hecate/diffbox.hpp>
#include <hecate/commitbox.hpp>

class Window {
    private:
        const std::string c_AppName = "HecateGIT";
        int m_Width;
        int m_Height;
        bool m_isStarted;
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
        SDL_Color m_RenderColor;

        std::unique_ptr<TopBar> m_TopBar;
        std::unique_ptr<LeftBar> m_LeftBar;
        std::unique_ptr<BranchBox> m_BranchBox;
        std::unique_ptr<DiffBox> m_DiffBox;
        std::unique_ptr<CommitBox> m_CommitBox;

        void Render();
        
    public:
        Window();
        ~Window();

        // TODO Add more window create options
        // TODO Read configs from a file (start app + during runtime)
        Window* Size(int width, int height);
        Window* BaseColor(int r, int g, int b, int a);

        void CreateWindow();
        void Start();
        void Quit();
};

#endif