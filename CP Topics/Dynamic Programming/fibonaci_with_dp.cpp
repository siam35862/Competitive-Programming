#include<bits/stdc++.h>
using namespace std;
int cn=0;
int fibonacci(vector<int>&fib,int n)
{
     cn++;
     if (n==0||n==1)
     {
          return fib[n]=n;
     }
     else if(fib[n]!=0)
     {
          return fib[n];
     }
     else 
     return fib[n]=fibonacci(fib,n-1)+fibonacci(fib,n-2);
}
int main()
{
     
     int n;
     cin>>n;
     vector<int>fib(n+1,0);
     fibonacci(fib,n-1);
     for(int i=0;i<n;i++)
     {
          cout<<fib[i]<<" ";
     }
     cout<<endl<<cn<<endl;
}