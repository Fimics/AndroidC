#include <iostream>

using namespace std;

#include "string"


const double PI = 3.14;

class Circle {
public:
    double calculateZC() {
        return 2 * PI *r;
    }

    int r;
    int getR() const {
        return r;
    }

    void setR(int r) {
        Circle::r = r;
    }
};

void test01() {
    Circle c1; //通过类 创建一个对象   实例化对象
    //给c1 半径赋值
    //c1.m_R = 10;
    c1.setR(10);
    //求c1圆周长
    cout << "圆的半径为： " << c1.getR() << endl;
    cout << "圆的周长为： " << c1.calculateZC() << endl;
}

int main() {
    test01();
    return EXIT_SUCCESS;
}


