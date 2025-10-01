#include<stdio.h>
#include<math.h>

int main(){
    double a,b,c,d,x1,x2;
    printf("input koefisien a: "); scanf("%lf", &a);
    printf("input koefisien b: "); scanf("%lf", &b);
    printf("input koefisien c: "); scanf("%lf", &c);

    // a = 10
    // b = 20
    // c = 30
    // d=b^2−4a.c=20^2−4(10).(30)=400−1200=−800
    d=b*b-4*a*c;

    if(d<0) printf("Imaginary");
    else {
        x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        printf("x1 = %lf        x2 = %lf", x1, x2);
    }
    return 0;
}