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
