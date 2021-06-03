typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
} App;

typedef struct {
	int x;
	int y;
	SDL_Texture *texture;
} Entity;

typedef struct {
	int ID_tile;
	int display_x;
	int display_y;
	int logic_x;
	int logic_y;
	SDL_Texture *texture;
	int resource_type;
	int dice_number;
} Tiles;

typedef struct {
	int ID_building; // player 1=0-9 (0-5 colonies, 6-9 cities) player 2=10-19
									// later, the 15 roads will be se from 10-24 P1, and etc..
	int display_x;
	int display_y;
	int logic_x;
	int logic_y;
	SDL_Texture *texture;
	int exist;
} Buildings;

typedef struct {
	int ID_location; // player 1=0-9 (0-5 colonies, 6-9 cities) player 2=10-19
									// later, the 15 roads will be se from 10-24 P1, and etc..
	int display_x;
	int display_y;
	int logic_x;
	int logic_y;
	SDL_Texture *texture;
	int exist;
} Locations;

typedef struct {
	int dice_number;
	int x;
	int y;
	SDL_Texture *texture;
} Numbers;

typedef struct {
	SDL_Texture *texture;
} Resources;

typedef struct {
	int ID_player;
	const char* name;
	int resources[6];
} Players;

typedef struct {
	int state;
	int value;
	int who;
}Return_Values;
