#include "common.h"

extern void cleanup(void);
extern void initSDL(void);
extern SDL_Texture *loadTexture(char *filename);
extern void prepareScene(void);
extern void presentScene(void);
extern void doInput(void);
extern void blit(SDL_Texture *texture, int x, int y);
extern void renderText(const char* text, int x, int y, TTF_Font* Sans);
extern void renderText2(const char* text, int x, int y, TTF_Font* Sans);

extern int continueButton(int set);

extern void initPlayers(Players player[], Resources resource[]);
extern void initBuildings(Buildings building[], int set);

extern void setupRound(int whoplays ,TTF_Font* Sans1, TTF_Font* Sans3);
extern void firstDistribution(Players player[], Tiles tile[], Buildings building[]);

extern void initMap(Tiles tile[19],  int mapChange);
extern void privatePanel(Players player[], Resources resource[], TTF_Font* Sans3, TTF_Font* Sans4);
extern void roll();
extern void distribution(Players player[], Tiles tile[], Buildings building[], int sum);
extern void trade(TTF_Font* Sans3);
extern void build(TTF_Font* Sans3);
extern void next();
extern void VPRefresh(Players player[], Buildings building[]);

App app;
Tiles tile[37];
Entity  select_circle[1],
        temp_location;
Buildings building[50];
Players player[2];
Resources resource[5];
Return_Values var[2];
