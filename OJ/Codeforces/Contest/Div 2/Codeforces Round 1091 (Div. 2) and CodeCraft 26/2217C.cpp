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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        //    cout << "Case " << cs << ": ";
        int a, b, n, m, i, j, k;
        cin >> n >> m >> a >> b;
        int v1=0,v2=0;
        int cnta=0,cntb=0;
        vector<vector<int>>v(n+1,vector<int>(m+1,0));
        i=1,j=1;
        int cnt=0;
        while(cnt<10000000)
        {
            cnt++;
            if(cnt%2==1)i=((i+a-1)%n)+1;
            else j=((j+b-1)%m)+1;
            if(v[i][j]==0)
            {
                cnta++;
                v[i][j]=1;
            }
        }
        cout<<cnta<<" "<<n*m<<endl;
        if(cnta==m*n)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}

