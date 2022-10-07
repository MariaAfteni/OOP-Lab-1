#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node*next;
};

struct node *new_list(int value){
    int i = 0;
    struct node *head =NULL;
    struct node *temp =NULL;
    struct node *p =NULL;

    for(i=0; i<value; i++){

        temp =  malloc(sizeof(struct node));
        scanf("%d", &(temp->value));
        temp->next = NULL;

        if(head == NULL) head = temp;
        else{
            p = head;
            while(p->next != NULL)
                p = p->next;
            p->next = temp;

        }
    }
    return head;
}

void display_list(struct node *head){
    struct node *p = head;
     while (p != NULL){
         printf("\t%d -> ", p->value);
         p = p->next;
     }
}

void add_to_end(struct node **head, int val){
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL){
        exit(1);
    }
    new_node->next = NULL;
    new_node->value = val;

    struct node *p = *head;
    while(p->next !=NULL){
        p = p->next;
    }
    p->next = new_node;
}

void add_to_head(struct node **head, int val){
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = val;
    new_node->next = *head;

    *head = new_node;
}

void reverse(struct node **head){
    struct node *prev = NULL;
    struct node *curr = *head;

    while(curr != NULL){
        struct node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

int main(){
  int n = 0;

    struct node *head = malloc(sizeof (struct node));
    int choice, choice2, l, a, s;
    struct node *tmp;
    struct node *tmp1;

    while(1){
        printf("\n1. Create linked list");
        printf("\n2. Display the linked list");
        printf("\n3. Append element to the linked list");
        printf("\n4. Prepend element to the linked list");
        printf("\n5. Reverse linked list");
        printf("\n6. Exit");
        printf("\nSelect: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Input the number of elements of linked list: ");
                scanf("%d", &n);
                printf("Input the elements of the linked list\n");
                head = new_list(n);
                break;
            case 2:
                printf("\n2. Display the linked list\n");
                display_list(head);
                printf("\n");
                break;

            case 3:
                printf("\n3. Append element to the linked list");
                printf("\nInput the element you want to append\n");
                n = 0;
                scanf("%d", &n);
                add_to_end(&head, n);
                break;

            case 4:
                printf("\n4. Prepend element to the linked list");
                printf("\nInput the element you want to add\n ");
                scanf("%d", &l);
                add_to_head(&head, l);
                break;

            case 5:
                printf("\n5. Reverse linked list");
                printf("\nReversed linked list\n");
                reverse(&head);
                display_list(head);
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid option");

        }
    }
  return 0;
}
