#include"functions.c"

/*
SDL credits in SDL_IMPORTANT_NOTES > CREDITS
(SDL is amazing! Many thanks to the developers of SDL!)

Compile command:
gcc -Isrc/Include -Lsrc/lib -o run main.c -lmingw32 -lSDL2main -lSDL2

*/

int main(int argc, char* args[])
{
    int running = 1;
    int window_height = 640;
    int window_with = 480;

    // Set up SDL.
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;

    SDL_Surface *surface;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(window_with, window_height, 0, &window, &renderer);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // Enables alpha blending.

    // SDL_SetWindowResizable(window, SDL_TRUE);

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
        
    }

    // Start exiting.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
