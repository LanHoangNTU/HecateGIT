
#include "hecate/branchbox.hpp"

BranchBox::BranchBox() { }

BranchBox::~BranchBox() { }


void BranchBox::Resize(int offset, int gap, int screenW, int screenH) {
    SetPanel(std::make_shared<Panel>(
        offset + TopBarH(screenW) + gap, 
        TopBarOffset(offset, gap, screenH), 
        BBoxW(screenW), 
        BBoxH(offset, gap, screenH)
    ));
}