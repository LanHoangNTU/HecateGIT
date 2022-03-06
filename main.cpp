#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <hecate/window.h>
#include <hecate/square.h>
#include <hecate/renderable.h>

int main(int argc, char** argv) {

    Window* win = new Window();
    win->Size(1536, 864)
        ->BaseColor(217, 223, 228, 255);
        // ->BaseColor(0, 0, 0, 255);
    win->CreateWindow();
    win->Start();
    win->Quit();

    return 0;
}