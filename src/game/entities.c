

#include "common.h"
#include "defs.h"
#include "draw.h"
#include "structs.h"
#include "util.h"
#include "entities.h"

//layer 0 = bg deepest = green
//layer 1 = bg          1 less deep
//layer 2 = bg          2 less deep
//layer 3 = gameplay    3 less deep = platforms and player
//layer 4 = fg          4 less deep
//layer 5 = UI          5 less deep
//inline Entity layers[NUM_LAYERS];
//inline Sprite layer_spr[NUM_LAYERS];

inline void init_layers(void);
inline void init_environment_entity(Vec2i POS, SDL_Rect SRC, Layers LAYER, Entity_Type ENT_TYPE);
inline void init_platforms(void);
inline void init_traps(void);

void init_entities(void)
{
    //Layer BG 0
    init_environment_entity(
            (Vec2i){ get_scr_width_scaled() / 2, get_scr_height_scaled() / 2 },
            (SDL_Rect){ 480, 0, 60, 320}, 
            BG_0, ENVIRONMENT);
    init_environment_entity(
            (Vec2i){ get_scr_width_scaled() / 2, (get_scr_height_scaled() / 2) - (320 * SCREEN_SCALE) },
            (SDL_Rect){ 480, 0, 60, 320}, 
            BG_0, ENVIRONMENT);

    //Layer BG 1
    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) - (45 * SCREEN_SCALE), get_scr_height_scaled() / 2 },
            (SDL_Rect){ 208, 0, 80, 320}, 
            BG_1, ENVIRONMENT);
    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) + (55 * SCREEN_SCALE), get_scr_height_scaled() / 2 },
            (SDL_Rect){ 304, 0, 96, 320}, 
            BG_1, ENVIRONMENT);
    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) - (45 * SCREEN_SCALE), (get_scr_height_scaled() / 2) - (320 * SCREEN_SCALE) },
            (SDL_Rect){ 208, 0, 80, 320}, 
            BG_1, ENVIRONMENT);
    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) + (55 * SCREEN_SCALE), (get_scr_height_scaled() / 2) - (320 * SCREEN_SCALE) },
            (SDL_Rect){ 304, 0, 96, 320}, 
            BG_1, ENVIRONMENT);

    //Layer BG 2
    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) - (65 * SCREEN_SCALE), get_scr_height_scaled() / 2 },
            (SDL_Rect){ 80, 0, 58, 320}, 
            BG_2, ENVIRONMENT);
    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) + (65 * SCREEN_SCALE), get_scr_height_scaled() / 2 },
            (SDL_Rect){ 146, 0, 62, 320}, 
            BG_2, ENVIRONMENT);
    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) - (65 * SCREEN_SCALE), (get_scr_height_scaled() / 2) - (320 * SCREEN_SCALE) },
            (SDL_Rect){ 80, 0, 58, 320}, 
            BG_2, ENVIRONMENT);
    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) + (65 * SCREEN_SCALE), (get_scr_height_scaled() / 2) - (320 * SCREEN_SCALE) },
            (SDL_Rect){ 146, 0, 62, 320}, 
            BG_2, ENVIRONMENT);

    //Layer GAMEPLAY
    init_platforms();
    init_traps();

    //Layer FG
    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) - (75 * SCREEN_SCALE), get_scr_height_scaled() / 2 },
            (SDL_Rect){ 16, 0, 32, 320}, 
            FG, ENVIRONMENT);
    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) + (75 * SCREEN_SCALE), get_scr_height_scaled() / 2 },
            (SDL_Rect){ 48, 0, 32, 320}, 
            FG, ENVIRONMENT);
    init_environment_entity(
            (Vec2i){ 35 * SCREEN_SCALE, get_scr_height_scaled() / 2 },
            (SDL_Rect){ 400, 0, 80, 320}, 
            FG, ENVIRONMENT);
    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) + (130 * SCREEN_SCALE), get_scr_height_scaled() / 2 },
            (SDL_Rect){ 400, 0, 80, 320}, 
            FG, ENVIRONMENT);

    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) - (75 * SCREEN_SCALE), (get_scr_height_scaled() / 2) - (320 * SCREEN_SCALE) },
            (SDL_Rect){ 16, 0, 32, 320}, 
            FG, ENVIRONMENT);
    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) + (75 * SCREEN_SCALE), (get_scr_height_scaled() / 2) - (320 * SCREEN_SCALE)  },
            (SDL_Rect){ 48, 0, 32, 320}, 
            FG, ENVIRONMENT);
    init_environment_entity(
            (Vec2i){ 35 * SCREEN_SCALE, (get_scr_height_scaled() / 2) - (320 * SCREEN_SCALE)  },
            (SDL_Rect){ 400, 0, 80, 320}, 
            FG, ENVIRONMENT);
    init_environment_entity(
            (Vec2i){ (get_scr_width_scaled() / 2) + (130 * SCREEN_SCALE), (get_scr_height_scaled() / 2) - (320 * SCREEN_SCALE) },
            (SDL_Rect){ 400, 0, 80, 320}, 
            FG, ENVIRONMENT);
}

inline void init_platforms(void)
{
        init_environment_entity(
                (Vec2i){ (get_scr_width_scaled() / 2) - (85 * SCREEN_SCALE), get_scr_height_scaled() / 2 },
                (SDL_Rect){ 544, 0, 48, 320}, 
                GAMEPLAY, PLATFORM);

        init_environment_entity(
                (Vec2i){ (get_scr_width_scaled() / 2) + (85 * SCREEN_SCALE), get_scr_height_scaled() / 2 },
                (SDL_Rect){ 544, 0, 48, 320}, 
                GAMEPLAY, PLATFORM);

        /*
        init_environment_entity(
                (Vec2i){ (get_scr_width_scaled() / 2) - (85 * SCREEN_SCALE), 140 * SCREEN_SCALE},
                (SDL_Rect){ 544, 0, 48, 80}, 
                GAMEPLAY, PLATFORM);

        init_environment_entity(
                (Vec2i){ (get_scr_width_scaled() / 2) + (85 * SCREEN_SCALE), 220 * SCREEN_SCALE},
                (SDL_Rect){ 544, 0, 48, 80}, 
                GAMEPLAY, PLATFORM);

        init_environment_entity(
                (Vec2i){ (get_scr_width_scaled() / 2) - (85 * SCREEN_SCALE), 260 * SCREEN_SCALE},
                (SDL_Rect){ 544, 0, 48, 80}, 
                GAMEPLAY, PLATFORM);

        init_environment_entity(
                (Vec2i){ (get_scr_width_scaled() / 2) + (85 * SCREEN_SCALE), 330 * SCREEN_SCALE},
                (SDL_Rect){ 544, 0, 48, 80}, 
                GAMEPLAY, PLATFORM);
        */
}

inline void init_traps(void)
{
        init_environment_entity(
                (Vec2i){ (get_scr_width_scaled() / 2) - (85 * SCREEN_SCALE), 43 * SCREEN_SCALE },
                (SDL_Rect){ 0, 0, 90, 120 }, 
                GAMEPLAY, TRAP);

        init_environment_entity(
                (Vec2i){ (get_scr_width_scaled() / 2) - (85 * SCREEN_SCALE), 183 * SCREEN_SCALE },
                (SDL_Rect){ 0, 0, 90, 80 }, 
                GAMEPLAY, TRAP);

        init_environment_entity(
                (Vec2i){ (get_scr_width_scaled() / 2) - (85 * SCREEN_SCALE), 305 * SCREEN_SCALE },
                (SDL_Rect){ 0, 0, 90, 80 }, 
                GAMEPLAY, TRAP);

        init_environment_entity(
                (Vec2i){ (get_scr_width_scaled() / 2) + (55 * SCREEN_SCALE), 0},
                (SDL_Rect){ 0, 0, 100, 90 }, 
                GAMEPLAY, TRAP);
        init_environment_entity(
                (Vec2i){ (get_scr_width_scaled() / 2) + (55 * SCREEN_SCALE), 130 * SCREEN_SCALE },
                (SDL_Rect){ 0, 0, 100, 120 }, 
                GAMEPLAY, TRAP);
        init_environment_entity(
                (Vec2i){ (get_scr_width_scaled() / 2) + (55 * SCREEN_SCALE), 265 * SCREEN_SCALE },
                (SDL_Rect){ 0, 0, 100, 50 }, 
                GAMEPLAY, TRAP);
}

inline void init_environment_entity(Vec2i POS, SDL_Rect SRC, Layers LAYER, Entity_Type ENT_TYPE)
{
    Entity e;
    Sprite* s = (Sprite*)malloc(sizeof(Sprite));

    e.active = 1;
    e.dx = 0;
    e.dy = 0;

    s->active = 1;

    e.x = POS.x;
    e.y = POS.y;

    s->src = SRC;

    e.layer = LAYER;
    e.ent_type = ENT_TYPE;

    s->dest.x = e.x;
    s->dest.y = e.y;
    s->dest.w = s->src.w;
    s->dest.h = s->src.h;

    e.sprite = s;

    e.hitbox = e.sprite->dest;

    stage.entity_count++;
    stage.entities_pool[stage.entity_count] = e;
}
        
void update_entities(void)
{
    int i = 0;
    Entity* e = NULL; 
    SDL_Rect p_rect = stage.entities_pool[0].sprite->dest;
    p_rect.w *= SCREEN_SCALE;
    p_rect.h *= SCREEN_SCALE;
    for(i = 0; i <= stage.entity_count; i++)
    {
        e = &stage.entities_pool[i];
        if(e->ent_type == PLAYER)
            continue;
        
        if(e->layer == BG_0)
            e->dy = 1;
        else if(e->layer == BG_1)
            e->dy = 2;
        else if (e->layer == BG_2)
            e->dy = 3;
        //else if (e->layer == GAMEPLAY)
            //e->dy = 3;
        else if (e->layer == FG)
            e->dy = 4;
        
        if(e->ent_type == TRAP)
        {
            e->dy = 3;
            SDL_Rect t_rect = e->sprite->dest;
            if(SDL_HasIntersection(&p_rect, &t_rect))
            {
                SDL_Log("COLLIDE");
                stage.entities_pool[0].active = 0;
                player.active = 0;
            }
        }

        e->x += e->dx;
        e->y += e->dy;
        e->sprite->dest.x = e->x;
        e->sprite->dest.y = e->y;
     
        {//Env entity wrapping
            //if(e->layer != GAMEPLAY)
            if(e->ent_type != PLAYER)
            {
                if(e->y > get_scr_height_scaled() + ((e->sprite->dest.h / 2) * SCREEN_SCALE))
                {
                    if(e->ent_type == ENVIRONMENT)
                    {
                        e->y = -(((e->sprite->dest.h / 2) * SCREEN_SCALE) - 30);
                    }
                    else if(e->ent_type == PLATFORM)
                    {
                        e->y = -((e->sprite->dest.h / 2) * SCREEN_SCALE);
                    }
                    else if(e->ent_type == TRAP)
                    {
                        e->y = -(e->sprite->dest.h) * SCREEN_SCALE;
                    }
                }
            }
        }
    }
}

void draw_entities(void)
{
    Entity* e;
    int i = 0;
    for(i = 0; i <= stage.entity_count; i++)
    {
        e = &stage.entities_pool[i];

        if(e->ent_type == TRAP)
        {
            SDL_SetRenderDrawColor(game.renderer, 235, 162, 84, 255);
            //SDL_RenderDrawRect(game.renderer, &e->sprite->dest);
            SDL_RenderFillRect(game.renderer, &e->sprite->dest);
        } 
        else 
        {
            blit_from_sheet(game.spritesheet, e->sprite->dest, e->sprite->src, 0, SCREEN_SCALE, 1); 
        }
    }
}

void reset_entities(void)
{
    stage.entity_count = 0;

    init_entities();
}
