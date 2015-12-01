#include "Engine/OpenGl.h"

int main () {
	OpenGl* graphics = OpenGl::CreateGraphicsSystem();
	while(!graphics->ShouldClose())
	{
		graphics->Draw();
	}
	graphics->Close();
	return 0;
}