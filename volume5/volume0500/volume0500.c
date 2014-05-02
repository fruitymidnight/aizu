#include <stdio.h>

#define LOG(...) fprintf(stderr, __VA_ARGS__)

int main(void)
{
    
    while (1) {
        int num, a, b;
        int result_a = 0;
        int result_b = 0;
        int i = 0;
        
        scanf("%d\n", &num);
        LOG("num = %d\n", num);

        if (num == 0) {
            break;
        }
        
        for (i = 0; i < num; i++) {
            scanf("%d %d\n", &a, &b);
            LOG("a = %d, b = %d\n", a, b);

            if (a < b) {
                result_b = result_b + a + b;
            }
            else if (a > b) {
                result_a = result_a + a + b;
            }
            else {
                result_a = result_a + a;
                result_b = result_b + b;
            }
        }
        printf("%d %d\n", result_a, result_b);
    }
    
    return 0;
}


