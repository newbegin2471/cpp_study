#include <iostream>
using namespace std;
class Stu
{
    private:
        string name;
        mutable int age;
        double score;
    public:
        Stu(){}
        Stu(string n,int a,double s):name(n),age(a),score(s){}
        ~Stu(){}
    
};
int main()
{
    
    return 0;
}