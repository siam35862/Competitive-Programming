#include <bits/stdc++.h>
using namespace std;

#define int long long

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

        cin >> n;
        int p, q;
        cin >> p >> q;
        if (q < p)
            swap(p, q);
        vector<int> a(n + 1);
        map<int, int> mp;
        priority_queue<int> pqq;
        priority_queue<int> pqp;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        for (auto it : mp)
        {
            if (it.second >= q)
            {
                pqq.push(it.first * it.second);
            }
            else if (it.second >= p)
            {
                pqp.push(it.first * it.second);
            }
        }

        int v1 = 0, v2 = 0, v3 = 0;
        if (!pqq.empty())
        {
            v1 = pqq.top();
            pqq.pop();
        }
        if (!pqq.empty())
        {
            v2 = pqq.top();
            pqq.pop();
        }
        if (!pqp.empty())
        {
            v3 = pqp.top();
            pqp.pop();
        }
        if (v2 > 0 && v3 > 0)
        {
            cout << max(v1 + v2, v1 + v3) << endl;
        }
        else if (v2 > 0)
        {
            cout << v1 + v2 << endl;
        }
        else if (v1 > 0 && v3 > 0)
            cout << v1 + v3 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}