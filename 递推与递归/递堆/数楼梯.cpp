#include<bits/stdc++.h>
using namespace std;
vector<int> addBig(const vector<int>&a,const vector<int>&b){
    vector<int> c;
    int carry = 0;
    int len = max((int)a.size(),(int)b.size());

    for ( int i = 0; i < len || carry; i++){
        int sum = carry;

        if (i < (int)a.size()){
            sum += a[i];
        }
        if (i < (int)b.size()){
            sum += b[i];
        }

        c.push_back(sum % 10);
        carry = sum / 10;
    }
    while(c.size() > 1 && c.back() == 0){
        c.pop_back();
    }

    return c;
}

void printBig(const vector<int>&a){
    for(int i = (int)a.size() -1; i >= 0; i--){
        cout << a[i];
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if ( n <= 1){
        cout << 1 << endl;
        return 0;
    }
    vector<int> f0 = {1};
    vector<int> f1 = {1};

    for (int i = 2; i <= n; i++){
        vector<int> f2 = addBig(f0,f1);
        f0 = f1;
        f1 = f2;
    }
    printBig(f1);
    return 0;
}