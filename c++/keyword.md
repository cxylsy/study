## **关键字与运算符**

### **指针与引用**
指针存放某个对象的地址，其本身就是变量（命了名的对象），本身就有地址，所以可以有指向指针的指针；可变，包括其所指向的地址的改变和其指向的地址中所存放的数据的改变。  
引用就是变量的别名，从一而终，不可变，必须初始化。  
不存在指向空值的引用，但是可以存在指向空值的指针  

### **const**
见const.md  

### **define 和 typedef 的区别**  
**define**  
1.只是简单的字符替换，没有类型检查  
2.只是在编译的预编译阶段起作用  
3.可以用来防止头文件重复引用  
4.不分配内存，给出的是立即数，有多少次引用就有多少次替换  
**typedef**  
1.有对应的数据类型，是要进行判断的  
2.是在编译、运行的时候起作用  
3.在静态存储区中分配空间，在程序运行中内存中只有一个拷贝  

### **define 和 inline 的区别**  
**define**  
定义预编译时处理的宏，只是简单的字符串替换，无类型检查，不安全。  
**inline**  
inline是先将内敛函数编译完成生成了函数体直接插入到被调用的地方，减少了压栈、跳转和返回的地方，没有普通函数调用时额外的开销。  
内联函数是一种特殊的函数，会进行类型检查  
对编译器的一种请求，编译器有可能拒绝这种请求  
**C++中inline编译限制**  
1.不存在任何形式的循环语句  
2.不能存在过多的条件判断语句  
3.函数体不能过于庞大  
4.内联函数声明必须在调用语句之前  

### **override 和 overload**  
**override是重写了一个方法**  
以实现不同的功能，一般用于子类在继承父类时，重写父类方法。  
**规则**  
1.重写方法的参数列表、返回值、所抛出的异常与被重写方法一致  
2.被重写的方法不能为private  
3.静态方法不能被重写为非静态方法  
4.重写方法的访问修饰符一定要大于被重写方法的访问修饰符（public > protected > default > prvate）  
**overload是重载，方法名相同参数列表不同**  
一个方法有不同版本存在于一个类中  
**规则**  
1.不能通过访问权限、返回类型、抛出的异常进行重载  
2.不同的参数类型可以是不同的参数类型、不同的参数个数、不同的参数顺序（参数类型必须不一样）  
3.方法的异常类型和数目不会对重载造成影响  

**使用多态是为了避免在父类里面大量的重载引起代码的臃肿且难于维护。  
重写与重载的本质区别是，加入了override的修饰符的方法，此方法始终只有一个被你使用的方法**  

### **new 和 malloc**  
1. new内存分配失败时，会抛出bac_alloc异常，他不会返回NULL;malloc分配内存失败时返回NULL。  
2. 使用new操作符申请内存分配时无须指定内存块的大小，而malloc则需要显示的指出所需内存的尺寸  
3. opeartor new/opeartor delete 可以被重载，而malloc/free并不允许重载  
4. new/delete会调用对象的析构函数/析构函数以完成对象的构造/析构，而malloc不会  
5. malloc与free是C++/C语音的标准函数，new/delete是C++的运算符  
6. new操作符从自由存储区上为对象动态分配内存空间，而malloc函数从堆上动态的分配内存  

### **volatile**  
**定义**  
与const绝对对立的，是类型修饰符，影响编译器编译的结果，用该关键字声明的变量表示该变量随时可以发生变化，与该变量有关的运算，不要进行编译优化;会从内存中重新装载内容，而不是直接从寄存器拷贝内容。  
**作用**  
指令关键字，确保本条质量不会因为编译器的优化而省略，且要求每次直接读值，保证对特殊的地址稳定的访问。  
**使用场合**  
在中断服务程序和cpu相关的寄存器的定义  
举例说明  
空循环：  
`for(volatile int i = 0; i < 1000; i++);//他会执行，不会被优化掉`

### **extern**  
定义：声明外部变量【在函数或者文件外部定义的全局变量】  

### **static**  
作用：实现多个对象直接的数据共享+隐藏，并且使用静态成员还不会破坏隐藏原则;默认初始化为0

### **前置++与后置++**  

```  
self &operator++() {  
    node = (linktype)((node).next);  
    return *this;  
}  

const self operator++(int) {  
    self tmp = *this;  
    ++*this;  
    return tmp;  
}  
```  

为了区分前后置，重载函数是以参数类型来区分，在调用的时候，编译器默默给int指定为一个0  
**1. 为什么后置返回对象，而不是引用**  
因为后置为了返回旧值创建了一个临时对象，在函数结束的时候这个对象就好被销毁，如果返回引用，对象都被销毁了，没有可以引用的了。  
**2. 为什么后置前面也要加上const**  
其实也可以不加，但是为了防止使用i++++,连续两次的调用后置++重载符。  
**原因**  
它与内置类型行为不一致;你无法得到你所期望的结果，因为第一次返回的是旧值，而不是原对象，你调用两次后置++，结果只累加了一次，所以我们必须手动禁止其合法化，就要在前面加上const。  
**3.  处理用户的自定义类型**  
最好使用前置的++，因为他不会创建临时的对象，进而不会带来构造和析构所造成的额外开销  
