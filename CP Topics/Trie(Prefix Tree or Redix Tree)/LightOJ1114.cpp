#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int cnt;
    bool endmark;
    node *next[53];
    node()
    {
        cnt = 0;
        endmark = false;
        for (int i = 0; i < 53; i++)
            next[i] = NULL;
    }
};
node *root;
int total = 0;
void add(string s)
{
    node *temp = root;
    int i;
    int n = s.length();
    for (i = 0; i < n; i++)
    {
        int pos;
        if (s[i] >= 97)
        {
            pos = s[i] - 71;
        }
        else
            pos = s[i] - 'A';
        if (temp->next[pos] == NULL)
            temp->next[pos] = new node();
        temp = temp->next[pos];
    }
    temp->endmark = true;
    temp->cnt++;
}
int count(string s)
{
    node *temp = root;
    int i;
    int n = s.length();
    for (i = 0; i < n; i++)
    {
        int pos;
        if (s[i] >= 97)
        {
            pos = s[i] - 71;
        }
        else
            pos = s[i] - 'A';
        if (temp->next[pos] == NULL)
            return 0;
        temp = temp->next[pos];
    }

    return temp->cnt;
}
void del(node *temp)
{

    for (int i = 0; i < 53; i++)
    {
        if (temp->next[i] != NULL)
            del(temp->next[i]);
    }
    delete (temp);
}
signed main()
{
    int t;
    cin >> t;
    int cs = 0;
    while (t--)
    {
        cs++;
        cout << "Case " << cs << ":\n";
        int n;
        cin >> n;
        root = new node();
        int i;
        for (i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if (s.size() > 2)
                sort(s.begin() + 1, s.end() - 1);

            add(s);
        }
        int m;
        cin >> m;
        cin.ignore();
        string s[m];
        for (i = 0; i < m; i++)
        {
            getline(cin, s[i]);
            int ans = 1;
            string a;
            int j = 0;
            int l = s[i].size();
            while (j < l)
            {
                if (s[i][j] == ' ')
                {
                    if (a.size() > 2)
                        sort(a.begin() + 1, a.end() - 1);

                    if (a.size() > 0)
                    {
                        int cnt = count(a);
                        ans *= cnt;
                    }
                    a = "";
                }
                else if (j == l - 1)
                {
                    a += s[i][j];
                    if (a.size() > 2)
                        sort(a.begin() + 1, a.end() - 1);

                   if (a.size() > 0)
                    {
                        int cnt = count(a);
                        ans *= cnt;
                    }
                    a = "";
                }
                else
                {
                    a += s[i][j];
                }
                j++;
            }
            cout << ans << endl;
        }
        del(root);
    }
}