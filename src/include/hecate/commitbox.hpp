#if !defined(HECATE_COMMITBOX)
#define HECATE_COMMITBOX

#include <hecate/render_manager.h>
#include <hecate/topbar.hpp>
#include <hecate/branchbox.hpp>

class CommitBox : public RenderManager {
    public:
        CommitBox();
        ~CommitBox();

        void Resize(int offset, int gap, int screenW, int screenH);
};

#endif // HECATE_COMMITBOX
