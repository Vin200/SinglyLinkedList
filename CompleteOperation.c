#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void Insert_At_Front(struct node **head_ref,int new_data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
    }
    else{
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    printf("Inserted Successfully!...\n");
}
void Insert_At_Givenposition(struct node **head_ref,int item,int new_data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    struct node *temp = *head_ref;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(temp != NULL){
        if(temp->data == item){
            new_node->next = temp->next;
            temp->next = new_node;
        }
        temp = temp->next;
    }
    printf("Inserted Successfully!....\n");
}
void append(struct node **head_ref,int new_data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *temp = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    printf("Inserted Successfully!...\n");
    return;
}
void deleteNode(struct node **head_ref, int key)
{
    struct node *temp = *head_ref, *prev;
    if(*head_ref == NULL){
        printf("The List is Empty can not be deleted!..\n");
        return;
    }
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    printf("The Element %d is deleted successfully!\n",key);
    free(temp);
}
void Display(struct node *head_ref){
    printf("\n");
    struct node *temp;
    temp = head_ref;
    if(temp == NULL){
        printf("The linked list is empty\n");
        return;
    }
    else{
            while(temp != NULL){
                printf("%d\n",temp->data);
                temp = temp->next;
            }
    }
}
int main()
{
   struct node *head = NULL;
   int choice,new_data,elem,choice1;
   int item;
   while(1){
      printf("!.........................MENU.........................!\n");
      printf("1.Insert\t2.Display\t3.Delete\t4.Exit\n");
      printf("Enter your choice\n");
      scanf("%d",&choice);
      if(choice == 1){
        printf("!.......Menu..........!\n");
        printf("1.Insert_At_Front\n2.Append\n3.At Given Position\n");
        printf("Enter Your Choice\n");
        scanf("%d",&choice1);
        switch(choice1){
        case 1:
            printf("Enter the element to insert at front: ");
            scanf("%d",&new_data);
            Insert_At_Front(&head,new_data);
            break;
        case 2:
            printf("Entert the element to insert at End: ");
            scanf("%d",&new_data);
            append(&head,new_data);
            break;
        case 3:
            printf("Enter The Linked List element,after which you can insert: ");
            scanf("%d",&item);
            printf("Enter Number to insert: ");
            scanf("%d",&new_data);
            Insert_At_Givenposition(&head,item,new_data);
            break;
        default:printf("Enter correct choice\n");
        }
      }
      switch(choice){
      case 2:
        Display(head);
        break;
      case 3:
        printf("Enter Element to Delete: ");
        scanf("%d",&elem);
        deleteNode(&head,elem);
        break;
      case 4:
        exit(0);
      }
   }
   return 0;
}
