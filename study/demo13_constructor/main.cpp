#include <iostream>
using namespace std;
class Stu{
    private:
        string &name;
        int age;
        double score;
    public:
        Stu(){
            cout<<"无参构造函数"<<endl;
        }
        Stu(string name,int age,double score):name(name),age(age),score(score)
        {
            // this->name=name;
            // this->age=age;
            // this->score=score;
            cout<<"有参构造函数被调用"<<endl;
        }
        // Stu(string name,int age,double score=0){
        //     this->name=name;
        //     this->age=age;
        //     this->score=score;
        //     cout<<"带默认参数的有参构造函数调用"<<endl;
        // }
        ~Stu(){
            cout<<"析构函数:当对象生命周期结束时调用(作用域结束或delete)"<<endl;
            
        }

};
int main()
{
    Stu s1;
    Stu s2("tom",20,100);
    Stu *s3;
    s3=new Stu("sam",18,99);
    return 0;
}