#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxSize (int)1e5
int tree[maxSize + 1];
void update(int ind, int n, int val)
{
    while (ind <= n)
    {
        tree[ind] += val;
        ind = ind + (ind & (-ind));
    }
}
int query(int ind)
{
    int sum = 0;
    while (ind > 0)
    {
        sum += tree[ind];
        ind -= ind & (-ind);
    }
    return sum;
}

int inversion_count(int *a, int n)
{
    int i, count = 0;
    for (i = n - 1; i >= 0; i--)
    {
        int cnt = query(a[i] - 1);

        count += cnt;
        update(a[i], maxSize, 1);
    }

    for (i = 0; i <= maxSize; i++)
    {
        tree[i] = 0;
    }
    return count;
}

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
        int a[n], b[n], i;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        int tinvs = inversion_count(a, n);
        sort(b, b + n);
        vector<int> maxofi(100001, 0);
        vector<int> minofi(100001, 0);
        for (i = 0; i < n - 1; i++)
        {
            if (b[i] != b[i + 1])
            {
                minofi[b[i + 1]] = i + 1;
                maxofi[b[i]] = n - i - 1;
            }
        }
        for (i = 0; i < n - 1; i++)
        {
            if (b[i] != b[i + 1])
            {
                minofi[b[i + 1]] = i + 1;
                maxofi[b[i]] = n - i - 1;
            }
        }
        int invs[n];
        invs[0] = tinvs;

        for (i = 1; i < n; i++)
        {
            invs[i] = invs[i - 1] - minofi[a[i - 1]] + maxofi[a[i - 1]];
        }
        int ans[n] = {};
        for (i = 1; i < n; i++)
        {
            int gcd = __gcd(i, n);
            if (gcd == i)
            {
                int j;
                int mn = INT_MAX;
                for (j = 0; j < n; j += i)
                {
                    mn = min(invs[j], mn);
                }
                ans[i] = mn;
            }
            else
                ans[i] = ans[gcd];
            cout << ans[gcd];
            if (i < n - 1)
                cout << ' ';
        }

        cout << '\n';
    }
}