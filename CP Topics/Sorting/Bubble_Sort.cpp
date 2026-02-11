#include<bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int>&v,int n)
{
     int i,j;
     int f=0;
     for(i=0;i<n;i++)
     {
          for(j=0;j<n-i-1;j++)
          {
               if(v[j]>v[j+1])
               {
                    int temp=v[j+1];
                    v[j+1]=v[j];
                    v[j]=temp;
                    f=1;
               }
          }
          if(f==0)break;
     }
}
void bubble_sort(int *v,int n)
{
     int i,j;
     int f=0;
     for(i=0;i<n;i++)
     {
          for(j=0;j<n-i-1;j++)
          {
               if(v[j]>v[j+1])
               {
                    int temp=v[j+1];
                    v[j+1]=v[j];
                    v[j]=temp;
                    f=1;
               }
          }
          if(f==0)break;
     }
}
int main()
{
     int n;
     cin >> n;
     vector<int>v(n);
     int i,a[n];
     for(i=0;i<n;i++)
     {
          cin >>v[i];
          a[i]=v[i];

     }
     bubble_sort(a,n);
     for(i=0;i<n;i++)
     {
          cout<< a[i]<<" ";
          
     }
}