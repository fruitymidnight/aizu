#include <stdio.h>

#ifdef DEBUG
#define LOG(...) fprintf(stderr, __VA_ARGS__)
#else
#define LOG(...) 
#endif // DEBUG


int main(void)
{
    int n = 0;
    int count = 0;
    while(1) {
        scanf("%d\n", &n);
        if (n == 0) {
            break;
        }
        printf("n = %d, ", n);
        for ( ; n != 1; count++) {
            
            if (n % 2 == 0) {
                n = n / 2 ;
            }
            else {
                n = n * 3 + 1;
            }
        }
        printf("count = %d\n", count);
        count = 0;
    }
    
    return 0;
}

