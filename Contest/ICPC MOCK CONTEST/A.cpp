#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define pf push_front
#define beg begin()
#define end end()
#define size size()

signed main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        int pos[n + 1], i;
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
            pos[a[i]] = i;
        }
        int cost = 0;
        if ((n & (n + 1)) == 0)
            cost = 1;
        vector<pair<int, int>> v;
        int index = log2(n);
        int zindex = 1 << index;
        int findex = 1 << (index + 1);
        findex -= 1;
        for (i = n; i > zindex; i--)
        {
            if (pos[i] != i)
            {
                int cindex;
                if (i == findex)
                    cindex = 1;
                else
                    cindex = findex - i;
                if (pos[i] != cindex)
                {

                    int temp = pos[i];
                    if (temp > zindex)
                    {
                        int ccindex = findex - temp;
                        v.push_back(make_pair(temp, ccindex));
                        swap(a[temp], a[ccindex]);
                        swap(pos[a[temp]], pos[a[ccindex]]);
                    }
                    temp = pos[i];
                    v.push_back(make_pair(temp, zindex));
                    swap(a[temp], a[zindex]);
                    swap(pos[a[temp]], pos[a[zindex]]);
                    v.push_back(make_pair(cindex, zindex));
                    swap(a[cindex], a[zindex]);
                    swap(pos[a[cindex]], pos[a[zindex]]);
                }
                v.push_back(make_pair(cindex, i));
                swap(a[i], a[cindex]);
                pos[i] = i;
                pos[a[cindex]] = cindex;
            }
        }
        for (i = 1; i < zindex; i++)
        {
            if (pos[i] != i)
            {
                int cindex;
                cindex = zindex;
                if (pos[i] != cindex)
                {
                    v.push_back(make_pair(pos[i], cindex));
                    int temp = pos[i];
                    swap(a[cindex], a[temp]);
                    pos[i] = cindex;
                    pos[a[temp]] = temp;
                }
                v.push_back(make_pair(cindex, i));
                swap(a[i], a[cindex]);
                pos[i] = i;
                pos[a[cindex]] = cindex;
            }
        }
        cout << cost << endl;
        int m = v.size;
        cout << m << endl;
        for (i = 0; i < m; i++)
        {
            cout << v[i].first << " " << v[i].second << endl;
        }
        // for(i=1;i<=n;i++)cout<<a[i]<<" ";
        // cout<<endl;
    }
}