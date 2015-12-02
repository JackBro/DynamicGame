#pragma once
#include <string>
#include <vector>

class Component;

using namespace std;

class Actor
{
	private:
		Actor()
		{
			
		};
		string name;
		string tag;
	public:
	
		//Name
		string GetName();
		void SetName(string name);
		vector<Component*> components;
		
		//Tag
		string GetTag();
		void SetTag(string Tag);
		
		static Actor* CreateActor(string name);
		
};
