#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int cnt;
    bool endmark;
    node *next[3];
    node()
    {
        cnt = 0;
        endmark = false;
        for (int i = 0; i < 3; i++)
            next[i] = NULL;
    }
};
node *root;
int total = 0;
int ans=0;
void add(string s)
{
    node *temp = root;
    int i;
    int n = s.length();
    for (i = 0; i < n; i++)
    {

        int pos = s[i] - '0';
        if (temp->next[pos] == NULL)
            temp->next[pos] = new node();
        temp = temp->next[pos];
    }
    temp->endmark = true;
    temp->cnt++;
}
int calculation(node * temp,int count)
{
    
    for(int i=0;i<3;i++)
    {
        if(temp->next[i]!=NULL)
        {
            temp->cnt=temp->cnt+calculation(temp->next[i],count+1);
        }
        
    }
    ans=max(ans,count*temp->cnt);
    
    return temp->cnt;
    

}
void del(node *temp)
{

    for (int i = 0; i< 3; i++)
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
        ans=0;
        cs++;
       // cout << "Case " << cs << ": ";
        int n;
        cin >> n;
        root = new node();
        int i;
        for (i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            add(s);
        }
        calculation(root,0);
        cout<<ans<<endl;
        del(root);
    }
}
