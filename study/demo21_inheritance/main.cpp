#include <iostream>
using namespace std;
class Person
{
    private:
        int money;
    protected:
        int property;
    public:
        string name;
        Person(){}
        Person(string n,int p,int m):name(n),property(p),money(m){}
        ~Person(){}
        void show(){
            cout<<"Person::name="<<name<<endl;
            cout<<"Person::property="<<property<<endl;
            cout<<"Person::money="<<money<<endl;
        }
};
class Stu:public Person{
    private: 
        string address;
    protected:
        double score;
    public:
        int numb;
        Stu(){}
        void show()
        {
            cout<<"Person::name="<<name<<endl;
            cout<<"Person::property="<<property<<endl;
            // cout<<"Person::money="<<money<<endl;
            cout<<"Stu::numb="<<numb<<endl;
            cout<<"Stu::score="<<score<<endl;
            cout<<"Stu::address="<<address<<endl;
        }
};
int main()
{
    Person p1("csg",100,10);
    p1.show();
    // Stu s1("c",)
    Stu s1;
    s1.show();
    return 0;
}