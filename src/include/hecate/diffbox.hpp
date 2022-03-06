#if !defined(HECATE_DIFFBOX)
#define HECATE_DIFFBOX

#include <hecate/render_manager.h>
#include <hecate/topbar.hpp>
#include <hecate/branchbox.hpp>

class DiffBox : public RenderManager {
    public:
        DiffBox();
        ~DiffBox();

        void Resize(int offset, int gap, int screenW, int screenH);
};

#endif // HECATE_DIFFBOX
