#include "GameBase.h"
#include <iostream>

GameBase::GameBase()
{

}


void GameBase::Update(float deltaTime)
{
	std::cout << "delta Time: " << deltaTime << std::endl;
}
