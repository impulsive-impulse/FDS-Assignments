===================================================================================================================================================================================
assignment 1 starts here


#include <stdio.h>
#include <stdlib.h>
int input(int set[])   //function to input sets
{
    int i=0,l,j;
    printf("\n\tEnter the length of set:- ");
    scanf("%d", &l);
    printf("\n\tEnter the elements of set:- \n");
    while(i<l)
    {
        scanf("%d", &set[i]);
        for(j=0; j<i; j++)
        if(set[i]==set[j])
        {
            break;
        }
        if(i==j)
            i++;
    }
    return l;
}

int Union(int set1[20],int set2[20], int l1,int l2, int set3[20])  // function to perform union
{
    int i,j,len=0, temp;
    for(i=0; i<l1; i++)   // coping set1 element to set3.
    {
        set3[i]=set1[i];
    }
    len=l1;
    for(i=0; i<l2; i++)  // set2
    {
        temp=0;
        for(j=0;j<l1;j++)   //set1
        {
            if(set1[j]==set2[i])
            {
                temp=1;
                break;
            }
        }
        if(temp==0)
        {
            set3[len]=set2[i];
            len++;
        }
    }
    return len;
}

int Intersect(int set1[20], int set2[20], int l1, int l2, int set3[20])  //function to perform intersection
{
    int i,j, len=0;

    for(i=0;i<l1;i++)   //set 1
    {
        for(j=0;j<l2;j++)   //set2
        {
            if(set1[i]==set2[j])
            {
                set3[len]=set1[i];
                len++;
                break;
            }
        }
    }
    return len;
}

int Difference(int set1[20], int set2[20], int l1, int l2, int set3[20])  // function to perform difference between two sets
{
    int i,j, len=0,temp;
    for(i=0;i<l1;i++)
    { temp=0;
        for(j=0;j<l2;j++)
        {
            if(set1[i]==set2[j])
            {
                temp=1;
                break;
            }
        }
        if(temp==0)
        {
            set3[len]=set1[i];
            len++;
        }
    }
    return len;
}

int Symmetric(int set1[20], int set2[20],int set3[20], int l1, int l2 ) // to perform symmetric difference
{
    int l3, se1[20], se2[20], un1, un2;
    un1= Difference(set1, set2, l1, l2, se1);
    un2= Difference(set2, set1, l2, l1, se2);
    l3=  Union(se1, se2, un1, un2, set3);
    return l3;
}

void Display(int set[], int l)   // to display the set
{
    int i;
    for(i=0; i<l; i++)
    {
        printf("%d \t", set[i]);
    }
}

int main()
{
    int set1[20], set2[20], set3[20], set4[20], set5[20],set6[20],set7[20], l1, l2, l3, l4, l5, l6, l7, ch, ch1;

    do
    {

        printf("\n\n\n\n\t\t------MENU-------\n\n");
        printf("\n\t1.\tINPUT\n");
        printf("\n\t2.\tDISPLAY\n");
        printf("\n\t3.\tUNION\n");
        printf("\n\t4.\tINTERSECTION\n");
        printf("\n\t5.\tDIFFERENCE\n");
        printf("\n\t6.\tSYMMETRIC DIFFERENCE\n");
        printf("\n\t7.\tEXIT\n");
        printf("\n\tPlease Enter your choice\t:-");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\n\tNoW We Will Take Input Of Sets:-");
                    l1= input(set1);
                    l2= input(set2);
                    break;

            case 2: printf("\n\t SET1:-\t");
                    Display(set1,l1);
                    printf("\n\t SET2:-\t");
                    Display(set2,l2);
                    break;

            case 3: printf("\n\tNow We Will Perform Union Operation:-");
                    l3= Union(set1,set2,l1,l2,set3);
                    printf("\n\tThe set After Union:-\t");
                    Display(set3,l3);
                    break;

            case 4: printf("\n\t Now we Will perform Intersection of 2 sets:=");
                    l4= Intersect(set1,set2,l1,l2,set4);
                    printf("\n\tThe Set After Intersection:-\t");
                    Display(set4,l4);
                    break;

            case 5: printf("\n\tNow We Will Perform Difference Operation:-");
                    printf("\n\t1. SET1-SET2\t");
                    l5= Difference(set1,set2,l1,l2,set5);
                    Display(set5,l5);
                    printf("\n\t2. SET2-SET1\t");
                    l6= Difference(set2,set1,l2,l1,set6);
                    Display(set6,l6);
                    break;

            case 6: printf("\n\tNow we will perform Symmetric Difference:-\t");
            		printf("\n\tSymmetric Difference between Set1 and Set2 is:-");
                    l7= Symmetric(set1,set2,set7,l1,l2);
                    Display(set7,l7);
                    break;
            default:printf("\n\tTERMINATING!!!!!\t");

        }
    } while(ch!=7);
    return 0;
}


assignment 2 ends here
===================================================================================================================================================================================

assignment 1 starts here


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int input(char *p)
{
    int i=0;
    char ch;
    do
    {
        ch= getchar();
        *p= ch;
        p++;
        i++;
    }while(ch!='\n');
    p--;
    i--;
    *p='\0';
    return i;
}

void len(int l)
{
    printf("\n\tThe length of string is%d\t",l);
}
void display(char *p)
{
    while(*p!='\0')
    {
        printf("%c",*p++);
    }
}

char *rev1(char *a)
{
    int i,j,l;
    l= strlen(a);
    char temp, *m,*n,*c;
    c=a;
    m=c;
    n=c;
    for(i=0;i<l-1;i++)
        n++;
    for(i=0;i<l/2;i++)
    {
        temp=*n;
        *n=*m;
        *m=temp;
        m++;
        n--;
    }
    return c;
}

char *concatenate(char *d, char *k, int m, int n)
{
    char *a, *b,*c;
    a=d;
    c=a;
    while(*a!='\0')
    {
        a++;
    }
    b=k;
    while(*b!='\0')
    {
        *a=*b;
        a++;
        b++;
    }
    *a='\0';
   return c;

}
void palindrome(char *k)
{
    char *n;
    n= strrev(k);
    if(*n==*k)
        printf("\n\tPalindrome\t");
    else
        printf("\n\tNot a palindrome\t");
}

void comparestr(char *m, char *n)
{
    int a,b;
    a= strlen(m);
    b= strlen(n);
    if(a!=b)
        printf("\n\tStrings are not equal\t");
    else
    {
        if(*m==*n)
            printf("\n\tStrings are equal\t");
        else
            printf("\n\tStrings are not equal\t");
    }
}
void substring(char *p, char *q)
{

}


int main()
{
    char *p,*q,*a,*b,*c;
    int l,n,m;


    printf("\n\tEnter the string:\t");
    p=(char*)malloc(200*sizeof(char));
    l=input(p);
    len(l);
    p=(char*)realloc(p,l*sizeof(char));
    display(p);
    //palindrome(p);
    //a=rev1(p);
    //printf("\n\tThe Reversed string is:-\t");
    //display(a);
    printf("\n\tEnter the second string:\t");
    q=(char*)malloc(200*sizeof(char));
    n= input(q);
    len(n);
    q=(char*)realloc(q,n*sizeof(char));
    display(q);
    //palindrome(q);
    //printf("\n\tThe reversed string is:-\t");
    //b= rev1(q);
    //display(b);
    comparestr(p,q);
    c=(char*)malloc((l+n)*sizeof(char));
    printf("\n\tThe concatenated string is:-\t");
    c= concatenate(p,q,l,n);
    display(c);


    return 0;
}

assignment 2 ends here
==========================================================================================================================================================================

assignment 3 starts here


#include<stdio.h>
#include<stdlib.h>
void input(int **a, int m, int n)
{
    printf("\n\tEnter the elements of matrix:\t");
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",(*(a+i)+j));
    }
}

void display(int **a,int m, int n)
{
    printf("\n\tTHE MATRIX IS:\t");
    int i,j;
    for(i=0;i<m;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("\t%d",*(*(a+i)+j));
        }
    }
}

void sum(int **a, int **b,int **c, int m, int n, int l, int o)
{
    int i,j;
        printf("\n\tMATRIX ADDITION IS POSSIBLE\t");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                   *(*(c+i)+j)= *(*(a+i)+j)+*(*(b+i)+j);
            }
        }
}

void multiply(int **a, int **b, int **c, int m, int n, int l, int o)
{
    int i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<o;j++)
        {
            *(*(c+i)+j)=0;
            for(k=0;k<n;k++)
              {
                   *(*(c+i)+j)+=(*(*(a+i)+k))*(*(*(b+k)+j));
              }
        }
    }
}

void transpose(int **d, int **e, int m, int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            *(*(e+i)+j)=*(*(d+j)+i);
    }
}

void subtract(int **a, int **b, int **c, int m, int n, int l, int o)
{
    int i,j;
    printf("\n\tMATRIX SUBTRACTION IS POSSIBLE\t");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            *(*(c+i)+j)=*(*(a+i)+j)-*(*(b+i)+j);
        }
    }
}

int saddle(int **a, int m, int n)
{
    int i,j,t,p,min,max,k;
    for(i=0;i<m;i++)
    {
       min= *(*(a+i)+0);
       t=0;
       for(j=1;j<n;j++)
       {
           if(min>*(*(a+i)+j))
           {
                min=*(*(a+i)+j);
                t=j;
           }
       }
       max= *(*(a+0)+t);
       p=0;
       for(j=1;j<m;j++)
       {
           if(max<*(*(a+j)+t))
            max= *(*(a+j)+t);
            p=j;
       }
       if(i==p)
       {
           printf("\n\t Saddle point is at %d,%d and value is:\t%d",i,t,*(*(a+i)+t));
           return (1);
       }
    }
        printf("\n\tNo saddle point");
        return (0);
}
void MagicSquare(int **mat, int m, int n)
{
    int z, cnt=0;
    z= (((m*m)+1)*m)/2;
    int i,j,k, sum=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum+= *(*(mat+i)+j);
        }
        if(i==0)
            k=sum;
        if(sum==k&&sum==z)
            cnt++;
        sum=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            sum+= *(*(mat+i)+j);
        }
        if(sum==k&&sum==z)
            cnt++;
        sum=0;
    }
    if(cnt==m+n)
        printf("\n\tA MAGIC SQUARE:\t");
    else
        printf("\n\tNOT A MAGIC SQUARE:\t");
}


int main()
{
    int **a,**b,**c,**d,**e,**f,m,n,l,o,ch,i,j;
    do
    {
        printf("\n\t----------MATRIX OPERATION MENU-----------\t");
        printf("\n\t1.INPUT\t");
        printf("\n\t2.DISPLAY\t");
        printf("\n\t3.ADDITION\t");
        printf("\n\t4.SUBTRACTION\t");
        printf("\n\t5.MULTIPLICATION\t");
        printf("\n\t6.TRANSPOSE\t");
        printf("\n\t7.SADDLE POINT\t");
        printf("\n\t8.MAGIC SQUARE\t");
        printf("\n\t9.EXIT!!!\t");
        printf("\n\tENTER YOUR CHOICE\t");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\n\tEnter the no. of rows and columns of matrix:\t");
                    scanf("%d%d", &m,&n);
                    a=(int**)malloc(m*sizeof(int*));
                    for(i=0;i<m;i++)
                        *(a+i)=(int*)malloc(n*sizeof(int));
                    input(a,m,n);
                    printf("\n\tEnter the no. of rows and columns of second matrix:\t");
                    scanf("%d%d", &l, &o);
                    b=(int**)malloc(l*sizeof(int*));
                    for(i=0;i<l;i++)
                        *(b+i)=(int*)malloc(o*sizeof(int));
                    input(b,l,o);
                    break;

            case 2: display(a,m,n);
                    display(b,l,o);
                    break;

            case 3: c=(int**)malloc(m*sizeof(int*));
                    for(i=0;i<m;i++)
                        *(c+i)= (int*)malloc(n*sizeof(int));
                    if(m==l&&n==o)
                    {
                        printf("\n\tAddition of given two matrix is equal to:\t");
                        sum(a,b,c,m,n,l,o);
                        display(c,m,n);
                    }
                    else
                        printf("\n\tAddition is not possible for given two matrix:\t");
                    break;

            case 4: c=(int**)malloc(m*sizeof(int*));
                    for(i=0;i<m;i++)
                        *(c+i)= (int*)malloc(n*sizeof(int));
                    if(m==l&&n==o)
                    {
                        printf("\n\tSubtraction of given two matrix is equal to:\t");
                        subtract(a,b,c,m,n,l,o);
                        display(c,m,n);
                    }
                    else
                        printf("\n\tSubtraction is not possible for given two matrix:\t");
                    break;

            case 5: d=(int**)malloc(m*sizeof(int*));
                    for(i=0;i<m;i++)
                        *(d+i)=(int*)malloc(o*sizeof(int));
                    if(n==l)
                    {
                        printf("\n\tMultiplication is possible\t:");
                        multiply(a,b,d,m,n,l,o);
                        display(d,m,o);
                    }
                    else
                        printf("\n\tMultiplication is not possible:\t");
                    break;

            case 6: e=(int**)malloc(n*sizeof(int*));
                    for(i=0;i<n;i++)
                        *(e+i)=(int*)malloc(m*sizeof(int));
                    printf("\n\tTranspose of First Matrix:\t");
                    transpose(a,e,m,n);
                    display(e,n,m);
                    d=(int**)malloc(o*sizeof(int*));
                    for(i=0;i<o;i++)
                        *(d+i)=(int*)malloc(l*sizeof(int));
                    transpose(b,d,l,o);
                    display(d,o,l);
                    break;

            case 7: saddle(a,m,n);
                    saddle(b,l,o);
                    break;

            case 8: if(m==n)
                    {
                        MagicSquare(a,m,n);
                    }
                    if(l==o)
                    {
                        MagicSquare(b,l,o);
                    }
                    else
                    {
                        printf("\n\tEnter A square matrix:\t");
                        printf("\n\tEnter the no. of rows and columns of square matrix:\t");
                        scanf("%d", &m);
                        f=(int**)malloc(m*sizeof(int*));
                        for(i=0;i<m;i++)
                            *(f+i)=(int*)malloc(m*sizeof(int));
                        input(f,m,m);
                        MagicSquare(f,m,m);
                    }
                    break;

            default: printf("\n\tTERMINATING!!!!!\t");
        }
    }while(ch!=9);

}


assignment 3 ends here

==============================================================================================================================================================================

assignment 4 starts here


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
{
	int rno, marks;
	char name[50];
}student;

void create(student *s, int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		printf("\n\tEnter the roll no.:-\t");
		scanf("%d", &(s+i)->rno);
		for(j=0;j<i;j++)
		{
			if((s+i)->rno==(s+j)->rno)
			{
				printf("\n\tRoll no. already exist. Enter the new Roll no.\t");
				scanf("%d",&(s+i)->rno);
				j=-1;
			}
		}
		printf("\n\tEnter the Name:-\t");
		scanf("%d",&k);
		scanf("%[^\n]%*c",(s+i)->name);
		printf("\n\tEnter the Marks:-\t");
		scanf("%d",&(s+i)->marks);
	}
}

void display(student *s,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n\tRoll No.:-%d\t",(s+i)->rno);
		printf("\n\tName:-%s\t",(s+i)->name);
		printf("\n\tmarks:-%d\t",(s+i)->marks);
	}
}

void displayper(student *s, int n, int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(m==(s+i)->rno)
		{
			printf("\n\tRoll no:-%d\n\tName:-%s\n\tmarks:-%d\t", (s+i)->rno, (s+i)->name, (s+i)->marks);
			break;
		}
	}
	if(i==n)
	printf("\n\tNOT found\t");
}

int edit(student *s,int n, int m)
{
	int i,j,z;
	for(i=0;i<n;i++)
	{
		if(m==(s+i)->rno)
		{
			printf("\n\tEnter the name of student:\t");
			scanf("%d", &z);
			scanf("%[^\n]%*c",(s+i)->name);
			printf("\n\tEnter the marks:\t");
			scanf("%d",&(s+i)->marks);
			return 0;

		}

	}printf("\n\tNo Record found\t");
}

void insert(student *p, int n)
{
	int i,pos,roll,mak;
	char nam[200];

	printf("\n\tEnter the position where you want to insert:\t");
	scanf("%d",&pos);
        for(i=n-1;i>=pos;i--)
        {
            *(p+i)=*(p+i-1);
        }
        printf("\n\tEnter the Roll no.:\t");
        scanf("%d",&roll);
        for(i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(roll==(p+i)->rno)
                {
                    printf("\n\tRoll no. already exit.Enter New roll no.\t");
                    scanf("%d",&roll);
                }
            }
        }
        (p+pos-1)->rno=roll;
        printf("\n\tEnter the name of student:\t");
        fflush(stdin);
        scanf("%[^\n]%*c",nam);
        strcpy((p+pos-1)->name,nam);
        printf("\n\tEnter the marks:\t");
        scanf("%d",&mak);
        (p+pos-1)->marks=mak;

}

int delete(student *s, int n, int val)
{
	int i,j,r=0;
	for(i=0;i<n;i++)
	{
		if(val==(s+i)->rno)
		{
			printf("\n\tRoll no:-%d\n\tName:-%s\n\tmarks:-%d\t", (s+i)->rno, (s+i)->name, (s+i)->marks);
			printf("\n\tIf you really want to delete the press 1 or else 2:\t");
			scanf("%d",&j);
			if(j==1)
			{
			    r=1;
				for(j=i;j<n-1;j++)
				{
					(s+j)->rno=(s+j+1)->rno;
					strcpy((s+j)->name,(s+j+1)->name);
					(s+j)->marks=(s+j+1)->marks;
				}
			}
			break;
		}
	}
	return r;
}

int main()
{
	student *p;
	int n,m,k,j,o=0,i,y;
	int ch;
	do
	{
		printf("\n\t---------RECORD MENU---------\t");
		printf("\n\t1.CREATE DATABASE\t");
		printf("\n\t2.DISPLAY ALL\t");
		printf("\n\t3.DISPLAY PARTICULAR RECORD\t");
		printf("\n\t4.EDIT A SPECIFIC RECORD\t");
		printf("\n\t5.INSERT AT SPECIFIC LOCATION\t");
		printf("\n\t6.DELETE A RECORD\t");
		printf("\n\t7.EXIT!!!!!\t");
		printf("\n\tEnter Your choice:\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("\n\tFor How much student you want to enter the data:-\t");
					scanf("%d",&n);
					p=(student*)malloc(n*sizeof(student));
					create(p,n);
					break;

			case 2:	printf("\n\tDisplaying All the Record\t");
					display(p,n);
					break;

			case 3:	printf("\n\tHow many records you want to display:-\t");
					scanf("%d",&k);
					for(j=0;j<k;j++)
					{
						printf("\n\tEnter the Roll no. whose record you want to display:-\t");
						scanf("%d",&m);
						displayper(p,n,m);
					}
					break;

			case 4: printf("\n\tEnter the Roll no. whose record you want to edit:\t");
					scanf("%d",&m);
					edit(p,n,m);
					break;

			case 5: o=o+1;
                    n=n+o;
                    printf("\n\tEnter the details you Want to insert\t:");
                    p=(student*)realloc(p,(n)*sizeof(student));
                    insert(p,n);
                    break;

			case 6: printf("\n\tEnter the Roll no. whose record you Want to delete:\t");
					scanf("%d",&m);
					for(i=0;i<n;i++)
					{
						if(m==(p+i)->rno)
						break;
					}
					if(i==n)
						printf("\n\tRoll no. NOT FOUND!!. Cannot delete\t");
					else
					{
						p=(student*)realloc(p,(n)*sizeof(student));
						if(delete(p,n,m)==1)
						n--;
					}
					break;

			default: printf("\n\tTerminating!!!\t");

		}
	}while(ch!=7);
}


assignment 4 ends here
===============================================================================================================================================================================


assignment 5 starts here

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void stringsort(char a[][1000], int size)
{
    int i,j;
    char temp[1000];
    for(i=0;i<size-1;i++)
    {   int flag = 0;
        for(j=i+1;j<size;j++)
        {
            if(strcmpi(a[i],a[j])<0)
            {
                strcpy(temp,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],temp);
                flag = 1;
            }
        }
        if(!flag)   break;
        printf("\n\tSTRINGS AFTER PASS %d",i+1);
        for(int k=0;k<size;k++)
        {
        printf("\n\t");
            printf("%s\t",a[k]);
        }
    }
}

int Binarysearch(char a[][1000], char s[], int size) //Without Recursion
{
    int l,r;
    l = 0;  r = size - 1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(strcmp(s,a[mid])==0)
            return mid;
        else if(strcmp(s,a[mid])>0)
            l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int binary(char a[][1000], char s[], int l, int r)
{
    if(r>=l)
    {
        int mid = (l+r)/2;
        if(strcmp(s,a[mid])==0) return mid;

        if(strcmp(s,a[mid])>0)  return binary(a,s,mid+1,r);

        return binary(a,s,l,mid-1);
    }
    return -1;
}
void insertion(char a[][1000], int size)
{
    int i,j;
    char temp[1000];
    for(i=0;i<size;i++)
    {
        strcpy(temp,a[i]);
        j=i-1;
        while(j>=0 && strcmpi(a[j],temp)>0)
        {
            strcpy(a[j+1],a[j]);
            j = j-1;
        }
        strcpy(a[j+1],temp);
    }
    printf("\n\tInsertion Sorted String is:\t");
    for(i=0;i<size;i++)
    {
        printf("\n\t");
        printf("%s\t",a[i]);
    }

}
int main()
{
    char s[1000][1000],a[1000];
    int n,ch;
    printf("\n\tEnter the size of String\t");
    scanf("%d",&n);
    printf("\n\tEnter the String\t");
    for(int i=0;i<n;i++)
    {
            scanf("\n\t%s",s[i]);
    }
    do
    {
        printf("\n\t1.Bubble Sort\t");
        printf("\n\t2.Insertion sort\t");
        printf("\n\t3.Binary Search\t");
        printf("\n\t4.EXIT\t");
        printf("\n\tEnter your choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:     stringsort(s,n);
                        printf("\n\tSorted String is:-");
                        for(int i=0;i<n;i++)
                        {
                            printf("\n\t");
                            printf("%s\t",s[i]);
                        }
                        break;
            case 3:
                        printf("\n\tEnter The second string\t");
                        scanf("%s",a);
                        printf("\n\tITERATIVE\t");
                        int z = Binarysearch(s,a,n);
                        if(z == -1)
                        printf("\n\tNot Present\t");
                        else printf("\n\tPresent %d", z);
                        printf("\n\tRECURSIVE\t");
                        int k = binary(s,a,0,n-1);
                        if(k == -1)
                        printf("\n\tNot Present\t");
                        else printf("\n\tPresent %d", k);
                        break;
            case 2:     insertion(s,n);
                        break;
        }
    }while(ch!=4);


}

assignment 5 ends here
========================================================================================================================================================

assignment 6 starts here

#include<stdio.h>
struct student
{
            int rollno;
            char name[30];
            float mark;
};

int empty()
{
            struct student stud;
            int c = 0;
            FILE *fp;
            fp = fopen("Record", "r");
            while (fread(&stud, sizeof(stud), 1, fp))
            c = 1;
            fclose(fp);
            return c;
}

void insert()
{
            struct student stud;
FILE *fp;
fp = fopen("Record", "a");
printf("Enter the Roll no :");
scanf("%d", &stud.rollno);
printf("Enter the Name :");
scanf("%s", &stud.name);
printf("Enter the mark :");
scanf("%f", &stud.mark);
fwrite(&stud, sizeof(stud), 1, fp);
fclose(fp);
}

void disp()
{
            struct student stud;
FILE *fp1;
fp1 = fopen("Record", "r");
printf("\nRoll Number\tName\tMark\n\n");
while (fread(&stud, sizeof(stud), 1, fp1))
printf(" %d\t\t%s\t%.2f\n", stud.rollno, stud.name, stud.mark);
fclose(fp1);
}

int avlrollno(int rno)
{
            struct student stud;
int c = 0;
FILE *fp;
fp = fopen("Record", "r");
while (!feof(fp))
{
            fread(&stud, sizeof(stud), 1, fp);
if (rno == stud.rollno)
{
fclose(fp);
return 1;
}
}
fclose(fp);
return 0;
}

void search()
{
            struct student stud;
FILE *fp2;
int r, s, avl;
printf("\nEnter the Roll no you want to search :");
scanf("%d", &r);
avl = avlrollno(r);
if (avl == 0)
printf("Roll No %d is not available in the file\n",r);
else
{
fp2 = fopen("Record", "r");
while (fread(&stud, sizeof(stud), 1, fp2))
{
s = stud.rollno;
if (s == r)
{
printf("\nRoll no = %d", stud.rollno);
printf("\nName = %s", stud.name);
printf("\nMark = %.2f\n", stud.mark);
}
}
fclose(fp2);
}
}

void deletefile()
{
            struct student stud;
FILE *fpo;
FILE *fpt;
int r, s;
printf("Enter the Roll no you want to delete :");
scanf("%d", &r);
if (avlrollno(r) == 0)
printf("Roll no %d is not available in the file\n", r);
else
{
fpo = fopen("Record", "r");
fpt = fopen("TempFile", "w");
while (fread(&stud, sizeof(stud), 1, fpo))
            {
s = stud.rollno;
if (s != r)
fwrite(&stud, sizeof(stud), 1, fpt);
}
fclose(fpo);
fclose(fpt);

remove("Record");
rename("TempFile","Record");
}
}

void update()
{
            struct student stud;
int avl;
FILE *fpt;
FILE *fpo;
int s, r, ch;
printf("Enter roll number to update:");
scanf("%d", &r);
avl = avlrollno(r);
if (avl == 0)
{
printf("Roll number %d is not Available in the file", r);
}
else
{
fpo = fopen("Record", "r");
fpt = fopen("TempFile", "w");
while (fread(&stud, sizeof(stud), 1, fpo))
{
s = stud.rollno;
if (s != r)
fwrite(&stud, sizeof(stud), 1, fpt);
else
{
printf("\n\t1. Update Name of Roll Number %d", r);
printf("\n\t2. Update Mark of Roll Number %d", r);
printf("\n\t3. Update both Name and Mark of Roll Number %d", r);
printf("\nEnter your choice:");
scanf("%d", &ch);
switch (ch)
{
case 1:
printf("Enter Name:");
scanf("%s", &stud.name);
break;
case 2:
            printf("Enter Mark : ");
scanf("%f", &stud.mark);
break;
case 3:
printf("Enter Name: ");
scanf("%s", &stud.name);
printf("Enter Mark: ");
scanf("%f", &stud.mark);
break;
default:
printf("Invalid Selection");
break;
}
fwrite(&stud, sizeof(stud), 1, fpt);
}
}
fclose(fpo);
fclose(fpt);
fpo = fopen("Record", "w");
fpt = fopen("TempFile", "r");
while (fread(&stud, sizeof(stud), 1, fpt))
{
fwrite(&stud, sizeof(stud), 1, fpo);
}
fclose(fpo);
fclose(fpt);
printf("RECORD UPDATED");
}
}

void sort()
{
            struct student stud;
int a[20], count = 0, i, j, t, c;
FILE *fpo;
fpo = fopen("Record", "r");
while (fread(&stud, sizeof(stud), 1, fpo))
{
a[count] = stud.rollno;
count++;
}
c = count;
for (i = 0; i<count - 1; i++)
{
for (j = i + 1; j<count; j++)
{
if (a[i]>a[j])
{
t = a[i];
a[i] = a[j];
a[j] = t;
}
}
}
printf("Roll No.\tName\t\tMark\n\n");
count = c;
for (i = 0; i<count; i++)
{
rewind(fpo);
while (fread(&stud, sizeof(stud), 1, fpo))
{
if (a[i] == stud.rollno)
printf("\n %d\t\t %s \t\t %2f",stud.rollno, stud.name, stud.mark);
}
}
}

void main()
{
            struct student stud;
int c, emp;
do
{
printf("\n\t---Select your choice---------\n");
printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
printf("\n\t4. DELETE\n\t5. UPDATE\n\t6. SORT");
printf("\n\t7. EXIT");
printf("\n\n------------------------------------------\n");
printf("\nEnter your choice:");
scanf("%d", &c);
printf("\n");
switch (c)
{
case 1:
insert();
break;
case 2:
emp = empty();
if (emp == 0)
printf("\nThe file is EMPTY\n");
else
disp();
break;
case 3:
search();
break;
case 4:
deletefile();
break;
case 5:
update();
break;
case 6:
emp = empty();
if (emp == 0)
printf("\n The file is EMPTY\n");
else
sort();
break;
case 7:
exit(1);
break;
default:
printf("\nYour choice is wrong\nPlease try again...\n");
break;
}
} while (c != 7);
}


assignment 6 ends here

==============================================================================================================================================================================

assignment 7 starts here


#include<stdio.h>
void merge(int a[], int l ,int m, int n)
{
    int i,j,k,c[100];
    i = l;  j = m+1;
    k = 0;
    while(i <= m && j <= n)
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
            i++;    k++;
        }
        else
        {
            c[k]=a[j];
            j++;    k++;
        }
    }
    while(i <= n)
    {
        c[k] = a[i];
        i++;    k++;
    }
    while(j <= n)
    {
        c[k]=a[j];
        j++; k++;
    }
    for(i = l, j = 0; i <= n; i++,j++)
    {
        a[i]=c[j];
    }
}

void mergesort(int a[], int i, int j)
{
    int mid;
    if(i<j)
    {
        mid = (i+j)/2;
        mergesort(a,i,mid);
        mergesort(a,mid+1,j);
        merge(a,i,mid,j);
    }
}
int mina(int x, int y)
{
    return (x<y)?x:y;
}
void mersort(int a[],int n)
{
    int m, k;
    for(m = 1; m <= n-1; m = 2*m)
    {
        for(k = 0; k < n; k += 2*m)
        {
            int mid = mina(k+m-1,n-1);
            int right = mina(k+2*m-1, n-1);
            merge(a,k,mid,right);
        }
    }

}

int main()
{
    int a[1000],n,ch;
    printf("\n\tENTER HOW MANY ELEMENTS YOU WANT IN YOUR ARRAY\t");
    scanf("%d", &n);
    do
    {
        printf("\n\t1.RECURSIVE MERGE SORT\t");
        printf("\n\t2.ITRATIVE MERGE SORT\t");
        printf("\n\t3.EXIT\t");
        printf("\n\tENTER YOUR CHOICE:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\n\tENTER THE ELEMENTS:\t");
                    for(int i = 0; i < n; i++)
                        scanf("%d",&a[i]);
                    mergesort(a,0,n-1);
                    printf("\n\tENTER THE ELEMENTS:\t");
                    for(int i = 0; i < n; i++)
                        printf("%d\t",a[i]);
                    break;
            case 2: printf("\n\tENTER THE ELEMENTS:\t");
                    for(int i = 0; i < n; i++)
                        scanf("%d",&a[i]);
                    mersort(a,n);
                    printf("\n\tENTER THE ELEMENTS:\t");
                    for(int i = 0; i < n; i++)
                        printf("%d\t",a[i]);
                    break;
            default:    printf("\n\tTERMINATING\t");
                    break;

        }
    }while(ch!=3);
}


assignment 7 ends here
==============================================================================================================================================================================


assignment  8 starts here


#include<stdio.h>
#include<stdlib.h>
void two_sparse(int a[][10], int m, int n, int b[][3])
{
    int i, j, k;
    k = 1;
    b[0][0] = m;
    b[0][1] = n;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
        {
            if(a[i][j]!=0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    b[0][2] = k-1;
}
void display(int b[][3])
{
    int i,n;
    n = b[0][2];
    printf("\n\tROW = %d\tCOLUMN = %d", b[0][0], b[0][1]);
    printf("\n");
    for(i = 0; i <= n; i++)
        printf("\t%d\t%d\t%d\n",b[i][0], b[i][1], b[i][2]);
}
void sum(int a[][3], int b[][3], int c[][3])
{
    if((a[0][0]!=b[0][0])||(a[0][1]!=b[0][1]))
    {
        printf("\n\tMatrix cannot be added\t");
        exit(0);
    }
    else
    {
        int i,j,k,t1,t2;
        i = j = k = 0;
        t1 = a[0][2];   t2 = b[0][2];
        c[0][0] = a[0][0];
        c[0][1] = a[0][1];
        while(i <= t1 && j <= t2)
        {
            if(a[i][0]<b[j][0])
            {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2];
                k++;    i++;
            }
            else if(a[i][0]>b[j][0])
            {
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k][2] = b[j][2];
                k++;    j++;
            }
            else if(a[i][1]<b[j][1])
            {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2];
                k++;    i++;
            }
            else if(a[i][1]>b[j][1])
            {
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k][2] = b[j][2];
                k++;    j++;
            }
            else
            {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2]+b[j][2];
                k++;    i++;    j++;
            }
        }
        while(i <= t1)
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            k++;    i++;
        }
        while(j <= t2)
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            k++;    j++;
        }
        c[0][2] = k-1;
    }
}

void simple(int b[][3], int c[][3])
{
    int i,j,k,n;
    c[0][0] = b[0][1];
    c[0][1] = b[0][0];
    c[0][2] = b[0][2];
    k = 1;
    n = b[0][2];
    for(i = 0; i < b[0][1]; i++)
        for(j = 1; j <= n; j++)
        {
            if(i == b[j][1])
            {
                c[k][0] = i;
                c[k][1] = b[j][0];
                c[k][2] = b[j][2];
                k++;
            }
        }
}

void fast(int a[][3], int b[][3])
{
    int m,n,i,k,j,col,loc;
    int s[100], t[100];
    m = a[0][0]; n = a[0][1]; k = a[0][2];
    b[0][0] = n; b[0][1] = m; b[0][2] = k;
    for(i = 0; i < n; i++)
        s[i]= 0;
    for(i = 1; i <= k; i++)
    {
        col = a[i][1];
        s[col]++;
    }
    t[0] = 1;
    for(i = 1; i < n; i++)
        t[i] = t[i-1] + s[i-1];
    for(i = 1; i <= k; i++)
    {
        col = a[i][1];
        loc = t[col];
        b[loc][0] = a[i][1];
        b[loc][1] = a[i][0];
        b[loc][2] = a[i][2];
        t[col]++;
    }
}
int main()
{
    int a[10][10],i,j;
    int b[10][10],c[10][3],d[10][3],e[10][3],f[10][3],g[10][3],m,n,ch,o,p;
    do
    {
        printf("\n\t1.Enter The Matrix\t");
        printf("\n\t2.Display the  Sparse\t");
        printf("\n\t3.Add Two Sparse Matrix\t");
        printf("\n\t4.Simple Transpose\t");
        printf("\n\t5.Fast Transpose\t");
        printf("\n\t6.Exit\t");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\n\tEnter the rows and column of 1st matrix:\t");
                    scanf("%d%d",&m,&n);
                    printf("\n\tEnter the elements of matrix:\t");
                    for( i = 0; i < m; i++)
                    {
                        printf("\n\t");
                        for( j = 0; j < n; j++)
                        {
                            scanf("%d",&a[i][j]);
                            printf("\t");
                        }
                    }
                    printf("\n\tEnter the rows and column of 2nd matrix:\t");
                    scanf("%d%d",&o,&p);
                    printf("\n\tEnter the elements of matrix:\t");
                    for( i = 0; i < o; i++)
                    {
                        printf("\n\t");
                        for( j = 0; j < p; j++)
                        {
                            scanf("%d",&b[i][j]);
                            printf("\t");
                        }
                    }
                    printf("\n\t1st Matrix is:\t");
                    for( i = 0; i < m; i++)
                    {
                        printf("\n\t");
                        for( j = 0; j < n; j++)
                            printf("%d\t", a[i][j]);
                    }
                    printf("\n\t2nd Matrix is:\t");
                    for( i = 0; i < o; i++)
                    {
                        printf("\n\t");
                        for( j = 0; j < p; j++)
                            printf("%d\t", b[i][j]);
                    }
                    break;
            case 2: two_sparse(a,m,n,c);
                    display(c);
                    two_sparse(b,o,p,d);
                    display(d);
                    break;
            case 3: sum(c,d,e);
                    display(e);
                    break;
            case 4: simple(c,f);
                    display(f);
                    simple(d,g);
                    display(g);
                    break;
            case 5: fast(c,f);
                    display(f);
                    fast(d,g);
                    display(g);
                    break;
            default:printf("\n\tTerminating!!!!!\t");
                    break;
        }
    }while(ch!=6);
}


assignment 8 ends here
===============================================================================================================================================================================


assignment 9 starts here

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


assignment 9 ends here

============================================================================================================================================================================

assignment 10 starts here


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


assignment 10 ends here

======================================================================================================================
assignment 11 starts here


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int roll;
  char name[20];
  struct node* prev;
  struct node* next;
}node;

node* create(node *head,int a)
{
    int i;
    head->prev=NULL;
    node *p=head;
    node *q=head;
    for(i=1;i<=a;i++)
    {
        p->next=(node*)malloc(sizeof(node));
        p=p->next;
        printf("\nEnter roll number:");
        scanf("%d",&p->roll);
        printf("\nEnter name:");
        scanf("%s",&p->name);
        p->prev=q;
        q=q->next;
    }
    p->next=NULL;
    return head;
}

node* insert(node *head)
{
    int opt,r;
    if(head==NULL)
    {
        printf("\nNO database found for insertion.First create a database..");
    }
    else
    {node *p=head;
    node *q;
    q=(node*)malloc(sizeof(node));
    printf("\nEnter roll number:");
    scanf("%d",&q->roll);
    printf("\nEnter name:");
    scanf("%s",&q->name);

    printf("Where you want to insert the new record:\n1.At the beginning\n2.In between\n3.At the end\nEnter your option");
    scanf("%d",&opt);
    if(opt==1)
    {
        q->prev=NULL;
        q->next=head;
        head->prev=q;
        head=q;
        return head;
    }
    if(opt==2)
    {
        printf("\nEnter the roll no. after which you want to insert:");
        scanf("%d",&r);
        while(p->roll!=r)
        {
            p=p->next;
        }
        q->prev=p;
        q->next=p->next;
        p->next->prev=q;
        p->next=q;
        return head;
    }
    if(opt==3)
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=q;
        q->prev=p;
        q->next=NULL;
        return head;
    }
    }
}

node* del(node *head)
{
    int r;
    node *p=head;
    if(head==NULL)
    {
        printf("\nNo record found to delete!!");
    }
    else
    {printf("\nEnter the roll number you want to delete:");
    scanf("%d",&r);
    if(head->roll==r)
    {
        head=head->next;
        head->prev=NULL;
        free(p);
    }
    else
    {
        while(p->roll!=r)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(p);
        return head;
    }
    }
}

void modify(node *head)
{
    node *p=head;
    int r;
    if(head==NULL)
        printf("No record found to update!!");
    else
    {printf("\nEnter the roll no. to modify:");
    scanf("%d",&r);
    while(p->roll!=r)
    {
        p=p->next;
    }
    printf("\nEnter the new roll number:");
    scanf("%d",&p->roll);
    printf("\nEnter the new name:");
    scanf("%s",&p->name);
    }
}

void disfor(node *head)
{
    if(head==NULL)
        printf("NO RECORD FOUND!!!");
    else
    {while(head->next!=NULL)
    {
        printf("\nROLL NUMBER:%d",head->roll);
        printf("\tName:%s",head->name);
        head=head->next;
    }
    printf("\nROLL NUMBER:%d",head->roll);
    printf("\tName:%s",head->name);
    }
}

void disback(node *head)
{
    if(head==NULL)
        printf("No record found!!");
    else
    {node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(p->prev!=NULL)
    {
        printf("\nROLL NUMBER:%d",p->roll);
        printf("\tName:%s",p->name);
        p=p->prev;
    }
    printf("\nROLL NUMBER:%d",p->roll);
    printf("\tName:%s",p->name);
    }
}

int main()
{
    int ch,a,b,c;
    node *head;
    head=NULL;

    while(1)
    {printf("\n\n\t\t______Database Record_______\n\nSelect any one of the following:\n1.Create a new database\n2.Insert a new record\n3.Delete a record\n4.Modify a record\n5.Display forward\n6.Display backward\n7.EXIT\n\nEnter your option:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("\nEnter number of records:");
               scanf("%d",&a);
               head=(node*)malloc(sizeof(node));
               printf("\nEnter roll number:");
               scanf("%d",&head->roll);
               printf("\nEnter name:");
               scanf("%s",&head->name);
               head=create(head,a-1);
               break;

        case 2:head=insert(head);
               printf("Record Inserted Successfully!");
               break;

        case 3:head=del(head);
               printf("Record deleted Successfully!");
               break;

        case 4:modify(head);
               printf("Record modified Successfully!");
               break;

        case 5:printf("\nForward display:\n");
               disfor(head);
               break;

        case 6:printf("\n Backward display:\n");
               disback(head);
               break;

        case 7:printf("\nThank You\n\n");
               return 0;

        default:printf("Wrong Input!!!!");
                break;
    }
    }
    return 0;
}


assignment  11 ends here
====================================================================================================================

assignment 12 starts here


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct NODE
{
    int tag ;

    union U
    {
        char *ar ;
        struct NODE * link ;

    }var ;

    struct NODE * next ;

}node ;

void input( char *ar )
{
    char c ;
    int i  = 0 ;

    do
    {
        c = getchar() ;

        ar[ i++ ] = c ;

    }while( c != '\n' ) ;

    ar[ --i ] = '\0' ;

}

int create( node * curr, char *s, int ind )
{
    while( s[ ind ] == 32 )
        ind++;

    if( s[ ind ] == '(' )
    {
      curr -> tag = 1 ;

      curr -> var.link = ( node * )malloc( sizeof( node ) ) ;

      ind = create( curr -> var.link, s, ind + 1 );

    }
    else if( s[ ind ] != ')' )
    {
        curr -> tag = 0 ;

        int k = 0 ;

        curr -> var.ar = ( char * )malloc( sizeof( char ) * 4 ) ;

        while( s[ ind ] != '(' && s[ ind ] != ')' && s[ ind ] != 32 && ind <= strlen( s ) )
        {
            curr->var.ar[ k++ ]  = s[ ind++ ] ;
        }

        if( k )
            curr->var.ar[ k ] = '\0' ;

        curr -> var.ar = ( char * )realloc( curr -> var.ar, sizeof( char ) * ( k + 1 ) ) ;

    }

    while( s[ ind ] == 32 )
        ind++;

    if( s[ ind ]   == ')' || ind >= strlen( s )  )
    {
        curr -> next = NULL ;

        return ind + 1 ;
    }

    curr -> next = ( node * )malloc( sizeof( node ) ) ;

    return create( curr -> next, s, ind ) ;
}

void display( node * curr, int sp )
{
    int i;
    if( curr == NULL ){

        return ;

    }

    if( curr -> tag ){

        display( curr->var.link, sp + 1 ) ;

    }
    else{

        for( i = 0 ; i < sp ; i++ )
            printf( "\t" ) ;

        printf( "%s \n", curr->var.ar ) ;

    }

    display( curr -> next , sp ) ;

}

void FREE( node *curr ){

       if( curr == NULL ){

        return ;

       }

       if( curr -> tag ){

            FREE( curr -> var.link ) ;

       }
       else{

            free( curr -> var.ar ) ;

       }

       FREE( curr -> next ) ;

       free( curr ) ;
}

int main()
{



   printf( "1.) 1 2 3 4 5\n") ;
   printf( "2.) 1 ( 1.1 ( 1.1.1 ( 1.1.1.1 ) ) ) 2\n") ;
   printf( "3.) 1 ( 1.1 ) 2 ( 2.1 2.2 ) 3 ( 3.1 3.2 ) 4\n") ;
   printf( "4.) 1 ( 1.1 1.2 1.3 ) 2 ( 2.2 2.3 ( 2.3.1 2.3.2 ) 2.4 ) 3 4 ( 4.1 4.2 )\n" ) ;

   while( 1 ){

   printf( "Enter Book Index Data or 0 to Exit :-\n" ) ;
   char *s = ( char * )malloc( sizeof( char ) * MAX ) ;
   input( s ) ;

   if( strlen( s ) == 1 && s[ 0 ] == '0' )
   {
        return 0 ;
   }

   node *head = ( node * )malloc( sizeof( node ) ) ;

   int n = create( head, s, 0 ) ;

   display( head, 0 ) ;

   free( s ) ;

   FREE( head ) ;

   }

}


assignment 12 ends here
=======================================================================================================================================================================
