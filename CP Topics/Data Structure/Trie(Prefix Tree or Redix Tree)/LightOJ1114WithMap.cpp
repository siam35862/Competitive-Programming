#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int cs = 0;
    while (t--)
    {
        cs++;
        cout << "Case " << cs << ":\n";
        unordered_map<string, int> mp;
        int n;
        cin >> n;

        int i;
        for (i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if (s.size() > 2)
                sort(s.begin() + 1, s.end() - 1);

            mp[s]++;
        }
        int m;
        cin >> m;
        cin.ignore();
        vector<string> s(m);
        for (i = 0; i < m; i++)
        {
            getline(cin, s[i]);
            int ans = 1;
            string a;
            int j = 0;
            int l = s[i].size();
            while (j < l)
            {
                if (s[i][j] == ' ')
                {
                    if (a.size() > 2)
                        sort(a.begin() + 1, a.end() - 1);

                    if (a.size() > 0)

                    {
                        int cnt = mp[a];
                        ans *= cnt;
                    }
                    a = "";
                }
                else if (j == l - 1)
                {
                    a += s[i][j];
                    if (a.size() > 2)
                        sort(a.begin() + 1, a.end() - 1);

                    if (a.size() > 0)

                    {
                        int cnt = mp[a];
                        ans *= cnt;
                    }
                    a = "";
                }
                else
                {
                    a += s[i][j];
                }
                j++;
            }
            cout << ans << endl;
        }
    }
}