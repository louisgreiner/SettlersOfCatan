#include "init.h"

void initSDL(void)
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app.window = SDL_CreateWindow("The Settlers of Catan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}

void initPlayers(Players player[], Resources resource[])
{
	player[0].ID_player=0;
	player[0].name="bank";
	player[0].resources[0]=11;
	player[0].resources[1]=15;
	player[0].resources[2]=19;
	player[0].resources[3]=15;
	player[0].resources[4]=11;
	player[0].resources[5]=0;

	player[1].ID_player=1;
	player[1].name="Red";
	player[1].resources[0]=40;
	player[1].resources[1]=20;
	player[1].resources[2]=10;
	player[1].resources[3]=12;
	player[1].resources[4]=14;
	player[1].resources[5]=10;

	player[2].ID_player=2;
	player[2].name="Blue";
	player[2].resources[0]=4;
	player[2].resources[1]=2;
	player[2].resources[2]=0;
	player[2].resources[3]=2;
	player[2].resources[4]=4;
	player[2].resources[5]=0;

	resource[0].texture=loadTexture("gfx/sprites/number_1.png");
	resource[1].texture=loadTexture("gfx/sprites/number_2.png");
	resource[2].texture=loadTexture("gfx/sprites/number_3.png");
	resource[3].texture=loadTexture("gfx/sprites/number_4.png");
	resource[4].texture=loadTexture("gfx/sprites/number_5.png");
	resource[5].texture=loadTexture("gfx/sprites/number_7.png");
}

void initMap(Tiles tile[],int mapChange)
{
	int temp;
	if(mapChange)
	{
		tile[0].logic_x=0; 		tile[0].logic_y=0;
		tile[1].logic_x=4; 		tile[1].logic_y=0;
		tile[2].logic_x=2; 		tile[2].logic_y=6;
		tile[3].logic_x=-2; 	tile[3].logic_y=6;
		tile[4].logic_x=-4; 	tile[4].logic_y=0;
		tile[5].logic_x=-2; 	tile[5].logic_y=-6;
		tile[6].logic_x=2; 		tile[6].logic_y=-6;
		tile[7].logic_x=6; 		tile[7].logic_y=-6;
		tile[8].logic_x=8; 		tile[8].logic_y=0;
		tile[9].logic_x=6; 		tile[9].logic_y=6;
		tile[10].logic_x=4; 	tile[10].logic_y=12;
		tile[11].logic_x=0; 	tile[11].logic_y=12;
		tile[12].logic_x=-4; 	tile[12].logic_y=12;
		tile[13].logic_x=-6; 	tile[13].logic_y=6;
		tile[14].logic_x=-8; 	tile[14].logic_y=0;
		tile[15].logic_x=-6;	tile[15].logic_y=-6;
		tile[16].logic_x=-4; 	tile[16].logic_y=-12;
		tile[17].logic_x=0;	tile[17].logic_y=-12;
		tile[18].logic_x=4; 	tile[18].logic_y=-12;
		tile[19].logic_x=8; 	tile[19].logic_y=-12;
		tile[20].logic_x=10; 	tile[20].logic_y=-6;
		tile[21].logic_x=12; 	tile[21].logic_y=0;
		tile[22].logic_x=10; 	tile[22].logic_y=6;
		tile[23].logic_x=8; 	tile[23].logic_y=12;
		tile[24].logic_x=6;		tile[24].logic_y=18;
		tile[25].logic_x=2; 	tile[25].logic_y=18;
		tile[26].logic_x=-2;	tile[26].logic_y=18;
		tile[27].logic_x=-6; 	tile[27].logic_y=18;
		tile[28].logic_x=-8; 	tile[28].logic_y=12;
		tile[29].logic_x=-10; 	tile[29].logic_y=6;
		tile[30].logic_x=-12; 	tile[30].logic_y=0;
		tile[31].logic_x=-10; 	tile[31].logic_y=-6;
		tile[32].logic_x=-8; 	tile[32].logic_y=-12;
		tile[33].logic_x=-6; 	tile[33].logic_y=-18;
		tile[34].logic_x=-2;	tile[34].logic_y=-18;
		tile[35].logic_x=2; 	tile[35].logic_y=-18;
		tile[36].logic_x=6;		tile[36].logic_y=-18;

		for(int i=0; i<=36; i++)
		{
			tile[i].display_x=fromPixelToLogicX(tile[i].logic_x);
			tile[i].display_y=fromPixelToLogicY(tile[i].logic_y);
		}

		tile[0].dice_number=7;
		tile[1].dice_number=8;
		tile[2].dice_number=10;
		tile[3].dice_number=5;
		tile[4].dice_number=8;
		tile[5].dice_number=5;
		tile[6].dice_number=12;
		tile[7].dice_number=4;
		tile[8].dice_number=10;
		tile[9].dice_number=11;
		tile[10].dice_number=11;
		tile[11].dice_number=6;
		tile[12].dice_number=3;
		tile[13].dice_number=3;
		tile[14].dice_number=9;
		tile[15].dice_number=2;
		tile[16].dice_number=4;
		tile[17].dice_number=6;
		tile[18].dice_number=9;

		tile[0].resource_type=DESERT;
		tile[1].resource_type=ORE;
		tile[2].resource_type=CLAY;
		tile[3].resource_type=ORE;
		tile[4].resource_type=CLAY;
		tile[5].resource_type=WOOD;
		tile[6].resource_type=WOOL;
		tile[7].resource_type=WOOL;
		tile[8].resource_type=WOOL;
		tile[9].resource_type=WOOD;
		tile[10].resource_type=ORE;
		tile[11].resource_type=WHEAT;
		tile[12].resource_type=WHEAT;
		tile[13].resource_type=WOOD;
		tile[14].resource_type=WOOL;
		tile[15].resource_type=CLAY;
		tile[16].resource_type=WHEAT;
		tile[17].resource_type=WOOD;
		tile[18].resource_type=WHEAT;
		tile[19].resource_type=THREEONE;
		tile[20].resource_type=WATER;
		tile[21].resource_type=THREEONE;
		tile[22].resource_type=WATER;
		tile[23].resource_type=THREEONE;
		tile[24].resource_type=WATER;
		tile[25].resource_type=THREEONE;
		tile[26].resource_type=WATER;
		tile[27].resource_type=THREEONE;
		tile[28].resource_type=WATER;
		tile[29].resource_type=THREEONE;
		tile[30].resource_type=WATER;
		tile[31].resource_type=THREEONE;
		tile[32].resource_type=WATER;
		tile[33].resource_type=THREEONE;
		tile[34].resource_type=WATER;
		tile[35].resource_type=THREEONE;
		tile[36].resource_type=WATER;


		tile[19].texture = loadTexture("gfx/sprites/3:1_2.png");
		tile[20].texture = loadTexture("gfx/sprites/water2.png");
		tile[21].texture = loadTexture("gfx/sprites/3:1_2.png");
		tile[22].texture = loadTexture("gfx/sprites/water3.png");
		tile[23].texture = loadTexture("gfx/sprites/3:1_2.png");
		tile[24].texture = loadTexture("gfx/sprites/water3.png");
		tile[25].texture = loadTexture("gfx/sprites/3:1_4.png");
		tile[26].texture = loadTexture("gfx/sprites/water4.png");
		tile[27].texture = loadTexture("gfx/sprites/3:1_4.png");
		tile[28].texture = loadTexture("gfx/sprites/water5.png");
		tile[29].texture = loadTexture("gfx/sprites/3:1_4.png");
		tile[30].texture = loadTexture("gfx/sprites/water6.png");
		tile[31].texture = loadTexture("gfx/sprites/3:1_5.png");
		tile[32].texture = loadTexture("gfx/sprites/water6.png");
		tile[33].texture = loadTexture("gfx/sprites/3:1_6.png");
		tile[34].texture = loadTexture("gfx/sprites/water1.png");
		tile[35].texture = loadTexture("gfx/sprites/3:1_1.png");
		tile[36].texture = loadTexture("gfx/sprites/water2.png");

		for(int i=0; i<=18; i++){
			tile[i].ID_tile = i;
			switch(tile[i].resource_type)
			{
				case WOOD:
					tile[i].texture = loadTexture("gfx/sprites/forest.png");
					break;
				case WHEAT:
					tile[i].texture = loadTexture("gfx/sprites/field.png");
					break;
				case ORE:
					tile[i].texture = loadTexture("gfx/sprites/mountain.png");
					break;
				case WOOL:
					tile[i].texture = loadTexture("gfx/sprites/land.png");
					break;
				case CLAY:
					tile[i].texture = loadTexture("gfx/sprites/hill.png");
					break;
				case DESERT:
					tile[i].texture = loadTexture("gfx/sprites/desert.png");
					break;
			}
			number[i].x=tile[i].display_x+35; // 150/2 - 80*2
			number[i].y=tile[i].display_y+35; // tile/2 - number/2

			switch(tile[i].ID_tile)
			{
				case 0:
					number[i].texture = loadTexture("gfx/sprites/number_7.png");
					break;
				case 1:
					number[i].texture = loadTexture("gfx/sprites/number_8.png");
					break;
				case 2:
					number[i].texture = loadTexture("gfx/sprites/number_10.png");
					break;
				case 3:
					number[i].texture = loadTexture("gfx/sprites/number_5.png");
					break;
				case 4:
					number[i].texture = loadTexture("gfx/sprites/number_8.png");
					break;
				case 5:
					number[i].texture = loadTexture("gfx/sprites/number_5.png");
					break;
				case 6:
					number[i].texture = loadTexture("gfx/sprites/number_12.png");
					break;
				case 7:
					number[i].texture = loadTexture("gfx/sprites/number_4.png");
					break;
				case 8:
					number[i].texture = loadTexture("gfx/sprites/number_10.png");
					break;
				case 9:
					number[i].texture = loadTexture("gfx/sprites/number_11.png");
					break;
				case 10:
					number[i].texture = loadTexture("gfx/sprites/number_11.png");
					break;
				case 11:
					number[i].texture = loadTexture("gfx/sprites/number_6.png");
					break;
				case 12:
					number[i].texture = loadTexture("gfx/sprites/number_3.png");
					break;
				case 13:
					number[i].texture = loadTexture("gfx/sprites/number_3.png");
					break;
				case 14:
					number[i].texture = loadTexture("gfx/sprites/number_9.png");
					break;
				case 15:
					number[i].texture = loadTexture("gfx/sprites/number_2.png");
					break;
				case 16:
					number[i].texture = loadTexture("gfx/sprites/number_4.png");
					break;
				case 17:
					number[i].texture = loadTexture("gfx/sprites/number_6.png");
					break;
				case 18:
					number[i].texture = loadTexture("gfx/sprites/number_9.png");
					break;
			}
		}

		for(int i=19; i<=36; i++)
		{
			tile[i].ID_tile = i;
		}

		building_menu.x = 50;
		building_menu.y = 675;
		building_menu.texture = loadTexture("gfx/sprites/building_menu.png");
		square.texture = loadTexture("gfx/sprites/square.png");
		return_button.texture = loadTexture("gfx/sprites/return.png");
		return_button.x = 350;
		return_button.y = 900;
		confirm_button.x = 500;
		confirm_button.y = 725;
		confirm_button.texture = loadTexture("gfx/sprites/confirm.png");
	}
	for(int i=0; i<19; i++)
	{
		blit(tile[i].texture, tile[i].display_x, tile[i].display_y);
		blit(number[i].texture, number[i].x, number[i].y);
	}
	for(int i=19; i<=36; i++)
	{
		blit(tile[i].texture, tile[i].display_x, tile[i].display_y);
	}
	for(int i=10; i<=24; i++)
	{
		if(building[i].exist)
		{
			blit(building[i].texture, building[i].display_x, building[i].display_y);
		}
	}
	for(int i=35; i<=49; i++)
	{
		if(building[i].exist)
		{
			blit(building[i].texture, building[i].display_x, building[i].display_y);
		}
	}
	for(int i=0; i<=9; i++)
	{
		if(building[i].exist)
		{
			blit(building[i].texture, building[i].display_x, building[i].display_y);
		}
	}
	for(int i=25; i<=34; i++)
	{
		if(building[i].exist)
		{
			blit(building[i].texture, building[i].display_x, building[i].display_y);
		}
	}
}

void initBuildings(Buildings building[], int set)
{
	if(set)
	{	for(int i=0; i<=49; i++)
		{
			building[i].ID_building=i;
			building[i].exist=0;
		}
		for(int i=0; i<=5; i++)
		{
			building[i].texture=loadTexture("gfx/sprites/colony_red.png");
		}
		for(int i=6; i<=9; i++)
		{
			building[i].texture=loadTexture("gfx/sprites/city_red.png");
		}
		for(int i=10; i<=24; i++)
		{
			building[i].texture=loadTexture("gfx/sprites/road_red.png");
		}
		for(int i=25; i<=30; i++)
		{
			building[i].texture=loadTexture("gfx/sprites/colony_blue.png");
		}
		for(int i=31; i<=34; i++)
		{
			building[i].texture=loadTexture("gfx/sprites/city_blue.png");
		}
		for(int i=35; i<=49; i++)
		{
			building[i].texture=loadTexture("gfx/sprites/road_blue.png");
		}
	}
}

void cleanup(void)
{
	SDL_DestroyRenderer(app.renderer);

	SDL_DestroyWindow(app.window);

	SDL_Quit();
}
