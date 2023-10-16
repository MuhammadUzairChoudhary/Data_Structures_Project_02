//Muhammad_Uzair_Choudhary_22i2681
#include<iostream>
#include"Project.h"

using namespace std;


int main()
{
	Project* project = new Project();
	Task* head = project->newProject(project->tasks, project->resources);
	
	project->menu(project->tasks, project->resources, head);
}