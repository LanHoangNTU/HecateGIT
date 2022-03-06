
#include "hecate/commitbox.hpp"

CommitBox::CommitBox() { }

CommitBox::~CommitBox() { }


void CommitBox::Resize(int offset, int gap, int screenW, int screenH) {
    int topBarOffset = TopBarOffset(offset, gap, screenH);
    int branchBoxHeight = BBoxH(offset, gap, screenH);
    int offsetH = topBarOffset + branchBoxHeight + gap;
    int doubleGap = gap * 2;

    SetPanel(std::make_shared<Panel>(
        gap + TopBarH(screenW) + offset, 
        topBarOffset + branchBoxHeight + gap,
        BBoxW(screenW), 
        screenH - offsetH - offset
    ));
}