#include "actor.h"
#include <vector>

Actor* Actor::CreateActor(string name)
{
	Actor* createActor = new Actor();
	createActor->Setname(name);
	createActor->SetTag("Default");
	return createActor;
}


string Actor::GetName()
{
	return name;
}

void Actor::SetName(string name)
{
	this.name = name;
}

string Actor::GetTag()
{
	return tag;
}

void Actor::SetTag(string tag)
{
	this.tag = tag;
}

