#pragma once
//Muhammad_Uzair_Choudhary_22i2681
#include<iostream>
#include<Windows.h>
#include"Resource.h"
#include"Task.h"
using namespace std;

int skillId = 0;
int taskId = 0;

class Project
{
public:
    int id;

    Resource* resources;
    Task* tasks;
    float duration;

    Project()
    {
        int skillId = 0;
        int taskId = 0;
        id = 1;
        resources = NULL;
        tasks = NULL;
        duration = 0;
    }

    // Function to create a new project
    Task* newProject(Task* tasks, Resource* resources)
    {
        int NumOfResources;
        int NumOfTasks;
        int temp;

        cout << "Enter the number of Resources for this project:\n";
        cin >> NumOfResources;

        resources = new Resource();
        Resource* resourcesHead = resources; // Pointer to the head of the resources list
        int skillId = 0;

        for (int i = 1; i <= NumOfResources; i++) {
            cout << "Enter the name of the Skill possessed by Resource " << i << "\n";
            resources->skill = new Skill();
            cin >> resources->skill->name;

            cout << "Enter the proficiency level of this skill (between 0.1 & 2): \n";
            cin >> resources->skill->Proficiency;

            resources->skill->id = ++skillId;
            resources->id = skillId; // Assigning the same ID to the resource

            resources->next = new Resource();
            resources = resources->next;
        }

        resources = resourcesHead; // Resetting resources to the beginning

        cout << "Enter the number of Tasks for this project:\n";
        cin >> NumOfTasks;

        tasks = new Task();
        tasks = nullptr;
        Task* head = nullptr;
        int taskId = 0;

        for (int i = 1; i <= NumOfTasks; i++) {
            Task* newTask = new Task();
            newTask->id = ++taskId;
            cout << "Enter the name of Task " << i << "\n";
            cin >> newTask->name;

            cout << "Enter this task's dependencies (press 0 when done)\n";
            cin >> temp;
            newTask->Dependencies = nullptr;

            Task* prevDep = nullptr;

            while (temp != 0) 
            {
                Task* newDep = new Task();
                newDep->id = temp;

                if (newTask->Dependencies == nullptr) 
                {
                    newTask->Dependencies = newDep;
                }
                else 
                {
                    // Finding the last dependency and add the new one to the end
                    Task* lastDep = newTask->Dependencies;
                    while (lastDep->next != nullptr) 
                    {
                        lastDep = lastDep->next;
                    }
                    lastDep->next = newDep;
                }
                prevDep = newDep;

                cout << "Enter this task's dependencies (press 0 when done)\n";
                cin >> temp;
            }

            newTask->start_time = 0; // Initializing to 0

            if (newTask->Dependencies == nullptr) 
            {
                cout << "Enter the start time for this task:\n";
                cin >> newTask->start_time;
            }

            cout << "Enter the duration (in days) for this task:\n";
            cin >> newTask->duration;

            cout << "Enter the resource ID you want to allocate to this task  " << "\n";
            cin >> temp;

            Resource* allocatedResource = resourcesHead;
            while (allocatedResource && allocatedResource->id != temp) 
            {
                allocatedResource = allocatedResource->next;
            }

            if (allocatedResource) 
            {
                newTask->Resources = allocatedResource;
            }
            

            newTask->next = nullptr;

            if (tasks == nullptr) {
                tasks = newTask;
                head = tasks;
            }
            else {
                tasks->next = newTask;
                tasks = tasks->next;
            }
        }

        tasks = head;

        return tasks;
    }
    
    void menu(Task* tasks, Resource* resources, Task* head)
    {
        system("CLS");
        int input;
        cout << "\t\t\tCongratulations!!! Your Project has successfully been recorded...\n\n\n";
        cout << "\t\t\tYou can perform the following functions:\n";
        cout << "\t\t\t1.Add Resources to the Project\n\t\t\t2.Add Tasks to the Project\n\t\t\t3.Change Duration for all Tasks\n\t\t\t4.Change the Duration for a Specic Task\n\t\t\t5.Print Task Dependency List\n\t\t\t6.Calculate Basic Schedule\n\t\t\t7.Print Critical Tasks\n\t\t\t8.Calculate Completion Time with Resources\n\t\t\t9.Calculate Completion Time with Resource Proficiency\n\n\t\t\t";

        cin >> input;

        switch (input)
        {
        case 1:
            addResources(resources, skillId);
            Sleep(2000);
            system("CLS");
            menu(tasks, resources, head);
            break;

        case 2:
            addTasks(tasks, taskId);
            Sleep(2000);
            system("CLS");
            menu(tasks, resources, head);
            break;

        case 3:
            setTaskDuration(tasks);
            Sleep(2000);
            system("CLS");
            menu(tasks, resources, head);
            break;

        case 4:
            set_nth_TaskDuration(tasks, taskId);
            Sleep(2000);
            system("CLS");
            menu(tasks, resources, head);
            break;

        case 5:
            printTaskDependencyList(head);
            Sleep(2000);
            system("CLS");
            menu(tasks, resources, head);
            break;

        case 6:
            calculateBasicSchedule(head);
            Sleep(2000);
            system("CLS");
            menu(tasks, resources, head);
            break;

        case 7:
            printCriticalTasks();
            Sleep(2000);
            system("CLS");
            menu(tasks, resources, head);
            break;

        case 8:
            completionTimeWithResources();
            Sleep(2000);
            system("CLS");
            menu(tasks, resources, head);
            break;

        case 9:
            completionTimeWithResourceProficiency();
            Sleep(2000);
            system("CLS");
            menu(tasks, resources, head);
            break;

        default:
            cout << "Wrong Input. Enter Again";
            Sleep(2000);
            system("CLS");
            menu(tasks, resources, head);
            break;
        }

        
    }

    void addResources(Resource* resources, int skillId) {
        Resource* newResource = new Resource();
        newResource->id = ++skillId;

        cout << "Enter the name of the skill possessed by the resource:\n";
        cin >> newResource->skill->name;

        cout << "Enter the proficiency level of this skill (between 0.1 & 2):\n";
        cin >> newResource->skill->Proficiency;

        newResource->next = resources;
        resources = newResource;
    }


    void addTasks(Task* tasks, int taskId) {
        Task* newTask = new Task();
        newTask->id = ++taskId;

        cout << "Enter the name of the task:\n";
        cin >> newTask->name;

        cout << "Enter the start time for this task:\n";
        cin >> newTask->start_time;

        cout << "Enter the number of dependencies for this task (press 0 when done):\n";
        int temp;
        cin >> temp;
        newTask->Dependencies = nullptr;

        Task* prevDep = nullptr;

        while (temp != 0) {
            Task* newDep = new Task();
            newDep->id = temp;

            if (newTask->Dependencies == nullptr) {
                newTask->Dependencies = newDep;
            }
            else {
                prevDep->next = newDep;
            }
            prevDep = newDep;

            cout << "Enter this task's dependencies (press 0 when done):\n";
            cin >> temp;
        }

        cout << "Enter the duration (in days) for this task:\n";
        cin >> newTask->duration;

        newTask->next = tasks;
        tasks = newTask;
    }


    void setTaskDuration(Task* tasks) {
        int newDuration;

        cout << "Enter the new duration (in days) for all tasks:\n";
        cin >> newDuration;

        Task* currentTask = tasks;
        while (currentTask) {
            currentTask->duration = newDuration;
            currentTask = currentTask->next;
        }
    }

    
    void set_nth_TaskDuration(Task* tasks, int taskId) {
        int newDuration;
        cout << "Enter the new duration (in days) for task with ID " << taskId << ":\n";
        cin >> newDuration;

        Task* currentTask = tasks;
        while (currentTask) {
            if (currentTask->id == taskId) {
                currentTask->duration = newDuration;
                break;
            }
            currentTask = currentTask->next;
        }
    }


    void printTaskDependencyList(Task* head) 
    {
        Task* temp = head;
            cout << "Tasks\tDependencies\n";
            while (temp) {
                cout << temp->id << "\t";
                Task* dep = temp->Dependencies;
                while (dep) {
                    cout << dep->id << " ";
                    dep = dep->next;
                }

                temp = temp->next;
                cout << "\n";

            }
        
    }

    void printCriticalTasks()
    {

    }
    
    void completionTimeWithResources()
    {

    }

    void completionTimeWithResourceProficiency()
    {

    }


    void calculateBasicSchedule(Task* head)
    {
        forwardPass(head);

        backwardPass(head);

        printBasicSchedule(head);
        
    }

    void forwardPass(Task* head)
    {
        Task* Current = head;

        while (Current != NULL && !Current->forwardSet)
        {
            if (Current->NumOfDependentTasks != 0)
            {
                Task* Dependencies = Current->Dependencies;
                setDependencies(Dependencies);
                Current->ES = maxEF(Dependencies);
                Current->EF = Current->ES + Current->duration;
                Current->forwardSet = true;
            }
            else
            {
                Current->ES = Current->start_time;
                Current->EF = Current->ES + Current->duration;
                Current->forwardSet = true;
            }
            Current = Current->next;
        }
    }

    void setDependencies(Task* task)
    {
        Task* temp = task;
        if (temp->NumOfDependentTasks == 0)
        {
            temp->ES = temp->start_time;
            temp->EF = temp->ES + temp->duration;
            temp->forwardSet = true;
            setDependencies(temp->next);
            return;
            
        }
        else
        {
            if(temp->Dependencies)
                setDependencies(temp->Dependencies);

            return;
        }
        
    }
    

    int maxEF(Task* Dependencies)
    {
        Task* DepTask = Dependencies;
        int max = DepTask->EF;
        while (DepTask)
        {
            if (DepTask->EF > max)
            {
                max = DepTask->EF;
            }
            DepTask = DepTask->next;
        }

        return max;

    }


    void backwardPass(Task* head)
    {
        setLastTasks(head);


    }

    void setLastTasks(Task* head)
    {
        Task* currentTask = head;
        Task* lastTasks = nullptr; // Initialize the linked list for tasks with no dependencies
        Task* lastTasksTail = nullptr;

        while (currentTask) {
            bool isDependedUpon = false; // Initialize the flag to check if the task is depended upon by other tasks
            Task* checkTask = head;

            // First loop: Iterate through all tasks to find out if the currentTask is depended upon
            while (checkTask) {
                if (checkTask != currentTask) {
                    Task* dependency = checkTask->Dependencies;

                    // Second loop: Check if the current task is a dependency for any other task (checkTask)
                    while (dependency) {
                        if (dependency == currentTask) {
                            isDependedUpon = true;
                            break; // We found that the current task is depended upon, no need to check further
                        }
                        dependency = dependency->next;
                    }
                }

                if (isDependedUpon) {
                    break; // No need to check further for the currentTask, as it's depended upon
                }

                // This is where you add the task to LastTasks if it's not depended upon
                if (!isDependedUpon) {
                    if (lastTasks == nullptr) {
                        lastTasks = currentTask;
                        lastTasksTail = currentTask;
                    }
                    else {
                        lastTasksTail->next = currentTask;
                        lastTasksTail = currentTask;
                    }
                }

                checkTask = checkTask->next;
            }
        }


        // Finding the maximum EF among all the tasks which are not dependent upon by other tasks & assigning the maximum value to LF of all those tasks
        {
            Task* temp = lastTasks;
            int max = temp->EF;

            while (temp)
            {
                if (temp->EF > max)
                {
                    max = temp->EF;
                }
                temp = temp->next;
            }
            temp = lastTasks;

            while (temp)
            {
                temp->LF = max;
                temp->LS = temp->LF - temp->duration;
                temp->slack = temp->LF - temp->EF;
                temp->backwardSet = true;
                temp = temp->next;
            }
        }
        

        // Now Finding those tasks, which do not depend on other tasks, then we will check for those tasks which depend on the tasks which we identify. If those tasks have backwardSet = true, then we can set the backward of those tasks too. Else, we will look for tasks which are dependent on those tasks and so on...

        currentTask = head;
        Task* firstTasks = nullptr;
        Task* firstTasksTail = nullptr;

        while (currentTask)
        {
            if (currentTask->NumOfDependentTasks == 0)
            {
                if (firstTasks == nullptr)
                {
                    firstTasks = currentTask;
                    firstTasksTail = currentTask;
                }
                else
                {
                    firstTasksTail->next = currentTask;
                    firstTasksTail = firstTasksTail->next;
                }
            }
        }


        currentTask = firstTasks;
        Task* toFirstTask = firstTasks;
        while (toFirstTask)
        {
            toFirstTask->DependentTasks = collectDependentTasks(head, toFirstTask);

            setBackward(head, toFirstTask);
            
            toFirstTask = toFirstTask->next;
        }


    }

    Task* collectDependentTasks(Task* head, const Task* specificTask) {
        Task* dependentTasks = nullptr; // Initialize the linked list for dependent tasks
        Task* dependentTasksTail = nullptr;
        Task* currentTask = head;

        while (currentTask) {
            Task* dependency = currentTask->Dependencies;

            // Iterate through the dependencies of the current task
            while (dependency) {
                if (dependency == specificTask) {
                    // The current task depends on the specific task
                    // Add the current task to the list of dependent tasks
                    if (dependentTasks == nullptr) {
                        dependentTasks = currentTask;
                        dependentTasksTail = currentTask;
                    }
                    else {
                        dependentTasksTail->next = currentTask;
                        dependentTasksTail = currentTask;
                    }
                    break; // No need to check further for this current task
                }

                dependency = dependency->next;
            }

            currentTask = currentTask->next;
        }

        // The linked list dependentTasks now contains tasks that depend on the specific task
        return dependentTasks;
    }

    void setBackward(Task* head, Task* task)
    {
        Task* currentTask = head;
        Task* dep = task->DependentTasks;

        while (dep)
        {
            if(!dep->backwardSet)
            { 
                setBackward(head, dep->DependentTasks);
                dep = dep->next;
            }
            else
            {
                dep = dep->next;
            }
        }
        dep = task;
        task->LF =  minLS(dep);
        task->LS = task->LF - task->duration;
        task->slack = task->LF - task->EF;
        task->backwardSet = true;

        return;
    }

    int minLS(Task* dep)
    {
        Task* temp = dep;
        int min = temp->LS;

        while (temp)
        {
            if (temp->LS < min) 
            {
                min = temp->LS;
            }
        }

        return min;
    }


    void printBasicSchedule(Task* head)
    {
        Task* temp = head;

        cout <<"Basic Schedule:\n";
        cout << "ID\tES\tEF\tLS\tLF\tslac\t";

        while (temp)
        {
            cout << temp->id << "\t" << temp->ES << "\t" << temp->EF << "\t" << temp->LS << "\t" << temp->LF << "\t" << temp->slack << "\n";
            temp = temp->next;
        }
    }
};