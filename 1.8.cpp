#include<iostream>
using namespace std;
int main()
{
    string s1="nitinshukla";
    string s2="tinshuklani";
    string s3=s1+s1;
    //if s1 is rotation of s2 then s2 will 
    //definitely be a substring of s1s1
    size_t found = s3.find(s2);
    if (found!=std::string::npos)
        cout<<"Is rotation."<<endl;
    else
        cout<<"Is not rotation."<<endl;
}