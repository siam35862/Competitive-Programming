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
#define inputa(a,n,ind) for(int i=0;i<n;i++)cin>>a[i+ind]
#define output(v) for(auto &it:v)cout<<it<<" "
#define outputa(a,n,ind) for(int i=0;i<n;i++)cout<<a[i+ind]<<" "
#define outputl(v) for(auto &it:v)cout<<it<<'\n'
#define outputal(a,n,ind) for(int i=0;i<n;i++)cout<<a[i+ind]<<'\n'

#define maxn (int)(2e5+100)
#define M998 998244353
#define M7 1000000007
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

<<<<<<< HEAD
=======
    int q,v;
    cin>>q>>v;
    priority_queue<int>pq;

    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int tq,wq;
            cin>>tq>>wq;
            pq.push(wq-tq);
        }
        else
        {
            int tq;
            cin>>tq;

            if(pq.empty())cout<<-1<<endl;
            else
            {
                int ans=pq.top();
                pq.pop();
                cout<<min(v,ans+tq)<<endl;
            }
        }
    }
    

>>>>>>> 4e8cbe2ca856c14642b031ace175883db1ba1dbb
    
    return 0;
}