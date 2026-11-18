#include<bits/stdc++.h>
using namespace std;

string dfs(string &s, int &pos){
    string result;
    while(pos < (int)s.size() && s[pos] != ']'){
        if(s[pos] >= 'A' && s[pos] <= 'Z'){
            result.push_back(s[pos]);
            pos++;
        }else {
            pos++;

            int count = 0;
            while(pos < (int)s.size() && s[pos] >= '0' && s[pos] <= '9'){
                count = count*10 + (s[pos] - '0');
                pos++;
            }
            string index;
            index = dfs(s,pos);
            pos++;
            for(int i = 0; i < count; i++){
                result += index;
            }
        }
    }
    return result;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int pos = 0;
    cout << dfs(s,pos);


    return 0;
}