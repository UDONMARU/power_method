#include <stdio.h>

double max(int, double *);
double min(int, double *);

int main(){

    double a1[3] = {1.0,1.0,1.0}; // y
    double a2[3] = {0.0,0.0,0.0}; // x
    double b[3][3] = {{1.0,1.0,2.0},{3.0,1.0,1.0},{1.0,2.0,1.0}};
    double c[3] = {0.0,0.0,0.0}; // スタック用
    double d[3] = {10.0,8.0,4.0}; // yi/xi
    int i, j, k;
    double u; // 固有値

    printf("%f\n", max(3, d));
    printf("%f\n", min(3, d));

    while (max(3, d) - min(3, d) > 0.00001){
        for (i = 0; i < 3; i++){
            a2[i] = a1[i];
            c[i] = a1[i];
            a1[i] = 0.0;
        }
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++)
                a1[i] += b[i][j] * c[j];
        }
        u = max(3, a1);
        for (i = 0; i < 3; i++){
            d[i] = a1[i] / a2[i];
            a1[i] /= u;
        }
    }
    printf("%f\n", u);
    return 0;
}

double max(int n, double *s){
    int i;
    double max = 0;
    for (i = 0; i < n; i++)
        if (max < s[i])
            max = s[i];
    return max;
}

double min(int n, double *s){
    int i;
    double min = 100.0;
    for (i = 0; i < n; i++)
        if (min > s[i])
            min = s[i];
    return min;
}