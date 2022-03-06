#ifndef HECATE_SQUARE
#define HECATE_SQUARE

#include <iostream>
#include <hecate/renderable.h>

class Square : public Renderable {
    private:
        int test;  

    public:
        Square(int x, int y, int width, int height);
        virtual ~Square();

        void Render();
};

#endif