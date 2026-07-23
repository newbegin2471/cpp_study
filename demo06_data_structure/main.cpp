#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map> //键值对哈希表
#include <unordered_set> //单纯集合，没有值，只有key
#include <map>           //映射，有序的
#include <set>           //
int main()
{
    std::cout<<"数组array"<<std::endl;
    int array[]={1,2,3,4,5};
    std::cout<<"第一个元素:"<<array[0]<<std::endl;
    std::cout<<"结构体struct"<<std::endl;
    std::cout<<"类class"<<std::endl;
    std::cout<<"链表Linked List"<<std::endl;
    struct Node{
        int data;
        Node *next;
    };
    struct Node* head=nullptr;
    Node *newNode=new Node{10,nullptr};
    head=newNode; //插入新节点
    std::cout<<"栈Stack"<<std::endl;
    std::stack<int> s;
    s.push(1); //入栈
    s.push(2); 
    //出栈
    std::cout<<"出栈:"<<s.top()<<std::endl; //获取栈顶元素，不删除
    s.pop(); //删除栈顶元素，删除，无返回值
    std::cout<<"元素个数:"<<s.size()<<std::endl;
    std::cout<<"判断栈是否为空:"<<s.empty()<<std::endl;
    //pop和top使用前必须判断是否为空
    std::cout<<"队列Queue"<<std::endl;
    std::queue<int> q;
    //queue<int,vector<int>> q2;指定底层为容器
    //入队
    q.push(1);
    q.push(2);
    //原地构造
    // q.emplace()
    std::cout<<"判空:"<<q.empty()<<std::endl;
    std::cout<<"访问队首元素:"<<q.front()<<std::endl;
    std::cout<<"访问队尾元素:"<<q.back()<<std::endl;
    std::cout<<"队列元素数量:"<<q.size()<<std::endl;
    q.pop(); //出队，无返回值
    //空队列，pop/front/back会报错
    std::cout<<"双端队列deque:"<<std::endl;
    //创建
    std::deque<int> dq;
    std::deque<int> dq2(5,0); //5个0
    std::deque<int> dq3{1,2,3,4,5};
    //入队
    dq.push_front(1); //队首入队
    dq.push_back(2);  //队尾入队
    //emplace_back / emplace_front：直接在容器内存里原地构造对象，省去拷贝,简单参数几乎一样
    // emplace_back方式，直接传构造参数
    // dq.emplace_back("李四", 20);
    //访问
    dq.front();
    dq.back();
    dq[0];
    dq.at(0);
    //出队
    dq.pop_front(); //删除队首
    dq.pop_back();  //删除队尾
    std::cout<<"判空:"<<dq.empty()<<std::endl;
    std::cout<<"判断元素数量:"<<dq.size()<<std::endl;
    // dq.clear();
    //中间插入
    //dq.insert(0,1);
    //dq.erase(0);//删除

    //有迭代器
    dq.push_back(1);
    dq.push_front(2);
    for(auto &x:dq){
        std::cout<<x;
    }
    std::cout<<std::endl;

    std::cout<<"============哈希表Hash Table=============="<<std::endl;
    // 优点：查找、插入、删除操作效率高。
    // 缺点：无法保证元素顺序，哈希冲突时性能会下降。
    std::cout<<"键值对哈希表:"<<std::endl;
    std::unordered_map<std::string,int> mp;
    //插入
    mp["a"]=10; //[]访问，键不存在则自动插入
    mp.insert({"b",20});
    mp.emplace("c",3);
    
    //查找
    //查找键值对
    auto it=mp.find("a");
    if(it!=mp.end()){
        std::cout<<it->first<<std::endl;//键
        std::cout<<it->second<<std::endl;//值
    }
    //根据键值查找
    if(mp.count("a")){
        std::cout<<"a存在"<<std::endl;
    }

    //删除
    mp.erase(it);//通过迭代器删除
    mp.erase("b");//通过key删除

    //遍历
    /*情况 1：语法层面（局部变量重定义，编译报错）
    C++ 同一个作用域内，不能重复定义同名 auto 变量
    语义不同的迭代器不要复用同一个变量名
    */
    mp.emplace("d",4);
    mp.emplace("e",4);
    mp.emplace("f",4);
    for(auto it1=mp.begin();it1!=mp.end();++it1){
        std::cout<<it1->first;
        std::cout<<":";
        std::cout<<it1->second<<std::endl;
    }
    //常用
    for(auto &it2:mp){
        std::cout<<it2.first;
        std::cout<<":";
        std::cout<<it2.second<<std::endl;
    }
    
    //容量接口
    std::cout<<"键值对数量:"<<mp.size()<<std::endl;
    std::cout<<"是否为空:"<<mp.empty()<<std::endl;
    mp.clear(); //清空全部元素


    std::cout<<"=============unordered_set================"<<std::endl;
    std::unordered_set<int> st;
    //插入
    st.insert(1);
    st.insert(2);
    st.insert(3);
    //查询
    if(st.find(1)!=st.end()){
        std::cout<<"查询1是否存在"<<std::endl;
    }
    if(st.count(2)){
        std::cout<<"查询2是否存在"<<std::endl;
    }
    //删除
    st.erase(1);
    //遍历
    for(auto it_st:st){
        std::cout<<it_st;
    }

    std::cout<<"===========映射Map=============="<<std::endl;
    // key 唯一，自动按 key 升序排序
    // 底层：红黑树；增删查找 O(logn)
    // map<K,V> 存储 pair<const K, V>
    std::map<std::string,int>mp1;
    mp1["a"]=1;
    mp1.insert({"b",2});
    mp1.emplace("c",3);

    //查找
    auto it3=mp1.find("a");//返回指针
    if(it3!=mp1.end()){
        std::cout<<it3->first<<":";
        std::cout<<it3->second<<std::endl;
    }
    if(mp1.count("c")){
        std::cout<<"存在"<<std::endl;
    }
    //删除
    mp1.erase(it3);//通过迭代器删除
    mp1.erase("a");//通过key删除
    //遍历
    for(auto &it4:mp1){
        std::cout<<it4.first<<":";
        std::cout<<it4.second<<std::endl;
    }
    //通过迭代器
    for(auto it5=mp1.begin();it5!=mp1.end();++it5){
        std::cout<<it5->first<<":";
        std::cout<<it5->second<<std::endl;
    }
    //常用容量接口
    mp1.size();
    mp1.empty();
    // lower_bound(key)：>= key 的第一个元素
    auto it_low = mp1.lower_bound("b");
    std::cout<<it_low->first<<":"<<it_low->second<<std::endl;
    // upper_bound(key)：> key 的第一个元素
    auto it_up = mp1.upper_bound("b");
    std::cout<<it_up->first<<":"<<it_up->second<<std::endl;

    std::cout<<"============集合set============="<<std::endl;
    std::set<int>set1;
    //插入
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);
    // find 返回迭代器；找不到返回 st.end()
    auto it_set= set1.find(4);
    if(it_set != set1.end())
    {
        std::cout << *it_set << std::endl; // set没有first/second，直接解引用取值
    }

    // count：存在返回1，不存在返回0
    if(set1.count(4))
    {
        std::cout << "元素存在\n";
    }
    //删除 erase ()
    set1.erase(it_set);
    set1.erase(2);
    set1.clear();//清空所有元素
    //容量接口
    set1.size();
    set1.empty();
    //遍历
    //迭代器
    //范围
    //有序专属接口
    std::set<int> set2{10,20,30,40};

    // lower_bound(x)  >= x 的第一个元素
    auto it_set1 = set2.lower_bound(20);

    // upper_bound(x)  > x 的第一个元素
    auto it_set2 = set2.upper_bound(20);
    //set元素是const,map里面key是const
    return 0;
}
