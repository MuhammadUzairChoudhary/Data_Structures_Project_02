#pragma once
//Muhammad_Uzair_Choudhary_22i2681

#include<iostream>
#include"Resource.h"


using namespace std;

class Task
{
public:

	string name;
	int id;
	Task* next;
	Task* previous;
	Task* Dependencies;
	int NumOfDependentTasks;
	Resource* Resources;
	int start_time;
	int ES;
	int EF;
	int LS;
	int LF;
	int slack;
	int duration;
	bool forwardSet;
	bool backwardSet;

	Task* DependentTasks;
		
	Task()
	{
		NumOfDependentTasks = 0;
		forwardSet = false;
		backwardSet = false;
	}
	
};