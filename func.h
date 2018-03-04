#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct Node{
  struct Node *right;
  struct Node *left;
  char value[];
} Node;


struct Node* newNode(char newVal[]){
  Node *newNode= (Node*)malloc(sizeof(Node));
  strcpy(newNode->value,newVal);
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
};

void inOrder(struct Node* root){
  if(root != NULL){
    inOrder(root->left);
    printf("%s \n",root->value);
    inOrder(root->right);
  }
};



//iterative search function

void search(struct Node* root,char target[]){
  while(root != NULL){
    if (strcmp(target,root->value) == 0) {
      printf("%s is present in the tree \n", target);
      return;
    }
    if(strcmp(target,root->value) < 0){
      root = root->left;
    }
    if(strcmp(target, root->value) > 0){
      root = root->right;
    }
  }
  printf("%s is not present in the tree \n",target);
};


struct Node* add (struct Node* root, char value[]){
    if (root == NULL){
      root = newNode(value);
    }
    else if(strcmp(value,root->value) < 0){
      root->left = add(root->left,value);
    }
    else if(strcmp(value,root->value) == 0){
      printf("%s is already in the list \n",value);
    }
    else{
      root->right = add(root->right,value);
    }
    return root;
  };
