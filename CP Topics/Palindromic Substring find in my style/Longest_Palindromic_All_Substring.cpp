#include <bits/stdc++.h>
using namespace std;
//lexicographically sorted and distinct
struct List
{
     int st = -1, len = 0;
     struct List *next;
};
void add(struct List *(&tail), int st, int len)
{
     struct List *newnode = (struct List *)malloc(sizeof(struct List));
     newnode->next = NULL;
     newnode->st = st;
     newnode->len = len;
     tail->next = newnode;
     tail = newnode;
}
void lcs(string &s)
{

     int mxl = 0;
     int i;
     int n = s.size();
     struct List *head, *tail;

     for (i = 0; i < n; i++)
     {
          int j;
          for (j = 0; j <= 1; j++)
          {
               int l = i - 1 + j;
               int r = i + 1;
               while (l >= 0 && r < n)
               {
                    if (s[l] == s[r])
                    {
                         l--;
                         r++;
                    }
                    else
                         break;
               }
               int ln = (r - l - 1);
               if (ln > mxl)
               {
                    mxl = ln;
                    struct List *newnode = (struct List *)malloc(sizeof(struct List));
                    newnode->next = NULL;
                    newnode->st = l + 1;
                    newnode->len = ln;
                    head = newnode;
                    tail = newnode;
               }
               else if (mxl == ln)
               {
                    add(tail, l + 1, mxl);
               }
          }
     }
     set<string> ans;
     struct List *temp = head;
     while (temp != NULL)
     {
          ans.insert(s.substr(temp->st, temp->len));
          temp = temp->next;
     }
     cout << "Longest Palindromic All Substring:\n";
     cout<<ans.size()<<endl;
     for (auto it : ans)
          cout << it << endl;
}
int32_t main()
{
     int t;
     cin >> t;
     while (t--)
     {

          string s;
          cin >> s;
          int n = s.size();
          string ans;
          lcs(s);
     }
}