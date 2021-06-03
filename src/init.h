#include "common.h"

#include "SDL2/SDL_image.h"

extern SDL_Texture *loadTexture(char *filename);
extern void blit(SDL_Texture *texture, int x, int y);

extern int fromPixelToLogicX(int logic_x);
extern int fromPixelToLogicY(int logic_y);
extern int fromLogicToPixelX(int display_x);
extern int fromLogicToPixelY(int display_y);

extern App app;

Entity  building_menu,
        square,
        return_button,
        confirm_button;
Tiles tile[37];
Entity number[19];
Numbers dice[2];
Players player[2];
Resources resource[5];
Buildings building[50];
