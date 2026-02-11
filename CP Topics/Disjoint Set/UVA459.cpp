#include <bits/stdc++.h>
using namespace std;
int parent[100000];
void makeSet(int n)
{
    parent[n] = n;
}
int findParent(int c)
{
    if (c == parent[c])
        return c;
    else
        return parent[c] = findParent(parent[c]);
}
void makeFriend(int a, int b)
{
    int u = findParent(b);
    int v = findParent(a);
    if (u != v)
    {
        parent[u] = v;
    }
}

int main()
{
    int t;
    scanf("%d\n", &t);

    int a = 0, b = t;

    while (t--)
    {
        char start = 'A', end;
        scanf("%c", &end);

        for (int i = start; i <= end; i++)
        {
            makeSet(i);
        }
        char s[3];
        while (getchar() != '\n')
            ;
        while (gets(s))
        {
            if (strlen(s) == 0)
                break;

            else
            {
                makeFriend(s[0], s[1]);
            }
        }

        a++;
        // update
        set<int> st;
        for (int i = start; i <= end; i++)
        {
            parent[i] = findParent(i);
            st.insert(parent[i]);
        }

        cout << st.size() << endl;
        if (a < b)
            puts("");
        for (int i = start; i <= end; i++)
        {
            parent[i] = 0;
        }
    }
}