#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Array Size : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];}
    int hash[50]={0};
    for(int i=0;i<n;i++)
    {
        hash[arr[i]] +=1;
    }
    int q;
    cin>>q;
    int brr[q];
    for(int i=0;i<q;i++){cin>>brr[i];}
    while(q--)
    {
        cout<<brr[q]<<" "<<hash[brr[q]]<<endl;
    }
    return 0;
}   