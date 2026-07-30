#include <iostream>
#include <cstring>
using namespace std;
typedef int Datatype;
class My_stack
{
    private:
        Datatype *data;
        int top;
        int capacity;
    public:
        //构造函数
        My_stack():data(new Datatype[5]),top(0),capacity(5){}
        //有参构造函数
        // My_stack(int n){
        //     top=0;
        //     capacity=n;
        //     data=new Datatype[n];
        // }
        // My_stack
        // 析构函数
        ~My_stack(){
            delete[] data;
        }
        //拷贝构造函数
        My_stack(const My_stack&other){
            this->capacity=other.capacity;
            this->top=other.top;
            this->data=new Datatype[other.capacity];
            memcpy(this->data,other.data,top*sizeof(Datatype));
        }
        My_stack(My_stack&&other){
            this->capacity=other.capacity;
            this->top=other.top;
            this->data=other.data;
            other.data=nullptr;
        }
        //拷贝赋值函数
        My_stack & operator=(const My_stack &other){
            this->capacity=other.capacity;
            this->top=other.top;
            delete[] this->data;
            this->data=new Datatype[this->capacity];
            memcpy(this->data,other.data,this->top*sizeof(Datatype));
            return *this;
        }
        //访问栈顶元素函数
        Datatype get_top()
        {
            if(this->top==0){
                cout<<"栈为空"<<endl;
                exit(-1);
            }
            return data[this->top-1];
        }
        //判空函数
        bool empty(){
            return this->top==0;
        }
        //入栈函数
        void push(Datatype val){
            if(this->top==capacity){
                void extend();
            }
            this->data[this->top]=val;
            this->top++;
        }
        //出栈函数
        Datatype pop(){
            if(this->top==0){
                cout<<"栈为空"<<endl;
                exit(-1);
            }
            this->top--;
            return this->data[this->top];
        }
        //判断两个栈是否相等
        bool operator==(const My_stack &other)const{
            if(this->capacity!=other.capacity){
                return false;
            }
            if(this->top!=other.top){
                return false;
            }
            for(int i=0;i<top;i++){
                if(this->data[i]!=other.data[i])
                    return false;
            }
            return true;
        }
        //cin输入栈中元素
        friend istream & operator>>(istream &l,My_stack &r);
        //cout输出栈中所有元素
        friend ostream & operator<<(ostream &l,const My_stack &r);
        //使用下标实现随机访问
        Datatype & operator[](int index){
            if(index<0||index>=this->top){
                cout<<"越界访问"<<endl;
            }
            return this->data[index];
        }
        //扩容
        void extend(){
            this->capacity*=2;
            Datatype *temp=new Datatype[this->capacity];
            memcpy(temp,this->data,this->top*sizeof(Datatype));
            delete[] this->data;
            this->data=temp;
            temp=nullptr;
        }
};
istream & operator>>(istream &l,My_stack &r){
    Datatype num;
    while(l>>num){
        if(r.top==r.capacity){
            void extend();
        }
        r.data[r.top]=num;
        r.top++;
    }
    return l;

}
ostream & operator<<(ostream &l,const My_stack &r){
    for(int i=0;i<r.top;i++){
        l<<r.data[i]<<' ';
    }
    return l;
}
int main()
{
    My_stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout<<s1<<endl;
    cout<<"pop:";
    s1.pop();
    cout<<s1<<endl;
    cout<<"访问栈顶元素:"<<s1.get_top()<<endl;
    cout<<"判空:"<<boolalpha<<s1.empty()<<endl;
    My_stack s2;
    cin>>s2;
    cout<<s2<<endl;
    cout<<"s1==s2:"<<boolalpha<<(s1==s2)<<endl;
    return 0;
}