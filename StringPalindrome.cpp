#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int i=0;
    int j=str.length()-1;
    int flag=1;
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            flag=0;
            break;
        }
        i++;
        j--;
    }
    if(flag==0)
    {
        cout<<"FALSE";
    }
    else{
        cout<<"TRUE";
    }

}