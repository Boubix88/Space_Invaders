#include "main.h"


void Init_Sprite(sprite_t *sprite, int x, int y, int w, int h){
    sprite->x = x;
    sprite->y = y;
    sprite->h = h;
    sprite->w = w;
}


void Update_Data(ressources_t *ressources, world_t *world){
    depassement_limite_gauche(&world->spaceship);
    depassement_limite_droite(&world->spaceship);
}


void Menu(SDL_Event *event, world_t *world, ressources_t *ressources){
    Uint8 *keystates;
    Apply_Texture_Menu(ressources);
    while (world->nbr != 1){
        while( SDL_PollEvent( event ) ) {
            //Si une touche est appuyée
            if(event->type == SDL_KEYDOWN){
                //La touche HAUT est appuyée 
                if (event->key.keysym.sym == SDLK_UP){
                    world->selection = 1;
                }
                //La touche BAS est appuyée 
                else if (event->key.keysym.sym == SDLK_DOWN){
                    world->selection = 2;
                }
                //La touche entrée est appuyée et selection est à 2
                else if (event->key.keysym.sym == SDLK_RETURN && world->selection == 2){
                    world->gameover = 1;
                    world->nbr = 1;
                }
                //La touche entrée est appuyée et selection est à 1
                else if (event->key.keysym.sym == SDLK_RETURN && world->selection == 1){
                    world->nbr = 1;
                }
                //La touche echap est appuyée
                else if (event->key.keysym.sym == SDLK_ESCAPE){
                    world->gameover = 1;
                    world->nbr = 1;
                    world->selection = 2;
                }
            }
            else if( event->type == SDL_QUIT ) {
                    //On indique la fin du jeu si on clique sur la croix
                    world->gameover = 1;
                    world->nbr = 1;
                    world->selection = 2;
            }
        }   
    }
}