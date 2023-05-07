#include <stdio.h>
#include <stdlib.h>

#include "./static-list.h"

int main() {
    int option = 0;
    
    struct list *list = buildList();

    do {
        printf("0-Exit \n");
        printf("1-Add item in the end \n");
        printf("2-Remove last item \n");
        printf("3-Add item in the start \n");
        printf("4-Remove first item \n");
        printf("5-Print list \n");
        scanf("%d", &option);

        switch (option) {
            case 0:
                exit(0);
                break;
            case 1:
                push(list, buildItem());
                break;
            case 2:                
                pop(list);
                break;
            case 3:               
                unshift(list, buildItem());
                break;
            case 4:
                shift(list);
                break;
            case 5:
                printList(list);
                break;
        }
    } while(option);

    return 0;
}