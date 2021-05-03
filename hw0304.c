#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

typedef struct _sBmpheader
{
    char bm[2];
    uint32_t size;
    uint32_t reserve;
    uint32_t offset;
    uint32_t header_size;
    uint32_t width;
    uint32_t height;
    uint16_t planes;
    uint16_t bpp;
    uint32_t compression;
    uint32_t bitmap_size;
    uint32_t hres;
    uint32_t vres;
    uint32_t used;
    uint32_t important;
}__attribute__((__packed__)) Bmpheader;

int main()
{
    FILE *pFile , *pFile2;
    char input[127] , output[127];
    int32_t alpha = 0;
    Bmpheader header;
    printf("Please input a BMP file: ");
    fgets(input,127,stdin);
    if( input[strlen(input) - 1] == '\n' )
    {
        input[strlen(input) - 1] = 0;
    }
    pFile = fopen(input, "r");
    if( pFile == NULL )
    {
        printf("File could not be opened!\n");
        return 0;
    }

    printf("Please input the output BMP file name: ");
    fgets(output,127,stdin);
    if( output[strlen(output) - 1] == '\n' )
    {
        output[strlen(output) - 1] = 0;
    }

    printf("Alpha (0-31): ");
    scanf("%d",&alpha);
    if( alpha < 0 || alpha > 31 )
    {
        printf("Error!\n");
        return 0;
    }

    pFile2 = fopen(output, "w");
    if( pFile2 == NULL )
    {
        printf("File could not be opened!\n");
        return 0;
    }
    fread(&header,sizeof(header),1,pFile);
    
    if( header.bpp != 24 )
    {
        printf("%d",header.bpp);
        printf("BMP is not a 24-bit depth!\n");
        return 0;
    }

    int32_t p_times = 0 , n_times = 0;
    uint8_t *p_color , *n_color;
    p_times = (header.width) * 3 + (header.width) % 4;
    n_times = header.width * 4;
    p_color = (uint8_t*)malloc(sizeof(uint8_t) * p_times);
    n_color = (uint8_t*)malloc(sizeof(uint8_t) * n_times);
    header.bpp = (int32_t) 32;
    fwrite(&header,sizeof(header),1,pFile2);
    int count = 0;
    for(int i=0;i<header.height;i++)
    {
        count = 0;
        fread(p_color,1,p_times,pFile);
        for(int j=0;j<n_times;j+=4)
        {
            for(int k=0;k<4;k++)
            {
                //n_color[j+k] = 255;
                if( k != 3 )
                {
                    n_color[j+k] = p_color[count*3+k] * alpha / 31 + 31 * ( 31 - alpha ) / 31;
                }
                
            }
            count++;
        }
        fwrite(n_color,1,n_times,pFile2);
    }
    
    fclose( pFile );
    fclose( pFile2 );
    return 0;
}
