Certainly, here's a sample README file that explains how your system works:

---

# Project Management System

## Overview

The Project Management System is a software application designed to help users plan and manage their projects efficiently. It allows you to create a project, add resources, tasks, and dependencies, and calculate a basic project schedule using the Critical Path Method (CPM).

## Features

- **Adding Resources:** You can add resources to the project, each with specific skills and proficiency levels. Resources are essential for task allocation.

- **Adding Tasks:** You can add tasks to the project, along with their names, dependencies, start times, durations, and resource allocations. Tasks are the building blocks of your project.

- **Setting Task Duration:** You can modify the duration of all tasks in the project. This feature allows you to adjust the estimated time it takes to complete each task.

- **Setting Specific Task Duration:** If you need to change the duration of a specific task, you can use this feature to target a single task's duration.

- **Calculating Basic Schedule:** The system uses the Critical Path Method to calculate a basic schedule for your project. It identifies the critical path and helps you determine the earliest start time (ES), earliest finish time (EF), latest start time (LS), latest finish time (LF), and slack for each task.

## How to Use

1. **Adding Resources:**
   - Launch the application.
   - Select the option to add resources.
   - Enter the number of resources you want to add.
   - Provide the name, skill, and proficiency level for each resource.

2. **Adding Tasks:**
   - Select the option to add tasks.
   - Enter the number of tasks you want to add.
   - For each task, specify its name, dependencies (enter '0' to finish), start time, duration, and the resource to allocate.

3. **Setting Task Duration:**
   - Choose the option to set task duration.
   - Modify the duration of all tasks as needed.

4. **Setting Specific Task Duration:**
   - Select the option to set a specific task's duration.
   - Choose the task you want to change the duration for.
   - Enter the new duration.

5. **Calculating Basic Schedule:**
   - Use the option to calculate the basic project schedule.
   - The system will display the critical path and key scheduling information for each task.

## Known Issues

- Task dependencies may not be correctly handled in the provided code. Review the code and ensure proper linkage between tasks and their dependencies.

- Debugging may be required to identify and resolve any issues with resource allocation and task dependencies.

## Contributing

If you find any issues or want to contribute to the project, please submit a pull request or open an issue on the GitHub repository.
