#include <bits/stdc++.h>
using namespace std;
#define int long long
int max_4(int a, int b, int c, int d)
{
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    sort(v.begin(), v.end());
    return v[3];
}
int min_4(int a, int b, int c, int d)
{
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    sort(v.begin(), v.end());
    return v[0];
}
signed main()
{

    int n1, n2, n3, n4;
    int l1, r1, l2, r2, l3, r3, l4, r4;
    cin >> n1;
    int a1[n1];
    int i;
    for (i = 0; i < n1; i++)
        cin >> a1[i];
    sort(a1, a1 + n1);
    l1 = a1[0];
    r1 = a1[n1 - 1];
    cin >> n2;
    int a2[n2];
    int i;
    for (i = 0; i < n2; i++)
        cin >> a2[i];
    sort(a2, a2 + n2);
    l2 = a2[0];
    r2 = a2[n2 - 1];
    cin >> n3;
    int a3[n3];
    int i;
    for (i = 0; i < n3; i++)
        cin >> a3[i];
    sort(a3, a3 + n3);
    l3 = a3[0];
    r3 = a3[n3 - 1];
    cin >> n4;
    int a4[n4];
    int i;
    for (i = 0; i < n4; i++)
        cin >> a4[i];
    sort(a4, a4 + n4);
    l4 = a4[0];
    r4 = a4[n4 - 1];
    int l =min_4(r1,r2,r3,r4);
    int r=max_4(l1,l2,l3,l4);
}