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
#define maxsize 100000005
#define M 1000000007

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
    tree<T, null_type, comparator<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_setd = tree<T, null_type, greater<T>, rb_tree_tag,
                          tree_order_statistics_node_update>;

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n], i;
        int odd = 0;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 1)
                odd++;
        }
        if (odd == 0 || odd == n)
        {
            for (i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        else
        {
            sort(a,a+n);
            for (i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
    }

    return 0;
}
/*
  Md. Siam Ahmed
  CSE, Khulna University
*/