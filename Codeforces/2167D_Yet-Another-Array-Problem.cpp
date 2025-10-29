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
#define maxsize 1005
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

bool marked[maxsize+1];
vector<int>primes;

void sieve()
{
    marked[0]=marked[1]=1;
    for(int i=3;i*i<=maxsize;i++)
    {
        if(marked[i]==0)
        {
            for(int j=i*i;j<=maxsize;j+=2*i)
            {
                marked[j]=1;
            }
        }
    }
    primes.push_back(2);
    for(int i=3;i<=maxsize;i+=2)if(marked[i]==0)primes.push_back(i);

}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n], i;
       
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            
        }
        vector<int>ans;
        for(i=0;i<n;i++)
        {
            int f=0;
            for(auto it:primes)
            {
                if(__gcd(a[i],it)==1)
                {
                    f=1;
                     ans.push_back(it);
                    break;
                }
            }
           

        }
        srt(ans);
        cout<<ans[0]<<endl;
    }

    return 0;
}
/*
  Md. Siam Ahmed
  CSE, Khulna University
*/