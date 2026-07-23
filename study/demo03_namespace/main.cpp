#include <iostream>
namespace csg{
    int num1=1;
    float temp1=1.1f;
}
namespace ccc{
    int num1=2;
    float temp2=2.2f;
}
float temp1=3.3f;
int main()
{
    //两命名空间冲突
    std::cout<<"csg::num1:"<<csg::num1<<std::endl;
    std::cout<<"ccc::num1:"<<ccc::num1<<std::endl;
    //命名空间和全局变量冲突
    std::cout<<"全局变量temp1:"<<::temp1<<std::endl;
    std::cout<<"csg::temp1:"<<csg::temp1<<std::endl;
    //命名空间和局部变量冲突
    float temp2=3.3f;
    std::cout<<"局部变量temp2:"<<temp2<<std::endl;
    std::cout<<"ccc::temp2:"<<ccc::temp2<<std::endl;
    return 0;
}
