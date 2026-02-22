#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxsize (int)1e4
int ans = 0;
struct node
{
    vector<int> v;
    node()
    {
        v.resize(42, 0);
    }
};
struct node tree[4 * maxsize], temp[4 * maxsize];
vector<int> a;

void merge(int cn)
{
    int left = 2 * cn;
    int right = left + 1;
    int i;
    for (i = 1; i <= 40; i++)
    {
        tree[cn].v[i] = tree[left].v[i] + tree[right].v[i];
    }
}
void merge2(int cn)
{
    int left = 2 * cn;
    int right = left + 1;
    int i;
    for (i = 1; i <= 40; i++)
    {
        temp[cn].v[i] = temp[left].v[i] + temp[right].v[i];
    }
}
void initialize(int cn, int l, int r)
{
    if (l == r)
    {

        tree[cn].v[a[l]] = 1;
    }
    else
    {
        int left = 2 * cn;
        int right = left + 1;
        int mid = (l + r) / 2;
        initialize(left, l, mid);
        initialize(right, mid + 1, r);
        merge(cn);
    }
}

void frequency_range(int cn, int l, int r, int i, int j)
{

    if (r < i || l > j)
    {
        int i = 0;
        for (i = 1; i < 41; i++)
        {
            temp[cn].v[i] = 0;
        }

        return;
    }
    if (l >= i && r <= j)
    {
        int i = 0;
        for (i = 1; i < 41; i++)
        {
            temp[cn].v[i] = tree[cn].v[i];
        }
        return;
    }
    int left = 2 * cn;
    int right = left + 1;
    int mid = (l + r) / 2;
    frequency_range(left, l, mid, i, j);
    frequency_range(right, mid + 1, r, i, j);
    merge2(cn);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int i1;

        int n, q;
        cin >> n;
        cin >> q;
        a.resize(n + 2);
        for (i1 = 0; i1 < n * 4; i1++)
        {
            int i2;
            for (i2 = 1; i2 <= 40; i2++)
            {
                tree[i1].v[i2] = 0;
                temp[i1].v[i2] = 0;
            }
        }
        int i;
        for (i = 1; i <= n; i++)
            cin >> a[i];
        initialize(1, 1, n);

        while (q--)
        {
            int a, b, c;
            cin >> a >> b;
            frequency_range(1, 1, n, a, b);

            ans = 0;
            for (int i = 1; i <= 40; i++)
            {
                if (temp[1].v[i] > 0)
                {
                    int cnt = 0;
                    int j;

                    for (j = i + i; j <= 40; j += i)
                    {
                        cnt += temp[1].v[j];
                    }
                    ans += cnt * temp[1].v[i];
                }
            }
            cout << ans;
            if (q > 0)
                cout << " ";
        }
        cout << '\n';
    }
}