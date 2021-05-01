#include <stdio.h>
#include <stdio.h>
#include <stdint.h>

int max( int32_t a, int32_t b )
{
    
    int ret = a > b ? a : b;
    printf("%d",ret);
    return ret;
}
int main() 
{
    max(0,1);
    return 0;
}
