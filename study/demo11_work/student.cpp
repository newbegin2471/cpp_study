#include "student.h"
#include <iostream>
using namespace std;
// void setNum(int n);
//         void input();
//         void sort();
//         void show();
void StuInfo::init(){
    score=new double[100]{0};
    num=0;
}
void StuInfo::setNum(int n){
    num=n;
}
void StuInfo::input(){
    for(int i=0;i<num;i++){
        cout<<"请输入第"<<i+1<<"个人成绩:";
        cin>>score[i];
    }
}
void StuInfo::sort(){
    bool swapped=false;
    for(int i=0;i<num-1;i++){
        for(int j=0;j<num-i-1;j++){
            if(score[j]>score[j+1]){
                double t=score[j];
                score[j]=score[j+1];
                score[j+1]=t;
                swapped=true;
            }
        }
        if(!swapped)
            break;
    }
}
void StuInfo::show(){
    for(int i=0;i<num;i++){
        cout<<score[i]<<' ';
    }
    cout<<endl;
}
void StuInfo::freeScore(){
    delete[] score;
    score=nullptr;
}