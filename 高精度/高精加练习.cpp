#include<bits/stdc++.h>
using namespace std;

vector<int> addBig(vector<int>& a,vector<int>& b){
    vector<int> c;
    int carry = 0;
    int len = max(a.size(),b.size());
    for(int i = 0; i < len; i++){
        int sum = carry;
        if(i < a.size()){
            sum += a[i];
        }
        if(i < b.size()){
            sum += b[i];
        }
        c.push_back(carry%10);
        carry = sum /10;
    }
    while(c.size()>1&&c.back() == 0){
        c.pop_back();
    }
    return c;
}
vector<int> toBigInt(string x){
    vector<int> f;
    for(int i = 0; i < x.size(); i++){
        f.push_back(x[i]-'0');;

    }
    while(f.size()>1&&f.back()== 0){
        f.pop_back();
    }
    return f;
}
void printBig(vector<int>& x){
    for(int i = x.size()-1; i >= 0; i--){
        cout << x[i];
    }
}

int main(){
    string a, b;
    cin >> a >> b;
    vector<int>x = toBigInt(a);
    vector<int>y = toBigInt(b);
    vector<int>sum = addBig(x,y);
    printBig(sum);
    return 0;
}