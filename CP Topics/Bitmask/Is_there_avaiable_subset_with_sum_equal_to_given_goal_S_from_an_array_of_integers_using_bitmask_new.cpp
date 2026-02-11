#include<bits/stdc++.h>
using namespace std;
void is_there_available_required_subset(int *array,int n,long long target_sum)
{
    int mask;
    for(mask=0;mask<(1<<n);mask++)//total combination number
    {
        long long sum=0;
        int i;
        for(i=0;i<n;i++)
        {
            if((mask&(1<<i)))sum+=array[i];
        }
        if(sum==target_sum)
        {
            cout<<"There is available a subset with given condition\n";
            return ;
        }
    }
    cout<<"There is not available a subset with given condition\n";
}
int main()
{
    cout<<"Enter an integer(<20): ";
    int n;//the number of total integer
    cin >>n;
    int i;
    long long target_sum=0;
    int array[n];//array of integers
    cout<<"Enter "<<n<<" integers: "; 
    for(i=0;i<n;i++)
    {
        cin>>array[i];//array input
    }
    cout << "Target sum of finding subset: ";
    cin>>target_sum;
    is_there_available_required_subset(array,n,target_sum);// function call
    
}