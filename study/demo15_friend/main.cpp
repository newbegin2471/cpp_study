#include <iostream>
using namespace std;
class Cat;
class Dog;
int sum_num(Cat &c,Dog &d);
double sum_weight(Cat &c,Dog &d);
class Cat
{
    private:
        int count;
        double weight;
    public:
        Cat(int c,double w):count(c),weight(w)
        {

        }
    friend int sum_num(Cat &c,Dog &d);
    friend double sum_weight(Cat &c,Dog &d);
};
class Dog
{
    private:
        int count;
        double weight;
    public:
        Dog(int c,double w):count(c),weight(w)
        {

        }
    friend int sum_num(Cat &c,Dog &d);
    friend double sum_weight(Cat &c,Dog &d);
};
int sum_num(Cat &c,Dog &d){
    return d.count+c.count;
}
double sum_weight(Cat &c,Dog &d){
    return c.weight+d.weight;
}
int main()
{
    // Cat c(5,100);
    // Dog d(5,100);
    // cout<<"总个数:"<<sum_num(c,d)<<endl;
    // cout<<"总重量:"<<sum_weight(c,d)<<endl;
    return 0;
}