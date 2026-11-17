#include<bits/stdc++.h>
using namespace std;

int t(int n){
    if(n == 1){
        return 1;
    }
    return t(n-1) * n;
}
int main2(){
    int n;
    cin >> n;
    cout << t(n) << endl;
    return 0;
}