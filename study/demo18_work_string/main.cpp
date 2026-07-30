#include <iostream>
#include "My_string.h"
using namespace std;
int main()
{
    My_string s1="hello,";
    My_string s2="world";
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s1+s2<<endl;
    My_string s3=s1+s2;
    s3+='!';
    cout<<s3<<endl;
    cout<<"operator==:"<<boolalpha<<(s1==s2)<<endl;
    cout<<"operator!=:"<<boolalpha<<(s1!=s2)<<endl;
    cout<<"operator<:"<<boolalpha<<(s1<s2)<<endl;
    cout<<"operator>:"<<boolalpha<<(s1>s2)<<endl;
    cout<<"operator<=:"<<boolalpha<<(s1<=s2)<<endl;
    cout<<"operator>=:"<<boolalpha<<(s1>=s2)<<endl;
    My_string s4;
    cin>>s4;
    cout<<s4<<endl;
    return 0;
}