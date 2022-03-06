#include "hecate/panel.h"

Panel::Panel(int x, int y, int w, int h) {
    SDL_Rect rect = SDL_Rect();
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    m_Viewport = rect;
}


Panel::~Panel() {}


void Panel::Render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 37, 37, 37, 255);
    SDL_RenderDrawRect(renderer, &m_Viewport);
}