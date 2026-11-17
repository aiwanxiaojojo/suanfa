#include<bits/stdc++.h>
using namespace std;

vector<int> addBig(const vector<int>&a, const vector<int>&b){
    vector<int> c;
    int carry = 0;
    int len = max(a.size(),b.size());

    for(int i = 0; i < len || carry; i++){
        int sum = carry;

        if (i < (int)a.size()){
            sum+=a[i];
        }
        if (i < (int)b.size()){
            sum+=b[i];
        }
        c.push_back(sum%10);
        carry = sum / 10;
    }

    while (c.size() > 1 && c.back() == 0){
        c.pop_back();
    }
    return c;
}

vector<int>toBigInt(const string& s){
    vector<int> a;
    for (int i = (int)s.size() - 1; i >= 0; i--){
        a.push_back(s[i] - '0');
    }

    while (a.size() > 1 && a.back() == 0){
        a.pop_back();
    }

    return a;
}


void printBig(const vector<int>& a){
    for (int i = a.size()-1; i>= 0;i--){
        cout << a[i];
    }
    cout << endl;
}
int main(){
    string s1,s2;
    cin >> s1 >> s2;

    vector<int> a = toBigInt(s1);
    vector<int> b = toBigInt(s2);
    vector<int> c = addBig(a,b);

    printBig(c);
    return 0;
}