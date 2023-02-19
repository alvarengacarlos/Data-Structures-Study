#include <stdio.h>
#include <stdlib.h>

#include "./static-list.h"
#include "../../util/status-code-util.h"

int main() {
    int option = 0;
    
    TaskList *taskList = buildTaskList();

    do {
        printf("0-Exit \n");
        printf("1-Push task \n");
        printf("2-Pop task \n");
        printf("3-Unshift task \n");
        printf("4-Shift task \n");
        printf("5-Print list \n");
        scanf("%d", &option);

        switch (option) {
            case 0:
                exit(SUCCESS);
                break;
            case 1:
                push(taskList, buildTask());
                break;
            case 2:                
                pop(taskList);
                break;
            case 3:               
                unshift(taskList, buildTask());
                break;
            case 4:
                shift(taskList);
                break;
            case 5:
                printTasksList(taskList);
                break;
        }
    } while(option);

    return SUCCESS;
}