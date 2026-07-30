#include <iostream>
#include <cstring>
using namespace std;
typedef int datatype_t;
class MyVector{
    private:
        datatype_t *first=nullptr;
        datatype_t *last=nullptr;
        datatype_t *end=nullptr;
    public:
        MyVector(int size=2)
        {
            first = new datatype_t[size];
            last=first;
            end=first+size;
        }
        //析构函数
        ~MyVector()
        {
            delete [] first;
            first = last = end = nullptr;
        }
        //手动定义拷贝构造函数
        MyVector(const MyVector &other)
        {
            int len=other.last-other.first;
            int size=other.end-other.first;
            this->first=new datatype_t[size];
            memcpy(this->first,other.first,len*sizeof(datatype_t));
            this->last=this->first+len;
            this->end=this->first+size;
        }
        //顺序表判空
        bool empty()const
        {
            return this->first==this->last; 
        }
        //判满
        bool full() const
        {
            return this->last==this->end;
        }
        //二倍扩容
        void greater()
        {
            int size=this->end-this->first;
            int len=this->last-this->first;
            datatype_t *temp=new datatype_t[2*size];
            memcpy(temp,this->first,size*sizeof(datatype_t));
            delete[] first;
            this->first =temp;
            this->last=this->first+size;
            this->end=this->first+2*size;
        }
        //尾插
        bool push_back(datatype_t val)
        {
            if(this->full()){
                this->greater();
            }
            *last=val;
            last++;
            return true;
        }
        //尾删
        void pop_back(){
            if(this->empty()){
                return;
            }
            --last;
        }
        //重载==
        bool operator==(const MyVector &other) const
        {
            int size1=this->end-this->first;
            int size2=other.end-other.first;
            if(size1!=size2)
                return false;
            int len1=this->last-this->first;
            int len2=other.last-other.first;
            if(len1!=len2)
                return false;
            for(int i=0;i<len1;i++){
                if(this->first[i] != other.first[i])
                    return false;
            }
            return true;
        }
        MyVector & operator=(const MyVector &other){
            int len=other.last-other.first;
            int size=other.end-other.first;
            delete[] this->first;
            this->first=nullptr;
            this->first=new datatype_t[size];
            memcpy(this->first,other.first,len*sizeof(datatype_t));
            this->end=this->first+size;
            this->last=this->first+len;
            return *this;
        }
        //元素访问at
        datatype_t & at(int index){
            int len=this->last-this->first;
            if(index<0||index>=len){
                cout<<"越界访问"<<endl;
                exit(-1);
            }
            return this->first[index];
        }
        //operator[]
        datatype_t & operator[](int index){
            return this->first[index];
        }
        //返回容纳元素数
        int size() const
        {
            return this->last-this->first;
        }
        //返回当前存储空间容纳元素数
        int capacity()const
        {
            return this->end-this->first;
        }
        //清除内容
        bool clear(){
            this->last=this->first;
            return true;
        }
        friend ostream & operator<<(ostream &l,const MyVector & r);
        //operrator<
        bool operator<(const MyVector &other)const
        {
            datatype_t *p1=this->first;
            datatype_t *p2=other.first;
            while(1){
                if(p2==other.last)
                    return false;
                if(p1==this->last){
                    return true;
                }
                if(*p1<*p2){
                    return true; 
                }
                p1++;
                p2++;
            }
        }



};

//operator<<
ostream & operator<<(ostream &l,cosnt MyVector & r){
    l<<'[';
    int len=r.last-r.first;
    for(int i=0;i<len;i++){
        if(i<len-1)
        l<<r.first[i]<<',';
        else
        l<<r.first[i];
    }
    l<<']';
    return l;
}
int main()
{
    MyVector v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    cout<<v1<<endl;
    MyVector v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(4);
    cout<<boolalpha<<(v1<v2)<<endl;
    return 0;
}