#include <iostream>
/**
 * C++ 内联函数是通常与类一起使用
 * 个函数定义为内联函数，则需要在函数名前面放置关键字 inline，在调用函数之前需要对函数进行定义
 * 如果已定义的函数多于一行，编译器会忽略 inline 限定符
 * 在类定义中的定义的函数都是内联函数，即使没有使用 inline 说明符
 */
inline int add(int a,int b){
    return a+b;
}
int main()
{
    int a=1,b=2;
    std::cout<<"a+b="<<add(a,b)<<std::endl;
    return 0;
}
