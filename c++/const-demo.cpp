#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class  Student {
public:
    Student(char *name, int age, float score);
public:
    void show();
    //三个常函数
    char *getName() const;
    int getAge() const;
    float getScore() const;

private:
    char *m_name;
    int m_age;
    float m_score;
};

//常变量的赋值方式：参数列表
Student::Student(char *name, int age, float score) : m_name(name),m_age(age),m_score(score){}

//常函数的作用就是获取变量的值，又不能修改他们的值，这种措施主要是为了保护数据而设置的
char *Student::getName() const {
    return m_name;
}

int Student::getAge() const {
    return m_age;
}

float Student::getScore() const {
    return m_score;
}

void Student::show() {
    cout << "名字：" << m_name << "  年龄：" << m_age << "  分数：" << m_score << endl;
}
int main() {
    const Student stu("小明", 15, 90.5);
    //stu.show(); const 常对象只能调用const成员函数
    cout << stu.getName() << "的年龄是" << stu.getAge() << ",成绩是" << stu.getScore() << endl;

    const Student *pstu = new Student("小李", 16, 95);
    //pstu->show();
    cout << pstu->getName() << "的年龄是" << pstu->getAge() << ",成绩是" << pstu->getScore() << endl;

    int a = 0;
    int *b = &a;
    
    int e = 2;
    int *f = &e;

    int g = 4;
    int *h = &g;

    int const *c = b;// 常量指针， b是一个常量，c指向b，a的值不可以变，但是b的指向可以改变
    int * const d = b; // 指针常量，指针指向的地址不能变，该地址存贮的数据可以变

    cout << " c : " << c << " d: " << d << endl;// c : 0x61fee8 d: 0x61fee8
    cout << " c : " << *c << " d : " << *d << endl;// c : 0 d : 0

    *b = g;// 指针常量不能修改地址，但是数据可以变

    c = f;//常量指针数据不能变，但是可以修改指向的地址

    cout << " c : " << c << " f: " << f << " d: " << d << " h: " << h << endl;// c : 0x61fee4 f: 0x61fee4 d: 0x61fee8 h: 0x61fee0
    cout << " c : " << *c << " f: " << *f << " d: " << *d << " h: " << *h << endl;// c : 2 f: 2 d: 4 h: 4

    return 0;
}