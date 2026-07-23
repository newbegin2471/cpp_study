#include <iostream>
namespace csg
{
    using namespace std;
    int num=1;
    void printNum(){
        cout<<num<<endl;
    }
}
using csg::printNum;
int main()
{
    std::cout<<"csg::num:"<<csg::num<<std::endl;
    std::cout<<"printNum():";
    printNum();
    return 0;
}
