#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "./dynamic-list.h"

//private functions
bool isCreatedList(struct list*);
struct node* buildNode(int);
bool isCreatedNode(struct node*);
bool isEmptyList(struct list*);

struct node {    
  int number;
  struct node *next;
};

struct list {
  struct node *head;
  int size;
};

struct list* buildList() {
  puts("dynamic-list::buildList::creating list");

  struct list *list = (struct list*) malloc(sizeof(struct list));
  
  if (list == NULL) {
    puts("dynamic-list::buildList::it is not possible alloc memory");
    exit(1);
  }

  list->head = NULL;
  list->size = 0;

  puts("dynamic-list::buildList::created with success");
  return list;
}

int push(int number, struct list *list) {
  puts("dynamic-list::push::adding element at last position");

  if (!isCreatedList(list)) {
    return 1;
  }
  
  struct node *node = buildNode(number);
  if (!isCreatedNode(node)) {
    return 1;
  }

  if (list->size == 0) {
    puts("dynamic-list::push::is first element");

    list->head = node;
    list->size++;

    puts("dynamic-list::push::added with success");
    return 0;
  }

  puts("dynamic-list::push::is not first element");
  struct node *help = list->head;
  while (help->next != NULL) {
    help = help->next;
  }
  
  help->next = node;
  list->size++;

  puts("dynamic-list::push::added with success");
  return 0;
}

bool isCreatedList(struct list *list) {
  if (list == NULL) {
    puts("dynamic-list::isCreatedList::the list is not created");
    return false;
  }

  return true;
}

struct node* buildNode(int number) {
  puts("dynamic-list::buildNode::creating node");

  struct node *node = (struct node*) malloc(sizeof(struct node));
  if (node != NULL) {
    node->number = number;
    node->next = NULL;    
  }

  puts("dynamic-list::buildNode::created with success");
  return node;
}

bool isCreatedNode(struct node *node) {
  if (node == NULL) {
    puts("dynamic-list::isCreatedNode::it is not possible alloc memory");
    return false;
  }

  return true;
}

int unshift(int number, struct list *list) {
  puts("dynamic-list::unshift::adding element at first position");

  if (!isCreatedList(list)) {
    return 1;
  }
  
  struct node *node = buildNode(number);
  if (!isCreatedNode(node)) {
    return 1;
  }
  
  node->next = list->head;
  list->head = node;
  list->size++;

  puts("dynamic-list::unshift::added with success");
  return 0;
}

int pop(struct list *list) {
  puts("dynamic-list::pop::removing last element");

  if (!isCreatedList(list)) {
    return 1;
  }

  if (isEmptyList(list)) {
    return 1;
  }

  if (list->size == 1) {
    puts("dynamic-list::pop::it is first element");

    free(list->head);
    list->head = NULL;
    list->size--;
    return 0;
  }

  puts("dynamic-list::pop::it is not first element");
  struct node *help1 = list->head;
  struct node *help2 = list->head;
  while (help1->next != NULL) {
    help2 = help1;
    help1 = help1->next;    
  }
  
  free(help1);
  help2->next = NULL;
  list->size--;

  puts("dynamic-list::pop::removed with success");
  return 0;
}

int shift(struct list *list) {
  puts("dynamic-list::shift::removing first element");

  if (!isCreatedList(list)) {
    return 1;
  }

  if (isEmptyList(list)) {
    return 1;
  }

  struct node *help = list->head;
  list->head = help->next;
  
  free(help);  
  list->size--;

  puts("dynamic-list::shift::removed with success");
  return 0;
}

bool isEmptyList(struct list *list) {
  if (list->size == 0) {
    puts("dynamic-list::isEmptyList::empty list");
    return true;
  }

  return false;
}

int showList(struct list *list) {
  if (!isCreatedList(list)) {
    return 1;
  }

  if (isEmptyList(list)) {
    return 0;
  }

  struct node *help = list->head;
  while (help != NULL) {
    printf("Value: %d \n", help->number);
    help = help->next;
  }

  return 0;
}

int searchElementByPosition(int position, struct list *list) {
  puts("dynamic-list::searchElementByPosition::searching in the list");

  if (!isCreatedList(list)) {
    return 1;
  }

  if (isEmptyList(list)) {
    return 0;
  }

  if (position > list->size) {
    puts("dynamic-list::searchElementByPosition::position does not exist");
    return 1;
  }

  struct node *help = list->head;
  int i = 1;
  while(i != position) {
    help = help->next;
    i++;
  }
  
  printf("It is your element: %d \n", help->number);

  puts("dynamic-list::searchElementByPosition::searched with success");

  return 0;
}

int searchElement(int element, struct list *list) {
  puts("dynamic-list::searchElement::searching element in the list");

  if (!isCreatedList(list)) {
    return 1;
  }

  if (isEmptyList(list)) {
    return 0;
  }
  
  bool isFound = false;
  if (element == list->head->number) {
    isFound = true;
  }

  struct node *help = list->head;
  while(isFound == false && help->next != NULL) {    
    help = help->next;
    if (help->number == element) {
      isFound = true;
    }
  }
  
  if (isFound == false) {
    puts("dynamic-list::searchElement::element does not found");
    return 0;
  }

  printf("It is your element: %d \n", help->number);
  
  puts("dynamic-list::searchElement::searched element in the list");

  return 0;
}

int destroyList(struct list *list) {
  puts("dynamic-list::destroyList::destroying list");

  if (!isCreatedList(list)) {
    return 1;
  }

  if (isEmptyList(list)) {
    return 0;
  }

  struct node *help = list->head;
  int i = 1;
  while(help->next != NULL) {
    printf("dynamic-list::destroyList::removing %d element from list \n", i);    
    list->head = help->next;
    free(help);
    help = list->head;
    list->size--;
    i++;
    puts("dynamic-list::destroyList::removed with success");
  }
  
  printf("dynamic-list::destroyList::removing %d element from list \n", i);  
  free(list->head);
  list->size--;
  list->head = NULL;
  puts("dynamic-list::destroyList::removed with success");

  puts("dynamic-list::destroyList::destroyed with success");
  
  return 0;
}