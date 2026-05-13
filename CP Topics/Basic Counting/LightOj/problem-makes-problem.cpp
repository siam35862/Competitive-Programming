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
#define input(v) for(auto &it:v)cin>>it
#define inputa(a,n,ind) for(i=0;i<n;i++)cin>>a[i+ind]
#define output(v) for(auto &it:v)cout<<it<<" "
#define outputa(a,n,ind) for(i=0;i<n;i++)cout<<a[i+ind]<<" "
#define outputl(v) for(auto &it:v)cout<<it<<'\n'
#define outputal(a,n,ind) for(i=0;i<n;i++)cout<<a[i+ind]<<'\n'

#define maxn (int)(2e6+100)
#define M 1000000007

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

int fact[maxn+1];

void factCalc()
{
    fact[0]=1;
    for(int i=1;i<=maxn;i++)
    {
        fact[i]=(fact[i-1]*i)%M;
    }
}
int bin_exp(int a, int b, int mod)
{
    if (b == 0) return 1;

    int val = bin_exp(a, b / 2, mod);

    if (b % 2 == 0) return (1LL * val * val) % mod;
    else return (1LL * val * val % mod * a) % mod;
}

int nCr(int n,int r)
{
    int p=fact[n];
    int q1=fact[r];
    int q2=fact[n-r];
    int q=(q1*q2)%M;

    int ncr=(p*bin_exp(q,M-2,M))%M;
    return ncr;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    factCalc();

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        cout << "Case " << cs << ": ";
        int n, m, i, j, k;
        cin>>n>>m;
        
        int ans=nCr(n+m-1,m-1);
        cout<<ans<<endl;
    }
    
    return 0;
}