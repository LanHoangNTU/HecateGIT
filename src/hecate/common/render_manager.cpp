
#include "hecate/render_manager.h"

RenderManager::RenderManager() {
    // m_Panel = nullptr;
}

RenderManager::~RenderManager() {
    m_Scenes.clear();
}

void RenderManager::SetPanel(std::shared_ptr<Panel> panel) {
    m_Panel = panel;

    for (auto const& scene : m_Scenes) {
        scene.second->SetPanel(panel);
    }
}

void RenderManager::SetAvailableScenes(std::vector<std::string> keys) {
    m_Scenes.clear();
    for (auto key: keys) {
        m_Scenes[key] = std::make_shared<Scene>();
        m_Scenes[key]->SetPanel(m_Panel);
    }
}

void RenderManager::PutRenderable(std::string key, std::shared_ptr<Renderable> renderable) {
    auto it = m_Scenes.find(key);
    
    if (it != m_Scenes.end()) {
        it->second->AddRenderable(renderable);
    }
}

void RenderManager::SwitchScene(std::string key) {
    auto it = m_Scenes.find(key);
    
    if (it != m_Scenes.end()) {
        m_AciveScene = it->second;
    }
}

void RenderManager::Render(SDL_Renderer* renderer) {
    m_Panel->Render(renderer);
    m_AciveScene->RenderAll(renderer);
}