#include <iostream>
#include <cstring>
using namespace std;
class My_string
{
    private:
        char *ptr;
        int size;
        int len;
    public:
        //构造函数
        My_string():size(15)
        {
            this->ptr=new char[size];
            this->ptr[0]='\0';
            this->len=0;
        }
        //构造函数
        My_string(const char *src)
        {
            this->size=(int)(strlen(src)+1);
            this->ptr=new char[this->size];
            this->len=this->size-1;
            strcpy(this->ptr,src);
        }
        //构造函数
        My_string(int num,char value)
        {
            this->len=num;
            this->size=num+1;
            this->ptr=new char[this->size];
            for(int i=0;i<num;i++){
                this->ptr[i]=value;
            }
            this->ptr[num]='\0';
        }
        //拷贝构造函数
        My_string(const My_string &other)
        {
            this->len=other.len;
            this->size=other.size;
            if(other.ptr==nullptr){
                this->ptr=nullptr;
                return;
            }
            this->ptr=new char[other.size];
            strcpy(this->ptr,other.ptr);
        }
        //移动拷贝构造函数
        My_string(My_string &&other)
        {
            this->len=other.len;
            this->size=other.size;
            if(other.ptr==nullptr){
                this->ptr=nullptr;
                return;
            }
            this->ptr=new char[other.size];
            strcpy(this->ptr,other.ptr);
            other.ptr=nullptr;
        }
        //赋值拷贝构造函数
        My_string & operator=(const My_string &other)
        {
            if(this==&other){
                return *this;
            }
            delete[] ptr;
            this->len=other.len;
            this->size=other.size;
            if(other.ptr==nullptr){
                ptr=nullptr;
                return *this;
            }
            this->ptr=new char[other.size];
            strcpy(this->ptr,other.ptr);
            return *this;
        }
        //移动赋值拷贝构造函数
        My_string & operator=(My_string &&other)
        {
            if(this==&other){
                return *this;
            }
            delete[] this->ptr;
            this->len=other.len;
            this->size=other.size;
            this->ptr=new char[other.size];
            strcpy(this->ptr,other.ptr);
            return *this;
        }
        //析构函数
        ~My_string(){
            delete[] ptr;
        }
        //判空
        bool isEmpty(){
            return this->len==0;
        }
        //尾插
        void push_back(char value){
            if(this->len+1==this->size){
                //扩容
                dbextend();
            }
            this->ptr[this->len]=value;
            this->len++;
            this->ptr[this->len]='\0';
        }
        //尾删
        void pop_back(){
            this->len--;
            this->ptr[this->len]='\0';
        }
        //清空函数
        void clear(){
            this->len=0;
            this->ptr[0]='\0';
        }
        //返回c风格字符串
        char *data()
        {
            return this->ptr;
        }
        //返回实际长度
        int get_length(){
            return this->len;
        }
        //返回当前最大容量
        int get_size(){
            return this->size;
        }
        //二倍扩容
        void dbextend(){
            char *temp=new char[this->size*2]{0};
            char *temp1=this->ptr;
            this->ptr=temp;
            strcpy(this->ptr,temp1);
            delete[] temp1;
            temp=nullptr;
            temp1=nullptr;
            this->size*=2;
        }
        //at函数实现
        char &at(int index)
        {
            if(index<0||index>=this->len){
                perror("索引越界访问");
            }
            return this->ptr[index];
        }

};
int main()
{
    My_string str("hello,world");
    My_string str1;
    My_string str2(5,'A');
    cout<<"str:"<<str.data()<<endl;
    cout<<"str1:"<<str1.data()<<endl;
    cout<<"str2:"<<str2.data()<<endl;
    cout<<"str:size:"<<str.get_size()<<endl;
    cout<<"push_back:"<<endl;
    str.push_back('!');
    cout<<"length:"<<str.get_length()<<endl;
    cout<<"str:"<<str.data()<<endl;
    cout<<"pop_back:"<<endl;
    str.pop_back();
    cout<<"str:"<<str.data()<<endl;
    cout<<"this.at(0):"<<str.at(0)<<endl;
    cout<<"str.at(0)=H:"<<endl;
    str.at(0)='H';
    cout<<"str:"<<str.data()<<endl;
    cout<<"str.isEmpty():"<<boolalpha<<str.isEmpty()<<endl;
    cout<<"length:"<<str.get_length()<<endl;
    cout<<"size(扩容后):"<<str.get_size()<<endl;
    return 0;
}