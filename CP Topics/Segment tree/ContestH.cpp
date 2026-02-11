#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l[n], r[n];
        int i;

        cin >> l[0] >> r[0];

        int s = l[0], s1 = l[0], s2 = r[0];
        bool flag = true;
        for (i = 1; i < n; i++)
        {
            cin >> l[i] >> r[i];
            int current = s + i;
            if (current < l[i])
            {
                int news = l[i] - i;
                if (news > s2)
                {
                    flag = false;
                
                }
                else
                {
                    s = news;
                    s1 = s;
                    s2 = min(s2, r[i] - i);
                }
            }
            else if (current > r[i])
            {
                flag = false;
            
            }
            else
            {
                s2 = min(s2, r[i] - i);
            }
        }
        if (flag)
            cout << s << "\n";
        else
            cout << "I'm Stuck :(" << "\n";
    }
}