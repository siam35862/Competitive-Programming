#include <bits/stdc++.h>
using namespace std;
struct node
{
    int cnt;
    bool endmark;
    node *next[54];
    node()
    {
        cnt = 0;
        endmark = false;
        for (int i = 0; i < 54; i++)
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
        if (s[i] == ' ')
            pos = 0;
        else if (s[i] >= 97)
        {
            pos = s[i] - 70;
        }
        else
            pos = s[i] - 64;
        if (temp->next[pos] == NULL)
            temp->next[pos] = new node();
        temp = temp->next[pos];
    }
    temp->endmark = true;
    temp->cnt++;
}
void solve(node *temp, string s)
{

    int i;
    if (temp->endmark == true)
    {
        cout << s << " ";
        double ans = 100.0 * temp->cnt / total;
        cout << ans << endl;
    }
    for (i = 0; i < 54; i++)
    {

        if (temp->next[i] != NULL)
        {
            char ch = 0;
            if (i == 0)
            {
                s += " ";
            }
            else
            {
                if (i >= 1 && i <= 26)
                {
                    ch = 'A' + i - 1;
                }
                else
                    ch = 'a' + i - 27;
                s += ch;
            }
            solve(temp->next[i], s);
            s.pop_back();
        }
    }
}
int main()
{
    cout << fixed << setprecision(4);

    int t;
    scanf("%d\n\n", &t);
    int a = 0;
    int b = t;
    while (t--)
    {
        root = new node();
        total = 0;
        int f = 0;
        int n;
        char str[35];
        while (gets(str))
        {
            if (strlen(str) == 0)
                break;
            string s = string(str);

            add(s);
            total++;
            f = 1;
        }
        if (f == 1)
        {
            string temp;
            solve(root, temp);
            a++;
            if (a < b)
                puts("");
        }
    }
}