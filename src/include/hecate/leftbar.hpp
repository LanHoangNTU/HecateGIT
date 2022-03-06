#if !defined(HECATE_LEFTBAR)
#define HECATE_LEFTBAR

#include <hecate/topbar.hpp>
#include <hecate/render_manager.h>

class LeftBar : public RenderManager {
    public:
        LeftBar();
        ~LeftBar();

        void Resize(int offset, int gap, int screenW, int screenH);
};

#endif // HECATE_LEFTBAR
