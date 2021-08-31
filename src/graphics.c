/**
 * \file graphics.c
 * \brief Programme qui gère la partie graphique
 * \author Gehin Sandy
 * \version 1.0
 * \date 12 juin 2021
 */

#include "main.h"


void Init_Screen(ressources_t *ressources){
    ressources->window = SDL_CreateWindow("Space Invaders",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,518, 920,SDL_WINDOW_SHOWN);
    ressources->icon = SDL_LoadBMP("../ressources/space_invaders_logo.bmp");
    SDL_SetWindowIcon(ressources->window, ressources->icon);
    ressources->renderer = SDL_CreateRenderer(ressources->window, -1, 0);
}


void Init_Background(ressources_t *ressources){
    ressources->backgroundIMG=  SDL_LoadBMP("../ressources/space_light.bmp");
    ressources->background = SDL_CreateTextureFromSurface(ressources->renderer, ressources->backgroundIMG);

    if (ressources->backgroundIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    SDL_FreeSurface(ressources->backgroundIMG);
}


void Init_Spaceship(ressources_t *ressources, sprite_t *sprite, world_t *world){

    Init_Sprite(&world->spaceship, SCREEN_WIDTH/2 - 25, SCREEN_HEIGHT - 100, 50, 72);

    Apply_Screen(ressources, world);
    SDL_FreeSurface(ressources->spaceshipIMG);
}


void Init_Texture(ressources_t *ressources){
    ressources->start_buttonIMG=  SDL_LoadBMP("../ressources/start_button.bmp");
    if (ressources->start_buttonIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    ressources->start_button = SDL_CreateTextureFromSurface(ressources->renderer, ressources->start_buttonIMG);

    ressources->exit_buttonIMG=  SDL_LoadBMP("../ressources/exit_button.bmp");
    if (ressources->exit_buttonIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    ressources->exit_button = SDL_CreateTextureFromSurface(ressources->renderer, ressources->exit_buttonIMG);

    ressources->backgroundIMG=  SDL_LoadBMP("../ressources/space_light.bmp");
    if (ressources->backgroundIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    ressources->background = SDL_CreateTextureFromSurface(ressources->renderer, ressources->backgroundIMG);

    ressources->spaceshipIMG = SDL_LoadBMP("../ressources/spaceship.bmp");
    if (ressources->spaceshipIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    ressources->spaceship = SDL_CreateTextureFromSurface(ressources->renderer, ressources->spaceshipIMG);

    ressources->ammo_leftIMG = SDL_LoadBMP("../ressources/ammo.bmp");
    if (ressources->ammo_leftIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    ressources->ammo_left = SDL_CreateTextureFromSurface(ressources->renderer, ressources->ammo_leftIMG);

    ressources->ammo_rightIMG = SDL_LoadBMP("../ressources/ammo.bmp");
    if (ressources->ammo_rightIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    ressources->ammo_right = SDL_CreateTextureFromSurface(ressources->renderer, ressources->ammo_leftIMG);
}


void Init_Texture_menu(ressources_t* ressources){
    ressources->backgroundIMG=  SDL_LoadBMP("../ressources/space_light.bmp");
    if (ressources->backgroundIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    ressources->background = SDL_CreateTextureFromSurface(ressources->renderer, ressources->backgroundIMG);

    ressources->start_buttonIMG=  SDL_LoadBMP("../ressources/start_button.bmp");
    if (ressources->start_buttonIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    ressources->start_button = SDL_CreateTextureFromSurface(ressources->renderer, ressources->start_buttonIMG);

    ressources->exit_buttonIMG=  SDL_LoadBMP("../ressources/exit_button.bmp");
    if (ressources->exit_buttonIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    ressources->exit_button = SDL_CreateTextureFromSurface(ressources->renderer, ressources->exit_buttonIMG);

    ressources->start_button_selectionIMG=  SDL_LoadBMP("../ressources/start_button_selection.bmp");
    if (ressources->start_button_selectionIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    ressources->start_button_selection = SDL_CreateTextureFromSurface(ressources->renderer, ressources->start_button_selectionIMG);

    ressources->exit_button_selectionIMG=  SDL_LoadBMP("../ressources/exit_button_selection.bmp");
    if (ressources->exit_button_selectionIMG == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    ressources->exit_button_selection = SDL_CreateTextureFromSurface(ressources->renderer, ressources->exit_button_selectionIMG);
}


void Apply_Screen (ressources_t *ressources, world_t *world){
    SDL_Rect dst = {world->spaceship.x, world->spaceship.y, world->spaceship.w, world->spaceship.h};
    SDL_RenderClear(ressources->renderer);
    SDL_RenderCopy(ressources->renderer, ressources->background, NULL, NULL);
    SDL_RenderCopy(ressources->renderer, ressources->spaceship, NULL, &dst);
    SDL_RenderPresent(ressources->renderer);
}


void Apply_Ammo(ressources_t *ressources, world_t *world){
    SDL_Rect dst_left = {world->ammo_left.x, world->ammo_left.y, AMMO_WIDTH, AMMO_HEIGHT};
    SDL_Rect dst_right = {world->ammo_right.x, world->ammo_right.y, AMMO_WIDTH, AMMO_HEIGHT};
    SDL_RenderClear(ressources->renderer);
    SDL_RenderCopy(ressources->renderer, ressources->ammo_left, NULL, &dst_left);
    SDL_RenderCopy(ressources->renderer, ressources->ammo_right, NULL, &dst_right);
    SDL_RenderPresent(ressources->renderer);
}


void Apply_Texture_Menu(ressources_t *ressources){
    SDL_Rect dst_start = {109, 300, 300, 143};
    SDL_Rect dst_exit = {109, 450, 300, 143};
    SDL_RenderClear(ressources->renderer);
    SDL_RenderCopy(ressources->renderer, ressources->background, NULL, NULL);
    SDL_RenderCopy(ressources->renderer, ressources->start_button, NULL, &dst_start);
    SDL_RenderCopy(ressources->renderer, ressources->exit_button, NULL, &dst_exit);
    SDL_RenderPresent(ressources->renderer);
}


void Apply_Start_Selection(ressources_t *ressources){
    SDL_Rect dst_start = {109, 300, 300, 143};
    SDL_Rect dst_exit = {109, 450, 300, 143};
    SDL_RenderClear(ressources->renderer);
    SDL_RenderCopy(ressources->renderer, ressources->background, NULL, NULL);
    SDL_RenderCopy(ressources->renderer, ressources->start_button_selection, NULL, &dst_start);
    SDL_RenderCopy(ressources->renderer, ressources->exit_button, NULL, &dst_exit);
    SDL_RenderPresent(ressources->renderer);
}


void Apply_Exit_Selection(ressources_t *ressources){
    SDL_Rect dst_start = {109, 300, 300, 143};
    SDL_Rect dst_exit = {109, 450, 300, 143};
    SDL_RenderClear(ressources->renderer);
    SDL_RenderCopy(ressources->renderer, ressources->background, NULL, NULL);
    SDL_RenderCopy(ressources->renderer, ressources->start_button, NULL, &dst_start);
    SDL_RenderCopy(ressources->renderer, ressources->exit_button_selection, NULL, &dst_exit);
    SDL_RenderPresent(ressources->renderer);
}


void Update_Screen(ressources_t *ressources, world_t *world){
    SDL_Rect dst = {world->spaceship.x, world->spaceship.y, world->spaceship.w, world->spaceship.h};
    SDL_RenderClear(ressources->renderer);
    SDL_RenderCopy(ressources->renderer, ressources->background, NULL, NULL);
    SDL_RenderCopy(ressources->renderer, ressources->spaceship, NULL, &dst);
    SDL_RenderPresent(ressources->renderer);
}


void Free_Texture(ressources_t *ressources, world_t *world){
    SDL_DestroyTexture(ressources->background);
    SDL_FreeSurface(ressources->backgroundIMG);
    SDL_DestroyTexture(ressources->spaceship);
    SDL_FreeSurface(ressources->spaceshipIMG);
    SDL_DestroyRenderer(ressources->renderer);
    SDL_FreeSurface(ressources->backgroundIMG);
    SDL_FreeSurface(ressources->start_buttonIMG);
    SDL_FreeSurface(ressources->exit_buttonIMG);
    SDL_FreeSurface(ressources->start_button_selectionIMG);
    SDL_FreeSurface(ressources->start_button_selectionIMG);
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