#include "main.h"


void Init_Sprite(sprite_t *sprite, int x, int y, int w, int h){
    sprite->x = x;
    sprite->y = y;
    sprite->h = h;
    sprite->w = w;
}


void Init_Ammo(ressources_t* ressources, world_t* world){
    Init_Sprite(&world->ammo_left, world->spaceship.x - 18, world->spaceship.y - 9, AMMO_WIDTH, AMMO_HEIGHT);
    Init_Sprite(&world->ammo_right, world->spaceship.x + 18, world->spaceship.y - 9, AMMO_WIDTH, AMMO_HEIGHT);
}


void Init_Data(){
    ressources_t *ressources;
    world_t *world;

    world = malloc(sizeof(world_t));
    ressources = malloc(sizeof(ressources_t));

    world->gameover = 0;
    world->vy = 10;

    //Init_Ammo(ressources, world);
}


void Update_Data(ressources_t *ressources, world_t *world){
    depassement_limite_gauche(&world->spaceship);
    depassement_limite_droite(&world->spaceship);
    world->ammo_left.y = world->ammo_left.y - world->vy;
    world->ammo_right.y = world->ammo_right.y - world->vy;
}


void Menu(SDL_Event *event, world_t *world, ressources_t *ressources){
    Init_Texture_menu(ressources);
    Apply_Texture_Menu(ressources);
    while (world->nbr != 1){
        while( SDL_PollEvent( event ) ) {
            //Si une touche est appuyée
            if(event->type == SDL_KEYDOWN){
                //La touche HAUT est appuyée 
                if (event->key.keysym.sym == SDLK_UP){
                    world->selection = 1;
                    Apply_Start_Selection(ressources);
                }
                //La touche BAS est appuyée 
                else if (event->key.keysym.sym == SDLK_DOWN){
                    world->selection = 2;
                    Apply_Exit_Selection(ressources);
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