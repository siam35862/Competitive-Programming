#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
// using namespace __gnu_pbds;
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    string s;
    cin >> s;
    int n = s.size();
    ans += stoll(s);
    int i;
    for (i = 1; i < n; i++)
    {

        int m = n - 1;
        int j;
        for (j = 0; j < (1LL << m); j++)
        {
            if (i == __popcount(j))
            {
                string temp;
                temp += s[0];
                vector<string> st;
                int k;
                int in = 1;
                for (k = m - 1; k >= 0; k--)
                {
                    if ((j & (1LL << k)) == 0)
                    {
                        temp += s[in];
                        in++;
                    }
                    else
                    {
                        st.push_back(temp);
                        temp="";
                        temp+=s[in];
                        in++;
                    }
                }
                st.push_back(temp);
                for(auto it:st)
                {
                    ans+=stoll(it);
                   // cout<<it<<" ";
                }
              //  cout<<endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// time complexity O(2^n)
