#include "main.h"


int main(int argc, char* argv[])
{
    ressources_t ressources;
    sprite_t *sprite;
    world_t world;
    SDL_Event event;

    Init_Data();
    Init_Screen(&ressources);
    SDL_Init(SDL_INIT_VIDEO);
    Init_Texture(&ressources);
    Menu(&event,&world,&ressources);
    Init_Spaceship(&ressources,sprite, &world);
    SDL_Delay(10);
    printf("Valeur : %d\n", world.gameover);

    while (world.gameover != 1){
        handle_events(&event, &world);
        Init_Ammo(&ressources, &world);
        Update_Screen(&ressources, &world);
        Update_Data(&ressources, &world);
        printf("Valeur : %d\n", world.gameover);
        printf("Ammo x : %d\n", world.ammo_left.x);
        SDL_Delay(10);
    }
    Free_Memory();
    
    SDL_Quit();
    return EXIT_SUCCESS;
}

//gcc -Wall src/world.c src/graphics.c src/deplacement.c src/main.c -o bin/test -I include -L lib -lmingw32 -lSDL2main -lSDL2
//gcc src/world.c src/graphics.c src/deplacement.c src/main.c -o bin/test -I include -L lib -lmingw32 -lSDL2main -lSDL2