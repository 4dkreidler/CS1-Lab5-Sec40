#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char letter;
  struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
  int count=0; 
  while (head->next != NULL){
    head = head->next; 
    count++; 
  }
  return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{ 
  char* str = (char*)malloc((length(head)+1)*sizeof(char));
  int i=0; 
  while(head != NULL){
    str[i]= head->letter;
    head = head->next;
    i++;
  }
  str[i]='\0'; 
  return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
  if(*pHead == NULL){
    *pHead = (node*) malloc(sizeof(node));
    (*pHead)->letter= c; 
    (*pHead)->next= NULL; 
    return;
  }
  node* head = *pHead; 
  while ((head->next != NULL)){
    head = head->next; 
  }
  node *newNode = (node*)malloc(sizeof(node));  
  newNode->letter = c; 
  newNode->next = NULL;
  head->next = newNode; 
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
  node* head = *pHead;
  node* tmp = head;
  while(head != NULL){
    head = head->next; 
    free(tmp); 
    tmp = head; 
  }
  *pHead = NULL; 
}

int main(void)
{
  int i, strLen, numInputs;
  node* head = NULL;
  char* str;
  char c;
  FILE* inFile = fopen("input.txt","r");

  fscanf(inFile, " %d\n", &numInputs);

  while (numInputs-- > 0)
  {
    fscanf(inFile, " %d\n", &strLen);
    for (i = 0; i < strLen; i++)
    {
      fscanf(inFile," %c", &c);
      insertChar(&head, c);
    }

    str = toCString(head);
    printf("String is : %s\n", str);

    
    deleteList(&head);

    if (head != NULL)
    {
      printf("deleteList is not correct!");
      break;
    }
  }
  
  fclose(inFile);
}