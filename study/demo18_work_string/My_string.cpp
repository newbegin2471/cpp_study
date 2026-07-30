#include "My_string.h"
#include <iostream>
#include <cstring>
using namespace std;
//无参构造
        My_string::My_string():size(15),len(0),str(new char[15]{0}){}
        //有参构造
        My_string::My_string(const char *s){
            this->size=strlen(s)+1;
            this->len=strlen(s);
            this->str=new char[this->size];
            strcpy(this->str,s);
        }
        My_string::My_string(int num,const char c){
            this->len=num;
            this->size=num+1;
            this->str=new char[this->size];
            for(int i=0;i<num;i++){
                this->str[i]=c;
            }
            this->str[num]='\0';
        }
        //拷贝构造函数
        My_string::My_string(const My_string &other)
        {   
            this->size=other.size;
            this->len=other.len;
            this->str=new char[other.size];
            strcpy(this->str,other.str);
        }
        //移动拷贝构造函数
        My_string::My_string(My_string &&other){
            this->size=other.size;
            this->len=other.len;
            this->str=other.str;
            other.str=nullptr;

        }
        //赋值拷贝构造函数
        My_string &My_string::operator=(const My_string &other){
            if(&other==this){
                return *this;
            }
            delete[] this->str;
            this->len=other.len;
            this->size=other.size;
            this->str=new char[other.size];
            strcpy(this->str,other.str);
            return *this;
        }
        //移动赋值拷贝构造函数,返回值不加const为何接着使用
        My_string &My_string::operator=(My_string &&other){
            if(&other==this){
                return *this;
            }
            delete[] this->str;
            this->len=other.len;
            this->size=other.size;
            this->str=other.str;
            other.str=nullptr;
            return *this;
        }
        //析构函数
        My_string::~My_string(){
            delete[] this->str;
        }
        //判空
        bool My_string::isEmpty(){
            return this->len==0;
        }
        //尾插
        void My_string::push_back(char value){
            if(this->len+1==this->size){
                //扩容
            }
            this->str[this->len]=value;
            this->len++;
            this->str[this->len]='\0';
        }
        //尾删
        void My_string::pop_back(){
            this->len--;
            this->str[this->len]='\0';
        }
        //清空函数
        void My_string::clear(){
            this->len=0;
            this->str[this->len]='\0';
        }
        //返回c风格字符串
        char * My_string::data(){
            return this->str;
        }
        //返回实际长度
        int My_string::get_length(){
            return this->len;
        }
        //返回当前最大容量
        int My_string::get_size(){
            return this->size;
        }
        //二倍扩容
        void My_string::dbextend(){
            this->size*=2;
            char *temp=new char[this->size];
            strcpy(temp,this->str);
            delete[] this->str;
            this->str=temp;
            temp=nullptr;
        }
        //at函数实现
        char & My_string::at(int index){
            if(index<0||index>=this->len){
                cout<<"索引越界"<<endl;
                exit(-1);
            }
            return this->str[index];
        }
        //operator[]
        char & My_string::operator[](int index){
            return this->str[index];
        }
        //operator+=
        My_string & My_string::operator+=(const char ch){
            if(this->len+1==this->size){
                dbextend();
            }
            this->str[this->len]=ch;
            this->len++;
            this->str[this->len]='\0';
            return *this;
        }
        //非成员函数operator+
        My_string operator+(const My_string &l,const My_string &r){
            My_string temp;
            temp.len=l.len+r.len;
            temp.size=temp.len+1;
            temp.str=new char[temp.size];
            strcpy(temp.str,l.str);
            strcat(temp.str,r.str);
            temp[temp.len]='\0';
            return temp;
        }
        //非成员函数operator==
        bool operator==(const My_string &l,const My_string &r){
            return strcmp(l.str,r.str)==0;
        }
        //非成员函数operator!=
        bool operator!=(const My_string &l,const My_string &r){
            return strcmp(l.str,r.str)!=0;
        }
        //非成员含operator<
        bool operator<(const My_string &l,const My_string &r){
            return strcmp(l.str,r.str)<0;
        }
        //非成员函数operator>
        bool operator>(const My_string &l,const My_string &r){
            return  strcmp(l.str,r.str)>0;
        }
        //非成员函数operator<=
        bool operator<=(const My_string &l,const My_string &r){
            return  strcmp(l.str,r.str)<=0;
        }
        //非成员函数operator>=
        bool operator>=(const My_string &l,const My_string &r){
            return  strcmp(l.str,r.str)>=0;
        }
        //输入输出operator<<
        ostream & operator<<(ostream &l,const My_string &r){
            l<<r.str;
            return l;
        }
        //输入输出operator>>
        istream & operator>>(istream &l,My_string & r){
            char temp[1024];
            l>>temp;
            delete[] r.str;
            r.str=new char[strlen(temp)+1];
            strcpy(r.str,temp);
            r.len=(int)strlen(temp);
            r.size=r.len+1;
            r.str[r.len]='\0';
            return l;
        }