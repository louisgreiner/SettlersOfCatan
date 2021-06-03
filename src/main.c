#include "main.h"

/*	1) Welcome screen
		2) Number of players
		3) initialization
		4) Game processing
		5) End of the game + display winner
*/

int main(int argc, char *argv[])
{
	initSDL();
	TTF_Init();
	TTF_Font* Sans1 = TTF_OpenFont("BreatheFire-65pg.ttf", 100);
	TTF_Font* Sans2 = TTF_OpenFont("BreatheFire-65pg.ttf", 60);
	TTF_Font* Sans3 = TTF_OpenFont("BreatheFire-65pg.ttf", 40);
	TTF_Font* Sans4 = TTF_OpenFont("BreatheFire-65pg.ttf", 20);
	atexit(cleanup);

	int welcome_screen=1, choose_players=1, init_game=1, game_process=1, end_game=1;
	int continue_button_set=1;
	int buildings_set=1;
	int map_change=1;

	temp_location.x = 15;
	var[0].state = 0;
	var[0].value = 0;
	var[1].state = 0;
	var[1].who = 0;
	int whoplays;

	char temp[50];
	select_circle[0].texture = loadTexture("gfx/sprites/select.png");

	while (1)
	{
		prepareScene();
		doInput();
		if(welcome_screen)
		{
			// Display welcome screen and continue button
			renderText("Welcome to Catan !",450,100,Sans1);
			welcome_screen = continueButton(continue_button_set);
			continue_button_set = 0;
		}
		else if(choose_players)
		{
			// Choose number of players (not implemented yet)
			initPlayers(player, resource);
			choose_players = 0;
			initBuildings(building,buildings_set);
			buildings_set=0;
		}
		else if(init_game)
		{
			// Game's initialization (first colonies, roads and resources distribution)
				initMap(tile,map_change);
				map_change = 0;
				switch(var[0].value)
				{
				case 0:
					renderText("Player 1 : ",100,150,Sans1);
					renderText(player[1].name,500,150,Sans1);
					whoplays=1;
					break;
				case 1:
					renderText("Player 2 : ",100,150,Sans1);
					renderText(player[2].name,500,150,Sans1);
					whoplays=2;
					break;
				case 2:
					renderText("Player 2 : ",100,150,Sans1);
					renderText(player[2].name,500,150,Sans1);
					whoplays=2;
					break;
				case 3:
					renderText("Player 1 : ",100,150,Sans1);
					renderText(player[1].name,500,150,Sans1);
					whoplays=1;
					break;
			}
			setupRound(whoplays,Sans1,Sans3);
			if(var[0].value == 4)
			{
				init_game = 0;
				firstDistribution(player,tile,building);
			}
		}
		else if(game_process)
		{
			// Board game, hot-seat only
			initMap(tile,map_change);
			privatePanel(player, resource, Sans3, Sans4);
			roll();
			if(var[1].state == 3)
			{
				distribution(player,tile,building,var[1].value);
			}
			if(var[1].state >= 3)
			{
				trade(Sans3);
				build(Sans3);
				next();
			}
			VPRefresh(player,building);
			if(player[1].resources[5]>=5 || player[2].resources[5]>=5)
			{
				game_process = 0;
			}
		}
		else if(end_game)
		{
			if(player[1].resources[5]>=5)
			{
				renderText("Congratulations Player 1 (Red) has won !",50,200,Sans3);
			}
			else if(player[2].resources[5]>=5)
			{
				renderText("Congratulations Player 2 (Blue) has won !",50,200,Sans3);
			}
		}
		presentScene();
		SDL_Delay(1000/60); // 60 fps
	}
	return 0;
}
