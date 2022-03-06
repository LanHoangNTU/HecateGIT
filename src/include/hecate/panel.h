#if !defined(HECATE_PANEL)
#define HECATE_PANEL

#include <iostream>
#include <SDL2/SDL.h>

class Panel {
    private:
        SDL_Rect m_Viewport;
        SDL_Texture* m_Texture;
    
    public:
        Panel(int x, int y, int w, int h);
        ~Panel();

        void Render(SDL_Renderer* renderer);
};

#endif // HECATE_PANEL
