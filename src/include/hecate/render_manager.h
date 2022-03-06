#ifndef HECATE_WINDOW_MANAGER
#define HECATE_WINDOW_MANAGER

#include <iostream>
#include <map>
#include <memory>
#include <stdarg.h>
#include <SDL2/SDL.h>
#include <hecate/renderable.h>
#include <hecate/scene.h>
#include <hecate/panel.h>

class RenderManager {
    protected:
        std::map<std::string, std::shared_ptr<Scene>> m_Scenes;
        std::shared_ptr<Scene> m_AciveScene;
        std::shared_ptr<Panel> m_Panel;

    public:
        RenderManager();
        ~RenderManager();

        void SetPanel(std::shared_ptr<Panel> panel);
        void SetAvailableScenes(std::vector<std::string> keys);
        void PutRenderable(std::string key, std::shared_ptr<Renderable> renderable);
        void SwitchScene(std::string key);
        void Render(SDL_Renderer* renderer);

        void Resize(int offset, int gap, int screenW, int screenH) {}
};

#endif