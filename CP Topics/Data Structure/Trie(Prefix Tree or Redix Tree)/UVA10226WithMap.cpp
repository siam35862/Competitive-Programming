#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int main()
{
    cout << fixed << setprecision(4);

    int t;
    cin >> t;
    cin.ignore();
    map<string, int> mp;
    string s;
    while (t--)
    {

        while (getline(cin, s))
        {

            if (s == "")
            {
                if (v.size() != 0)
                {
                    sort(v.begin(), v.end());
                    int n = v.size();
                    for (int i = 0; i < n; i++)
                    {
                        if (mp[v[i]] != 0)
                        {
                            cout << v[i] << " ";
                            double ans = 100.0 * mp[v[i]] / n;
                            mp[v[i]] = 0;
                            cout << ans << endl;
                        }
                    }
                    cout << endl;
                    mp.clear();
                    v.clear();
                    break;
                }
            }
            else if (!cin.eof())
                break;
            else
            {
                v.push_back(s);
                mp[s]++;
            }
        }
        if (v.size() != 0)
        {
            sort(v.begin(), v.end());
            int n = v.size();
            for (int i = 0; i < n; i++)
            {
                if (mp[v[i]] != 0)
                {
                    cout << v[i] << " ";
                    double ans = 100.0 * mp[v[i]] / n;
                    mp[v[i]] = 0;
                    cout << ans << endl;
                }
            }

            mp.clear();
            v.clear();
        }
    }
}