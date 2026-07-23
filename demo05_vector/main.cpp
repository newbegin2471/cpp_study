#include <iostream>
#include <vector>
void printVector(std::vector<int> vec);
int main()
{
    /**
     * vector 本质上是一个可自动扩容的动态数组 
     * vector 可以自动扩容和缩容。
     * 元素在内存中连续存储，访问效率非常高。
     * 支持通过下标快速访问元素，时间复杂度为 O(1)
     * 不需要手动 malloc/free。
     * 支持迭代器：可以方便地与 STL 算法配合使用。
     */
    //初始化
    //初始化为空
    std::vector<int> vec1(5);
    //初始化5个10
    std::vector<int> vec2(5,10);  //(元素数量，原始值)
    //初始化列表
    std::vector<int> vec3{1,2,3,4,5};
    //拷贝初始化
    std::vector<int> vec4(vec3);
    //迭代区间初始化
    std::vector<int> vec5(vec3.begin(),vec3.end()); 
    printVector(vec1);
    printVector(vec2);
    printVector(vec3);
    printVector(vec4);
    printVector(vec5);
    //常用函数
    std::cout<<"vec3[0]:"<<vec3[0]<<std::endl;
    std::cout<<"vec3.at[0]访问，越界报错:"<<vec3.at(0)<<std::endl;
    std::cout<<"首元素vec3.front():"<<vec3.front()<<std::endl;
    std::cout<<"尾元素vec3.back():"<<vec3.back()<<std::endl;
    /**
     *  v.begin();      // 首元素迭代器
        v.end();        // 末尾后一位迭代器（哨兵，不能解引用）
        v.rbegin();     // 反向迭代器
        v.rend();
     */
    
    return 0;
}
void printVector(std::vector<int> vec){
    for(unsigned int i=0;i<vec.size();i++){
        std::cout<<vec[i]<<' ';
    }
    std::cout<<std::endl;
}
void printVector1(std::vector<int> vec){
    for(auto it=vec.begin();it!=vec.end();++it){
        std::cout<<*it;
    }
}
void printVector2(std::vector<int> vec){
    for(const auto &x:vec){
        std::cout<<x<<' ';
    }
    std::cout<<std::endl;
}