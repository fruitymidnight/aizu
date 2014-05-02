#include <stdio.h>
#include <math.h>

#define LOG(...) fprintf(stderr, __VA_ARGS__)


double round_with_decimal(double src, int decimal);

int main(int argc, char *argv[])
{
    int num;
    double x1, x2, x3, y1, y2, y3, px, py, r;
    int i = 0;

    scanf("%d\n", &num);
    LOG("num = %d\n", num);
    while(i < num) {
        scanf("%lf %lf %lf %lf %lf %lf\n", &x1, &y1, &x2, &y2, &x3, &y3);
        LOG("x1 = %lf, y1 = %lf, x2 = %lf, y2 = %lf, x3 = %lf, y3 = %lf\n", x1, y1, x2, y2, x3, y3);
        
        px = ((y1 - y3) * (pow(x1, 2) - pow(x2, 2) + pow(y1, 2) - pow(y2, 2)) - (y1 - y2) * (pow(x1, 2) - pow(x3, 2) + pow(y1, 2) - pow(y3, 2))) / (2 * ((x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2)));
        py = ((x1 -x3) * (pow(x1, 2) - pow(x2, 2) + pow(y1, 2) - pow(y2, 2)) - (x1 - x2) * (pow(x1, 2) - pow(x3, 2) + pow(y1, 2) - pow(y3, 2))) / (2 * ((x1 -x3) * (y1 - y2) - (x1 - x2) * (y1 - y3)));
        r = sqrt(pow(px - x1, 2) + pow(py - y1, 2));
        LOG("px = %lf, py = %lf, r = %lf\n", px, py, r);
        LOG("px = %lf, py = %lf, r = %lf\n", round_with_decimal(px, 4), round_with_decimal(py, 4), round_with_decimal(r, 4));
        printf("%.03lf %.03lf %.03lf\n", round_with_decimal(px, 4), round_with_decimal(py, 4), round_with_decimal(r, 4));

        /* 四捨五入は下記のコードでも実現可能（ただし、仕様として未定義なので処理系依存 */
        //printf("%.03lf %.03lf %.03lf\n", px, py, r);
        i++;
    }
    
    return 0;
}

/* 四捨五入する関数 */
double round_with_decimal(double src, int decimal)
{
    double dst;

    src = src * pow(10, decimal - 1);   /*処理を行う桁を10-1 の位にする*/
    if(src < 0) {
        dst = (double)(int)(src - 0.5);
    }
    else {
        dst = (double)(int)(src + 0.5);
    }
    dst = dst * pow(10, -decimal + 1);    /*処理を行った桁を元に戻す*/

    return dst;
}

