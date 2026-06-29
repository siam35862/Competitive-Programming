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
#define inputa(a, n, ind)   \
    for (i = 0; i < n; i++) \
    cin >> a[i + ind]
#define output(v)      \
    for (auto &it : v) \
    cout << it << " "
#define outputa(a, n, ind)  \
    for (i = 0; i < n; i++) \
    cout << a[i + ind] << " "
#define outputl(v)     \
    for (auto &it : v) \
    cout << it << '\n'
#define outputal(a, n, ind) \
    for (i = 0; i < n; i++) \
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
vector<int>dp;

int dp_can_construct_string(string &s,int j, vector<string> &wordbank)
{
    if (s.size()-j==0)
        return 1;
    if (dp[j]!=-1)
        return dp[j];
    int result = 0;
    for (auto &str : wordbank)
    {
        if (str.size() <= s.size()-j)
        {
            int i = 0;
            int flag = 1;
            for (auto ch : str)
            {
                if (ch != s[j+i])
                {
                    flag = 0;
                    break;
                }
                i++;
            }
            if (flag)
            {
                
                result=result + dp_can_construct_string(s,i+j,wordbank);
            }
        }
    }
  
    return dp[j]=result;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string target;
    vector<string> s(n);
    cin >> target;
    dp.resize(target.size()+1,-1);
    int i;
    inputa(s, n, 0);
    int ans=dp_can_construct_string(target,0,s);
    cout<<ans<<endl;

    return 0;
}