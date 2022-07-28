#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Shape
{
public:
    //提供接口框架的纯虚函数
    virtual int getArea() = 0;
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h) {
        height = h;
    }
protected:
    int width;
    int height;
};

//派生类
class Rectangle: public Shape
{
public:
    int getArea()
    {
        return width * height;
    }
};

class Triangle: public Shape
{
public:
    int getArea()
    {
        return (width * height) / 2;
    }
};

int main() {
    Rectangle rect;
    Triangle tri;

    rect.setHeight(10);
    rect.setWidth(20);
    int area = rect.getArea();
    cout << "rect area: " << area << endl;

    tri.setHeight(10);
    tri.setWidth(20);
    area = tri.getArea();
    cout << "tri area: " << area << endl;

    return 0;
}