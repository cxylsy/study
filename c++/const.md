# **const**
### **const修饰指针：指针常量和常量指针**
指针常量（顶层const）
本质是一个常量型的指针，指针指向的地址不能改变，但是该地址存贮的数据可以改变。`int * const p = a;`
常量指针（底层const）
本质是一个常量的指针，`int const *p = a;` a 是一个常量，p指向a的地址空间，a的值不能够改变，但是p的指向可以改变。  
更一般的，顶层const可以表示任意的对象是常量，对任何数据类型都适用，比如int、类、指针.  
比较特殊的是：指针可以是底层const也可以是顶层const，和其它类型有明显的区别

### **const修饰变量**
const修饰变量的主要有两个作用：  
1、将变量定义为常量，保护被修饰的东西，防止意外的修改，增强程序的健壮性。  
**const常量和宏定义的区别：**  
1.const常量会进行类型检查  
const常量有数据类型，而宏常量没有数据类型。编译器可以对前者进行类型的安全检查，而对后者只进行字符替换，没有进行安全检查，并且再字符替换时可能会发生意料不到的错误。  
2.const常量更节省空间，避免不必要的内存分配  
const定义常量从汇编的角度来看，只是给出了对应的内存地址，而不是像#define一样给出的是立即数，所以，const定义的常量在运行过程中只有一份拷贝，而#define宏定义的常量在内存中有若干个拷贝。  
2、和static一样，修饰全局变量使其可见范围为当前文件  
普通全局变量的作用域是当前文件，但是在其他文件中也是可见的，使用extern声明后就可以使用const全局变量的作用域也是当前文件，但是他在其他文件中是不可见的，这和static关键字效果类似。  

### **const修饰函数**
1、const修饰函数参数，表示参数不可变，若参数为引用，可以增加效率（引用传递而不用值拷贝）  
2、const修饰函数的返回值：含义和const修饰变量和指针的含义相同，很少用到。例如`const A test = A`实例，test实例只能访问类A中的公有数据成员和const成员，并且不允许对其进行赋值操作，这在一般情况下很少用到。

### **const修饰类成员**
1、const修饰类的成员变量  
表示成员变量不能被修改，同时只能在初始化列表中赋值。  
2、const修饰类的成员函数  
该函数不能改的对象的成员变量。  
不能调用非const成员函数，任何非const成员函数会有修改成员变量的企图。  
const关键字不能与static关键字同时使用，因为static关键字修饰静态成员函数，静态成员函数不含有this指针，即不能实例化，而const成员函数必须具体到某一个实例所以冲突。  

**类中的所有函数都可以声明为const函数吗？那些函数不能？**  
1、构造函数不能  
因为const修饰的成员函数不能修改数据成员。构造函数也属于类的成员函数，但是构造函数是要修改类的成员变量，所以构造函数不能声明为const类型。  
2、static静态函数不行  
static静态成员是属于类的，不是属于某一个具体的对象，所以对象共用static成员。this指针是某个具体对象的地址，因为static成员函数没有this指针。而函数中的const其实就是用来修饰this指针的，表示指针指向的内容不可变，static静态成员却没有this指针，所以const不能用来修饰static成员函数。  

### **const 修饰对象**
对象的任何成员都不能被修改
只能调用const成员函数

### **const实例代码**
const修饰的变量、函数、对象 分别成为：常变量、常函数、常对象。  
常函数只能访问常变量，常对象只能访问常函数和常变量。  
代码见const-demo.cpp

### **constexpr**
constexpr: constant erperssion 常量表达式  
实际开发中，我们经常会用到常量表达式。以定义数组为例，数组的长度必须是一个常量表达式。  
`int a[100];//正确`  
`int a[100+10];//正确`  
`int length = 6;`  
`int a[length];//错误`  
`constexpr int num = 1 + 2 + 3;`  
`int a[num];//正确`  
**为什么需要constexpr ?**  
我们知道，c++程序的执行过程大致要经历编译、链接、运行这3个阶段。常量表达式和非常量表达式的计算时机不同：  
非常量表达式只能在运行阶段计算出结果。  
而常量表达式的计算往往发生在程序的编译阶段，这可以极大提高程序的执行效率，因为表达式只需要在编译阶段计算一次，节省了每次程序运行时都需要计算一次的时间，对于用c++编写的程序，性能往往是永恒的追求。  
**const和constexpr的区别：**  
const 强调 只读  
constexpr 强调 常量  
即凡是表达“只读”语义的场景都使用 const，表达“常量”语义的场景都使用 constexpr。