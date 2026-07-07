#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define endl '\n'
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define input(v)       \
    for (auto &it : v) \
    cin >> it
#define inputa(a, n, ind)       \
    for (int i = 0; i < n; i++) \
    cin >> a[i + ind]
#define output(v)      \
    for (auto &it : v) \
    cout << it << " "
#define outputa(a, n, ind)      \
    for (int i = 0; i < n; i++) \
    cout << a[i + ind] << " "
#define outputl(v)     \
    for (auto &it : v) \
    cout << it << '\n'
#define outputal(a, n, ind)     \
    for (int i = 0; i < n; i++) \
    cout << a[i + ind] << '\n'

#define maxn (int)(2e5 + 100)
#define M 998244353
#define inf 1e18

template <class T>
struct comparator
{
    bool operator()(const T &a, const T &b) const
    {
        return a < b;
    }
};

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using ordered_setd = tree<T, null_type, greater<T>, rb_tree_tag,
                          tree_order_statistics_node_update>;

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int a[n + 1];
    inputa(a, n, 1);

    vector<pair<int, int>> v;
    v.push_back({0,0});
    for (int i = 1; i <= n; i++)
    {
        int two = 0, five = 0;
        int temp = a[i];
        while (temp % 2 == 0)
        {
            two++;
            temp /= 2;
        }
        while (temp % 5 == 0)
        {
            five++;
            temp /= 5;
        }
       // cout<<two<<" "<<five<<endl;
        v.push_back({two, five});
    }
   // cout<<"done\n";
    vector<vector<vector<pair<int, int>>>> dp(n + 1, vector<vector<pair<int, int>>>(k + 1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=min(k+1,i);j++)
        {
            if(j==1)
            {
                dp[i][j].push_back(v[i]);
            }
            else
            {
                for(auto it:dp[i-1][j-1])
                {
                    
                    dp[i][j-1].push_back(it);
                    if(j<=k)
                    dp[i][j].push_back({it.first+v[i].first,v[i].second+it.second});
                    // cout<<i<<" "<<j-1<<" "<<it.first<<" "<<it.second<<endl;
                    // cout<<i<<" "<<j<<" "<<it.first+v[i].first<<" "<<it.second+v[i].second<<endl;
                    // cout<<endl;
                }
            }
        }
    }
    int ans=0;
    for(auto it:dp[n][k])
    {
       // cout<<it.second<<" "<<it.first<<endl;
        ans=max(ans,min(it.first,it.second));
    }
    cout<<ans<<endl;

    return 0;
}