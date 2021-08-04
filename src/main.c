#include "main.h"


int main(int argc, char* argv[])
{
    ressources_t *ressources;
    sprite_t *sprite;
    world_t world;
    SDL_Event event;
    SDL_Renderer *renderer;
    world.gameover = 0;
    Init_Data();

    SDL_Init(SDL_INIT_VIDEO);
    Init_Screen(&ressources);
    Init_Spaceship(&ressources,&sprite, &world);

    while (world.gameover != 1){
        handle_events(&event, &world);
        Update_Screen(ressources, &world);
        SDL_Delay(10);
    }
    Free_Memory();
    
    SDL_Quit();
    return EXIT_SUCCESS;
}

//gcc src/graphics.c src/deplacement.c src/main.c -o bin/test -I include -L lib -lmingw32 -lSDL2main -lSDL2