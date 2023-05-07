#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "./static-list.h"

#define LIST_SIZE 10

struct list {
    int size;
    struct item items[LIST_SIZE];
};

bool isListFull(struct list *list);
bool isListEmpty(struct list *list);

struct list* buildList() {
    struct list *newList = (struct list*) malloc(sizeof(struct list));
    if (newList == NULL) {
        exit(1);
    }

    newList->size = 0;

    return newList;
}

int push(struct list *list, struct item item) {
    if (isListFull(list)) {
        return 1;
    }

    list->items[list->size] = item;
    list->size += 1;

    return 0;
}

bool isListFull(struct list *list) {
    if (list->size == LIST_SIZE) {
        return true;
    }
    
    return false;
}

int pop(struct list *list) {
    if (isListEmpty(list)) {
        return 1;
    }

    list->size -= 1;

    return 0;
}

bool isListEmpty(struct list *list) {
    if (list->size == 0) {
        return true;
    }

    return false;
}

int unshift(struct list *list, struct item item) {
    if (isListFull(list)) {
        return 1;
    }

    int i;
    for (i=list->size; i>0; i--) {
        list->items[i] = list->items[i-1];
    }

    list->items[0] = item;
    list->size += 1;

    return 0;
}

int shift(struct list *list) {
    if (isListEmpty(list)) {
        return 1;
    }

    int i;
    for (i=0; i<list->size; i++) {
        list->items[i] = list->items[i+1];
    }
    
    list->size -= 1;

    return 0;
}

struct item buildItem() {
    struct item item;
    printf("What is the item name? \n");
    setbuf(stdin, NULL);
    fgets(item.name, ITEM_NAME_SIZE, stdin);

    printf("What is the item description? \n");
    setbuf(stdin, NULL);
    fgets(item.description, ITEM_DESCRIPTION_SIZE, stdin);
    
    return item;
}


void printList(struct list *list) {
    int i;
    for (i=0; i<list->size; i++) {
        printf(":----------------------------------------:\n");
        printf("Item name: %s \n", list->items[i].name);
        printf("Item description: %s \n", list->items[i].description);
    }
    printf(":----------------------------------------:\n");
    printf("List size: %d \n", list->size);
    printf(":----------------------------------------:\n");
}