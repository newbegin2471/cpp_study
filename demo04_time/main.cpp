#include <iostream>
#include <ctime>
int main()
{
    time_t now=time(NULL);
    std::cout<<"1970到现在的秒数:"<<now<<std::endl;
    char *dt=ctime(&now);
    std::cout<<"本地日期和时间:"<<dt<<std::endl;
    //把now转换为tm结构
    tm *gmtm=gmtime(&now);
    dt=asctime(gmtm);
    std::cout << "UTC时间:"<<dt<<std::endl;
    tm *ltm=localtime(&now);
    return 0;
}
