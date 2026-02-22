#include <bits/stdc++.h>
using namespace std;
int ans = 0;
struct node
{
    bool endmark;
    node *next[26 + 1];
    int pos;
    node()
    {
        pos = 0;
        endmark = false;
        int i;
        for (i = 0; i < 27; i++)
        {
            next[i] = NULL;
        }
    }
};
node *root;
void add(string s, int k)
{
    node *current = root;
    int n = s.size();
    int i;
    for (i = 0; i < n; i++)
    {
        int pos = s[i] - 'a';
        if (current->next[pos] == NULL)
        {
            current->next[pos] = new node();
        }
        current = current->next[pos];
    }
    current->pos = k;
    current->endmark = true;
}
void search(string s,int k)
{
    node *current = root;
    int n = s.size();
    int i;
    for (i = 0; i < n; i++)
    {
        int pos = s[i] - 'a';
        if (current->next[pos] == NULL)
        {
            return ;
        }
        current = current->next[pos];
    }
    return;
}

int main()
{
    root = new node();
    int n;
    cin >> n;
    vector<string> s(n);
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> s[i];
        add(s[i],i);
    }
    for(i=0;i<n;i++)
    {
        ans=s[i].size();
        if(i==0)cout<<ans<<"\n";
        else 
        {
            search(s[i],i);
            cout<<ans<<"\n";
        }
    }
}
