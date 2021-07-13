#include "main.h"


int main(int argc, char* argv[])
{
    ressources_t *ressources;
    sprite_t *sprite;
    world_t *world;
    SDL_Event *event;
    SDL_Renderer *renderer;

    Init_Data();

    SDL_Init(SDL_INIT_VIDEO);
    Init_Screen(&ressources);
    Init_Spaceship(&ressources,&sprite, &world);

    printf("Valeur : %d\n",world->gameover);
   
    while (!is_game_over(world)){
        printf("Valeur 2 : %d\n", world->gameover);
        handle_events(event, world);
        //Update_Screen(ressources, world);
        SDL_Delay(10);
    }
    printf("Valeur 3 : %d", world->gameover);
    Free_Memory();
    
    SDL_Quit();
    return EXIT_SUCCESS;
}

//gcc src/graphics.c src/deplacement.c src/main.cpp -o bin/test -I include -L lib -lmingw32 -lSDL2main -lSDL2