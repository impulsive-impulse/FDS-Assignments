#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct polynomial
{
    int coeff;
    int exp;
    struct polynomial* next;
}poly;
poly * create(poly *last,int coeff,int exp)
{
   // printf("hi ");
    poly *temp=NULL,*new_node=NULL;
    if(last==NULL)
    {
        last=(poly*)malloc(sizeof(poly));
        last->coeff=coeff;
        last->exp=exp;
        last->next=last;
        return last;
    }
    else if(exp>last->next->exp)
    {
        new_node=(poly*)malloc(sizeof(poly));
        new_node->coeff=coeff;
        new_node->exp=exp;
        new_node->next=last->next;
        last->next=new_node;

    }
    else if(exp<last->exp)
    {
        new_node=(poly*)malloc(sizeof(poly));
        new_node->coeff=coeff;
        new_node->exp=exp;
        new_node->next=last->next;
        last->next=new_node;
        last=last->next;
    }
    else
    {
        poly * prev=last;
        temp=last->next;
        do
        {
            if(exp==temp->exp)
            {
                temp->coeff+=coeff;
                return last;

            }
            else if(exp>temp->exp)
            {

                new_node=(poly*)malloc(sizeof(poly));
                new_node->coeff=coeff;
                new_node->exp=exp;
                prev->next=new_node;
                new_node->next=temp;
                return last;
            }
            prev=temp;
            temp=temp->next;
        }while(temp!=last->next);

    }
   /* new_node=(poly*)malloc(sizeof(poly));
    new_node->coeff=coeff;
    new_node->exp=exp;
    new_node->next=last->next;
    last=last->next;*/

    return last;
}
int Eval(poly* p)
{
            poly *temp=p->next;
            int x;
            int sum=0,Coef,Exp;
            printf("\n Enter the value of variable x : ");
            scanf("%d",&x);

            do
            {
                        Coef=temp->coeff;
                        Exp=temp->exp;
                        sum=sum+Coef*pow(x,Exp);
                        temp = temp->next;
            }while ( temp!= p->next);

            return(sum);
}
void display(poly * last)
{
   // printf("hi ");
   if(last==NULL)
   {
        printf("('.')sorry liat is empty");
       return ;
   }
    poly *start=last->next,*temp=last->next;
    while(temp->next!=start)
    {


        printf("%d*x^%d + ",temp->coeff,temp->exp);
        temp=temp->next;
    }
     printf("%d*x^%d",last->coeff,last->exp);
}
poly *add(poly *p1,poly* p2)
{
    poly * p3=NULL,*temp1=p1->next,*temp2=p2->next;
    do
    {
        p3=create(p3,temp1->coeff,temp1->exp);
        temp1=temp1->next;

    }while(temp1!=p1->next);
    display(p3);
    printf("hi   *");
    do
    {
        p3=
        create(p3,temp2->coeff,temp2->exp);
        temp2=temp2->next;

    }while(temp2!=p2->next);
    return p3;
}
poly *multi(poly *p1,poly * p2)
{
    poly *p3=NULL;
    if(p1==NULL || p2==NULL)
    {
        printf("('_') LIST IS EMPTY\n");
        return p3;
    }
    poly *temp1=p1->next,*temp2=p2->next,*new_node,*start3;

    do
    {
        do
        {
            int exp=temp1->exp+temp2->exp;
            int coeff=temp1->coeff*temp2->coeff;

            if(p3==NULL){
                    p3=(poly*)malloc(1*sizeof(poly));
                    p3->coeff=coeff;
                    p3->exp=exp;
                    p3->next=p3;
                }
                else{
                start3=p3->next;
                new_node=(poly*)malloc(1*sizeof(poly));
                new_node->next=start3;
                new_node->coeff=coeff;
                new_node->exp=exp;
                p3->next=new_node;
                p3=p3->next;
                }


            temp2=temp2->next;
        }while(temp2!=p2->next);
        temp1=temp1->next;
    }while(temp1!=p1->next);
    poly *p4=NULL,*temp3=p3->next;
    do
    {
        p4=create(p4,temp3->coeff,temp3->exp);
        temp3=temp3->next;
    }while(temp3!=p3->next);

    return p4;
}
int main()
{

    int choice,sum=0,n,c,e,i=0;
  printf("\n\nEnter the terms in first polynomial\n\n");
  scanf("%d",&n);
poly *p1=NULL,*p2=NULL;
  printf("\n\nEnter the first polynomial\n\n");
   while(i<n)
  {
      scanf("%d %d",&c,&e);
      p1 = create(p1,c,e);
      i++;
  }
  //poly *p1 = create();
  i=0;
    printf("\n\nEnter the terms in second polynomial\n\n");
  scanf("%d",&n);
  printf("Enter the Second polynomial\n\n");
  while(i<n)
  {
      scanf("%d %d",&c,&e);
      p2 = create(p2,c,e);
      i++;
  }


  printf("\nThe first polynomial is as follows\n");
  display(p1);
  printf("\nThe second polynomial is as follows\n");

  display(p2);
    poly *p3=NULL;
  do
  {
    printf("\n\t\t Main Menu");
    printf("\n 1.Addition \n 2.Multiplication \n 3.Evaluation\n 4.Exit ");
    printf("\n Enter Your Choice ");
    scanf("%d",&choice);

    switch(choice)
    {
     case 1:p3=add(p1,p2);
            printf("\n The addition of the polynomials is as follows\n");
            display(p3);
            break;

     case 2:
            p3 = multi(p1,p2);
            printf("\n The multiplication of the polynomials is as follows\n");
            display(p3);
            break;

     case 3:
            sum = Eval(p1);
            printf("\n The Evaluation of 1st polynomial is :  %d",sum);
            sum=Eval(p2);
            printf("\n The Evaluation of 2nd polynomial is : %d",sum);
            break;

     case 4:
            break;
    }
}while(choice!=4);
}
