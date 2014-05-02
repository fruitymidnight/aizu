#include <stdio.h>
#include <math.h>

#ifdef DEBUG
#define LOG(...) fprintf(stderr, __VA_ARGS__)
#else
#define LOG(...) 
#endif // DEBUG

#define MAX_VERTEX_NUM 50

int main(void)
{
    int count = 1;
    while (1) {
        int num;
        int x[MAX_VERTEX_NUM], y[MAX_VERTEX_NUM];
        int i;
        double result = 0;
        
        scanf("%d", &num);
        LOG("num = %d\n", num);

        if (num == 0) {
            break;
        }

        if (num < 2 || num > MAX_VERTEX_NUM) {
            break;
        }
        
        scanf("%d %d", &x[0], &y[0]);
        LOG("x[0] = %d, y[0] = %d\n",  x[0],  y[0]);
        for (i = 1; i <= num; i++) {
            if (i == num) {
                result = result + (x[i-1] * y[0] - x[0] * y[i-1]);
                LOG("result= %f\n", result);
            }
            else {
                scanf("%d %d", &x[i], &y[i]);
                LOG("x[%d] = %d, y[%d] = %d\n", i, x[i], i, y[i]);
                result = result + (x[i-1] * y[i] - x[i] * y[i-1]);
                LOG("result= %f\n", result);
            }
        }
        result = fabs(result / 2);
        printf("%d %.1f\n", count, result);
        count++;
                
    }
    
    return 0;
}
