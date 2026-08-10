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
#define M 998244353
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

        cin >> n >> m;
        int x, y;
        cin >> x >> y;
        int a[x], b[y];
        inputa(a, x, 0);
        inputa(b, y, 0);
        reverse(a, a + x);
        reverse(b, b + y);
        int ans = 0;
        {
            int ans1 = 0;
            int l1 = min(x, n - 1);
            int l2 = min(y, m);
            int i = 0, j = 0;
            int cnt1 = 0, cnt2 = 0;
            int cnt = 0;
            while ((i < x || j < y) && (cnt1 < l1 || cnt2 < l2))
            {
                if ((i < l1 && j < l2) && (cnt1 < l1 && cnt2 < l2))
                {

                    if (a[i] == b[j])
                    {
                        cnt++;
                        if (i + 1 == x && j + 1 == y)
                        {
                            ans1 += a[i];
                            i++;
                            j++;
                            cnt1++;
                        }
                        else if (i + 1 == x)
                        {
                            ans1 += a[i];
                            i++;
                            j++;
                            cnt1++;
                        }
                        else if (j + 1 == y)
                        {
                            ans1 += b[j];
                            i++;
                            j++;
                            cnt2++;
                        }
                        else
                        {
                            if (a[i + 1] <= b[j + 1])
                            {
                                ans1 += a[i];
                                i++;
                                j++;
                                cnt1++;
                            }
                            else
                            {
                                ans1 += b[j];
                                i++;
                                j++;
                                cnt2++;
                            }
                        }
                    }
                    else if (a[i] > b[j])
                    {
                        ans1 += a[i];
                        i++;
                        cnt1++;
                    }
                    else
                    {
                        ans1 += b[j];
                        j++;
                        cnt2++;
                    }
                }
                else if (i < x && cnt1 < l1)
                {
                    if (j > 0 && a[i] == b[j - 1])
                        i++;
                    if (i < x)
                    {
                        ans1 += a[i];
                        i++;
                        cnt1++;
                    }
                }
                else if (j < y && cnt2 < l2)
                {
                    if (i > 0 && a[i - 1] == b[j])
                        j++;
                    if (j < y)
                    {
                        ans1 += b[j];
                        j++;
                        cnt2++;
                    }
                }
                else
                    break;
            }
            int counter = 0;

            set<int> pq;
            cout<<a[i]<<endl;
            while (i < x)
            {
                pq.insert(a[i]);
                i++;
            }

            int cnt3 = cnt1 + cnt2;
            int len = 0;
            int ll = pq.size();
            auto it = pq.end();
            it--;
            cout << cnt1 << " " << cnt2 << endl;
            cout << ans1 << endl;
            while (counter < cnt && cnt2 < l2 && len < ll && ll > 0)
            {
                int v = *it;
                it--;
                ans1 += v;
                counter++;
                cnt2++;
                len++;
            }
            cout << cnt1 << " " << cnt2 << endl;
            cout << ans1 << endl;
            ans = max(ans, ans1);
        }
        {
            int ans1 = 0;
            int l1 = min(x, n);
            int l2 = min(y, m - 1);
            int i = 0, j = 0;
            int cnt1 = 0, cnt2 = 0;
            int cnt = 0;
            while ((i < x || j < y) && (cnt1 < l1 || cnt2 < l2))
            {
                if ((i < l1 && j < l2) && (cnt1 < l1 && cnt2 < l2))
                {

                    if (a[i] == b[j])
                    {
                        cnt++;
                        if (i + 1 == x && j + 1 == y)
                        {
                            ans1 += a[i];
                            i++;
                            j++;
                            cnt1++;
                        }
                        else if (i + 1 == x)
                        {
                            ans1 += a[i];
                            i++;
                            j++;
                            cnt1++;
                        }
                        else if (j + 1 == y)
                        {
                            ans1 += b[j];
                            i++;
                            j++;
                            cnt2++;
                        }
                        else
                        {
                            if (a[i + 1] <= b[j + 1])
                            {
                                ans1 += a[i];
                                i++;
                                j++;
                                cnt1++;
                            }
                            else
                            {
                                ans1 += b[j];
                                i++;
                                j++;
                                cnt2++;
                            }
                        }
                    }
                    else if (a[i] > b[j])
                    {
                        ans1 += a[i];
                        i++;
                        cnt1++;
                    }
                    else
                    {
                        ans1 += b[j];
                        j++;
                        cnt2++;
                    }
                }
                else if (i < x && cnt1 < l1)
                {
                    if (j > 0 && a[i] == b[j - 1])
                        i++;
                    if (i < x)
                    {
                        ans1 += a[i];
                        i++;
                        cnt1++;
                    }
                }
                else if (j < y && cnt2 < l2)
                {
                    if (i > 0 && a[i - 1] == b[j])
                        j++;
                    if (j < y)
                    {
                        ans1 += b[j];
                        j++;
                        cnt2++;
                    }
                }
                else
                    break;
            }
            int counter = 0;

            set<int> pq;
            while (i < x)
            {
                pq.insert(a[i]);
                i++;
            }

            int cnt3 = cnt1 + cnt2;
            int len = 0;
            int ll = pq.size();
            auto it = pq.end();
            it--;

            while (counter < cnt && cnt3 < (l1 + l2) && len < ll && ll > 0)
            {
                int v = *it;
                it--;
                ans1 += v;
                counter++;
                cnt3++;
                len++;
            }
            cout << cnt1 << " " << cnt2 << endl;
            cout << ans1 << endl;
            ans = max(ans, ans1);
        }
        cout << ans << endl;
    }

    return 0;
}