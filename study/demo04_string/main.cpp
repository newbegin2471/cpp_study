#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    // //1.初始化1
    // string s1;
    // cout<<"s1="<<s1<<endl;
    // cout<<"sizeof(s1):"<<sizeof(s1)<<endl;
    // s1="初始化1";
    // cout<<"s1="<<s1<<endl;
    // //2.初始化2
    // string s2="初始化2";
    // cout<<"s2="<<s2<<endl;
    // //初始化3
    // string s3={"初始化3"};
    // cout<<"s3="<<s3<<endl;
    // //初始化4
    // string s4(5,'a');
    // cout<<"s4="<<s4<<endl;
    // //初始化5
    // string s5("初始化5");
    // cout<<"s5="<<s5<<endl;
    //=====================================================================//
    // string s1="hello,world";
    // //定义一个字符串变量，使用拷贝构造函数初始化
    // string s2=s1;
    // cout<<"s2="<<s2<<endl;
    // string s3(s1); //显式调用拷贝构造函数
    // cout<<"s3="<<s3<<endl;

    // //两个字符串连接
    // string s4=s1+s2;
    // cout<<"s4=s1+s2:"<<s4<<endl;  

    // //4.使用常量加变量
    // string s5="hello"+s1;
    // cout<<"s5="<<s5<<endl;
    // string s6=s1+"hello";
    // cout<<"s6="<<s6<<endl;
    // //string s7="hello"+"world"; //不能将两个常量字符串相加
    // //使用一个字符串变量给另外一个字符串赋值
    // s6=s1;
    // cout<<"s6="<<s6<<endl;

    //================================string函数===============================//
    //c++风格字符串和c风格字符串转换
    // string s1="hello";
    // if(strcmp(s1.c_str(),"hello")==0){
    //     cout<<"s1==\"hello\""<<endl;
    // }
    // if(strcmp(s1.data(),"hello")==0){
    //     cout<<"s1==\"hello\""<<endl;
    // }
    // //查看长度
    // cout<<"s1.size():"<<s1.size()<<"s1.length():"<<s1.length()<<endl;
    // //判空，清空
    // if(s1.empty()){
    //     cout<<"s1为空"<<endl;
    // }else{
    //     cout<<"s1不为空"<<endl;
    // }
    // s1.clear();
    // if(s1.empty()){
    //     cout<<"s1为空"<<endl;
    // }else{
    //     cout<<"s1不为空"<<endl;
    // }
    // //插入删除函数
    // //尾插法插入
    // s1.push_back('H');
    // s1.push_back('e');
    // s1.push_back('l');
    // s1.push_back('l');
    // s1.push_back('e');
    // cout<<"s1="<<s1<<endl;
    // //尾部删除
    // s1.pop_back();
    // cout<<"s1="<<s1<<endl;
    // //两个字符串交换
    // string s2="hello";
    // cout<<"s1="<<s1<<" "<<"s2="<<s2<<endl;
    // s1.swap(s2);
    // cout<<"s1="<<s1<<" "<<"s2="<<s2<<endl;
    // //引用字符串的值
    // s1[0]='H';
    // cout<<"s1="<<s1<<endl;
    // s1.at(0)='h';
    // cout<<"s1="<<s1<<endl;
    int letter=0,num=0,blank=0,other=0;
    string s1;
    cout<<"请输入一个字符串："<<endl;
    getline(cin,s1);
    for(int i=0;i<(int)s1.size();i++){
        if(s1.at(i)>='a'&&s1.at(i)<='z'){
            letter++;
        }else if(s1.at(i)>='A'&&s1.at(i)<='Z'){
            letter++;
        }else if(s1.at(i)>='0'&&s1.at(i)<='9'){
            num++;
        }else if(s1.at(i)==' '){
            blank++;
        }else{
            other++;
        }
    }
    cout<<"letter="<<letter<<endl;
    cout<<"num="<<num<<endl;
    cout<<"blank="<<blank<<endl;
    cout<<"other="<<other<<endl;
    return 0;
}
