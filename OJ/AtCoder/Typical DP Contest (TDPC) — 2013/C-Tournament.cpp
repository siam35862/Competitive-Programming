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
vector<double>ans(1001,0);
vector<int>cnt(1001,0);

void calculates_probability(vector<int>&v,vector<int>players,vector<int>new_players,vector<double>prob,vector<double>prob_new)
{
    
    if(new_players.size()==players.size()/2)
    {
        //cout<<new_players.size()<<" "<<players.size();
        players.clear();
        prob.clear();
        for(auto it:new_players)players.push_back(it);
        for(auto it:prob_new)prob.push_back(it);
        new_players.clear();
        prob_new.clear();
        //cout<<"     "<<new_players.size()<<" "<<players.size()<<endl;
    }
    if(players.size()==1)
    {
        //cout<<players[0]<<" "<<ans[players[0]]<<" "<<prob[0]<<endl;
        ans[players[0]]+=prob[0];
        cnt[players[0]]++;
        
        return;
    }

    double x,y;
    int len=new_players.size();
    len*=2;
    int p=players[len];
    int q=players[len+1];
    x=1.0/(1.0+pow(10,(v[q]-v[p])/400.0));
    y=1.0/(1.0+pow(10,(v[p]-v[q])/400.0));
    x*=prob[len];
    y*=prob[len+1];
    new_players.push_back(p);
    prob_new.push_back(x);
    calculates_probability(v,players,new_players,prob,prob_new);
    new_players.pop_back();
    prob_new.pop_back();
    new_players.push_back(q);
    prob_new.push_back(y);
    calculates_probability(v,players,new_players,prob,prob_new);
}
int32_t main()
{
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;
    int n = (1 << k);
    vector<int> v(n + 1);
    int i, j;
    inputa(v, n, 1);
    vector<int> players(n);
    for (i = 1; i <= n; i++)
        players[i - 1] = i;
    vector<int>new_players;
    vector<double>probability_players(n,1);
    vector<double>prob_new_players;

    calculates_probability(v,players,new_players,probability_players,prob_new_players);
    cout<<fixed<<setprecision(10);
    cout<<cnt[1]<<endl;
    int K=1<<k;
    for (i = 1; i <= n; i++)
    {
        cout<<ans[i]/cnt[i]<<endl;
    }


    return 0;
}