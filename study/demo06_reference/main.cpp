#include <iostream>
using namespace std;
void swap1(int m,int n){
    int temp=m;
    m=n;
    n=temp;
    cout<<"swap1::m="<<m<<" n="<<n<<endl;
}
void swap2(int *ptr,int *qtr){
    int *temp=ptr;
    ptr=qtr;
    qtr=temp;
    cout<<"swap2::*ptr="<<*ptr<<"   *qtr="<<*qtr<<endl;
}
void swap3(int *ptr,int *qtr){
    int temp=*ptr;
    *ptr=*qtr;
    *qtr=temp;
    cout<<"swap3::*ptr="<<*ptr<<"   *qtr="<<*qtr<<endl;
}
void swap4(int &m,int &n){
    int temp=m;
    m=n;
    n=temp;
    cout<<"swap4::m="<<m<<" n="<<n<<endl;
}
int fun(){
    static int num=520;
    cout<<"fun::num="<<num<<endl;
    return num;
}
int &hun(){
    static int num=520;
    cout<<"fan::num"<<num<<"    &num"<<&num<<endl;
    return num;
}
void fun(int &m){
    cout<<"m= "<<m<<endl;
}
void fun(int &&m){
    cout<<"m= "<<m<<endl;
}
int main()
{
    // int num=520;
    // cout<<"num="<<num<<"  &num="<<&num<<"   sizeof(num):"<<sizeof(num)<<endl;
    // int &ref=num;
    // cout<<"ref="<<ref<<"    &ref"<<&ref<<"  sizeof(ref):"<<sizeof(ref)<<endl;
    // //对数据进行读写
    // cout<<"num="<<num<<"    ref="<<ref<<endl;
    // ref=1314;
    // cout<<"num="<<num<<"    ref="<<ref<<endl;
    // num=999;
    // cout<<"num="<<num<<"    ref="<<ref<<endl;
    //引用与目标类型必须保持一致
    // double &dref=(double)num;应用必须要类型一致，且必须是已经存在的变量不能是临时值；
    // cout<<"num="<<num<<"    ref="<<dref<<endl;
    // int key=888;
    // ref=key; //将key赋值给ref引用的空间
    // cout<<"&ref="<<&ref<<"  &key="<<&key<<endl;
    //一个目标可以定义多个引用,多个引用和目标是同一空间
    //===========================================================================
    // int m=2,n=3;
    // swap1(m,n);
    // cout<<"m="<<m<<" n="<<n<<endl;
    // m=2;
    // n=3;
    // swap2(&m,&n);
    // cout<<"m="<<m<<" n="<<n<<endl;
    // m=2;
    // n=3;
    // swap3(&m,&n);
    // cout<<"m="<<m<<" n="<<n<<endl;
    // m=2;
    // n=3;
    // swap4(m,n);
    // cout<<"m="<<m<<" n="<<n<<endl;
    //============================================================
    //引用作为函数返回值
    // int temp=hun();
    // cout<<"temp="<<temp<<"  &temp"<<&temp<<endl;
    // int &ref=hun();
    // cout<<"ref= "<<ref<<"   &ref"<<&ref<<endl;
    // hun()=1314;
    // cout<<"ref= "<<ref<<"   &ref"<<&ref<<endl;
    //=============================================================
    //数组引用
    //=============================================================
    //指针引用
    //=============================================================
    //左值引用,右值引用
    int num=520;
    int &ref=num; //左值引用目标只能是左值,不能是右值
    int &&ref2=520;//右值引用目标只能是右值
    fun(num);
    fun(520);//函数重载,实现同名函数调用
    //左值:只能放在等号左边的值,可以取地址&//变量,数组元素,引用返回,字符串数组等
    //右值:只能放在等号右边的值,不可以取地址//表达式结束就销毁的值,
    //引用绑定规则
    //普通引用,只能绑定左值,const
    
    return 0;
}