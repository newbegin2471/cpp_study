#include <iostream>
using namespace std;
/*
    函数重载：在同一作用域中的某个函数和运算符指定多个定义，分别称为函数重载和运算符重载。
    重载声明是指一个与之前已经在该作用域内声明过的函数或方法具有相同名称的声明，但是它们的参数列表和定义（实现）不相同。
    当您调用一个重载函数或重载运算符时，编译器通过把您所使用的参数类型与定义中的参数类型进行比较，决定选用最合适的定义。选择最合适的重载函数或重载运算符的过程，称为重载决策。
    重载要求**同一个类 / 同一个作用域**。   
    1.参数个数不同，参数顺序不同，参数类型不同
    2.只有返回值不同不算重载，不同作用域不算重载（子类和父类同名不算，是名称隐藏）
    3.引用，const对重载的影响，（int &x)和（const int &x),常量调用第二个
    4.匹配规则:精准匹配，隐式转换
    5.常用：构造函数重载
    运算符重载：
    1.**不能创造新运算符**，只能重载已有的；
    2.**不能改变运算符操作数个数**；
    3.`.` `.*` `::` `?:` **不能重载**；
    4.`=` `[]` `()` `->` **建议必须用成员函数重载**。
*/
//运算符重载示例，二维坐标点

class Point{
    private:
        int x;
        int y;
    public:
        Point(int x_=0,int y_=0):x(x_),y(y_){}
        //运算符重载+
        Point operator+(const Point &b){
            return Point(this->x+b.x,this->y+b.y);
        }
        //运算符重载==
        Point operator==(const Point &b){
            return (this->x==b.x&&this->y==b.y);
        }
        //运算符重载=,必须成员函数重载
        Point operator=(const Point &other){
            //防止自己赋值
            if(this==&other){
                return *this;
            }
            
        }
        virtual ~Point(){
            cout<<"析构函数"<<endl;
        }

};
int main()
{

    return 0;
}