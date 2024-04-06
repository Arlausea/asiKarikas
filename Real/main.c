#include"algorithm.c"

/*
SDL credits in SDL_IMPORTANT_NOTES > CREDITS
(SDL is amazing! Many thanks to the developers of SDL!)

Compile command:
gcc -Isrc/Include -Lsrc/lib -o run main.c -lmingw32 -lSDL2main -lSDL2

*/

int main(int argc, char* args[])
{
    int running = 1;
    int window_height = 840; // 480;
    int window_with = 1120; // 640

    int zoom = 1;

    // Mouse position.
    int mouse_x;
    int mouse_y;
    int mouse_x_old;
    int mouse_y_old;
    int right_clicking = 0;
    SDL_GetMouseState(&mouse_x_old, &mouse_y_old);

    int shift_x = 0;
    int shift_y = 0;

    // Set up SDL.
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;

    SDL_Surface *surface;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(window_with, window_height, 0, &window, &renderer);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // Enables alpha blending.

    // SDL_SetWindowResizable(window, SDL_TRUE);

    // Texture
    surface = SDL_LoadBMP("textures\\map.bmp");
    SDL_Texture* texture_map = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect;
    rect.w = window_with;
    rect.h = window_height;
    rect.y = 0;
    rect.x = 0;

    // Main loop.
    while(running){
        while(SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                running = 0;
                break;
            case SDL_MOUSEWHEEL:
                if(event.wheel.y > 0){
                    if(zoom<6){
                        zoom++;
                    }
                }
                else if(event.wheel.y < 0){
                    if(zoom>1){
                        zoom--;
                    }
                }
                break;
            case SDL_MOUSEBUTTONUP:
                switch(event.button.button){
                case SDL_BUTTON_RIGHT:
                    right_clicking = 0;
                    break;
                default:
                    break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button){
                case SDL_BUTTON_RIGHT:
                    right_clicking = 1;
                    break;
                case SDL_BUTTON_LEFT:
                    SDL_GetMouseState(&mouse_x, &mouse_y); // Works only for zoom = 1! For development use!
                        printf("Mouse pos: x: %d y: %d\n", mouse_x-shift_x, mouse_y-shift_y);
                    break;
                default:
                    break;
                }
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                    running = 0;
                    break;
                default: // Without this case,the previous case was considered as default.
                    break;
                }
            }
        }

        // Logic.
        if(right_clicking){
            SDL_GetMouseState(&mouse_x, &mouse_y);
            shift_x = (shift_x + mouse_x - mouse_x_old);
            shift_y = (shift_y + mouse_y - mouse_y_old);

            SDL_GetMouseState(&mouse_x_old, &mouse_y_old);
        }
        else{
            SDL_GetMouseState(&mouse_x_old, &mouse_y_old);
        }

        rect.y = shift_y-(window_height*zoom-window_height)/2;
        rect.x = shift_x-(window_with*zoom-window_with)/2;
        rect.w = window_with * zoom;
        rect.h = window_height * zoom;

        // Rendering.
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Give rect a color.

        SDL_RenderDrawRect(renderer, &rect); // Draw.

        SDL_RenderCopy(renderer, texture_map, NULL, &rect); // 1st NULL can be replaced to say what part to copy, NULL says that copy all.

        SDL_RenderPresent(renderer); // Update window.
    }

    // Start exiting.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    // Free textures:
    SDL_FreeSurface(surface);

    SDL_DestroyTexture(texture_map);

    return 0;
}
