#include <iostream>
#include <thread>
using namespace std;

// 值传递
void inc1(int x) {
    x += 1;
}
// 引用传递
void inc2(int &x) {
    x += 1;
}
// 指针传递
void inc3(int *x) {
    *x += 1;
}

int main() {
    int data = 0;

    // 值传递
    thread t1(inc1, data);
    t1.join();
    cout << data << endl;

    // 引用传递
    data = 0;
    thread t2(inc2, ref(data)); // 转换成一个引用对象，给 thread 构造函数拷贝；
    t2.join();
    cout << data << endl;
    
    // 指针传递
    data = 0;
    thread t3(inc3, &data);
    t3.join();
    cout << data << endl;

    return 0;
}
