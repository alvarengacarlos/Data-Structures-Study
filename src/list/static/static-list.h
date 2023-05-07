#define ITEM_NAME_SIZE 50
#define ITEM_DESCRIPTION_SIZE 200

struct item {
    char name[ITEM_NAME_SIZE];
    char description[ITEM_DESCRIPTION_SIZE];
};

struct list* buildList();
int push(struct list*, struct item);
int pop(struct list *list);
int unshift(struct list*, struct item);
int shift(struct list*);
struct item buildItem();
void printList(struct list*);