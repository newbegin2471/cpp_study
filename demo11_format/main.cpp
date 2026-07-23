#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int num=111;
    //printf("%#x %#o");
    cout<<oct <<"八进制:"<<num<<endl;
    cout<<dec <<"十进制:"<<num<<endl;
    cout<<hex <<"十六进制:"<<num<<endl;
    cout<<showbase<<"带进制前缀:"<<num<<endl;
    cout<<showbase<<uppercase<<"带进制前缀:"<<num<<endl;
    cout<<noshowbase <<"取消前缀:"<<num<<endl;
    //通过函数设置
    cout<<setbase(8)<<"setbase(8):"<<num<<endl;
    cout<<setbase(10)<<"setbase(10):"<<num<<endl;
    cout<<setbase(16)<<"setbase(16):"<<num<<endl;
    //printf("%10d")/printf("%-10d")
    cout<<setw(10)<<"设置宽度:"<<num<<endl;//宽度设置,只对下一个有效
    cout<<setw(10)<<setfill('0')<<"设置填充:"<<num<<endl;
    cout<<setw(10)<<left<<"左对齐:"<<num<<endl;
    float fnum=3.14159f;
    cout<<"默认输出:"<<fnum<<endl;
    cout<<"fixed:"<<fixed<<fnum<<endl;
    cout<<scientific<<"小写科学计数法:"<<fnum<<endl;
    cout<<uppercase<<scientific<<"大写科学计数法:"<<fnum<<endl;
    cout<<setprecision(3)<<"保留3位有效数字:"<<fnum<<endl;
    //布尔值
    bool a=true;
    cout<<boolalpha<<a<<endl;
    cout<<noboolalpha<<a<<endl;
    return 0;
}
