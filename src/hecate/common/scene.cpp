
#include "hecate/scene.h"

Scene::Scene() {
    // m_Panel = nullptr;
}
Scene::~Scene() {
    m_Renderables.clear();
}

void Scene::SetPanel(std::shared_ptr<Panel> panel) {
    m_Panel = panel;
}

void Scene::AddRenderable(std::shared_ptr<Renderable> renderable) {
    renderable->SetPanel(m_Panel);
    m_Renderables.push_back(renderable);
}

void Scene::RenderAll(SDL_Renderer* renderer) {
    for (auto const& renderable: m_Renderables) {
        renderable->Render();
    }
}