#include <iostream>
using namespace std;
int t(int n){
    int res;
    if(n == 1){
        res = 2;
    }else{
    res = t(n-1)*2;
    }
    return res;
}
int main1(){
    int n;
    cin >> n;
    cout << t(n) << endl;


    

    return 0;
}
