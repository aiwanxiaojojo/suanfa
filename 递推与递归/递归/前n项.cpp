#include<bits/stdc++.h>
using namespace std;

int main3(){
    int n;
    cin >> n;
    double a[40] = {1,1};
    double b[40] = {1,2};

    double sum = 0;
    for(int i = 2; i <= n; i++){
        a[i] = a[i-1] + a[i-2];
        b[i] = b[i-2] + b[i-1];
    }

    for(int i = 0; i < n; i++){
        sum += a[i] / b[i];
    }
    printf("%.3lf", sum);
    return 0;
}