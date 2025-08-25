#include <iostream>
using namespace std;
int main()
{
    string str;
    cout<<"Enter the String : ";
    cin>>str;
    int hash[256]={0};
    int l=str.size();
    int i;
    cout<<l;
    for(i=0;i<l;i++)
    {
        hash[str[i]] +=1;
    }
    cout<<"Enter Query array size"<<"\n";
    int n;
    cin>>n;
    char ch[n];
    cout<<"Enter Query array elements"<<"\n";
    for(i=0;i<n;i++)
    {
        cin>>ch[i];
    }
    cout<<"------------------"<<"\n";
    cout<<"      OUTPUT      "<<"\n";
    cout<<"-------------------"<<"\n";
    for(i=0;i<n;i++)
    {
        cout<<ch[i]<<" "<<hash[ch[i]]<<"\n";
    }


}