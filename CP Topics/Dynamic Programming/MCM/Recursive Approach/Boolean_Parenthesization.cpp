#include <bits/stdc++.h>
using namespace std;
//fully solved by Md. Siam Ahmed
void bp(string &s, int i, int j, vector<vector<int>> &siam1, vector<vector<int>> &siam2)
{
    if (i > j)
    {
        return;
    }
    else if (i == j)
    {
        if (s[i] == 'T')
        {
            siam1[i][i] = 1;
            siam2[i][i] = 0;
        }
        else
        {
            siam1[i][i] = 0;
            siam2[i][i] = 1;
        }
        return;
    }
    if (siam1[i][j] != -1)
        return;
    int t = 0, f = 0;
    for (int k = i + 1; k < j; k++)
    {
        if (s[k] != 'T' && s[k] != 'F')
        {

            bp(s, i, k - 1, siam1, siam2);
            bp(s, k + 1, j, siam1, siam2);
            int t1 = siam1[i][k - 1], t2 = siam1[k + 1][j];
            int f1 = siam2[i][k - 1], f2 = siam2[k + 1][j];
            if (s[k] == '|')
            {

                t += t1 * t2 + t1 * f2 + t2 * f1;
                f += f1 * f2;
            }
            else if (s[k] == '&')
            {
                f += f1 * f2 + t1 * f2 + t2 * f1;
                t += t1 * t2;
            }
            else if (s[k] = '^')
            {

                t += t1 * f2 + t2 * f1;
                f += t1 * t2 + f1 * f2;
            }
        }
    }
    siam1[i][j] = max(siam1[i][j], t);
    siam2[i][j] = max(siam2[i][j], f);
}

int32_t main()
{
   
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> siam1(n, vector<int>(n, -1));
    vector<vector<int>> siam2(n, vector<int>(n, -1));
    bp(s, 0, n - 1, siam1, siam2);
    cout << siam1[0][n - 1];
}