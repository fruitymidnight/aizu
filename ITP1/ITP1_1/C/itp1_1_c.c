#include <stdio.h>

#define LOG(...) fprintf(stderr, __VA_ARGS__)

int main(int argc, char *argv[])
{
    int width, height;

    scanf("%d %d", &width, &height);
    LOG("width = %d, height = %d\n", width, height);

    printf("%d %d\n", width * height, (width + height) * 2);
    
    return 0;
}


