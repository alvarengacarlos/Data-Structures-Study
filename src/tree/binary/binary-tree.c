#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "binary-tree.h"

struct node {
  int value;
  struct node *leftChild;
  struct node *rightChild;
};

struct tree {
  struct node *root;
};

int addChildRecursively(struct node*, struct node*);
bool isCreatedTree(struct tree*);
struct node* buildNode(int);
bool isCreatedNode(struct node*);
int destroyRecursively(struct node*);
int countRecursively(struct node*);
int getHightRecursively(struct node*);
int preOrderRecursively(struct node*);
int inOrderRecursively(struct node*);
int afterOrderRecursively(struct node*);
struct node* removeNode(struct node *node);

struct tree* buildTree() {
  struct tree *tree = (struct tree*) malloc(sizeof(struct tree));
  if (tree == NULL) {
    puts("binary-tree::buildTree::it is not possible alloc memory");
    exit(1);
  }

  tree->root = NULL;

  return tree;
}

int addChild(int value, struct tree *tree) {
  if (!isCreatedTree(tree)) {
    return 1;
  }
  
  struct node *node = buildNode(value);
  if (!isCreatedNode(node)) {
    return 1;
  }

  node->leftChild = NULL;
  node->rightChild = NULL;
  node->value = value;
  
  if (tree->root == NULL) {
    puts("binary-tree::addChildRecursively::is first node");

    tree->root = node;
    return 0;
  }
  puts("binary-tree::addChild::is not first node");

  return addChildRecursively(node, tree->root);
}

int addChildRecursively(struct node *newNode, struct node *root) {
  struct node *help = root;
  if (newNode->value > help->value && help->rightChild != NULL) {
    puts("binary-tree::addChildRecursively::accessing right child");

    addChildRecursively(newNode, help->rightChild);
  
  } else if (newNode->value < help->value && help->leftChild != NULL) {
    puts("binary-tree::addChildRecursively::accessing left child");

    addChildRecursively(newNode, help->leftChild);
  }

  if (newNode->value > help->value && help->rightChild == NULL) {
    puts("binary-tree::addChildRecursively::inserting a right child");

    help->rightChild = newNode;
    
    puts("binary-tree::addChildRecursively::success");
  
  } else if (newNode->value < help->value && help->leftChild == NULL) {
    puts("binary-tree::addChildRecursively::inserting a left child");

    help->leftChild = newNode;

    puts("binary-tree::addChildRecursively::success");
  }

  return 0;
}

bool isCreatedTree(struct tree *tree) {
  if (tree == NULL) {
    puts("binary-tree::isCreatedTree::the tree is not created");
    return false;
  }

  return true;
}

struct node* buildNode(int value) {
  struct node *node = (struct node*) malloc(sizeof(struct node));
  
  return node;
}

bool isCreatedNode(struct node *node) {
  if (node == NULL) {
    puts("binary-tree::isCreatedNode::the node is not created");
    return false;
  }

  return true;
}

int destroyTree(struct tree *tree) {
  puts("binary-tree::destroyTree::destroying tree");

  if (!isCreatedTree(tree)) {
    return 1;
  }
  
  destroyRecursively(tree->root);    
  tree->root = NULL;
  
  return 0;
}

int destroyRecursively(struct node *node) {
  struct node *help = node;

  if (help == NULL) {
    puts("binary-tree::destroyRecursively::is empty");

    return 0;
  }  

  puts("binary-tree::destroyRecursively::visiting a left node");
  destroyRecursively(help->leftChild);

  puts("binary-tree::destroyRecursively::visiting a right node");
  destroyRecursively(help->rightChild);

  puts("binary-tree::destroyRecursively::destroying a node");
  
  free(help);

  puts("binary-tree::destroyRecursively::success");

  return 0;
}

bool isEmptyTree(struct tree *tree) {
  if (!isCreatedTree(tree)) {
    return false;
  }
  
  if (tree->root == NULL) {
    return true;
  }

  return false;
}

int countNodes(struct tree *tree) {
  puts("binary-tree::countNodes::count nodes");
  
  if (!isCreatedTree(tree)) {
    return 1;
  }
  
  int result = countRecursively(tree->root);

  printf("Total nodes: %d \n", result);

  return 0;
}

int countRecursively(struct node *node) {
  struct node *help = node;

  if (help == NULL) {
    puts("binary-tree::countRecursively::is empty");

    return 0;
  }  

  puts("binary-tree::countRecursively::visiting a left node");
  int totalLeft = countRecursively(help->leftChild);

  puts("binary-tree::countRecursively::visiting a right node");
  int totalRight = countRecursively(help->rightChild);

  puts("binary-tree::countRecursively::success");

  return 1 + totalLeft + totalRight;
}

int getHight(struct tree *tree) {
  puts("binary-tree::getHight::count nodes");
  
  if (!isCreatedTree(tree)) {
    return 1;
  }
  
  int result = getHightRecursively(tree->root);

  printf("Tree hight: %d \n", result);

  return 0;
}

int getHightRecursively(struct node *node) {
  struct node *help = node;

  if (help == NULL) {
    puts("binary-tree::getHightRecursively::is empty");

    return 0;
  }

  puts("binary-tree::getHightRecursively::visiting a left node");
  int totalLeft = getHightRecursively(help->leftChild);

  puts("binary-tree::getHightRecursively::visiting a right node");
  int totalRight = getHightRecursively(help->rightChild);

  puts("binary-tree::getHightRecursively::success");

  if (totalLeft > totalRight) {
    return 1 + totalLeft;
  }
  
  return 1 + totalRight;
}

int preOrder(struct tree *tree) {
  puts("binary-tree::preOrder::printing values");

  if (!isCreatedTree(tree)) {
    return 1;
  }
  
  preOrderRecursively(tree->root);

  printf("\n");
  
  return 0;
}

int preOrderRecursively(struct node *node) {
  struct node *help = node;

  if (help == NULL) {
    puts("binary-tree::preOrderRecursively::is empty");

    return 0;
  }  

  printf("%d ", help->value);

  puts("binary-tree::preOrderRecursively::visiting a left node");
  preOrderRecursively(help->leftChild);

  puts("binary-tree::preOrderRecursively::visiting a right node");
  preOrderRecursively(help->rightChild);

  puts("binary-tree::preOrderRecursively::success");

  return 0;
}

int inOrder(struct tree *tree) {
  puts("binary-tree::inOrder::printing values");

  if (!isCreatedTree(tree)) {
    return 1;
  }
  
  inOrderRecursively(tree->root);

  printf("\n");
  
  return 0;
}

int inOrderRecursively(struct node *node) {
  struct node *help = node;

  if (help == NULL) {
    puts("binary-tree::inOrderRecursively::is empty");

    return 0;
  }  

  puts("binary-tree::inOrderRecursively::visiting a left node");
  inOrderRecursively(help->leftChild);
  
  printf("%d ", help->value);

  puts("binary-tree::inOrderRecursively::visiting a right node");
  inOrderRecursively(help->rightChild);

  puts("binary-tree::inOrderRecursively::success");

  return 0;
}

int afterOrder(struct tree *tree) {
  puts("binary-tree::afterOrder::printing values");

  if (!isCreatedTree(tree)) {
    return 1;
  }
  
  afterOrderRecursively(tree->root);

  printf("\n");
  
  return 0;
}

int afterOrderRecursively(struct node *node) {
  struct node *help = node;

  if (help == NULL) {
    puts("binary-tree::afterOrderRecursively::is empty");

    return 0;
  }  

  puts("binary-tree::afterOrderRecursively::visiting a left node");
  afterOrderRecursively(help->leftChild);  

  puts("binary-tree::afterOrderRecursively::visiting a right node");
  afterOrderRecursively(help->rightChild);

  printf("%d ", help->value);

  puts("binary-tree::afterOrderRecursively::success");

  return 0;
}

int removeElement(int value, struct tree *tree) {
  if (!isCreatedTree(tree)) {
    return 1;
  }

  if (tree->root == NULL) {
    puts("binary-tree::removeElement::there are not elements");
    return 0;
  }
    
  struct node *help1 = tree->root;
  struct node *help2 = NULL;
  while(help1 != NULL) {
    if (help1->value == value && help1 == tree->root) {
      tree->root = removeNode(help1);
      puts("binary-tree::removeElement::success");
      return 0;    
    
    } else if (help1->value == value && help2->rightChild == help1) {
      help2->rightChild = removeNode(help1);
      puts("binary-tree::removeElement::success");
      return 0;    
    
    } else if (help1->value == value && help2->leftChild == help1) {
      help2->leftChild = removeNode(help1);        

      puts("binary-tree::removeElement::success");
      return 0;    
    }

    help2 = help1;
    if (value > help1->value) {
      help1 = help1->rightChild;
    } else {
      help1 = help1->leftChild;
    }
  }
  
  puts("binary-tree::removeElement::element does not exist");

  return 1;
}

struct node* removeNode(struct node *node) {
  struct node *help1, *help2;

  if (node->leftChild == NULL) {
    help1 = node->rightChild;
    free(node);
    return help1;
  }

  help1 = node;
  help2 = node->leftChild;
  while (help2->rightChild != NULL) {
    help1 = help2;
    help2 = help2->rightChild;
  }

  if (help1 != node) {
    help1->rightChild = help2->leftChild;
    help2->leftChild = node->leftChild;
  }

  help2->rightChild = node->rightChild;
  free(node);
  return help2;
}

int searchElement(int value, struct tree* tree) {
  if (!isCreatedTree(tree)) {
    return 1;
  }

  if (tree->root == NULL) {
    puts("binary-tree::searchElement::there are not elements");
    return 0;
  }
  
  struct node *help1 = tree->root;
  while (help1 != NULL) {
    if (help1->value == value) {
      puts("binary-tree::searchElement::element exists");     
      return 0;
    }

    if (value > help1->value) {
      help1 = help1->rightChild;
    } else {
      help1 = help1->leftChild;
    }
  }

  puts("binary-tree::searchElement::element does not exist"); 
  return 1;
}