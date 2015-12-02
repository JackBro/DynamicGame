#include "actor.h"
#include <vector>
#include "../Engine/Shaders.h"

Actor* Actor::CreateActor(string name)
{
	Actor* createActor = new Actor();
	createActor->SetName(name);
	createActor->SetTag("Default");
	Shaders::Instance()->getShader("text");
	return createActor;
}


string Actor::GetName()
{
	return name;
}

void Actor::SetName(string name)
{
	this->name = name;
}

string Actor::GetTag()
{
	return tag;
}

void Actor::SetTag(string tag)
{
	this->tag = tag;
}

