//
// Created by mac on 2023/4/7.
//

#include "iostream"

using namespace std;


class CountX{



public:
    CountX(int x,int y):x(x),y(y){};

     void setX(int x){
         this->x=x;
     }

     int getX(){
         return this->x;
     }

     void setY(int y){
         this->y=y;
     }

     int getY(){
         return this->y;
     }

    CountX operator + (const CountX &c1){
         int x = this->x+c1.x;
         int y = this->y+c1.y;
        CountX c(x,y);
         return c;
     }

private:
    int x ;
    int y;
};


int main(){
    CountX c1(1,1);
    CountX c2(2,2);
    CountX c3=c1+c2;
    cout<< c3.getX()<< "-"<<c3.getY()<<endl;
}