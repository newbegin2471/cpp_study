#include <iostream>
using namespace std;
class Test{
    public:
        string name="csg";
    void show(){
        string name;
        this->name="csg";
        cout<<"this="<<this<<endl;
        name="ccc";
    }
    void fun(){
        this->show();
        show();
    }
};
int main()
{
    Test t1;
    t1.show();
    cout<<"&t1="<<&t1<<endl;  
    Test t2;
    t2.show();
    cout<<"&t2="<<&t2<<endl;
    return 0;
}