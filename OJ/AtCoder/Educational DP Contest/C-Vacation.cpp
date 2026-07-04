#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int dp[n+1][3]={};
    int hp[n+1][3];
    for(int i=1;i<=n;i++)
    {
        cin>>hp[i][0]>>hp[i][1]>>hp[i][2];
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+hp[i][0];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+hp[i][1];
        dp[i][2]=max(dp[i-1][1],dp[i-1][0])+hp[i][2];
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
    return 0;
}