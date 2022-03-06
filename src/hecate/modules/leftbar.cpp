
#include "hecate/leftbar.hpp"


LeftBar::LeftBar() {}

LeftBar::~LeftBar() {}

void LeftBar::Resize(int offset, int gap, int screenW, int screenH) {
    int topBarH = TopBarH(screenH);
    int topBarOffset = TopBarOffset(offset, gap, screenH);
    
    SetPanel(std::make_shared<Panel>(
        offset,
        topBarOffset,
        TopBarH(screenW),
        screenH - topBarOffset - offset
    ));
}