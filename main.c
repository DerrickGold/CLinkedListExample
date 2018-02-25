#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODE_KEY_SIZE 256

struct Node {
  char key[NODE_KEY_SIZE];
  int value;
  struct Node *next;
};

struct Node *makeNode(char *key, int value) {
  struct Node *newNode = malloc(sizeof(struct Node));
  if (!newNode) {
    printf("Failed to allocate node\n");
    return NULL;
  }

  strncpy(newNode->key, key, NODE_KEY_SIZE);
  newNode->value = value;
  newNode->next = NULL;
  
  return newNode;
}

struct Node *findNode(struct Node *headNode, char *key) {
  struct Node *curNode = headNode;
  while (curNode && strncmp(curNode->key, key, NODE_KEY_SIZE)) {
    curNode = curNode->next;
  }
  return curNode;
}

void addNode(struct Node **headNode, struct Node *newNode) {
  if (!*headNode) {
    *headNode = newNode;
    return;
  }
  
  struct Node *curNode = *headNode;
  while(curNode->next) {
    curNode = curNode->next;
  }
  
  curNode->next = newNode;
}

void printLinkedList(struct Node *headNode) {
  struct Node *curNode = headNode;
  
  while(curNode) {
    printf("Key: %s, Value: %d\n", curNode->key, curNode->value);
    curNode = curNode->next;
  }
}

void main() {

  struct Node *listHead = NULL;
  char keyBuf[NODE_KEY_SIZE];
  int i;

  
  for (i = 0; i < 6; i++) {
    snprintf(keyBuf, NODE_KEY_SIZE, "nodekey_number:%d", i);
    struct Node *newNode = makeNode(keyBuf, i);
    addNode(&listHead, newNode);
    
  }

  printLinkedList(listHead);
}
