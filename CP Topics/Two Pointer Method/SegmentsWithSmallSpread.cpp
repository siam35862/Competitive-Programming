#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct Stack{
    vector<int>st,mx={LONG_LONG_MIN},mn={LONG_LONG_MAX};
    void push(int data)
    {
        st.push_back(data);
        mx.push_back(max(data,mx.back()));
        mn.push_back(min(data,mn.back()));
    }
    int pop()
    {
        int data=st.back();
        st.pop_back();
        mx.pop_back();
        mn.pop_back();
        return data;

    }
    int mn_()
    {
         return mn.back();
    }
    int mx_()
    {
        return mx.back();
    }
    
};
Stack s1,s2;
void add(int data)
{
    s2.push(data);
}
void remove()
{
    if(s1.st.empty())
    {
        while(!s2.st.empty())
        {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}
signed main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int l=0,r=0;
    int diff;
    int ans=0;
    for(r=0;r<n;r++)
    {
        add(a[r]);
        diff=(max(s1.mx_(),s2.mx_())-min(s1.mn_(),s2.mn_()));
        
        while(diff>k)
        {
            remove();
            diff=(max(s1.mx_(),s2.mx_())-min(s1.mn_(),s2.mn_()));
           
            l++;
        }
       
        ans+=r-l+1;
    } 
    cout<<ans<<endl;
}