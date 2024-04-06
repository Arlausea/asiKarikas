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
    int window_height = 480;
    int window_with = 640;

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
    surface = SDL_LoadBMP("textures\\test_map.bmp");
    SDL_Texture* texture_map = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect;
    rect.w = window_with;
    rect.h = window_height;
    rect.y = 0;
    rect.x = 0;

    // Main loop.
    while(running){
        int start_loop = SDL_GetTicks();

        while(SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                running = 0;
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

        // Rendering.
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Give rect a color.
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // Draw.
        SDL_RenderDrawRect(renderer, &rect);

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
