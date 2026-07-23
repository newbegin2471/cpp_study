#include <iostream>

int main()
{
    std::cout<<"hello,world"<<std::endl;
    using std::cout;
    cout<<"hello,world"<<std::endl;
    using namespace std;
    cout<<"hello,world"<<endl;
    return 0;
}
