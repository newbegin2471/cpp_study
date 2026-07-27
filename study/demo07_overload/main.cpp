#include <iostream>
#include <iomanip>
using namespace std;
int sum(int a=100,int b=100,int c=100);
int sum(int a,int b){
    return a+b;
}
float sum(float a,float b){
    return a+b;
}
double sum(double a,double b){
    return a+b;
}
// float sum(int a,int b,int c){
//     return a+b+c;
// }
int findMax(int a,int b){
    return a>b?a:b;
}
float findMax(float a,float b){
    return a>b?a:b;
}
double findMax(double a,double b){
    return a>b?a:b;
}
int findMax(int a,int b,int c){
    int max=a;
    if(b>max)
        max=b;
    if(c>max)
       max=c;
    return max; 
}
int sum(int a,int b,int c){
    return a+b+c;
}
int main()
{
    // cout<<sum(1,2)<<endl;
    // cout<<sum(2.1,2.2)<<endl;
    // cout<<sum((float)2.1,(float)2.2)<<endl;
    // cout<<sum(1,2,3)<<endl;
    // int a=2,b=3,c=1;
    // cout<<"max="<<findMax(a,b,c)<<endl;
    // cout<<"max="<<fixed<<setprecision(2)<<findMax((double)a,(double)b)<<endl;
    cout<<"sum="<<sum()<<endl;
    return 0;
}