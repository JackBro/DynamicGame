#include "Engine/OpenGl.h"
#include "GameLogic/actor.h"

int main () {
	OpenGl* graphics = OpenGl::CreateGraphicsSystem();
	Actor* act = Actor::CreateActor("test");
	while(!graphics->ShouldClose())
	{
		graphics->Draw();
	}
	graphics->Close();
	return 0;
}