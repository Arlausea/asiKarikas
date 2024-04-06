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

void get_x_y(char name[42], int *x, int *y){
    if(!strcmp(name, "library") || !strcmp(name, "lib")){
        x = 858;
        y = 1073;
        return;
    }
    else if(!strcmp(name, "study building 1") || !strcmp(name, "u01"))
    {
        x = 551;
        y = 594;
        return;
    }
    else if(!strcmp(name, "study building 2") || !strcmp(name, "u02"))
    {
        x = 434;
        y = 848;
        return;
    }
    else if(!strcmp(name, "study building 3") || !strcmp(name, "u03"))
    {
        x = 510;
        y = 657;
        return;
    }

    else if(!strcmp(name, "study building 4") || !strcmp(name, "u04"))
    {
        x = 544;
        y = 609;
        return;
    }
     else if(!strcmp(name, "study building 5") || !strcmp(name, "u05"))
    {
        x = 575;
        y = 555;
        return;
    }
    else if(!strcmp(name, "study building 6") || !strcmp(name, "u06"))
    {
        x = 590;
        y = 501;
        return;
    }
    else if(!strcmp(name, "study building 7") || !strcmp(name, "nrg"))
    {
        x = 661;
        y = 808;
        return;
    }
    else if(!strcmp(name, "building of natural science") || !strcmp(name, "sci"))
    {
        x = 1201;
        y = 420;
        return;
    }
    else if(!strcmp(name, "student hostel 1") || !strcmp(name, "do1"))
    {
        x = 11;
        y = 11;
        return;
    }
    else if(!strcmp(name, "student hostel 2") || !strcmp(name, "do2"))
    {
        x = 779;
        y = 676;
        return;
    }
    else if(!strcmp(name, "student hostel 3") || !strcmp(name, "do3"))
    {
        x = 838;
        y = 561;
        return;
    }
    else if(!strcmp(name, "family hostel") || !strcmp(name, "do4"))
    {
        x = 885;
        y = 458;
        return;
    }
    else if(!strcmp(name, "academic hostel") || !strcmp(name, "ho1")) //note.
    {
        x = 709;
        y = 538;
        return;
    }
    else if(!strcmp(name, "student hostel") || !strcmp(name, "do7"))
    {
        x = 783;
        y = 457;
        return;
    }
    else if(!strcmp(name, "it building") || !strcmp(name, "do6"))
    {
        x = 817;
        y = 452;
        return;
    }
    else if(!strcmp(name, "laboratory building of civil engineering") || !strcmp(name, "mek"))
    {
        x = 848;
        y = 211;
        return;
    }
    else if(!strcmp(name, "technology park") || !strcmp(name, "con"))
    {
        x = 11;
        y = 11;
        return;
    }
    else if(!strcmp(name, "building of cybernetics") || !strcmp(name, "ico"))
    {
        x = 11;
        y = 11;
        return;
    }
    else if(!strcmp(name, "building of woodworking ") || !strcmp(name, "ict"))
    {
        x = 11;
        y = 11;
        return;
    }
    else if(!strcmp(name, "stadium") || !strcmp(name, "cyb"))
    {
        x = 11;
        y = 11;
        return;
    }
    else if(!strcmp(name, "textile technology building") || !strcmp(name, "tim"))
    {
        x = 11;
        y = 11;
        return;
    }
    else if(!strcmp(name, "sports centre") || !strcmp(name, "sta"))
    {
        x = 11;
        y = 11;
        return;
    }
    else if(!strcmp(name, "study building 10"))
    {
        x = 11;
        y = 11;
        return;
    }
    else if(!strcmp(name, "") || !strcmp(name, "s01"))
    {
        x = 11;
        y = 11;
        return;
    }
    else if(!strcmp(name, "") || !strcmp(name, "soc"))
    {
        x = 11;
        y = 11;
        return;
    }
    else if(!strcmp(name, "student house") || !strcmp(name, "stu"))
    {
        x = 11;
        y = 11;
        return;
    }
    

}
