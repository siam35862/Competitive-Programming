#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int cnt = 0;
int getIndexOfString(string s)
{
    if (mp[s] == 0)
    {
        mp[s] = ++cnt;
    }
    return mp[s];
}
vector<int> parent;
void makeSet(string s)
{
    int index = getIndexOfString(s);
    parent.push_back(index);
}
int findParent(int c)
{

    if (c == parent[c])
        return c;
    else
        return parent[c] = findParent(parent[c]);
}
void makeUnion(string a, string b)
{

    int i = getIndexOfString(a), j = getIndexOfString(b);
    if (i >= parent.size()) // a is not exist in parent
    {
        makeSet(a);
    }
    if (j >= parent.size()) // b is not exist in parent
    {
        makeSet(b);
    }
    int u = findParent(i);
    int v = findParent(j);
    if (u != v)
    {
        parent[u] = v;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        parent.push_back(0); // dummy for making parent is 1 indexed
        cout << "Enter  0 for making friendship between two person,\n";
        cout << " 1 for finding friendship between two person,\n";
        cout << " -1 to terminate.\n";
        while (true)
        {
            string type;
            cin >> type;
            if (type == "-1")
            {
                mp.clear();
                parent.clear();
                cnt = 0;
                break;
            }
            else if (type == "0")
            {
                string a, b;
                cin.ignore();
                cout << "Enter two person for making friendship(two person separated by new line):\n";
                getline(cin, a);
                getline(cin, b);
                makeUnion(a, b);
            }
            else if (type == "1")
            {
                string a, b;
                cin.ignore();
                cout << "Enter two person for finding friendship(two person separated by new line):\n";
                getline(cin, a);
                getline(cin, b);
                int i = getIndexOfString(a), j = getIndexOfString(b);
                if (i >= parent.size() || j >= parent.size())
                {
                    if (i >= parent.size() && j >= parent.size())
                    {
                        cout << "Both are not exist in list.\n";
                        mp[a] = 0;
                        mp[b] = 0;
                        cnt--;
                    }

                    else if (i >= parent.size())
                    {
                        cout << a << " does not exist in list.\n";
                        mp[a] = 0;
                    }
                    else if (j >= parent.size())
                    {
                        cout << b << " does not exist in list.\n";
                        mp[b] = 0;
                    }
                    cnt--;
                }
                else
                {
                    int u = findParent(i);
                    int v = findParent(j);
                    if (u == v)
                        cout << "They are friend.\n";
                    else
                        cout << "They are not friend.\n";
                }
            }
            else
                cout << "Invalid Input.\n";
        }
    }
}