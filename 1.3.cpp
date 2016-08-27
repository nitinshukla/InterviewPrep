#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int arr[256] ={0};
    string str1="nitin shukla";
    string str2="niitn suhlka";
    bool isPermutation=true;
    for(int i=0;i<str1.size();++i)
    {
        int val = str1[i];
        arr[val]++;
    }

    for(int j=0;j<str2.size();++j)
    {
        int val = str2[j];
        if(arr[val]>0)
        {
            arr[val]--;
        }
        else
        {
            isPermutation=false;
            break;
        }
    }
    for(int i=0;i<256;i++)
    {
        if(arr[i]>0)
        {
            isPermutation=false;   
        }
    }
    cout<<isPermutation<<endl;
}
