#include <iostream>
/*======================================*/
// C++ 访问控制：
// private 的含义：同一个类内的所有函数，可以访问该类任意对象的私有成员
// 不是：只能访问 this 对象的私有成员。
// 只要函数属于 Person 类，不管是 this-> 还是别的 Person 对象，私有成员都能直接读写。
/**
 * 类访问修饰符
 * public:公有：对外提供的接口函数（API）。类内部、子类、外部代码
 * private:私有：仅限家族内部（继承体系）使用的数据。类内部、子类
 * protected:受保护：仅限本类内部
 * 当你定义一个子类时（如 class B : public A），
 * 冒号后面的 public 也是一种访问修饰符，
 * 它决定了父类的成员在子类中"表现"成什么样。
 * 
 */
// class Box{
//     public:
//         double length;
//         double breadth;
//         double height;
//         void setLength(double len);
//         void setBreadth(double Bre);
//         void setHeight(double Hei);
//         double getVolume();
// };
// void Box::setLength(double len){
//     length=len;
// }
// void Box::setBreadth(double bre){
//     breadth=bre;
// }
// void Box::setHeight(double hei){
//     height=hei;
// }
// double Box::getVolume(){
//     return length*breadth*height;
// }
// int main()
// {
//     Box box1;
//     Box box2;
//     double volume=0.0;
//     box1.setLength(1);
//     box1.setBreadth(2);
//     box1.setHeight(3);
//     box2.setLength(2);
//     box2.setBreadth(3);
//     box2.setHeight(4);
//     volume=box1.getVolume();
//     std::cout<<"box1体积:"<<volume<<std::endl;
//     volume=box2.getVolume();
//     std::cout<<"box2体积:"<<volume<<std::endl;
//     return 0;
// }
/**************************************************************************/
/**
 * 类构造函数，类析构函数
 * 类的构造函数是类的一种特殊的成员函数，它会在每次创建类的新对象时自动执行。
 * 构造函数的名称与类的名称完全相同，且没有返回类型（连 void 也不能有）。
 * 构造函数通常用于为成员变量设置初始值。
 * 若未显式定义构造函数，编译器会自动生成一个不执行任何操作的默认构造函数。
 * 类的析构函数是类的一种特殊的成员函数，在对象的生命周期结束时（离开作用域或被 delete）自动执行，用于释放对象占用的资源
 * 析构函数的名称与类的名称完全相同，只是在前面加了个波浪号（~）作为前缀
 */
class Line{
    public:
        Line(double len); //构造函数，与类同名，无返回值
        void setLength(double len);
        double getLength();
    private:
        double length;
};

Line::Line(double len){
    std::cout<<"构造函数自动执行"<<std::endl;
    length=len;
}
//使用初始化成员列表初始化，初始化列表在进入函数体之前就完成了成员变量的初始化，
// 而函数体内赋值是先默认构造、再赋值
//C::C(double a, double b, double c) : X(a), Y(b), Z(c)
void Line::setLength(double len){
    length=len;
}
double Line::getLength(){
    return length;
}
int main()
{
    Line line(0.0);
    line.setLength(2.2);
    std::cout<<"line length:"<<line.getLength()<<std::endl;
    return 0;
}
