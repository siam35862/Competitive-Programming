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
#define maxsize 100000005
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
    tree<T, null_type, comparator<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_setd = tree<T, null_type, greater<T>, rb_tree_tag,
                          tree_order_statistics_node_update>;

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int a[n],i;
    int mn=INT_MAX;
    int val=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        val+=a[i];
        mn=min(mn,val);
    }
    int ans=0;
    if(mn>=0)ans++;
    for(i=0;i<n-1;i++)
    {
        mn-=a[i];
        if(mn>=0)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
/*
  Md. Siam Ahmed
  CSE, Khulna University
*/