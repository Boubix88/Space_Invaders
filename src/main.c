#include "main.h"


int main(int argc, char* argv[])
{
    ressources_t ressources;
    sprite_t *sprite;
    world_t world;
    SDL_Event event;
    Init_Data();
    printf("Valeur : %d\n", world.gameover);
    SDL_Init(SDL_INIT_VIDEO);
    //Init_Texture(&ressources);
    //Menu(&event,&world,&ressources);
    Init_Screen(&ressources);
    Init_Spaceship(&ressources,sprite, &world);
    SDL_Delay(10);
    printf("Valeur 1: %d\n", world.gameover);
    while (world.gameover != 1){
        //handle_events(&event, &world);
        Update_Screen(&ressources, &world);
        //Update_Data(&ressources, &world);
        printf("Valeur : %d\n", world.gameover);
        SDL_Delay(10);
    }
    Free_Memory();
    
    SDL_Quit();
    return EXIT_SUCCESS;
}

//gcc src/world.c src/graphics.c src/deplacement.c src/main.c -o bin/test -I include -L lib -lmingw32 -lSDL2main -lSDL2