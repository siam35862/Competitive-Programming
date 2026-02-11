#include <bits/stdc++.h>
using namespace std;
#define vs 20105
int cnt;
map<string, int> mp;
vector<vector<int>> v(vs);
vector<int> visited(vs, 0);
vector<int> visited2(vs, 0);
int getIndex(string s)
{
    if (mp[s] == 0)
    {
        mp[s] = cnt++;
    }
    return mp[s];
}
bool detect = false;
void cycleDetect(int ind)
{
    if (visited[ind] == 2)
        return;

    visited[ind] = 1;                                             
    int i;
    int n = v[ind].size();
    for (i = 0; i < n; i++)
    {
        if (visited[v[ind][i]] == 0)
            cycleDetect(v[ind][i]);
        else if (visited[v[ind][i]] == 1)
        {
            detect = true;
            return;
        }
    }
    visited[ind] = 2;
}
int main()
{
    int t;
    cin >> t;
    int cs;
    for (cs = 1; cs <= t; cs++)
    {
        detect = false;
        mp.clear();
        visited2.clear();
        for (int i = 0; i < vs; i++)
        {
            visited[i] = 0;
            v[i].clear();
        }
        cnt = 1;
        cout << "Case " << cs << ": ";
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;
            int ina = getIndex(a), inb = getIndex(b);
            v[inb].push_back(ina);
        }
        for (int i = 0; i <= 2 * n; i++)
        {
            if (detect == true)
                break;
            if (v[i].size() > 0 && visited[i] == 0)
            {

                cycleDetect(i);
            }
        }
        if (detect == false)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}