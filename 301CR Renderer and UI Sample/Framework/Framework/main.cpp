/*
This is a sample project using SFML to render shapes and textured shapes. Note that the structure of this sample
does not follow an optimal design pattern - the idea is that you structure the renderer yourself. What this code
DOES provide is a working basis for using SFML, with all of the awkward Visual Studio setup bits handled for you
while demonstrating the way in which you employ the basics of the API. Comments are included.
*/

// TEST CHANGE

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Box2D\Box2D.h"
#include "physicsSync.h"
#include "game.h"


using namespace std;


const int fps = 60;
const int  frameDelay = 1000 / fps;

vector <sf::Shape> shapesVector;

uint32 frameStart;
int frameTime;

game *game1 = nullptr;

sf::RenderWindow* gameWindow = nullptr;


void main()
{
	game1 = new game();

	
	game1->setUp("TestGame", 1920, 1080);




	while (game1->rendererGame->gameWindow->isOpen()) {
		//for (int32 i = 0; i < 60; ++i)
		//{

		game1->update();
		game1->render();
		game1->inputHandlerGame();
		game1->eventHandler();

		}
	//}
}