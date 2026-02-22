#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int cnt;
    bool endmark;
    unordered_map<char, node*> next;  // Use unordered_map to reduce space complexity

    node()
    {
        cnt = 0;
        endmark = false;
    }
};

node *root;
int ans = 0;

void add(string s)
{
    node *temp = root;
    for (char ch : s)
    {
        if (temp->next.find(ch) == temp->next.end())
            temp->next[ch] = new node();
        temp = temp->next[ch];
    }
    temp->endmark = true;
    temp->cnt++;
}

int calculation(node *temp, int count)
{
    for (auto p : temp->next)
    {
        temp->cnt += calculation(p.second, count + 1);
    }
    ans = max(ans, count * temp->cnt);
    return temp->cnt;
}

void del(node *temp)
{
    for (auto &p : temp->next)
    {
        del(p.second);
    }
    delete temp;
}

signed main()
{
    int t;
    cin >> t;
    int cs = 0;
    while (t--)
    {
        ans = 0;
        cs++;
        cout << "Case " << cs << ": ";
        int n;
        cin >> n;
        root = new node();
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            add(s);
        }
        calculation(root, 0);
        cout << ans << endl;
        del(root);
    }
}
