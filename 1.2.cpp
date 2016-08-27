#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char str[] ="nitin shukla";
    uint length = strlen(str);
    for(int i=0;i<length/2;++i)
    {
        char temp = str[i];
        str[i]=str[length-1-i];
        str[length-1-i]=temp;
    }
    cout<<str<<endl;
}