#include <iostream>
using namespace std;
class Rect{
    private:
        double height;
        double width;
    public:
        void init(double hei=0,double wid=0){
            if(hei<0||wid<0){
                cout<<"长度不对"<<endl;
                return;
            }
            height=hei;
            width=wid;
        }
        void setHeight(double hei){
            if(hei<0){
                cout<<"高度错误"<<endl;
                return;
            }
            height=hei;
        }
        void setWidth(double wid){
            if(wid<0){
                cout<<"宽度错误"<<endl;
                return;
            }
            width=wid;
        }
        double getHeight(){
            return height;
        }
        double getWidth(){
            return width;
        }
        double getPerimeter(){
            return 2*(height+width);
        }
        double getArea(){
            return height*width;
        }
        bool judge(Rect other){
            if(height==other.getHeight()&&width==other.getWidth()){
                return true;
            }
            return false;
        }
};
int main()
{
    Rect r;
    r.init();
    r.setHeight(2.0);
    r.setWidth(3.0);
    // cout<<"矩形高度:"<<r.getHeight()<<endl;
    // cout<<"矩形宽度:"<<r.getWidth()<<endl;
    // cout<<"矩形周长:"<<r.getPerimeter()<<endl;
    // cout<<"矩形面积:"<<r.getArea()<<endl;
    Rect r1;
    r1.init(2.0,3.0);
    if(r.judge(r1)){
        cout<<"r与r1相等"<<endl;
    }else{
        cout<<"r与r1不相等"<<endl;
    }
    return 0;
}