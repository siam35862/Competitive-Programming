#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m], i, j;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
        cin >> b[i];
    // sort(a, a + n);
    // sort(b, b + m);
    int countOfB[m];
    j = 0;
    i = 0;
    while (i < n || j < m)
    {
        if (j == m || i < n && a[i] < b[j])
            i++;
        else
        {
            countOfB[j] = i;
            cout << countOfB[j] << " " ;//<< b[j] << endl;
            j++;
        }
    }
}