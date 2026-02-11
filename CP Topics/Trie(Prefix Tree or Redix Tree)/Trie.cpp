#include <bits/stdc++.h>
using namespace std;

struct node
{
    bool endmark;
    node *next[26 + 1];
    node()
    {
        endmark = false;
        int i;
        for (i = 0; i < 27; i++)
        {
            next[i] = NULL;
        }
    }
};
node *root;
void add(string s)
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
    current->endmark = true;
}
bool search(string s)
{
    node *current = root;
    int n = s.size(),i;
    for (i = 0; i < n; i++)
    {
        int pos = s[i] - 'a';
        if (current->next[pos] == NULL)
        {
            return false;
        }
        current = current->next[pos];
    }
    return current->endmark;
}
void del( node *temp )
{
   
    for(int i=0;i<27;i++)
    {
        if(temp->next[i]!=NULL)del(temp->next[i]);
    }
    delete(temp);
}
int main()
{
    root = new node();
}
