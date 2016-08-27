#include<iostream>

using namespace std;
int main()
{
    string str="abcdefgh";
    string result="";
    for(int i=0;i<str.size();)
    {
        int j=i;
        int count=0;
        while(str[j]==str[j+1])
        {
            count++;
            j++;
        }
        result+=str[i];
        if(count)
        {
            result+=to_string(count+1);
            i=i+count+1;
        }
        else
            i++;    
    }
    cout<<result<<endl;
}
//could be done inplace also. Try that next time.