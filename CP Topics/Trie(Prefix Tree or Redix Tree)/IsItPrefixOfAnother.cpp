#include <bits/stdc++.h>
using namespace std;

struct node
{
    bool endmark;
    node *next[10 + 1];
    node()
    {
        endmark = false;
        int i;
        for (i = 0; i < 11; i++)
        {
            next[i] = NULL;
        }
    }
};
node *root;
bool answer = true;

void add(string s)
{
    node *current = root;
    int n = s.size();
    int i;
    for (i = 0; i < n; i++)
    {
        int pos = s[i] - '0';
        if (current->next[pos] == NULL)
        {
            current->next[pos] = new node();
        }
        current = current->next[pos];
    }
    current->endmark = true;
}
void search(node *temp, int endm)
{

    if (answer == false)
        return;
    if (temp->endmark == true)
        endm++;

    if (endm == 2)
    {
        answer = false;
        return;
    }
    for (int i = 0; i < 11; i++)
    {

        if (temp->next[i] != NULL)
        {
            search(temp->next[i], endm);
        }
    }
}
void del(node *temp)
{

    for (int i = 0; i < 11; i++)
    {
        if (temp->next[i] != NULL)
            del(temp->next[i]);
    }
    delete (temp);
}

int main()
{
    int t;
    cin >> t;
    int cs=0;
    while (t--)
    {
        cs++;
        cout<<"Case "<<cs<<": ";

        answer = true;
        root = new node();
        int n;
        cin >> n;
        int i;
        for (i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            add(s);
        }
        search(root, 0);
        del(root);
        if (answer)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
