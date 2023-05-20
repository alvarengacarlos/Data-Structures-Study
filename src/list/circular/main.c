#include <stdlib.h>
#include <stdio.h>

#include "./circular-list.h"

int main()
{
  int option = 0;

  struct list *list = buildList();
  int number = 1;

  do {
    puts("0-Exit");
    puts("1-Add a element in the end");
    puts("2-Remove the last element");
    puts("3-Add a element in the start");
    puts("4-Remove the first element");
    puts("5-Print the list");
    puts("6-Search element by position");
    puts("7-Search element");
    puts("8-Destroy all elements");
    scanf("%d", &option);

    switch (option) {
    case 0:
      destroyList(list);
      break;
    case 1:
      push(number++, list);
      break;
    case 2:
      pop(list);
      break;
    case 3:
      unshift(number++, list);
      break;
    case 4:
      shift(list);
      break;
    case 5:
      showList(list);
      break;
    case 6:
      int position = 1;
      scanf("%d", &position);
      searchElementByPosition(position, list);
      break;
    case 7:
      int element = 0;
      scanf("%d", &element);
      searchElement(element, list);
      break;
    case 8:
      destroyList(list);
      break;
    }

  } while (option);

  return 0;
}