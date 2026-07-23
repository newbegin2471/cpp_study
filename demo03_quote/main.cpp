#include <iostream>
int a[]={1,2,3,4,5};
int &setvalue(int i);
int main()
{
    /**
     * 当返回一个引用时，要注意被引用的对象不能超出作用域。所以返回一个对
     * 局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用。
     */
    for(int i=0;i<5;i++){
        std::cout<<a[i]<<' ';
    }
    std::cout<<std::endl;
    setvalue(2)=5;
    setvalue(3)=6;
    for(int i=0;i<5;i++){
        std::cout<<a[i]<<' ';
    }
    std::cout<<std::endl;
    return 0;
}
int &setvalue(int i){
    int &ref=a[i];
    return ref;
}