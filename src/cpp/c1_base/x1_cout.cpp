#include <iostream>
using namespace std;

int atk=200;

void test(){
    int atk=100;
    std::cout << "atk = " << atk << std::endl;
    // ::代表作用域  如果前面什么都不添加 代表全局作用域
    std::cout << "全局 atk = " << ::atk << std::endl;
}

int main(){
    test();
    cout<< "hello world"<<endl;
}