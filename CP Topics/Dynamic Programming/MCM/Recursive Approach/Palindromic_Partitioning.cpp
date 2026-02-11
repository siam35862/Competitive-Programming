#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ispalindrome(string &s, int i, int j)
{
    int cnt = 0;
    for (int k = i; k <= (j + i) / 2; k++)
    {
        if (s[k] != s[j - cnt])
        {
            return false;
        }
        cnt++;
    }
    return true;
}
int pp(string &a, int i, int j, vector<vector<int>> &siam)
{
    if (i >= j)
        return 0;

    if (siam[i][j] != -1)
        return siam[i][j];
    if (ispalindrome(a, i, j))
        return 0;
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left;
        int right;
        if(siam[i][k]!=-1)left=siam[i][k];
        else 
        left=siam[i][k]=pp(a,i,k,siam);

        if(siam[k+1][j]!=-1)right=siam[k+1][j];
        else 
        right=siam[k+1][j]=pp(a,k+1,j,siam);
        mn=min(mn,left+right+1);
    }
    siam[i][j] = mn;
    return mn;
}
signed main()
{
    int n;
    string s;
    cin >> s;
    n = s.size();
    vector<vector<int>> siam(n, vector<int>(n, -1));
    int ans = pp(s, 0, n - 1, siam);
    cout << ans << endl;
}