#include <iostream>
#include <iomanip>
using namespace std;
void sort(double *arr,int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                double temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
        // int *p1=new int[5];
        // for(int i=0;i<5;i++){
        //     cout<<p1[i]<<' ';
        // }
        // cout<<endl;
        // //申请空间并初始化
        // double *p2=new double[5]{1,2,3,4,5};
        // for(int i=0;i<5;i++){
        //     cout<<fixed<<setprecision(2)<<p2[i]<<' ';
        // }
        // cout<<endl;
        // delete[] p1;
        // delete[] p2;
        // double score;
        double *scorearr=new double[8];
        cout<<"请输入成绩:";
        for(int i=0;i<8;i++){
            cin>>scorearr[i];
        }
        cout<<"成绩：";
        for(int i=0;i<8;i++){
            cout<<scorearr[i]<<' ';
        }
        cout<<endl;
        sort(scorearr,8);
        cout<<"升序后的成绩:";
        for(int i=0;i<8;i++){
            cout<<scorearr[i]<<' ';
        }
        cout<<endl;
        delete[] scorearr;
    return 0;
}