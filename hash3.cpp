// hashing using map
#include <iostream>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    map<int, int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    cout<<"Enter Query Array Size"<<"\n";
    int m;
    cin>>m;
    int brr[m];
    for(int i=0;i<m;i++)
    {
        cin>>brr[i];
    }
    for(int i=0;i<m;i++)
    {
        cout<<brr[i]<<" "<<mp[brr[i]]<<"\n";
    }



}