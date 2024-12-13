#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
    n * s must be less than or equal 1e8
*/
vector<vector<int>> siam;
bool isSubsetSum(int n, int s, int *a)
{
    if (s == 0)
        return true;
    if (n == 0)
        return false;
    if (siam[n][s] != -1)
        return siam[n][s];
    if (a[n - 1] <= s)
    {
        return siam[n][s] = max(isSubsetSum(n - 1, s, a), isSubsetSum(n - 1, s - a[n - 1], a));
    }
    else
        return siam[n][s] = isSubsetSum(n - 1, s, a);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,s;
    cin>>n>>s;
    int a[n],i;
    for(i=0;i<n;i++)cin>>a[i];
    siam.resize(n+1);
    for(i=0;i<=n;i++)siam[i].resize(s+1,-1);
    bool ans=isSubsetSum(n,s,a);
    if(ans)cout<<"YES\n";
    else cout<<"NO\n";

}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/