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

bool comparator1(pair<int,int>a,pair<int ,int>b)
{
    if(a.second<b.second)return true;
    else return false;
}

bool ispossible(vector<pair<int,int>>&v,int n,int k,int val)
{
    int cnt=1;
    int end=v[0].second;
    int i;
    for (i = 1; i < n; i++)
    {
        if(v[i].first-end>=val)
        {
            end=v[i].second;
            cnt++;
        }
    }
    return cnt>=k;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end(),comparator1);
    int end=-1;
    int cnt=0;
    for(i=0;i<n;i++)
    {
        if(v[i].first>end)
        {
            cnt++;
            end=v[i].second;
        }
        
    }
  
    if(cnt<k)cout<<-1<<endl;
    else
    {
        int ans=0;
        int l=1,r=1e9;
        while(l<=r)
        {
            int mid=(l+r)/2;

            if(ispossible(v,n,k,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        cout<<ans<<endl;
    }

    return 0;
}