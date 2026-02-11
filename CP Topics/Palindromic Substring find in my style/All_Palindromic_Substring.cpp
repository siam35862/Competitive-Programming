#include <bits/stdc++.h>
using namespace std;
// distinct use set
// otherwise use multiset

void lcs(string &s)
{
     int i;
     int n = s.size();
     multiset<pair<int, string>> ans;
     for (i = 0; i < n; i++)
     {
          ans.insert({1, s.substr(i,1)});
          int j;
          for (j = 0; j <= 1; j++)
          {
               int l = i - 1 + j;
               int r = i + 1;
               while (l >= 0 && r < n)
               {
                    if (s[l] == s[r])
                    {
                         int len = r - l + 1;
                         ans.insert({len, s.substr(l, len)});
                         l--;
                         r++;
                    }
                    else
                         break;
               }
          }
     }
     cout<<"All Palindromic Substring:\n";
     cout<<ans.size()<<endl;
     for (auto it : ans)
          cout << it.second << endl;
}
int32_t main()
{
     int t;
     cin >> t;
     while (t--)
     {

          string s;
          cin >> s;
          int n = s.size();
          string ans;
          lcs(s);
     }
}