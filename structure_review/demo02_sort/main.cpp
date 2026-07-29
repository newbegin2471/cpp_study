#include <iostream>
using namespace std;
void print(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
void swap(int &i,int &j){
    int temp=i;
    i=j;
    j=temp;
}
//√∞≈›≈≈–Ú
void bubbleSort(int *arr,int n){
    bool swapped=false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                swapped=true;
            }
        }
        if(!swapped)
            break;
    }
}
//—°‘Ò≈≈–Ú
void selectSort(int *arr,int size){
    for(int i=0;i<size-1;i++){
        int minIndex=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}
//≤Â»Î≈≈–Ú
void insertSort(int *arr,int size){
    for(int i=1;i<size;i++){
        int base=arr[i];
        int j=i-1;
        for(;j>=0&&arr[j]>base;j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=base;
    }
}
//œ£∂˚≈≈–Ú
void shellSort(int *arr,int size){
    
}
int main()
{
    int arr[5]={5,4,3,2,1};
    // selectSort(arr,5);
    // print(arr,5);
    // insertSort(arr,5);
    // print(arr,5);
    return 0;
}