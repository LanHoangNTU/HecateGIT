#if !defined(HECATE_BARCHBOX)
#define HECATE_BARCHBOX

#include <hecate/render_manager.h>
#include <hecate/topbar.hpp>

#define BBoxH(offset, gap, h) ((h - TopBarOffset(offset, gap, h)) / 1.55)
#define BBoxW(w) ((w - TopBarH(w)) / 2)

class BranchBox : public RenderManager {
    public:
        BranchBox();
        ~BranchBox();

        void Resize(int offset, int gap, int screenW, int screenH);
};

#endif // HECATE_BARCHBOX
