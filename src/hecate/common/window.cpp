
#include "hecate/window.h"

Window::Window() {
    m_BranchBox = std::make_unique<BranchBox>();
    m_TopBar = std::make_unique<TopBar>(1, 1, 1, 1);
    m_LeftBar = std::make_unique<LeftBar>();
    m_DiffBox = std::make_unique<DiffBox>();
    m_CommitBox = std::make_unique<CommitBox>();

    // m_PanelBranch->AddRenderable(std::make_shared<Square>(2, 4, 8, 16));
    m_isStarted = false;
}
Window::~Window() { 
}

Window* Window::Size(int width, int height) {
    m_Width = width;
    m_Height = height;
    int offset = 5, gap = 2;
    int topBarHeight = m_Height / 25;
    int branchWidth = m_Width * 1/3;

    m_TopBar->Resize(offset, gap, m_Width, m_Height);
    std::vector<std::string> test;
    test.emplace_back("a");
    m_TopBar->SetAvailableScenes(test);
    m_TopBar->SwitchScene("a");

    m_LeftBar->Resize(offset, gap, m_Width, m_Height);
    m_LeftBar->SetAvailableScenes(test);
    m_LeftBar->SwitchScene("a");

    m_BranchBox->Resize(offset, gap, m_Width, m_Height);
    m_BranchBox->SetAvailableScenes(test);
    m_BranchBox->SwitchScene("a");

    m_DiffBox->Resize(offset, gap, m_Width, m_Height);
    m_DiffBox->SetAvailableScenes(test);
    m_DiffBox->SwitchScene("a");

    m_CommitBox->Resize(offset, gap, m_Width, m_Height);
    m_CommitBox->SetAvailableScenes(test);
    m_CommitBox->SwitchScene("a");

    // m_PanelBranch->SetPanel(std::make_shared<Panel>(offset, topBarHeight + gap * 2, branchWidth, m_Height - topBarHeight - offset - gap));
    // m_PanelDiff->SetPanel(std::make_shared<Panel>(branchWidth + gap + offset, topBarHeight + gap * 2, m_Width - branchWidth - gap - offset * 2, m_Height - topBarHeight - offset - gap));

    return this;
}

void Window::CreateWindow() {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw "Error: SDL failed to initialize\nError: ", SDL_GetError();
    }

    m_Window = SDL_CreateWindow("HecateGIT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_Width, m_Height, 0);
    if(!m_Window){
        throw "Error: Failed to open window\nError:", SDL_GetError();
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
    if(!m_Renderer){
        throw "Error: Failed to create renderer\n", SDL_GetError();
    }

    m_isStarted = true;
}

void Window::Start() {
    bool running = m_isStarted;
    unsigned int tick;
    unsigned int previousTick;
    unsigned int delta;
    
    while(running){
        SDL_Event event;
        if(SDL_WaitEvent(&event) != 0){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;

                default:
                    break;
            }
        }

        tick = SDL_GetTicks();
        delta = tick - previousTick;
        if (delta > 1000/60.0) {
            SDL_SetRenderDrawColor(m_Renderer, m_RenderColor.r, m_RenderColor.g, m_RenderColor.b, m_RenderColor.a);
            SDL_RenderClear(m_Renderer);
            Render();
            SDL_RenderPresent(m_Renderer);

            previousTick = tick;
        }
    }
}

Window* Window::BaseColor(int r, int g, int b, int a) {
    m_RenderColor = SDL_Color();
    m_RenderColor.r = r;
    m_RenderColor.g = g;
    m_RenderColor.b = b;
    m_RenderColor.a = a;
}

void Window::Quit() {
    m_isStarted = false;
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}


void Window::Render() {
    m_TopBar->Render(m_Renderer);
    m_LeftBar->Render(m_Renderer);
    m_BranchBox->Render(m_Renderer);
    m_DiffBox->Render(m_Renderer);
    m_CommitBox->Render(m_Renderer);
}