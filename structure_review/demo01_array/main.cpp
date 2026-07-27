#include <iostream>
#include <ctime>
using namespace std;
//随机访问
int randomAcess(int *arr,int size);
//插入元素
void insert(int *arr,int size,int index,int val){
    if(index>=size){
        return;
    }
    for(int i=size-1;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=val;
}
//删除元素
void deleteElem(int *arr,int size,int index){
    if(index<0||index>=size){
        return;
    }
    for(int i=index;i<size-1;i++){
        arr[i]=arr[i+1];
    }
}
//遍历数组
void tarverse(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
//查找元素
int findElem(int *arr,int size,int val){
    for(int i=0;i<size;i++){
        if(arr[i]==val){
            return i;
        }
    }    
    return -1;
}
//扩容数组
int *extend(int *arr,int size,int enlarge){
    int *temp=new int[size+enlarge];
    for(int i=0;i<size;i++){
        temp[i]=arr[i];
    }
    delete[] arr;
    return temp;
}
int main()
{
    srand((unsigned int)time(0));
    //=======================================================================================
    /*初始化方式*/
    int arr1[5]={1,2,3,4,5};
    int *arr2=new int[5];
    int *arr3=new int[5]{1,2,3,4,5};
    /*操作：随机访问，插入元素，删除元素，遍历数组，查找元素,扩容数组*/
    cout<<"randomIndex:"<<randomAcess(arr3,5)<<endl;
    return 0;
}
int randomAcess(int *arr,int size){
    int randomIndex=rand()%size;
    return arr[randomIndex];
}