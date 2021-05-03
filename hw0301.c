#include "hw0301.h"

int main(void) 
{
    FILE	*pFile = NULL;
    char name[127];
    printf("Open a LRC file: ");
    scanf("%s",name);
    if( ( pFile = fopen( name, "r" ) ) == NULL )
    {
        printf( "File could not be opened!\n" );
        return 0;
    }
    lyric( pFile );
	fclose( pFile );
	return 0;
}
