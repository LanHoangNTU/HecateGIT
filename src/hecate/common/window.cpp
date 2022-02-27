#ifndef HECATE_WINDOW
#define HECATE_WINDOW

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include "hecate/window.h"

Window::Window() {
    m_isStarted = false;
}
Window::~Window() { }

Window* Window::Size(int width, int height) {
    m_Width = width;
    m_Height = height;

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
    while(running){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;

                default:
                    break;
            }
        }

        SDL_SetRenderDrawColor(m_Renderer, m_RenderColor.r, m_RenderColor.g, m_RenderColor.b, m_RenderColor.a);
        SDL_RenderClear(m_Renderer);
        SDL_RenderPresent(m_Renderer);
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

#endif