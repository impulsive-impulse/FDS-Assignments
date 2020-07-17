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
