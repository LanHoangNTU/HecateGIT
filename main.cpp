#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <hecate/window.h>

int main(int argc, char** argv) {

    try {
        std::unique_ptr<Window> win = std::make_unique<Window>(Window());
        win->Size(1366, 786);
        win->CreateWindow();
        win->Start();
        win->Quit();
    } catch (char const* error) {
        std::cout << error;
    }

    return 0;
}