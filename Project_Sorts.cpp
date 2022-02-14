#define _DEBUG_
#define SHOW_ELEM 50
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sorts.h"

int CreateTab( int** pTab, int size );
void PrintTab( int* pTab, int size );
void Randomize( int* pTab,int size );

typedef void ( *pF )( int*,int );

int main( int argc, char* argv[] )
{
	if( argc != 2 )
	{
		printf( "Usage: %s <size>", argv[0] );
		return 1;
	}

	int N = atoi( argv[1] );
	int* tab = NULL;
	CreateTab( &tab,N );
	int* sortTab = NULL;
	CreateTab( &sortTab,N );
	
	if( !tab || !sortTab )
	{
		perror( "Allocation error in tab / sortTab!" );
		return 1;
	}
	pF pSortTab[] = { wstawianieSort,wybieranieSort,babelkoweSort,mieszaneSort,polowkoweSort,stogoweSort,szybkieSort };
	const char* NameTab[] = { "wstawianieSort","wybieranieSort","babelkoweSort","mieszaneSort","polowkoweSort","stogoweSort","szybkieSort" };

	#ifdef _DEBUG_
	printf( "Size of array: %d\n",N );
	#endif

	Randomize( tab,N );

	#ifdef _DEBUG_
	printf( "First %d elements of the original array: \n", SHOW_ELEM );
	PrintTab( tab,SHOW_ELEM );
	#endif

	for( int i = 0; i < sizeof( pSortTab )/sizeof( pF ); i++ )
	{
		memcpy( sortTab,tab,sizeof( int )*N );
		printf( "\nArray sorted with %s \n", NameTab[i] );
		clock_t start = clock();
		pSortTab[i]( sortTab,N );
		clock_t end = clock();
		double cpu_time_used = ( ( double )( end - start ) ) / CLOCKS_PER_SEC;

		#ifdef _DEBUG_
		printf( "First %d elements of sorted array: \n", SHOW_ELEM );
		PrintTab( sortTab, SHOW_ELEM );
		#endif

		printf( "\n Time: %0.10f seconds\n", cpu_time_used );
	}
	
	free( tab );
	free( sortTab );
	return 0;
}
int CreateTab( int** pTab, int size )
{
	
	*pTab = ( int* )malloc( sizeof( int ) * size );
	if( !*pTab ) return 0;
	memset( *pTab, 0, sizeof( int ) * size );
	return 1;
}
void PrintTab( int* pTab, int size )
{
	for(int i = 0; i < size; i++)
	{
		printf( "%5d",*pTab++ );
		if( !( ( i+1 )%10 ) ) printf( "\n" );
	}
}
void Randomize( int* pTab, int size )
{
	srand( ( unsigned int )time( NULL ) );
	for( int i = 0; i<size; i++ )
		*pTab++ = rand()%size;
}