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

#define maxn (int)(2e5+100)
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

void minimizeString(string &s)
{
    stack<char>st;
    int n=s.length();

    int i;
    for (i = 0; i < n; i++)
    {
        if(s[i]==')')
        {
            if(st.size()>=3)
            {
                char a,b,c;
                c=st.top();
                st.pop();
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();

                if(a=='('&&b=='x'&&c=='x')
                {
                    st.push(b);
                    st.push(c);
                }
                else
                {
                    st.push(a);
                    st.push(b);
                    st.push(c);
                    st.push(')');

                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
    s.clear();

    while(!st.empty())
    {
        s.push_back(st.top());
        st.pop();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        int n, m, i, j, k;

        string a,b;
        cin>>a>>b;
        minimizeString(a);
        minimizeString(b);
        if(a==b)cout<<"Yes\n";
        else cout<<"No\n";

        
    }
    
    return 0;
}