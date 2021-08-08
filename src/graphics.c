/**
 * \file graphics.c
 * \brief Programme qui gère la partie graphique
 * \author Gehin Sandy
 * \version 1.0
 * \date 12 juin 2021
 */

#include "main.h"


void Init_Sprite(sprite_t *sprite, int x, int y, int w, int h){
    sprite->x = x;
    sprite->y = y;
    sprite->h = h;
    sprite->w = w;
}


void Init_Screen(ressources_t *ressources){

    ressources->window = SDL_CreateWindow("Space Invaders",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,518, 920,SDL_WINDOW_SHOWN);
    ressources->icon = SDL_LoadBMP("../ressources/space_invaders_logo.bmp");
    SDL_SetWindowIcon(ressources->window, ressources->icon);
    ressources->renderer = SDL_CreateRenderer(ressources->window, -1, 0);


    SDL_Surface *backgroundIMG=  SDL_LoadBMP("../ressources/space_light.bmp");
    ressources->background = SDL_CreateTextureFromSurface(ressources->renderer, backgroundIMG);

    if (backgroundIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
}


void Init_Spaceship(ressources_t *ressources, sprite_t *sprite, world_t *world){

    ressources->spaceshipIMG = SDL_LoadBMP("../ressources/spaceship.bmp");
    if (ressources->spaceshipIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    ressources->spaceship = SDL_CreateTextureFromSurface(ressources->renderer, ressources->spaceshipIMG);
    Init_Sprite(&world->spaceship, SCREEN_WIDTH/2 - 25, SCREEN_HEIGHT - 100, 50, 72);

    Apply_Screen(ressources, world);
}


void apply_sprite(SDL_Renderer *renderer, ressources_t *ressources, world_t *world){
    ressources->backgroundIMG=  SDL_LoadBMP("../ressources/space_light.bmp");
    ressources->background = SDL_CreateTextureFromSurface(ressources->renderer, ressources->backgroundIMG);

    ressources->spaceshipIMG = SDL_LoadBMP("../ressources/spaceship.bmp");
    ressources->spaceship = SDL_CreateTextureFromSurface(ressources->renderer, ressources->spaceshipIMG);
}


void Apply_Screen (ressources_t *ressources, world_t *world){
    SDL_Rect dst = {world->spaceship.x, world->spaceship.y, world->spaceship.w, world->spaceship.h};
    SDL_RenderClear(ressources->renderer);
    SDL_RenderCopy(ressources->renderer, ressources->background, NULL, NULL);
    SDL_RenderCopy(ressources->renderer, ressources->spaceship, NULL, &dst);
    SDL_RenderPresent(ressources->renderer);
}


void Update_Screen(ressources_t* ressources, world_t *world){
    //SDL_FreeSurface(ressources->spaceshipIMG);
    /*SDL_DestroyTexture(ressources->spaceship);
    SDL_DestroyRenderer(ressources->renderer);*/

    SDL_Rect dst = {world->spaceship.x + 100, world->spaceship.y, world->spaceship.w, world->spaceship.h};

    //ressources->spaceshipIMG = SDL_LoadBMP("../ressources/spaceship.bmp");
    //ressources->spaceship = SDL_CreateTextureFromSurface(ressources->renderer, ressources->spaceshipIMG);
    SDL_RenderClear(ressources->renderer);
    SDL_RenderCopy(ressources->renderer, ressources->spaceship, NULL, &dst);
    SDL_RenderPresent(ressources->renderer);
    printf("Update\n");
}


void Free_Texture(ressources_t *ressources, world_t *world){
    SDL_DestroyTexture(ressources->background);
    SDL_FreeSurface(ressources->backgroundIMG);
    SDL_DestroyTexture(ressources->spaceship);
    SDL_FreeSurface(ressources->spaceshipIMG);
    SDL_DestroyRenderer(ressources->renderer);
}


void Free_Memory(){

    ressources_t *ressources;
    world_t *world;
    SDL_FreeSurface(ressources->icon);
    SDL_DestroyWindow(ressources->window);
    Free_Texture(ressources, world);
    free(ressources);
    free(world);
}