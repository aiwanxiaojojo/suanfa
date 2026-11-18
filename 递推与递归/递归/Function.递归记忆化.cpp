#include<bits/stdc++.h>
using namespace std;

long long dp[21][21][21];
bool visited[21][21][21];
long long dfs(long long a, long long b, long long c ){
    if (a <= 0 || b<=0 || c <= 0)return 1;
    if(a >20 || b > 20 || c > 20)return dfs(20,20,20);

    if(visited[a][b][c]){
        return dp[a][b][c];
    }

    long long result;

    if( a<b && b < c){
        result = dfs(a,b,c-1) + dfs(a,b-1,c-1) - dfs(a,b-1,c);
    }
    else{
        result = dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);
    }
    visited[a][b][c] = true;
    dp[a][b][c] = result;
    return result;
}
int main4(){
    long long a, b, c;
    while(cin >> a >> b >> c){
        if(a == -1 && b == -1 && c == -1){
            break;
        }
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,dfs(a,b,c));

    }

    return 0;
}
