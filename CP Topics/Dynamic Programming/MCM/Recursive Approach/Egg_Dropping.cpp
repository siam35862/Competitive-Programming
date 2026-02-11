#include<bits/stdc++.h>
using namespace std;
#define int long long

int eggdropping(int e,int f,vector<vector<int>>&siam)
{
    
    if(e==1||f==0||f==1)return f;
    if(siam[e][f]!=-1)return siam[e][f];
    int mn=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        int temp=1+max(eggdropping(e-1,k-1,siam),eggdropping(e,f-k,siam));
        mn=min(temp,mn);
    }
    return siam[e][f]=mn;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int e,f;
    cin>>e>>f;
    vector<vector<int>>siam(e+1,vector<int>(f+1,-1));
    int ans=eggdropping(e,f,siam);
    cout<<ans<<endl;
    return 0;
}