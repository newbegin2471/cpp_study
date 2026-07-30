#ifndef __MY_STRING__
#define __MY_STRING__
#include <iostream>
using namespace std;
class My_string{
    private:
        char *str;
        int size;
        int len;
    public:
        //无参构造
        My_string();
        //有参构造
        My_string(const char *s);
        My_string(int num,const char c);
        //拷贝构造函数
        My_string(const My_string &other);
        //移动拷贝构造函数
        My_string(My_string &&other);
        //赋值拷贝构造函数
        My_string &operator=(const My_string &other);
        //移动赋值拷贝构造函数,返回值不加const为何接着使用
        My_string &operator=(My_string &&other);
        //析构函数
        ~My_string();
        //判空
        bool isEmpty();
        //尾插
        void push_back(char value);
        //尾删
        void pop_back();
        //清空函数
        void clear();
        //返回c风格字符串
        char *data();
        //返回实际长度
        int get_length();
        //返回当前最大容量
        int get_size();
        //二倍扩容
        void dbextend();
        //at函数实现
        char &at(int index);
        //operator[]
        char &operator[](int index);
        //operator+=
        My_string &operator+=(const char ch);
        //非成员函数operator+
        friend My_string operator+(const My_string &l,const My_string &r);
        //非成员函数operator==
        friend bool operator==(const My_string &l,const My_string &r);
        //非成员函数operator!=
        friend bool operator!=(const My_string &l,const My_string &r);
        //非成员含operator<
        friend bool operator<(const My_string &l,const My_string &r);
        //非成员函数operator>
        friend bool operator>(const My_string &l,const My_string &r);
        //非成员函数operator<=
        friend bool operator<=(const My_string &l,const My_string &r);
        //非成员函数operator>=
        friend bool operator>=(const My_string &l,const My_string &r);
        //输入输出operator<<
        friend ostream & operator<<(ostream &l,const My_string &r);
        //输入输出operator>>
        friend istream & operator>>(istream &l,My_string & r);
};
#endif