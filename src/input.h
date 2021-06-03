#include "common.h"

#include "SDL2/SDL_image.h"

extern SDL_Texture *loadTexture(char *filename);
extern void blit(SDL_Texture *texture, int x, int y);
extern void renderText(const char* text, int x, int y, TTF_Font* Sans);
extern void renderText2(const char* text, int x, int y, TTF_Font* Sans);
extern int SDL_ShowSimpleMessageBox(Uint32      flags,
                             const char* title,
                             const char* message,
                             SDL_Window* window);
extern App app;

Entity  continue_button,
        next_button,
        roll_button,
        select_circle[1],
        building_menu,
        square,
        return_button,
        temp_location,
        confirm_button;
Numbers dice[2];
Players player[3];
Tiles tile[37];
Resources resource[5];
Buildings building[50];
Return_Values var[2];
