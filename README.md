# cpp11实现的muoduo网络库

## 时间

---

- 2023-3-2 新建项目, 准备实现base部分
- 2023-3-3 完成timestamp，nocopyable.h CurrentThread Thread

---

## 已完成部分
- Base
  - Timestamp nocopyable.h CurrentThread Thread 

---

## 知识点

  1. explicit 是避免构造函数的参数自动转换为类对象的标识符,显式地定义了一个带一个参数的构造函数（ 带explicit），必须要显示地调用构造函数,此关键字只能对用户自己定义的对象起作用，不对默认构造函数起作用,此关键字只能够修饰构造函数。而且构造函数的参数只能有一个。
  2. static https://blog.csdn.net/www_dong/article/details/116102066
  3. 函数声明为 =default,编译器将其设置为默认的函数定义体，提高效率


