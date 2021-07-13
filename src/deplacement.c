/**
 * \file deplacement.c
 * \brief Programme dédié au déplacement
 * \author Gehin Sandy
 * \version 1.0
 * \date 12 juin 2021
 */

#include "main.h"


/**
 * \brief La fonction test si le vaisseau dépasse le bord gauche (0), si c'est le cas il le déplace de +1
 * \param sprite Le vaisseau
 */

/*void depassement_limite_gauche(sprite_t *sprite){
    
    if ((sprite->x - SHIP_WIDTH/2 + 10) < 0){
        sprite->x = sprite->x + 1;
    }
}



/**
 * \brief La fonction test si le vaisseau dépasse le bord gauche (300), si c'est le cas il le déplace de -1
 * \param sprite Le vaisseau
 */
/*
void depassement_limite_droite(sprite_t *sprite){

    if ((sprite->x + SHIP_WIDTH + 10) > 300){
        sprite->x = sprite->x - 1;
    }
}*/



/**
 * \brief La fonction test si il y à une colision entre le sprite 1 et le 2 (vaisseau,météorite ou ligne d'arrivé au choix.)
 * \param spr1 sprite numero 1
 * \param spr2 sprite numero 2
 */
/*
int sprites_collide(sprite_t *sp1, sprite_t *sp2){
    
    
    if((abs(sp1->x + sp1->w/2 - sp2->x - sp2->w/2) <= (sp1->w + sp2->w)/2) && abs(sp1->y + sp1->h/2 - sp2->y - sp2->h/2) <= (sp1->h + sp2->h)/2){
                return 1;
    }
    return 0;
}
*/


/**
 * \brief Test si il y à une colision, si c'est le cas la vitesse de déplacement devient 0.
 * \param world données du monde
 */
/*
int handle_events_collision(sprite_t *sp1, sprite_t *sp2, world_t *world){
    int make_disappear = 0;
    if (sprites_collide(sp1, sp2) == 1){
        world->vy = 0;
        make_disappear = 1;
    }
    return make_disappear;
}
*/


/**
 * \brief Appel la fonction de test de collision et renvoi 1 si il y a une collision.
 * \param world données du monde
 */
/*
int test_collision (world_t *world){
    world->sprite_collision = 0;
    for (int i = 0; i < 6; i++){
        if (handle_events_collision(&world->meteorite_walls[i], &world->spaceship,world) == 1){
            world->sprite_collision = 1;
            world->gameover=1;
        }
    }
    if (handle_events_collision(&world->spaceship, &world->finishLine, world) == 1){
        world->sprite_collision = 1;
        world->gameover=1;
    }
    
    return world->sprite_collision;
}
*/


/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */

void handle_events(SDL_Event *event,world_t *world){
    //Uint32 *keystates;
    ressources_t* ressources;
    SDL_Renderer *renderer;
    
    while(SDL_PollEvent(event)){
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
            world->gameover = 1;
        }
       
         //si une touche est appuyée
         if(event->type == SDL_KEYDOWN){
            //si la touche appuyée est 'D' 
            if(event->key.keysym.sym == SDLK_d || event->key.keysym.sym == SDLK_RIGHT){
                 printf("La touche D est appuyée\n");
                 world->spaceship.x = world->spaceship.x + MOVING_STEP;
              }
            //si la touche appuyée est 'Q'
            else if (event->key.keysym.sym == SDLK_q || event->key.keysym.sym ==SDLK_LEFT){
                printf("La touche Q est appuyée\n");
                world->spaceship.x = world->spaceship.x - MOVING_STEP;
            }
            //si la touche appuyée est 'Haut' ou 'Z'
            else if (event->key.keysym.sym == SDLK_z || event->key.keysym.sym ==SDLK_UP){
                printf("La touche Z est appuyée\n");
                world->spaceship.y = world->spaceship.y - MOVING_STEP;
            }
            //si la touche appuyée est 'Bas' ou 'S'
            else if (event->key.keysym.sym == SDLK_s || event->key.keysym.sym ==SDLK_DOWN){
                printf("La touche S est appuyée\n");
                world->spaceship.y = world->spaceship.y + MOVING_STEP;
            }
            //si la touche appuyée est 'Echap'
            else if (event->key.keysym.sym == SDLK_ESCAPE){
                printf("La touche ECHAP est appuyée\n");
                world->gameover = 1;
                SDL_Quit();
        
            }
         }
    }
}