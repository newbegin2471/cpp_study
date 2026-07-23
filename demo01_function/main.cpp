#include <iostream>
void fun1(int &x);
int main()
{
    // int a=1;
    // std::cout<<"a的地址:"<<&a<<std::endl;
    // fun1(a);
    auto func=[](){
        std::cout<<"hello,world"<<std::endl;
    };
    func();
    //捕获，值捕获只读
    
    return 0;
}
void fun1(int &x){
    std::cout<<"引用调用:"<<x<<"地址:"<<&x<<std::endl;
}