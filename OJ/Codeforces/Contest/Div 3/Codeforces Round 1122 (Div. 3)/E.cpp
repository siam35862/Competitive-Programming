#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define endl '\n'
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define input(v)       \
    for (auto &it : v) \
    cin >> it
#define inputa(a, n, ind)       \
    for (int i = 0; i < n; i++) \
    cin >> a[i + ind]
#define output(v)      \
    for (auto &it : v) \
    cout << it << " "
#define outputa(a, n, ind)      \
    for (int i = 0; i < n; i++) \
    cout << a[i + ind] << " "
#define outputl(v)     \
    for (auto &it : v) \
    cout << it << '\n'
#define outputal(a, n, ind)     \
    for (int i = 0; i < n; i++) \
    cout << a[i + ind] << '\n'

#define maxn (int)(2e5 + 100)
#define M998 998244353
#define M7 1000000007
#define inf 1e18

template <class T>
struct comparator
{
    bool operator()(const T &a, const T &b) const
    {
        return a < b;
    }
};

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using ordered_setd = tree<T, null_type, greater<T>, rb_tree_tag,
                          tree_order_statistics_node_update>;

int marked[maxn + 1];
vector<int> primes;
void sieve()
{
    int i, j;
    for (i = 3; i * i <= maxn; i += 2)
    {
        if (marked[i] == 0)
        {
            for (int j = i * i; j <= maxn; j += 2 * i)
            {
                marked[j] = 1;
            }
        }
    }
    marked[0] = marked[1] = 1;
    primes.push_back(2);
    for (i = 3; i <= maxn; i++)
        if (i % 2 == 0)
            marked[i] = 1;
        else if (marked[i] == 0)
            primes.push_back(i);
}
int primediv[maxn + 1];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();

    for (int l = 2; l < 200005; l++)
    {
        int v = l;
        int fl = 0;
        for (int j = 0; primes[j] <= v; j++)
        {
            if (primediv[v] > 0)
            {
                primediv[l] += primediv[v];
                fl = 1;
                break;
            }
            while (v % primes[j] == 0)
            {
                v /= primes[j];
                primediv[l]++;
            }
        }
        if (fl)
            continue;
        if (marked[v] == 0)
        {
            primediv[l]++;
        }
    }

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        int n, m, i, j, k;
        cin >> n >> k;
        int a[n + 1];

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        int count[n + 1] = {};
        int count2[n + 1] = {};
        for (i = 0; i < n; i++)
        {
            if (a[i] > k)
            {
                if (count[a[i]] != 0)
                    ans += count[a[i]];
                else
                {
                    int mx = 1;
                    int counter = 0;
                    for (j = 1; j * j <= a[i]; j++)
                    {
                        if (a[i] % j == 0)
                        {
                            if (j <= k)
                            {
                                if (primediv[j] > counter)
                                {
                                    mx = j;
                                }
                                else if (primediv[j] == counter)
                                    mx = max(mx, j);
                            }
                            else if (a[i] / j <= k)
                            {
                                if (primediv[a[i] / j] > counter)
                                {
                                    mx = a[i] / j;
                                }
                                else if (primediv[a[i] / j] == counter)
                                    mx = max(mx, a[i] / j);
                            }
                        }
                    }
                    int x = 1;
                    int cnt = 0;
                    int mn = a[i] / mx;
                    int temp = mn;
                    if (count2[temp] != 0)
                        cnt = count2[temp];
                    else
                    {
                        for (j = 0; primes[j] <= mn; j++)
                        {
                            while (mn % primes[j] == 0)
                            {
                                mn /= primes[j];
                                cnt += x;
                                x *= primes[j];
                            }
                        }
                        if (marked[mn] == 0)
                        {
                            cnt += x;
                        }

                        count2[temp] = cnt;
                    }
                    count[a[i]] = cnt;
                    ans += cnt;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}