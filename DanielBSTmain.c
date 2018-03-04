//CREATED BY Daniel Gomez
//in Colaboration with Sebastian Gonzalez
#include "functions.h"
#include <stdlib.h>
int main() {
  //create a new null root
  Node *root = NULL;
  FILE *file;
  
  //Memory allocation for name
  char fname[20];
  char inputname[20];
  int option;
  root = add(root,"Daniel");

  file = fopen("names.txt", "r");
  rewind(file);
  while(fscanf(file,"%s", fname)!= EOF){
    fscanf(file,"%s",fname);
    add(root, fname);
  }
  fclose(file);
 while(1){
   printf("select an option\n");
   printf("Press 1 to add an name\n");
   printf("Press 2 to display all name\n");
   printf("Press 0 to exit\n");
   printf("\n");
   scanf("%d",&option);
    if(option == 1){
      printf("Enter the employee's name\n");
      scanf("%s",name);
      add(root,name);
      printf("\n");        
   }
    else if(option == 2){
      printf("The employees are:\n");
      inOrder(root);
    }
    else if(option == 0){
      exit(1);
    }
    else{
      printf("Invalid input, try again.\n");
      printf("\n");
    }
  }
  return 0;
}
