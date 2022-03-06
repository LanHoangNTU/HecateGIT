#ifndef HECATE_RENDERABLE
#define HECATE_RENDERABLE

#include <memory>
#include <hecate/panel.h>

class Renderable {
    protected:
        std::shared_ptr<Panel> m_Panel;

    public: 
        int x;
        int y;
        int width;
        int height;

        Renderable() {
            this->x      = 0;
            this->y      = 0;
            this->width  = 0;
            this->height = 0;
        }

        virtual ~Renderable() {}
        virtual void Render() {}

        void SetPanel(std::shared_ptr<Panel> panel) {
            m_Panel = panel;
        }
};

#endif