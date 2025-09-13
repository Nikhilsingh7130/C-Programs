#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr({1,2,3,3,7,8,9,9,9,11});
    int low=0,high=arr.size()-1,ans=arr.size(),num=9;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid]<=num){ans=mid;low=mid+1;}
        else{high=mid-1;}
        cout<<ans<<" ";
    }
    cout<<"\n"<<ans;
    return 0;
}