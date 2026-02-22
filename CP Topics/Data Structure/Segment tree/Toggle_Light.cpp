#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxsize (int)2e5

struct node
{
    int on;
    bool prop;
};
struct node light[3 * maxsize];
void initialize(int cn, int l, int r)
{
    if (l == r)
    {
        light[cn].on = 0;
        light[cn].prop = false;
        return;
    }
    int left = 2 * cn;
    int right = left + 1;
    int mid = (l + r) / 2;
    initialize(left, l, mid);
    initialize(right, mid + 1, r);
    light[cn].on = 0;
    light[cn].prop = false;
}
void propagate(int cn, int l, int r)
{
    if (light[cn].prop == false)
        return;
    else if (l == r)
    {
        light[cn].prop = !light[cn].prop;
        if (light[cn].on == 0)
            light[cn].on = 1;
        else
            light[cn].on = 0;
        return;
    }
    int left = 2 * cn;
    int right = left + 1;
    light[cn].on = (r - l + 1) - light[cn].on;
    light[cn].prop = !light[cn].prop;
    light[left].prop = !light[left].prop;
    light[right].prop = !light[right].prop;
}
void update(int cn, int l, int r, int i, int j)
{
    propagate(cn, l, r);

    if (r < i || l > j)
        return;

    if (l >= i && r <= j)
    {
        light[cn].prop = !light[cn].prop;
        propagate(cn, l, r);
        return;
    }
    int left = 2 * cn;
    int right = left + 1;
    int mid = (l + r) / 2;
    update(left, l, mid, i, j);
    update(right, mid + 1, r, i, j);
    light[cn].on = light[left].on + light[right].on;
}

int count(int cn, int l, int r, int i, int j)
{
    propagate(cn, l, r);
    if (r < i || l > j)
        return 0;

    if (l >= i && r <= j)
    {
        return light[cn].on;
    }
    int left = 2 * cn;
    int right = left + 1;
    int mid = (l + r) / 2;
    int v1 = count(left, l, mid, i, j);
    int v2 = count(right, mid + 1, r, i, j);
    return v1 + v2;
}

signed main()
{
    int n, q;
    cin >> n >> q;
    initialize(1, 1, n);

    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // cout<<"ok\n";
        if (a == 0)
        {
            //  cout<<"in0\n";
            update(1, 1, n, b, c);
            // cout<<"ok0\n";]
            // int i;
            // for (i = 1; i < 2 * n; i++)
            // {
            //     cout << i << " " << light[i].on << " " << light[i].prop << endl;
            // }
            // cout << endl;
        }
        else
        {
            int ans = count(1, 1, n, b, c);
            cout << ans << endl;
        }
    }
}