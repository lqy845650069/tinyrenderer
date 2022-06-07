#include "tgaimage.h"
#include "model.h"
#include "geometry.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);
constexpr int width  = 800; // output image size
constexpr int height = 800;

void line(vec2 t0, vec2 t1, TGAImage &image, TGAColor color) { 
    int x0 = t0[0], y0 = t0[1], x1 = t1[0], y1 = t1[1];
    bool steep = false; 
    if (std::abs(x0-x1)<std::abs(y0-y1)) { 
        std::swap(x0, y0); 
        std::swap(x1, y1); 
        steep = true; 
    } 
    if (x0>x1) { 
        std::swap(x0, x1); 
        std::swap(y0, y1); 
    } 
    int dx = x1-x0; 
    int dy = y1-y0; 
    int derror2 = std::abs(dy)*2; 
    int error2 = 0; 
    int y = y0; 
    for (int x=x0; x<=x1; x++) { 
        if (steep) { 
            image.set(y, x, color); 
        } else { 
            image.set(x, y, color); 
        } 
        error2 += derror2; 
        if (error2 > dx) { 
            y += (y1>y0?1:-1); 
            error2 -= dx*2; 
        } 
    } 
}

void triangle(vec2 t0, vec2 t1, vec2 t2, TGAImage& image, TGAColor color){
    line(t0, t1, image, color);
    line(t1, t2, image, color);
    line(t2, t3, image, color);

}

int main(int argc, char** argv) {
    
    vec2 t0[3] = {vec2(10, 70), vec2}

    return 0;
}

