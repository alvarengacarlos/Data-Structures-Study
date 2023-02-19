#define LIST_SIZE 10
#define TASK_NAME_SIZE 50
#define TASK_DESCRIPTION_SIZE 255

typedef struct taskList TaskList;
typedef struct {
    char name[TASK_NAME_SIZE];
    char description[TASK_DESCRIPTION_SIZE];
} Task;

TaskList* buildTaskList();
int push(TaskList *list, Task task);
int pop(TaskList *list);
int unshift(TaskList *list, Task task);
int shift(TaskList *list);
int getListSize(TaskList *list);
Task buildTask();
void printTasksList(TaskList *list);