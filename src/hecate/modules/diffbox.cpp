
#include "hecate/diffbox.hpp"

DiffBox::DiffBox() { }

DiffBox::~DiffBox() { }


void DiffBox::Resize(int offset, int gap, int screenW, int screenH) {
    int doubleGap = gap * 2;
    int topBarOffset = TopBarOffset(offset, gap, screenH);
    int offsetW = offset + TopBarH(screenW) + BBoxW(screenW) + doubleGap;

    SetPanel(std::make_shared<Panel>(
        offsetW, 
        topBarOffset,
        screenW - offsetW - offset,
        screenH - topBarOffset - offset
    ));
}