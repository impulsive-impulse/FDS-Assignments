#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int roll;
    char name[30];
    struct node *next;
}node;

node *create(int n)
{
    node *head, *p;
    head = (node *)malloc(sizeof(node));
    printf("\n\tEnter the roll no. and name:-\t");
    scanf("%d %s", &(head->roll), (head->name));
    head->next = NULL;
    p = head;
    for(int  i = 1; i < n; i++)
    {
        p->next = (node *)malloc(sizeof(node));
        p = p->next;
        printf("\n\tEnter the roll no. and name:-\t");
        scanf("%d %s", &(p->roll), (p->name));
        p->next = NULL;
    }
    return head;
}
void display(node *head)
{
    if(head == NULL)
    {
        printf("\n\tlist is empty\t");
        exit(0);
    }
    while(head!=NULL)
    {
        printf("%d %s\n", head->roll, head->name);
        head = head->next;
        printf("\n\t");
    }
    printf("\n\t");
}
node *insert(node *head, int r, char a[30], int pos)
{
    node *p, *q;
    p = (node *)malloc(sizeof(node));
    p->roll = r;    strcpy(p->name,a);
    p->next = NULL;
    if(pos == 1)
    {
        p -> next = head;
        return p;
    }
    q = head;
    for(int  i = 1; i < pos-1; i++)
        if(q!=NULL)
            q = q->next;
        else
        {
            printf("\n\tOVERFLOW\t");
            return head;
        }
    p->next = q->next;
    q->next = p;
    return head;
}    
node *delete(node *head,int loc)
{
    node *p, *q;
    if(loc == 1)
    {
        p = head;
        head = head->next;
        free(p);
        return head;
    }
    q = head;
    for(int i = 1; i < loc- 1; i++)
        q = q->next;
    if(q == NULL)
    {
        printf("\n\tUnderflow\t");
        return head;
    }
    p = q->next;
    q -> next = p -> next;
    free(p);
    return head;
}
void revese(node *head)
{
    if(head == NULL)
    {
        printf("\n\tlist is emplty\t");
        return;
    }
    revese(head->next);
    printf("%d %s\n", head->roll, head->name);
}
node *revert(node *head)
{
    node *p, *q, *r;
    p = NULL;   q = head; r = q->next;
    while(q!=NULL)
    {
        q->next = p;
        p = q;
        q = r;
        if(r != NULL)
        r = r->next;
    }
    return p;
}
int main()
{
    node *head = NULL;
    int ch,n,pos;
    int rollno;
    char names[30];
    do
    {
        printf("\n\t-----Singly Linked List-----\t");
        printf("\n\t1.Create Nodes\t");
        printf("\n\t2.Display All\t");
        printf("\n\t3.Insert\t");
        printf("\n\t4.Delete\t");
        printf("\n\t5.Display in Reverse\t");
        printf("\n\t6.Revert the list\t");
        printf("\n\t7.Exit!!!\t");
        printf("\n\tEnter your choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\n\tHow Manys Node you want to create:\t");
                    scanf("%d",&ch);
                    head = create(ch);
                    break;
            case 2: printf("\n\tDisplay All\n\t");
                    display(head);
                    break;
            case 3: printf("\n\tEnter the record you want to insert\t");
                    scanf("%d %s", &rollno, names);
                    printf("\n\tEnter the position where you want to insert\t");
                    scanf("%d",&pos);
                    head = insert(head,rollno,names,pos);
                    break;
            case 4: printf("\n\tEnter the location of node you want to delete:\t");
                    scanf("%d", &pos);
                    head = delete(head,pos);
                    break;
            case 5: printf("\n\tDisplay in Reverse\t");
                    revese(head);
                    break;
            case 6: printf("\n\tReverting The SLL\t");
                    head = revert(head);
                    break;
            default: printf("\n\tTermnating!!!!");
        }
    } while (ch!=7);
}