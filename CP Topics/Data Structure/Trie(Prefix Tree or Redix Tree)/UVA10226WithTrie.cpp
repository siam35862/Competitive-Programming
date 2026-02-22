#include <bits/stdc++.h>
using namespace std;
struct node
{
    int cnt;
    bool endmark;
    node * next[54];
    node()
    {
        cnt=0;
        endmark=false;
        for(int i=0;i<54;i++)next[i]=NULL;
    }
};
node * root;
void add(string s)
{
    node *temp=root;
    int i;
    int n=s.length();
    for(i=0;i<n;i++)
    {
        int pos;
        if(s[i]==' ')pos=0;
        else if(s[i]>=97)
        {
            pos=s[i]-70;
        }
        else pos=s[i]-64;
        if(temp->next[pos]==NULL)temp->next[pos]=new node();
        temp=temp->next[pos];
    }
    temp->endmark=true;
    temp->cnt++;
}
int count(string s)
{
    node *temp=root;
    int i;
    int n=s.length();
    for(i=0;i<n;i++)
    {
        int pos;
        if(s[i]==' ')pos=0;
        else if(s[i]>=97)
        {
            pos=s[i]-70;
        }
        else pos=s[i]-64;
        
        temp=temp->next[pos];
    }
   
    return temp->cnt;
}
int main()
{
    cout << fixed << setprecision(4);

    int t;
    cin >> t;

    while (t--)
    {
        root=new node();
        int n;
        cin >> n;
        
        int i;
        set<string>st;
        vector<string>v;
        for(i=0;i<n;i++)
        {
            string s;
            cin >> s;
            add(s);
            v.push_back(s);
        }
        sort(v.begin(),v.end());
        for(i=0;i<n;i++)
        {
            st.insert(v[i]);
        }
       
        
        //
        for(auto it: st)
        {
            int cnt=count(it);
            double ans=100.0*cnt/n;
            cout<<it<<" "<<ans<<endl;
        }
    }
}