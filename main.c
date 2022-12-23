#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

char *stack_undo[100];
char *stack_redo[100];
int top1=-1;
int top2=-1;
int i=0,l=0;

void write();
int push(char);
void undo();
void redo();
void read();
void text_editor_menu();
void main_menu();

int main()
{
  system("color 1f");
  main_menu();
  return 0;
}

void main_menu()
{
    int ch;
      printf("\n************************************************************************************************************************");
      printf("\n\t\t\t\t\tWELCOM TO TEXT EDITOR");
      printf("\n************************************************************************************************************************\n");
      getch();
      printf("\n1] OPEN EDITOR");
      printf("\n2] HELP");
      printf("\n3] EXIT");

      printf("\n\nYour choice: \t");
      scanf("%d",&ch);

      switch(ch)
      {
        case 1: text_editor_menu();
        break;

        case 2:
        break;

        case 3: printf("\n\n\n\t\tPROGRAM TERMINATED");
        exit(1);
      }

}

void text_editor_menu()
{
  int ch;
  while(1){
    printf("\n\n-----------------------------------------------");
    printf("\n\t\tMENU");
    printf("\n--------------------------------------------------");

    printf("\n1] Write");
    printf("\n2] Undo");
    printf("\n3] Redo");
    printf("\n4] Read");
    printf("\n5] Exit");
    printf("\nEnter choice from given : ");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1: write();
      break;

      case 2: undo();
      break;

      case 3: redo();
      break;

      case 4:  read();
      break;

      case 5:
      printf("\n\n\tProgram Terminated.");
      exit(0);

      default:
      printf("\nWrong Choice!!");
    }
  }
}


void write()
{
    char str[100];
    int m=0;
    char c;
    printf("\nEnter the string (press / to save) :");
    while(1)
    {
      c = getchar();
      if(c=='/')
      {
        break;
      }
      str[m] = c;
      m++;
    }
    str[m] = '\0';
    (stack_undo[++top1]) = strdup(str);
}

void undo()
{
    stack_redo[++top2] = stack_undo[top1--];
}

void redo()
{
    stack_undo[++top1] = stack_redo[top2--];
}

void read()
{
    int i=0;
    if(top1==-1)
    {
      printf("\nFile Empty!!");
      return;
    }
    while(1)
    {
    if(i>top1)
    break;
    printf(" %s",(stack_undo[i]));
    i++;
    }
}
