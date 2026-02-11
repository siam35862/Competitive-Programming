#include <bits/stdc++.h>
using namespace std;
//lexicographically smallest
void lcs(string &s, string &ans)
{
     int st = 0;
     int mxl = 1;
     ans += s[0];
     int i;
     int n = s.size();
     for (i = 0; i < n - 1; i++)
     {
          int j;
          for (j = 0; j <= 1; j++)
          {
               int l = i - 1 + j;
               int r = i + 1;
               while (l >= 0 && r < n)
               {
                    if (s[l] == s[r])
                    {
                         l--;
                         r++;
                    }
                    else
                         break;
               }
               int ln = (r - l - 1);
               if (ln > mxl)
               {
                    mxl = ln;
                    ans = s.substr(l + 1, mxl);
               }
               else if (mxl == ln)
               {
                    ans = min(ans, s.substr(l + 1, mxl));
               }
          }
     }
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
          lcs(s, ans);
          cout << ans << endl;
     }
}