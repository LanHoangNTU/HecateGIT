#if !defined(HECATE_TOPBAR)
#define HECATE_TOPBAR

#include <hecate/render_manager.h>

#define TOPBAR_H 30
#define TopBarH(h) (h / TOPBAR_H)
#define TopBarOffset(offset, gap, h) (offset + gap + TopBarH(h))

class TopBar : public RenderManager {
    public:
        TopBar(int offset, int gap, int screenW, int screenH);
        ~TopBar();

        void Resize(int offset, int gap, int screenW, int screenH);
};

#endif // HECATE_TOPBAR
