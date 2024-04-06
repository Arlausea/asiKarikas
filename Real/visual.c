#include"algorithm.h"

void highlight(int x, int y, int shift_x, int shift_y, int window_w, int window_h, int zoom, SDL_Renderer *renderer){
    int size = 64;
    SDL_Rect rect;
    rect.w = size;
    rect.h = size;

    rect.y = shift_y-(window_h*zoom-window_h)/2 + y*zoom - size/2;
    rect.x = shift_x-(window_w*zoom-window_w)/2 + x*zoom - size/2;
    
    SDL_RenderDrawRect(renderer, &rect); // Draw.
    SDL_RenderFillRect(renderer, &rect);
}
