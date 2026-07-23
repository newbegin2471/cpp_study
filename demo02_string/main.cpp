#include <iostream>
#include <string>
int main()
{
    std::string str1="hello,";
    std::string str2="world";
    std::string str3;
    std::cout<<"str1:"<<str1<<"\tsize:"<<str1.size()<<std::endl;
    std::cout<<"str2"<<str2<<"\tsize"<<str2.size()<<std::endl;
    str3=str1+str2;
    std::cout<<"str3=str1+str2"<<str3<<"\tsize:"<<str3.size()<<std::endl;
    return 0;
}
