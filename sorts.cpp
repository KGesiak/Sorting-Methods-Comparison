#include "sorts.h"
void Update( int* tab, int l, int p );
void sortuj( int* tab,int l,int p );

void wstawianieSort( int* tab, int size )
{
	for( int i=1;i<size;i++ )
	{
		int x = tab[i];
		int j = i-1;
		while( j >= 0 && ( x < tab[j] ) )
			tab[j+1] = tab[j--];
		tab[j+1] = x;
	}
}
void wybieranieSort( int* tab, int size )
{
	for( int i = 0; i < size - 1; i++ )
	{
		int x = tab[i];
		int k = i;
		for( int j = i + 1; j < size; j++ )
		{
			if( tab[j] < x )
			{
				x = tab[j];
				k = j;
			}			
		}
		tab[k] = tab[i];
		tab[i] = x;
	}
}
void babelkoweSort( int* tab, int size )
{
	for( int i = 1; i < size; i++ )
	{
		for( int j = size-1; j >= i; j-- )
		{
			if( tab[j] < tab[j - 1] )
			{
				int x = tab[j];
				tab[j] = tab[j-1];
				tab[j-1] = x;
			}
		}
	}
}
void mieszaneSort( int* tab, int size )
{
	int l = 1;
	int p = size-1;
	int k= size-1;
	int x;
	do
	{
	for( int j = p; j >= l; j-- )
	{
		if( tab[j - 1] > tab[j] )
		{
			x = tab[j-1];
			tab[j-1] = tab[j];
			tab[j] = x;
			k = j;
		}
	}
	l = k+1;
	for( int j = l; j <= p; j++ )
	{
		if( tab[j - 1] > tab[j] )
		{
			x = tab[j-1];
			tab[j-1]=tab[j];
			tab[j] =x;
			k=j;
		}
	}
	p = k-1;
	}while( l<=p );
}
void polowkoweSort( int* tab, int size )
{
	for( int i=1;i<size;i++ )
	{
		int x = tab[i];
		int j = i-1;
		int p = j;
		int l = 0;
		while( p >= l )
		{
			int s = ( l+p )/2;
			if( tab[s] >= x )
				p = s-1;
			else
				l = s+1;
		}
		while( j>=l )
			tab[j+1] = tab[j--];
		tab[l] = x;
	}
}

void Update( int* tab, int l, int p )
{
	if( l>=p ) return;
	int i=l;
	int j = 2*i +1;
	int x = tab[i];
	while( j <= p )
	{
		if( j<p )
			if( tab[j+1]>tab[j] ) j++;
		if( x>=tab[j] ) break;
		tab[i] = tab[j];
		i=j;
		j=2*i +1;
	}
	tab[i] =x;
}
void stogoweSort( int* tab, int size )
{
	int p=size -1;
	for(int l = size/2;l>=0;l--)
		Update( tab,l,p );
	for(p;p>0;p--)
	{
		int x = tab[0];
		tab[0]=tab[p];
		tab[p]=x;
		Update( tab,0,p-1 );
	}

}
void sortuj( int* tab,int l,int p )
{
	int i=l;
	int j=p;
	int x= tab[ (l+p)/2 ];
	do
	{
		while( tab[i]<x ) i++;
		while( x<tab[j] ) j--;
		if( i <= j )
		{
			int w=tab[i];
			tab[i] = tab[j];
			tab[j] = w;
			i++;
			j--;
		}
	}while( i<=j );
	if( l<j ) sortuj( tab,l,j );
	if( i<p )sortuj( tab,i,p );

}
void szybkieSort( int* tab, int size )
{
	sortuj( tab,0,size-1 );

}