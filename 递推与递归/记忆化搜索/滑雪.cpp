#include<bits/stdc++.h>
using namespace std;
    int r,c;
    int h[110][110];
    int dp[110][110];
    int dx[5] = {0, 0,1, 0, -1};
    int du[5] = {0, 1, 0, -1, 0};
    int ans;
int main(){
        cin >> r >> c;
        for (int i = 1; i <= r; i++){
            for (int j = 1; j <= c; j++) {
                cin >> h[i][j];
            }
        }


 
    return 0;
}