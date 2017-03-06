#ifndef GAME_H
#define GAME_H

//Dependencies
#include "World.h"

//Constants
//const float MS_PER_UPDATE = 10.0;
const int MAX_ENTITIES = 3000;

//Functions
void Execute();

void CreateTestLevel(std::vector<GameObject> & gameObjects);


#endif