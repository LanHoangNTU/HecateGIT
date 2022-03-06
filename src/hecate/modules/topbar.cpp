
#include "hecate/topbar.hpp"

TopBar::TopBar(int offset, int gap, int screenW, int screenH) {
    Resize(offset, gap, screenW, screenH);
}

TopBar::~TopBar() { }


void TopBar::Resize(int offset, int gap, int screenW, int screenH) {
    SetPanel(std::make_shared<Panel>(
        offset, 
        offset, 
        screenW - offset * 2, 
        TopBarH(screenH)
    ));
}