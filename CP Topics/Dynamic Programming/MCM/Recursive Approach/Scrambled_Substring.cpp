#include <bits/stdc++.h>
using namespace std;
//aditya verma
bool ss(string a, string b, map<pair<string, string>, int> &mp)
{
    if (a == b)
        return true;
    if (a.size() != b.size())
        return false;
    else if (a.size() <= 1)
        return false;
    if (mp[{a, b}] == 1)
        return false;
    else if (mp[{a, b}] == 2)
        return true;
    int k;
    int n = a.size();
    bool f=false;
    for (k = 1; k < n; k++)
    {
        bool f1=ss(a.substr(0,k),b.substr(0,k),mp)&&ss(a.substr(k,n-k),b.substr(k,n-k),mp);
        bool f2=ss(a.substr(0,k),b.substr(n-k,k),mp)&&ss(a.substr(k,n-k),b.substr(0,n-k),mp);
        f|=f1;
        f|=f2;
       
    }
    if(f)mp[{a,b}]=2;
    else mp[{a,b}]=1;
    return f; 
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;
    
    map<pair<string, string>, int> mp;
    bool f=ss(a,b,mp);
    if(f)cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}