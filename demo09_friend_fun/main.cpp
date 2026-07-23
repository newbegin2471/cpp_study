#include <iostream>
/*
    类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。
尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。
    友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，该类被称为友元类，
在这种情况下，整个类及其所有成员都是友元。
    如果要声明函数为一个类的友元，需要在类定义中该函数原型前使用关键字 friend
    声明类 ClassTwo 的所有成员函数作为类 ClassOne 的友元，
需要在类 ClassOne 的定义中放置如下声明：
        friend class ClassTwo;
*/
class Box{
    double width;
    public:
        double length;
        friend void printWidth(Box box);//****************************************** */
        void setWidth(double wid);
};
void printWidth(Box box){
    std::cout<<"Width:"<<box.width<<std::endl;
}
void Box::setWidth(double wid){
    width=wid;
}
int main()
{
    Box box1;
    box1.setWidth(10.0);
    std::cout<<"width:";
    printWidth(box1);
    return 0;
}
