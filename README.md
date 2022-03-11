# cpp_learn

## Nowdays

[C++ Primer 5th](#C-Primer-5th)  
[一些总结性的文章](#一些总结性的文章)

## Future

Effective C++  
More Effective C++  
Inside the C++ Object Model  
The Annotated STL Sources  
C++ concurrency in action  
C++ Templates

---

## C++ Primer 5th

[书上的源代码](./cpp_primer/source) 和 [参考答案](https://github.com/Mooophy/Cpp-Primer)

### Index

- 开始
  - [Chapter 1 开始](#Chapter-1-开始)
- C++ 基础
  - [Chapter 2 变量和基本类型](#Chapter-2-变量和基本类型)
  - [Chapter 3 字符串、向量和数组](#Chapter-3-字符串向量和数组)
  - [Chapter 4 表达式](#Chapter-4-表达式)
  - [Chapter 5 语句](#Chapter-5-语句)
  - [Chapter 6 函数](#Chapter-6-函数)
  - [Chapter 7 类](#Chapter-7-类)


### Chapter 1 开始

[CH1 习题](./cpp_primer/exercise/ch1/exercise_ch1.md)

1. 复习一下CSAPP学的不同类型运算的转换，有符号和无符号运算，默认先转为无符号，先保证同有无符号；然后如果大小不同，那么符号扩展到相同类型，要明白只有相同类型才能运算。
2. endl 输出换行符并刷新缓冲区。
3. EOF(Unix 是 Ctrl+D, Windows 是 Ctrl+Z) 或无效输入会导致IO流对象状态变成无效，条件判断变为 false，来终止循环。
4. cin标准输入、cout标准输出、cerr错误输出、clog日志输出。
5. 定义在函数内部的内置类型变量默认是不初始化的，里面的值是未定义的。

---

### Chapter 2 变量和基本类型

1. 引用本身不是一个对象，只是对象的一个别名而已(这里是指外在表现，不是说内部实现)。

2. 看复合类型从右往左最贴近标识符的说明了类型

  ```c++
  int *& val; => int *(&val); // 比如这个复制的类型，是对int *的引用
  ```

3. 引用绑定之后就不再改变绑定到其他对象了，所以它的const只是代表绑定的对象的值是const的。（如果是指针的引用，那么指针本身变量是const，即指针不能改变指向，而不是指向的变量是const）

4. 类型转换(截断或者提升)是一种运算，产生一个临时值(是右值，和原来的左值变量没有关系)，可以看成结果是一个常量，一个是原来的变量，一个是新的临时常量。因为const引用既可以绑定左值也可以绑定右值，所以类型转换结果是一个临时值的行为可能会造成一些误解。  
比如const引用要绑定一个变量，如果引用的类型和要绑定的变量类型不一样，发生隐式类型转换或者显示强制类型转换，那么要知道这里绑定的是一个临时值，是一个右值，因为类型转换运算的结果就是一个与原来那个变量无关的临时值，这时候绑定的就是这个右值常量(和字面值一样)，这样即使你改了那个变量的值，和这个临时右值常量没有一点关系；如果类型一致没有发生类型转换运算的普通情况下，const引用绑定就是个左值，那么虽然不可以通过const引用改变，但可以通过其他途径改值，而const引用也能从中体现实体改过值。

5. using TYPE = type; 类型别名

6. decltype 可以用来推断类型

7. C的C风格字符串本质是数组，所以==比较的就是数组地址是否相同；java、C#的String的==默认也都是比较地址；而C++的string类型特殊，它重载的==运算符操作函数的实现比较的就是字符串，而不是地址。

---

### Chapter 3 字符串、向量和数组

---

### Chapter 4 表达式

---

### Chapter 5 语句

---

### Chapter 6 函数

---

### Chapter 7 类

---

## 一些总结性的文章

1. [关于全局变量多文件共享全局变量(extern、static)的总结](#关于全局变量多文件共享全局变量externstatic的总结)  
2. [const引用绑定可能是一个类型转换产生的右值，而非你想的左值](#const引用绑定可能是一个类型转换产生的右值而非你想的左值)

### 关于全局变量多文件共享全局变量(extern、static)的总结

一个全局变量的可见性只是单个源文件，比如我们在a.cpp定义了一个全局变量，那么自然在b.cpp看不到也使用不到这个全局变量，那么我们该如何共享呢？

你可能会想在头文件里面定义这个全局变量，然后分别通过因为头文件，但这是错误的，头文件的本质是文本替换，意思是在预处理阶段的时候会把#include文本替换成对应的头文件里面的内容，如果a.cpp和b.cpp都分别引用同一个头文件，那么在头文件里面定义的代码会分别放入这两个源文件，那么这个意思是a.cpp和b.cpp分别重复定义了一个可见域都只是所在源文件的不共享的全局变量，根本没有实现共享，而且还重复定义了。

所以为了防止重复定义，再说本来也没有共享全局变量的功能，所以一个C++好的规范要求头文件里面不能放定义，无论是函数还是变量的定义都不可以。

为了实现共享，我们在其中一个源文件比如a.cpp里面定义了一个全局变量，然后在头文件里面声明这个全局变量，注意声明是用extern而且不能含有初始化，然后其他源文件就可以通过引用这个头文件(或者自己手动在源文件里面extern声明)里面的extern声明来实现共享这个全局变量。

这个方式注意如果是const常量，那么const常量在定义的时候也要加上extern(不过一些不同环境这里无所谓的)，另外const常量完全可以放在头文件里面，因为虽然也是不同源文件里面重复定义了可见范围仅限于本文件的全局变量也无所谓，因为const常量不会改变内容，虽然重复定义会浪费一些内存，但是他们的值都是一样的，都是最初我们写在头文件里面定义的那个值，这个代码风格挺不好的但是能用，当然这种情况下在头文件里面之间用宏来写更好，连声明和定义都不涉及，单纯文本替换了。

然后思考一下static的用法，对于全局变量，用了static那么这个全局变量的可见域就强制仅限于该源文件了，即使别的源文件extern声明也找不到这个static的全局变量。这样比如两个源文件里面都有同名(这里是麻烦的地方，重名，但是需要只共享其中的一个)的全局变量，一个要共享一个不需要共享，那么为了防止不需要共享的重名全局变量干扰，那么static就是一个解决方案，这对于链接库有时很有帮助。

### const引用绑定可能是一个类型转换产生的右值，而非你想的左值

类型转换(截断或者提升)是一种运算，产生一个临时值(是右值，和原来的左值变量没有关系)，可以看成结果是一个常量，一个是原来的变量，一个是新的临时常量。因为const引用既可以绑定左值也可以绑定右值，所以类型转换结果是一个临时值的行为可能会造成一些误解。

比如const引用要绑定一个变量，如果引用的类型和要绑定的变量类型不一样，发生隐式类型转换或者显示强制类型转换，那么要知道这里绑定的是一个临时值，是一个右值，因为类型转换运算的结果就是一个与原来那个变量无关的临时值，这时候绑定的就是这个右值常量(和字面值一样)，这样即使你改了那个变量的值，和这个临时右值常量没有一点关系；如果类型一致没有发生类型转换运算的普通情况下，const引用绑定就是个左值，那么虽然不可以通过const引用改变，但可以通过其他途径改值，而const引用也能从中体现实体改过值。

[代码示例](./source/blog2.cpp)  

```txt
/* 运行结果 */
未发生类型转换，const引用绑定的是一个 int 左值变量: 1
发生类型转换，const引用绑定的是一个 long 临时右值常量: 1
绑定的就是那个左值变量: 2
绑定的右值和原来那个变量一点关系都没有: 1
```
