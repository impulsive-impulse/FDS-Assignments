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
