#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "./static-list.h"
#include "../../util/status-code-util.h"

bool isListFull(TaskList *taskList);
bool isListEmpty(TaskList *taskList);

struct taskList {
    int length;
    Task tasks[LIST_SIZE];
};

TaskList* buildTaskList() {
    TaskList *newList = (TaskList*) malloc(sizeof(TaskList));
    if (newList == NULL) {
        exit(ERROR);
    }

    newList->length = 0;

    return newList;
}

int push(TaskList *taskList, Task task) {
    if (isListFull(taskList)) {
        return ERROR;
    }

    taskList->tasks[taskList->length] = task;
    taskList->length += 1;

    return SUCCESS;
}

bool isListFull(TaskList *taskList) {
    if (taskList->length == LIST_SIZE) {
        return true;
    }
    
    return false;
}

int pop(TaskList *taskList) {
    if (isListEmpty(taskList)) {
        return ERROR;
    }

    taskList->length -= 1;

    return SUCCESS;
}

bool isListEmpty(TaskList *taskList) {
    if (taskList->length == 0) {
        return true;
    }

    return false;   
}

int unshift(TaskList *taskList, Task task) {
    if (isListFull(taskList)) {
        return ERROR;
    }

    for (int i=taskList->length; i>0; i--) {
        taskList->tasks[i] = taskList->tasks[i-1];
    }

    taskList->tasks[0] = task;
    taskList->length += 1;

    return SUCCESS;
}

int shift(TaskList *taskList) {
    if (isListEmpty(taskList)) {
        return ERROR;
    }

    for (int i=0; i<taskList->length; i++) {
        taskList->tasks[i] = taskList->tasks[i+1];
    }
    
    taskList->length -= 1;

    return SUCCESS;
}

Task buildTask() {
    Task task;
    printf("What is the task name? \n");
    setbuf(stdin, NULL);
    fgets(task.name, TASK_NAME_SIZE, stdin);

    printf("What is the task description? \n");
    setbuf(stdin, NULL);
    fgets(task.description, TASK_DESCRIPTION_SIZE, stdin);
    
    return task;
}


void printTasksList(TaskList *taskList) {
    for (int i=0; i<taskList->length; i++) {
        printf(":----------------------------------------:\n");
        printf("Task name: %s \n", taskList->tasks[i].name);
        printf("Task description: %s \n", taskList->tasks[i].description);
    }
    printf(":----------------------------------------:\n");
    printf("Task list size: %d \n", getListSize(taskList));
    printf(":----------------------------------------:\n");
}

int getListSize(TaskList *taskList) {
    return taskList->length;
}