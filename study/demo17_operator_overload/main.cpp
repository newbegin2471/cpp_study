#include <iostream>
using namespace std;
class Complex;

class Complex
{
    private:
        int real;
        int vir;
    public:
        Complex(){}
        Complex(int r,int v):real(r),vir(v){}
        ~Complex(){}
        void show()
        {
            cout<<this->real<<'+'<<this->vir<<'i'<<endl;
        }
        const Complex operator+(const Complex &r)const
        {
            Complex temp;
            temp.real=this->real+r.real;
            temp.vir=this->vir+r.vir;
            return temp;
        }
        // const Complex operator-(const Complex &r)const
        // {
        //     Complex temp;
        //     temp.real=this->real-r.real;
        //     temp.vir=this->vir-r.vir;
        //     return temp;
        // }
        // Complex & operator+=(const Complex &r)
        // {
        //     this->real+=r.real;
        //     this->vir+=r.vir;
        //     return *this;
        // }
        friend ostream & operator<<(ostream &L,const Complex &r);
        friend istream & operator>>(istream &l,Complex & r);
        friend const Complex operator-(const Complex &l,const Complex &r);
        friend Complex & operator+=(Complex &l,const Complex &r);
};
const Complex operator-(const Complex &l,const Complex &r)
{
    Complex temp;
    temp.real=l.real-r.real;
    temp.vir=l.vir-r.vir;
    return temp;
}
Complex & operator+=(Complex &l,const Complex &r)
{
    l.real+=r.real;
    l.vir+=r.vir;
    return l;
}
//自定义全局函数实现<<运算符重载
ostream & operator<<(ostream &l,const Complex &r)
{
    if(r.vir<0){
        l<<r.real<<r.vir<<'i';
    }else{
        l<<r.real<<'+'<<r.vir<<'i';
    }
    return l;
}
istream & operator>>(istream &l,Complex & r)
{
    l>>r.real>>r.vir;
    return l;
}
int main()
{
    Complex c1(1,2);
    cout<<"c1:";
    c1.show();
    Complex c2(2,3);
    cout<<"c2:";
    c2.show();
    Complex c3=c1+c2;
    cout<<"c3=c1+c2:";
    c3.show();
    c3+=c1;
    cout<<"c3+=c1:";
    c3.show();
    cout<<c3<<endl;
    cin>>c3;
    cout<<c3<<endl;
    return 0;
}