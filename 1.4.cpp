#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string str="ni  ti  mi huk          ";
    string replace="%20";
    for(int i=0;i<str.size();++i)
    {
        if(str[i]==' ')
        {
            int count=replace.size()-1;
            while(count)
            {
                for(int j=str.size()-1;j>i;j--)
                {
                    str[j]=str[j-1];
                }
                count--;
            }
            int l=i;
            for(int k=0;k<replace.size();k++)
            {
                str[l]=replace[k];
                l++;
            }
        }
    }
    cout<<str<<endl;
}
