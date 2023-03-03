#pragma once 





/* 
    禁止拷贝操作的基类，设置为prodected权限的成员函数可以让派生类继承
    派生类对象可以正常的析构和构造
 */


class nocopyable{
public:
    nocopyable(const nocopyable &) = delete;
    nocopyable &operator = (const nocopyable &) = delete;

protected:
    nocopyable() = default;
    ~nocopyable() = default;
};