#if !defined(HECATE_SCENE)
#define HECATE_SCENE

#include <memory>
#include <vector>
#include <hecate/panel.h>
#include <hecate/renderable.h>

class Scene {
    private:
        std::vector<std::shared_ptr<Renderable>> m_Renderables;
        std::shared_ptr<Panel> m_Panel;

    public:
        Scene();
        ~Scene();

        void SetPanel(std::shared_ptr<Panel> panel);

        void AddRenderable(std::shared_ptr<Renderable> renderable);
        void RenderAll(SDL_Renderer* renderer);

};

#endif // HECATE_SCENE
