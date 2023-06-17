#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "./binary-tree.h"

int main() {
  int option = 0;

  struct tree *tree = buildTree();
  
  do {
    puts("0-Exit");
    puts("1-Add a element");
    puts("2-Destroy tree");
    puts("3-Count nodes");
    puts("4-Get tree hight");
    puts("5-Pre order");
    puts("6-In order");
    puts("7-After order");
    puts("8-Remove Element");
    puts("9-Search Element");
    scanf("%d", &option);

    switch (option) {
      case 0:
        destroyTree(tree);
      break;    
      case 1:
        int newNumber = rand() % 40;
        printf("Random number: %d \n", newNumber);
        addChild(newNumber, tree);      
      break;
      case 2:
        destroyTree(tree);
      break;
      case 3:
        countNodes(tree);
      break;
      case 4:
        getHight(tree);
      break;        
      case 5:
        preOrder(tree);
      break;
      case 6:
        inOrder(tree);
      break;
      case 7:
        afterOrder(tree);
      break;
      case 8:
        puts("What is the element?");
        int element = 0;
        scanf("%d", &element);
        removeElement(element, tree);
      break;
      case 9:
        puts("What is the element?");
        int searchedElement = 0;
        scanf("%d", &searchedElement);
        searchElement(searchedElement, tree);
    }

  } while (option);

  return 0;
}