#include <iostream>
using namespace std;

int main()
{
    bool b1=0;
    bool b2=1;
    bool b3=-1;
    bool b4=true;
    bool b5=false;
    //使用数字输出
    cout<<"b1="<<b1<<endl;
    cout<<"b2="<<b2<<endl;
    cout<<"b3="<<b3<<endl;
    cout<<"b4="<<b4<<endl;
    cout<<"b5="<<b5<<endl;
    //使用字母输出用boolalpha,持久化输出，设置noboolalpha改回数字
    cout<<boolalpha<<"b1="<<b1<<endl;
    cout<<"b2="<<b2<<endl;
    cout<<"b3="<<b3<<endl;
    cout<<"b4="<<b4<<endl;
    cout<<"b5="<<b5<<endl;
    //更改为数字
    cout<<noboolalpha<<"b1="<<b1<<endl;
    cout<<"b2="<<b2<<endl;
    cout<<"b3="<<b3<<endl;
    cout<<"b4="<<b4<<endl;
    cout<<"b5="<<b5<<endl;
    //在内存中占用一个字节
    cout<<"sizeof(bool):"<<sizeof(bool)<<endl;
    return 0;
}