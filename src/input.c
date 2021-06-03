#include "input.h"

void doInput(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;

			default:
				break;
		}
	}
}

int continueButton(int set)
{
	int clickContinue=1;
	continue_button.x = 1300;	continue_button.y = 800;

	int mouse_x, mouse_y;
	int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

	if(set)
	{
		continue_button.texture = loadTexture("gfx/sprites/continue_button.png");
		next_button.texture = loadTexture("gfx/sprites/continue_button.png");
	}
	else if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>1300 && mouse_x<1500 && mouse_y>800 && mouse_y<850)
	{
	//	continue_button.texture = loadTexture("gfx/sprites/roll_dice_onclick.png");
		clickContinue = 0;
		SDL_Delay(100);
	}

	blit(continue_button.texture, continue_button.x, continue_button.y);
	return (clickContinue);
}

void next()
{
	next_button.x = 700;	next_button.y = 900;

	int mouse_x, mouse_y;
	int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

	if(var[1].state == 3)
	{
		next_button.texture = loadTexture("gfx/sprites/continue_button.png");
		var[1].state = 4;
	}
	else if (var[1].state>=4 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>700 && mouse_x<900 && mouse_y>825 && mouse_y<950)
	{
		var[1].state = 0;
		var[1].who++;
		SDL_Delay(200);
	}

	blit(next_button.texture, next_button.x, next_button.y);
}

void confirm()
{
	int mouse_x, mouse_y;
	int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

	if(var[0].state == 4)
	{
		blit(confirm_button.texture, confirm_button.x, confirm_button.y);
	}
	if (var[0].state == 4 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>500 && mouse_x<700 && mouse_y>725 && mouse_y<771)
	{
		var[0].state = 5;
		SDL_Delay(200);
	}

	if(var[1].state == 12)
	{
		blit(confirm_button.texture, confirm_button.x, confirm_button.y);
	}
	if (var[1].state == 12 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>500 && mouse_x<700 && mouse_y>725 && mouse_y<771)
	{
		var[1].state = 13;
		SDL_Delay(200);
	}

	if(var[1].state == 15)
	{
		blit(confirm_button.texture, confirm_button.x, confirm_button.y);
	}
	if (var[1].state == 15 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>500 && mouse_x<700 && mouse_y>725 && mouse_y<771)
	{
		var[1].state = 16;
		SDL_Delay(200);
	}

	if(var[1].state == 18)
	{
		blit(confirm_button.texture, confirm_button.x, confirm_button.y);
	}
	if (var[1].state == 18 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>500 && mouse_x<700 && mouse_y>725 && mouse_y<771)
	{
		var[1].state = 19;
		SDL_Delay(200);
	}

	if(var[1].state == 21)
	{
		blit(confirm_button.texture, confirm_button.x, confirm_button.y);
	}
	if (var[1].state == 21 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>500 && mouse_x<700 && mouse_y>725 && mouse_y<771)
	{
		var[1].state = 22;
		SDL_Delay(200);
	}
}

int nextSetup(int next_button_set)
{
	int set = next_button_set;
	next_button.x = 700;	next_button.y = 900;

	int mouse_x, mouse_y;
	int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

	if(set == 1)
	{
		blit(next_button.texture, next_button.x, next_button.y);
	}
	if (set==1 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>700 && mouse_x<900 && mouse_y>900 && mouse_y<950)
	{
		set = 2;
		SDL_Delay(200);
	}

	return(set);
}

int fromPixelToLogicX(int logic_x)
{
	int display_x = 1150 + logic_x * 40;
	return(display_x);
}

int fromPixelToLogicY(int logic_y)
{
	int display_y = 375 + logic_y * 20;
	return(display_y);
}

int fromLogicToPixelX(int display_x)
{
	float logic_x = (display_x-1150)/40;
	int temp = logic_x;
	if(abs(logic_x-temp)<=0.5)
	{
		return(temp);
	}
	else{
		return(temp+1);
	}
}

int fromLogicToPixelY(int display_y)
{
	float logic_y = (display_y-375)/20;
	int temp = logic_y;
	if(abs(logic_y-temp)<=0.5)
	{
		return(temp);
	}
	else{
		return(temp+1);
	}
}

int rollDice()
{
	 int n;
	 do {
			n = rand() % 8;
	 } while (n == 0 || n > 6);
	 return n;
}

void roll()
{
	int sum=0, roll_request=0;
	roll_button.x = 350;		roll_button.y = 575;
	dice[0].x = 88;					dice[0].y = 575;
	dice[1].x = 188;				dice[1].y = 575;

	int mouse_x, mouse_y;
	int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

	if(var[1].state==0)
	{
		roll_button.texture = loadTexture("gfx/sprites/roll_dice.png");
		var[1].state = 1;
	}
	else if (var[1].state==1 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>350 && mouse_x<450 && mouse_y>575 && mouse_y<664)
	{
	//	roll_button.texture = loadTexture("gfx/sprites/roll_dice_onclick.png");
		var[1].state = 2;
	}

	if (var[1].state==2)
	{
		dice[0].dice_number=rollDice();
		dice[1].dice_number=rollDice();
		var[1].value = dice[0].dice_number + dice[1].dice_number;
		switch(dice[0].dice_number)
		{
			case 1:
				dice[0].texture = loadTexture("gfx/sprites/dice_1.png");
				break;
			case 2:
				dice[0].texture = loadTexture("gfx/sprites/dice_2.png");
				break;
			case 3:
				dice[0].texture = loadTexture("gfx/sprites/dice_3.png");
				break;
			case 4:
				dice[0].texture = loadTexture("gfx/sprites/dice_4.png");
				break;
			case 5:
				dice[0].texture = loadTexture("gfx/sprites/dice_5.png");
				break;
			case 6:
				dice[0].texture = loadTexture("gfx/sprites/dice_6.png");
				break;
		}
		switch(dice[1].dice_number)
		{
			case 1:
				dice[1].texture = loadTexture("gfx/sprites/dice_1.png");
				break;
			case 2:
				dice[1].texture = loadTexture("gfx/sprites/dice_2.png");
				break;
			case 3:
				dice[1].texture = loadTexture("gfx/sprites/dice_3.png");
				break;
			case 4:
				dice[1].texture = loadTexture("gfx/sprites/dice_4.png");
				break;
			case 5:
				dice[1].texture = loadTexture("gfx/sprites/dice_5.png");
				break;
			case 6:
				dice[1].texture = loadTexture("gfx/sprites/dice_6.png");
				break;
		}
		var[1].state = 3;
	}

	if(var[1].state==1)
	{
		blit(roll_button.texture, roll_button.x, roll_button.y);
	}
	else if(var[1].state >= 3)
	{
		blit(dice[0].texture, dice[0].x, dice[0].y);
		blit(dice[1].texture, dice[1].x, dice[1].y);
	}
}

int remainingBuilding(Buildings building[], int who, int building_type)
{
	if(building_type == 0)
	{
		int roads = 15;
		for(int i=10; i<=24; i++)
		{
			if(building[i+25*(who-1)].exist)
			{
				roads--;
			}
		}
		return(roads);
	}
	else if(building_type == 1)
	{
		int colonies = 6;
		for(int i=0; i<=5; i++)
		{
			if(building[i+25*(who-1)].exist)
			{
				colonies--;
			}
		}
		return(colonies);
	}
	else if(building_type == 2)
	{
		int cities = 4;
		for(int i=6; i<=9; i++)
		{
			if(building[i+25*(who-1)].exist)
			{
				cities--;
			}
		}
		return(cities);
	}
}

void privatePanel(Players player[], Resources resource[], TTF_Font* Sans3, TTF_Font* Sans4)
{
	char temp[50];
	int i = (var[1].who % 2) + 1;

	renderText("Player :",25,25,Sans3);
	renderText(player[i].name,200,25,Sans3);
	// renderText(player[1].name,350,25,Sans3);
	// renderText(player[2].name,500,25,Sans3);

	renderText("Wood",25,100,Sans3);
	sprintf(temp, "%d", player[i].resources[0]);
	renderText(temp,200,100,Sans3);
	// sprintf(temp, "%d", player[1].resources[0]);
	// renderText(temp,350,100,Sans3);
	// sprintf(temp, "%d", player[2].resources[0]);
	// renderText(temp,500,100,Sans3);

	renderText("Wheat",25,150,Sans3);
	sprintf(temp, "%d", player[i].resources[1]);
	renderText(temp,200,150,Sans3);
	// sprintf(temp, "%d", player[1].resources[1]);
	// renderText(temp,350,150,Sans3);
	// sprintf(temp, "%d", player[2].resources[1]);
	// renderText(temp,500,150,Sans3);

	renderText("Ore",25,200,Sans3);
	sprintf(temp, "%d", player[i].resources[2]);
	renderText(temp,200,200,Sans3);
	// sprintf(temp, "%d", player[1].resources[2]);
	// renderText(temp,350,200,Sans3);
	// sprintf(temp, "%d", player[2].resources[2]);
	// renderText(temp,500,200,Sans3);

	renderText("Wool",25,250,Sans3);
	sprintf(temp, "%d", player[i].resources[3]);
	renderText(temp,200,250,Sans3);
	// sprintf(temp, "%d", player[1].resources[3]);
	// renderText(temp,350,250,Sans3);
	// sprintf(temp, "%d", player[2].resources[3]);
	// renderText(temp,500,250,Sans3);

	renderText("Clay",25,300,Sans3);
	sprintf(temp, "%d", player[i].resources[4]);
	renderText(temp,200,300,Sans3);
	// sprintf(temp, "%d", player[1].resources[4]);
	// renderText(temp,350,300,Sans3);
	// sprintf(temp, "%d", player[2].resources[4]);
	// renderText(temp,500,300,Sans3);

	renderText("Remaining colonies",25,350,Sans3);
	sprintf(temp, "%d", remainingBuilding(building,i,1));
	renderText(temp,350,350,Sans3);
	// sprintf(temp, "%d", remainingBuilding(building,2,1));
	// renderText(temp,500,350,Sans3);

	renderText("Remaining cities",25,400,Sans3);
	sprintf(temp, "%d", remainingBuilding(building,i,2));
	renderText(temp,350,400,Sans3);
	// sprintf(temp, "%d", remainingBuilding(building,2,2));
	// renderText(temp,500,400,Sans3);

 	renderText("Remaining roads",25,450,Sans3);
	sprintf(temp, "%d", remainingBuilding(building,i,0));
	renderText(temp,350,450,Sans3);
	// sprintf(temp, "%d", remainingBuilding(building,2,0));
	// renderText(temp,500,450,Sans3);

	renderText("Victory points",25,500,Sans3);
	sprintf(temp, "%d", player[i].resources[5]);
	renderText(temp,350,500,Sans3);
	// sprintf(temp, "%d", player[2].resources[5]);
	// renderText(temp,500,500,Sans3);

	renderText("1 colony = 1 victory point",450,25,Sans4);
	renderText("1 city = 2 victory points",450,75,Sans4);
	renderText("More than 5 roads = 1 victory points",450,125,Sans4);

	blit(building_menu.texture, building_menu.x, building_menu.y);
}

int verifySetupBuilding(int x, int y)
{
	int bool = 1;
	for(int i=0; i<=49; i++)
	{
		if(building[i].exist)
		{
			if(building[i].logic_x == x && building[i].logic_y == y)
			{
				bool = 0;
			}
		}
	}
	if(	( abs(y) % 6 == 0 )
	||  ( abs(x) % 2 == 1 )
	||  !((abs(x) % 4 == 0 && (abs(y) == 4 || abs(y) == 8 || abs(y) == 16))
	|| 	(abs(x) % 4 == 2 && (abs(y) == 2 || abs(y) == 10 || abs(y) == 14)))
	|| (abs(x) == 10 && abs(y) == 10)
	|| (abs(x) == 10 && abs(y) == 14)
	|| (abs(x) == 8  && abs(y) == 16)
	)
	{
		bool = 0;
	}
	return(bool);
}

int verifyBuilding(int x, int y)
{
	int bool = 0;
	for(int i=0; i<=49; i++)
	{
		if(building[i].exist)
		{
			if(building[i].logic_x == x && building[i].logic_y == y)
			{
				bool = 0;
			}
		}
		if(   (building[i].logic_x == x		  && building[i].logic_y == y + 2)
			 || (building[i].logic_x == x 		&& building[i].logic_y == y - 2)
			 || (building[i].logic_x == x + 1 && building[i].logic_y == y + 1)
			 || (building[i].logic_x == x + 1 && building[i].logic_y == y - 1)
			 || (building[i].logic_x == x - 1 && building[i].logic_y == y + 1)
			 || (building[i].logic_x == x - 1 && building[i].logic_y == y - 1)
		 )
		 {
			 bool = 1;
		 }
	}
	if(  (abs(y) % 6 == 0 )
	  || (abs(x) % 2 == 1 )
	  || !( (abs(x) % 4 == 0 && (abs(y) == 4 || abs(y) == 8 || abs(y) == 16))
	  			|| (abs(x) % 4 == 2 && (abs(y) == 2 || abs(y) == 10 || abs(y) == 14))
				)
		)
	{
		bool = 0;
	}
	return(bool);
}

int verifyRoadStart(int x, int y, int owner)
{
	int bool = 0;
	for(int i=0; i<=49; i++)
	{
		if(building[i].exist)
		{
			if(building[i].logic_x == x && building[i].logic_y == y && building[i].ID_building % 25 <= 9 && building[i].ID_building / 25 == owner)
			{
				bool = 1;
			}
		}
		if( ( (building[i].logic_x == x		  && building[i].logic_y == y + 2)
			 || (building[i].logic_x == x 		&& building[i].logic_y == y - 2)
			 || (building[i].logic_x == x + 1 && building[i].logic_y == y + 1)
			 || (building[i].logic_x == x + 1 && building[i].logic_y == y - 1)
			 || (building[i].logic_x == x - 1 && building[i].logic_y == y + 1)
			 || (building[i].logic_x == x - 1 && building[i].logic_y == y - 1)
		    )
		&& building[i].ID_building % 25 >= 10 && building[i].ID_building % 25 <= 24 && building[i].ID_building / 25 == owner)
		{
			bool = 1;
		}
	}
	return(bool);
}

int verifyRoad(int previous_x, int previous_y, int next_x, int next_y)
{
	int bool = 0;
	if(previous_y <= 0)
	{
		if(abs(previous_y) % 6 == 2)
		{
			if( (next_x == previous_x     && next_y == previous_y + 4 )
			|| 	(next_x == previous_x - 2 && next_y == previous_y - 2 )
			||	(next_x == previous_x + 2 && next_y == previous_y - 2 )
			)
			{
				bool = 1;
			}
		}
		else if (abs(previous_y) % 6 == 4)
		{
			if( (next_x == previous_x     && next_y == previous_y - 4 )
			|| 	(next_x == previous_x - 2 && next_y == previous_y + 2 )
			||	(next_x == previous_x + 2 && next_y == previous_y + 2 )
			)
			{
				bool = 1;
			}
		}
	}
	else
	{
		if(previous_y % 6 == 4)
		{
			if( (next_x == previous_x     && next_y == previous_y + 4 )
			|| 	(next_x == previous_x - 2 && next_y == previous_y - 2 )
			||	(next_x == previous_x + 2 && next_y == previous_y - 2 )
			)
			{
				bool = 1;
			}
		}
		else if (previous_y % 6 == 2)
		{
			if( (next_x == previous_x     && next_y == previous_y - 4 )
			|| 	(next_x == previous_x - 2 && next_y == previous_y + 2 )
			||	(next_x == previous_x + 2 && next_y == previous_y + 2 )
			)
			{
				bool = 1;
			}
		}
		for(int i=0; i<=49; i++)
		{
			if(building[i].exist)
			{
				if( building[i].logic_x == (previous_x+next_x)/2
				&& building[i].logic_y == (previous_y+next_y)/2
			)
				{
					bool = 0;
				}
			}
		}
	}
	return(bool);
}

int verifyColony(int x, int y, int owner)
{
	int bool = 0;
	for(int i=0; i<=49; i++)
	{
		if(building[i].exist)
		{
			if( ( building[i].logic_x == x && building[i].logic_y == y
			&& building[i].ID_building % 25 <= 5 && building[i].ID_building / 25 == owner)
		)
			{
				bool = 1;
			}
		}
	}
	return(bool);
}

void costColony(Players player[], int owner)
{
	player[owner].resources[0]--;
	player[owner].resources[1]--;
	player[owner].resources[3]--;
	player[owner].resources[4]--;

	player[0].resources[0]++;
	player[0].resources[1]++;
	player[0].resources[3]++;
	player[0].resources[4]++;
}

void costCity(Players player[], int owner)
{
	player[owner].resources[1]--;
	player[owner].resources[1]--;
	player[owner].resources[2]--;
	player[owner].resources[2]--;
	player[owner].resources[2]--;

	player[0].resources[1]++;
	player[0].resources[1]++;
	player[0].resources[2]++;
	player[0].resources[2]++;
	player[0].resources[2]++;
}

void costRoad(Players player[], int owner)
{
	player[owner].resources[0]--;
	player[owner].resources[4]--;

	player[0].resources[0]++;
	player[0].resources[4]++;
}

int verifyResources(int build, int who)
{
	int bool = 0;
	switch(build)
	{
		case 0:
			if(		(player[who].resources[0] >= 1)
				&& 	(player[who].resources[4] >= 1))
			{
				bool = 1;
			}
			break;
		case 1:
			if(		(player[who].resources[0] >= 1)
				&& 	(player[who].resources[1] >= 1)
				&& 	(player[who].resources[3] >= 1)
				&& 	(player[who].resources[4] >= 1))
			{
				bool = 1;
			}
			break;
		case 2:
			if(		(player[who].resources[1] >= 2)
				&& 	(player[who].resources[2] >= 3))
			{
				bool = 1;
			}
			break;
	}
	return(bool);
}

void determinePlayerRoad(int who, int ID_building, int direction)
{
	if(who ==  1)
	{
		if(direction == 1)
		{
			building[ID_building].texture = loadTexture("gfx/sprites/road_red1.png");
		}
		else if(direction == 2)
		{
			building[ID_building].texture = loadTexture("gfx/sprites/road_red2.png");
		}
		else if(direction == 3)
		{
			building[ID_building].texture = loadTexture("gfx/sprites/road_red3.png");
		}
	}
	else if(who == 2)
	{
		if(direction == 1)
		{
			building[ID_building].texture = loadTexture("gfx/sprites/road_blue1.png");
		}
		else if(direction == 2)
		{
			building[ID_building].texture = loadTexture("gfx/sprites/road_blue2.png");
		}
		else if(direction == 3)
		{
			building[ID_building].texture = loadTexture("gfx/sprites/road_blue3.png");
		}
	}
	else if(who == 3)
	{
		if(direction == 1)
		{
			building[ID_building].texture = loadTexture("gfx/sprites/road_yellow1.png");
		}
		else if(direction == 2)
		{
			building[ID_building].texture = loadTexture("gfx/sprites/road_yellow2.png");
		}
		else if(direction == 3)
		{
			building[ID_building].texture = loadTexture("gfx/sprites/road_yellow3.png");
		}
	}
	else if(who == 4)
	{
		if(direction == 1)
		{
			building[ID_building].texture = loadTexture("gfx/sprites/road_green1.png");
		}
		else if(direction == 2)
		{
			building[ID_building].texture = loadTexture("gfx/sprites/road_green2.png");
		}
		else if(direction == 3)
		{
			building[ID_building].texture = loadTexture("gfx/sprites/road_green3.png");
		}
	}
}

void determineTexture(int ID_building, int logic_x, int logic_y)
{
	if(abs(logic_x) % 2 == 0)
	{
		determinePlayerRoad(ID_building/25 + 1, ID_building,1);
	}
	else if( logic_y <= 0 && logic_x > 0 )
	{
		if(logic_x % 4 == 1 )
		{
			if(logic_y == -3 || logic_y == -15)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,2);
			}
			else if(logic_y == -9)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,3);
			}
		}
		else if(logic_x % 4 == 3)
		{
			if(logic_y == -3 || logic_y == -15)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,3);
			}
			else if(logic_y == -9)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,2);
			}
		}
	}
	else if( logic_y <= 0 && logic_x < 0)
	{
		if(abs(logic_x) % 4 == 3 )
		{
			if(logic_y == -3 || logic_y == -15)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,2);
			}
			else if(logic_y == -9)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,3);
			}
		}
		else if(abs(logic_x) % 4 == 1)
		{
			if(logic_y == -3 || logic_y == -15)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,3);
			}
			else if(logic_y == -9)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,2);
			}
		}
	}
	else if( logic_y > 0 && logic_x < 0)
	{
		if(abs(logic_x) % 4 == 1 )
		{
			if(logic_y == 3 || logic_y == 15)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,2);
			}
			else if(logic_y == 9)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,3);
			}
		}
		else if(abs(logic_x) % 4 == 3)
		{
			if(logic_y == 3 || logic_y == 15)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,3);
			}
			else if(logic_y == 9)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,2);
			}
		}
	}
	else if( logic_y > 0 && logic_x > 0)
	{
		if(logic_x % 4 == 3 )
		{
			if(logic_y == 3 || logic_y == 15)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,2);
			}
			else if(logic_y == 9)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,3);
			}
		}
		else if(logic_x % 4 == 1)
		{
			if(logic_y == 3 || logic_y == 15)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,3);
			}
			else if(logic_y == 9)
			{
				determinePlayerRoad(ID_building/25 + 1, ID_building,2);
			}
		}
	}
}

void placeBuilding(Buildings building[], Players player[], int ID_building, int logic_x, int logic_y)
{
	if(ID_building <= 5)
	{
		costColony(player,1);
	}
	else if(ID_building <= 9)
	{
		costCity(player,1);
	}
	else if(ID_building <= 24)
	{
		costRoad(player,1);
		determineTexture(ID_building,logic_x,logic_y);
	}
	else if(ID_building <= 30)
	{
		costColony(player,2);
	}
	else if(ID_building <= 34)
	{
		costCity(player,2);
	}
	else if(ID_building <= 49)
	{
		costRoad(player,2);
		determineTexture(ID_building,logic_x,logic_y);
	}

	building[ID_building].exist=1;
	building[ID_building].display_x = fromPixelToLogicX(logic_x) + 50;
	building[ID_building].display_y = fromPixelToLogicY(logic_y) + 50;
	building[ID_building].logic_x = logic_x;
	building[ID_building].logic_y = logic_y;
}

void deleteColony(int x, int y)
{
	for(int i = 0; i<49; i++)
	{
		if(building[i].logic_x == x && building[i].logic_y == y)
		{
			building[i].exist = 0;
		}
	}
}

int chooseBuildingID(Buildings building[], int player_play, int type_building)
{
	int who = (player_play - 1) % 2;
	if(type_building == 1)
	{
		for(int i=0; i<=5; i++)
		{
			if(building[i+25*who].exist == 0)
			{
				return(i+25*who);
			}
		}
	}
	else if(type_building == 2)
	{
		for(int i=6; i<=9; i++)
		{
			if(building[i+25*who].exist == 0)
			{
				return(i+25*who);
			}
		}
	}
	else if(type_building == 0)
	{
		for(int i=10; i<=24; i++)
		{
			if(building[i+25*who].exist == 0)
			{
				return(i+25*who);
			}
		}
	}
}

// => Do no trust the cursor, but the center of the blue circle
void selectLocation(TTF_Font* Sans3)
{
	char temp[50];
	int mouse_x, mouse_y;
	int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
	if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if( fromLogicToPixelX(mouse_x)<=11 && fromLogicToPixelX(mouse_x)>=-10
		 && fromLogicToPixelY(mouse_y)<=19 && fromLogicToPixelY(mouse_y)>=-19)
		{
			// sprintf(temp, "%d", mouse_x);
			// renderText(temp,50,10,Sans3);
			// sprintf(temp, "%d", mouse_y);
			// renderText(temp,150,10,Sans3);
			select_circle[0].x = fromPixelToLogicX(fromLogicToPixelX(mouse_x - 40));
			select_circle[0].y = fromPixelToLogicY(fromLogicToPixelY(mouse_y - 60));
		}
	}
	blit(select_circle[0].texture, select_circle[0].x+25, select_circle[0].y+25);
	// sprintf(temp, "%d", select_circle[0].x);
	// renderText(temp,50,50,Sans3);
	// sprintf(temp, "%d", select_circle[0].y);
	// renderText(temp,150,50,Sans3);
	// sprintf(temp, "%d", fromLogicToPixelX(select_circle[0].x));
	// renderText(temp,400,50,Sans3);
	// sprintf(temp, "%d", fromLogicToPixelY(select_circle[0].y));
	// renderText(temp,500,50,Sans3);
}

void setupRound(int whoplays ,TTF_Font* Sans1, TTF_Font* Sans3)
{
	renderText("1) Click on the map to select a location",50,350,Sans3);
	renderText("at a crossing for your colony.",50,400,Sans3);
	renderText("2) Then click on another location at a",50,550,Sans3);
	renderText("crossing around your colony to build a road.",50,600,Sans3);
	selectLocation(Sans3);
	int position_select_x = fromLogicToPixelX(select_circle[0].x);
	int position_select_y = fromLogicToPixelY(select_circle[0].y);
	// char temp[50];
	// sprintf(temp, "%d", var[0].state);
	// renderText(temp,50,100,Sans3);

	if(var[0].state <= 1)
	{
		if( position_select_x<=13 && position_select_x>=-13
				&& position_select_y<=19 && position_select_y>=-19)
		{
			if(verifySetupBuilding(position_select_x,position_select_y))
			{
				var[0].state = 1;
			}
			else
			{
				var[0].state = 0;
			}
		}
	}

	if(nextSetup(var[0].state) == 2)
	{
		var[0].state = 3;
		int temp_id_building = chooseBuildingID(building,whoplays,1);
		placeBuilding(building,player,temp_id_building,position_select_x,position_select_y);

		int position_select_x = fromLogicToPixelX(select_circle[0].x);
		int position_select_y = fromLogicToPixelY(select_circle[0].y);
		temp_location.x = position_select_x;
		temp_location.y = position_select_y;
		select_circle[0].x = 0;
		select_circle[0].y = 0;
		SDL_Delay(200);
	}

	if(var[0].state == 3 || var[0].state == 4)
	{
		selectLocation(Sans3);
		int position_select_x = fromLogicToPixelX(select_circle[0].x);
		int position_select_y = fromLogicToPixelY(select_circle[0].y);
		if( position_select_x<=13 && position_select_x>=-13
				&& position_select_y<=19 && position_select_y>=-19)
		{
			if(verifyRoad(temp_location.x,temp_location.y,position_select_x,position_select_y))
			{
				var[0].state = 4;
			}
			else
			{
				var[0].state = 3;
			}
			confirm();
		}
		if(var[0].state == 5)
		{
			var[0].state = 0;
			var[0].value++;
			int temp_id_building = chooseBuildingID(building,whoplays,0);
			placeBuilding(building,player,temp_id_building,(temp_location.x + position_select_x)/2,(temp_location.y + position_select_y)/2);
			select_circle[0].x = 0;
			select_circle[0].y = 0;
		}
	}
}

void distribution(Players player[], Tiles tile[], Buildings building[], int sum)
{
	int lucky_one=0;
	for(int i=0; i<=18; i++)
	{
		if(tile[i].dice_number == sum)
		{
			for(int j=0; j<=49; j++)
			{
				if(building[j].exist==1)
				{
					if( ( building[j].logic_x == tile[i].logic_x + 2 && ( building[j].logic_y==tile[i].logic_y + 2 || building[j].logic_y==tile[i].logic_y - 2 ) )
							|| ( building[j].logic_x == tile[i].logic_x && ( building[j].logic_y==tile[i].logic_y + 4 || building[j].logic_y==tile[i].logic_y - 4 ) )
							|| ( building[j].logic_x == tile[i].logic_x - 2 && ( building[j].logic_y==tile[i].logic_y + 2 || building[j].logic_y==tile[i].logic_y - 2 ) )
						)
					{
						if(building[j].ID_building <= 9)
						{
							lucky_one = 1;
						}
						else if(building[j].ID_building >= 25)// && building[j].ID_building <= 19)
						{
							lucky_one = 2;
						}
						if((building[j].ID_building % 25) <= 5)
						{
							player[lucky_one].resources[tile[i].resource_type]++;
							player[0].resources[tile[i].resource_type]--;
						}
						else if ((building[j].ID_building % 25) <= 9)
						{
							player[lucky_one].resources[tile[i].resource_type]++;
							player[lucky_one].resources[tile[i].resource_type]++;
							player[0].resources[tile[i].resource_type]--;
							player[0].resources[tile[i].resource_type]--;
						}
					}
				}
			}
		}
	}
}

void firstDistribution(Players player[], Tiles tile[], Buildings building[])
{
	for(int who=0; who<=1; who++)
	{
		for(int i=0; i<=1; i++)
		{
			for(int j=0; j<=18; j++)
			{
				if((tile[j].logic_x == building[i+25*who].logic_x 		&& tile[j].logic_y == building[i+25*who].logic_y + 4)
				|| (tile[j].logic_x == building[i+25*who].logic_x 		&& tile[j].logic_y == building[i+25*who].logic_y - 4)
				|| (tile[j].logic_x == building[i+25*who].logic_x + 2 && tile[j].logic_y == building[i+25*who].logic_y + 2)
				|| (tile[j].logic_x == building[i+25*who].logic_x + 2 && tile[j].logic_y == building[i+25*who].logic_y - 2)
				|| (tile[j].logic_x == building[i+25*who].logic_x - 2 && tile[j].logic_y == building[i+25*who].logic_y + 2)
				|| (tile[j].logic_x == building[i+25*who].logic_x - 2 && tile[j].logic_y == building[i+25*who].logic_y - 2)
				)
				{
					player[who+1].resources[tile[j].resource_type]++;
					player[0].resources[tile[j].resource_type]--;
				}
			}
		}
	}
}

void VPRefresh(Players player[], Buildings building[])
{
	for(int who=0; who<=1; who++)
	{
		int tempVP = 0, roads = 0;
		for(int i=0; i<=5; i++)
		{
			if(building[i+who*25].exist)
			{
				tempVP++;
			}
		}
		for(int i=6; i<=9; i++)
		{
			if(building[i+who*25].exist)
			{
				tempVP++;
				tempVP++;
			}
		}
		for(int i=10; i<=24; i++)
		{
			if(building[i+who*25].exist)
			{
				roads++;
			}
		}
		if(roads >= 5)
		{
			tempVP++;
		}
		player[who+1].resources[5]=tempVP;
	}
}

void trade(TTF_Font* Sans3)
{
	int mouse_x, mouse_y;
	int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

	if(var[1].state == 4)
	{
		blit(square.texture,350,675);
		renderText2("Trade",355,700,Sans3);
	}
	if (var[1].state == 4 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>350 && mouse_x<450 && mouse_y>675 && mouse_y<775)
	{
		var[1].state = 5;
		SDL_Delay(200);
	}

	if(var[1].state == 5)
	{
		blit(return_button.texture,return_button.x,return_button.y);
		blit(square.texture,350,775);
		renderText2("Player",355,800,Sans3);
		blit(square.texture,500,775);
		renderText2("4 -> 1",505,800,Sans3);
		blit(square.texture,650,775);
		renderText2("3 -> 1",655,800,Sans3);
		// blit(square.texture,800,675);
		// renderText2("2 -> 2",805,700,Sans3);
	}

	if (var[1].state == 5 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>350 && mouse_x<493 && mouse_y>900 && mouse_y<950)
	{
		var[1].state = 4;
		SDL_Delay(200);
	}

}

void build(TTF_Font* Sans3)
{
	int mouse_x, mouse_y;
	int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

	if(var[1].state == 4)
	{ // DISPLAY BUILD
		blit(square.texture,500,675);
		renderText2("Build",510,700,Sans3);
	}

	if (var[1].state == 4 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>500 && mouse_x<600 && mouse_y>675 && mouse_y<775)
	{ // GO TO BUILD MENU
		var[1].state = 10;
		SDL_Delay(200);
	}

	if(var[1].state == 10)
	{ // BUILD MENU
		blit(return_button.texture,return_button.x,return_button.y);
		blit(square.texture,350,775);
		renderText2("Road",355,800,Sans3);
		blit(square.texture,500,775);
		renderText2("Colony",505,800,Sans3);
		blit(square.texture,650,775);
		renderText2("City",655,800,Sans3);
	}

	if (var[1].state == 10 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>350 && mouse_x<450 && mouse_y>775 && mouse_y<875)
	{ // ROAD 1
		var[1].state = 14;
		select_circle[0].x = 0;
		select_circle[0].y = 0;
		if(!verifyResources(0,(var[1].who%2)+1))
		{
			var[1].state = 4;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                         "Alert",
                         "You don't have enough resources to build a road.",
                         NULL);
		}
		SDL_Delay(200);
	}

	if(var[1].state == 14 || var[1].state == 15)
	{ // ROAD 2
		blit(return_button.texture,return_button.x,return_button.y);
		selectLocation(Sans3);
		int position_select_x = fromLogicToPixelX(select_circle[0].x);
		int position_select_y = fromLogicToPixelY(select_circle[0].y);
		if( position_select_x<=13 && position_select_x>=-13
				&& position_select_y<=19 && position_select_y>=-19)
		{
			if(verifyRoadStart(position_select_x,position_select_y,var[1].who%2))
			{
				var[1].state = 15;
			}
			else
			{
				var[1].state = 14;
			}
			confirm();
		}
		if(var[1].state == 16)
		{
			var[1].state = 17;
			temp_location.x = position_select_x;
			temp_location.y = position_select_y;
			select_circle[0].x = 0;
			select_circle[0].y = 0;
			SDL_Delay(200);
		}
	}

	if(var[1].state == 17 || var[1].state == 18)
	{ // ROAD 3
		blit(return_button.texture,return_button.x,return_button.y);
		selectLocation(Sans3);
		int position_select_x = fromLogicToPixelX(select_circle[0].x);
		int position_select_y = fromLogicToPixelY(select_circle[0].y);
		if( position_select_x<=13 && position_select_x>=-13
				&& position_select_y<=19 && position_select_y>=-19)
		{
			if(verifyRoad(temp_location.x,temp_location.y,position_select_x,position_select_y))
			{
				var[1].state = 18;
			}
			else
			{
				var[1].state = 17;
			}
			confirm();
		}
		if(var[1].state == 19)
		{
			var[1].state = 4;
			int temp_id_building = chooseBuildingID(building,(var[1].who%2)+1,0);
			placeBuilding(building,player,temp_id_building,(temp_location.x + position_select_x)/2,(temp_location.y + position_select_y)/2);
		}
	}

	if (var[1].state == 10 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>500 && mouse_x<600 && mouse_y>775 && mouse_y<875)
	{ // COLONY 1
		var[1].state = 11;
		select_circle[0].x = 0;
		select_circle[0].y = 0;
		if(!verifyResources(1,(var[1].who%2)+1))
		{
			var[1].state = 4;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
												 "Alert",
												 "You don't have enough resources to build a colony.",
												 NULL);
		}
		SDL_Delay(200);
	}

	if(var[1].state == 11 || var[1].state == 12)
	{ // COLONY 2
		blit(return_button.texture,return_button.x,return_button.y);
		selectLocation(Sans3);
		int position_select_x = fromLogicToPixelX(select_circle[0].x);
		int position_select_y = fromLogicToPixelY(select_circle[0].y);
		if( position_select_x<=13 && position_select_x>=-13
				&& position_select_y<=19 && position_select_y>=-19)
		{
			if(verifyBuilding(position_select_x,position_select_y))
			{
				var[1].state = 12;
			}
			else
			{
				var[1].state = 11;
			}
			confirm();
		}
		if(var[1].state == 13)
		{
			var[1].state = 4;
			int temp_id_building = chooseBuildingID(building,(var[1].who%2)+1,1);
			placeBuilding(building,player,temp_id_building,position_select_x,position_select_y);
		}
	}

	if (var[1].state == 10 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>650 && mouse_x<750 && mouse_y>775 && mouse_y<875)
	{ // CITY 1
		var[1].state = 20;
		select_circle[0].x = 0;
		select_circle[0].y = 0;
		if(!verifyResources(0,(var[1].who%2)+1))
		{
			var[1].state = 4;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
												 "Alert",
												 "You don't have enough resources to build a city.",
												 NULL);
		}
		SDL_Delay(200);
	}

	if(var[1].state == 20 || var[1].state == 21)
	{ // CITY 2
		blit(return_button.texture,return_button.x,return_button.y);
		selectLocation(Sans3);
		int position_select_x = fromLogicToPixelX(select_circle[0].x);
		int position_select_y = fromLogicToPixelY(select_circle[0].y);
		if( position_select_x<=13 && position_select_x>=-13
				&& position_select_y<=19 && position_select_y>=-19)
		{
			if(verifyColony(position_select_x,position_select_y,var[1].who%2))
			{
				var[1].state = 21;
			}
			else
			{
				var[1].state = 20;
			}
			confirm();
		}
		if(var[1].state == 22)
		{
			var[1].state = 4;
			int temp_id_building = chooseBuildingID(building,(var[1].who%2)+1,2);
			deleteColony(position_select_x,position_select_y);
			placeBuilding(building,player,temp_id_building,position_select_x,position_select_y);
		}
	}

	if (var[1].state >= 10 && buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x>350 && mouse_x<493 && mouse_y>900 && mouse_y<950)
	{ // RETURN
		var[1].state = 4;
		SDL_Delay(200);
	}
}
