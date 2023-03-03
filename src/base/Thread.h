#pragma once


#include <thread>
#include <functional>
#include <memory>
#include <string>
#include <atomic>

#include "nocopyable.h"

class Thread : nocopyable{
public:
    using ThreadFunc = std::function<void()>;
    explicit Thread(ThreadFunc, const std::string &name = std::string());
    ~Thread();
    void start();
    void join();
    bool started(){ return started_;}
    pid_t tid() const { return tid_;}
    static int numCreated(){ return numCreated_;}


private:
    void setDefaultName();// 设置线程名
    bool started_; //线程是否开始
    bool joined_;   // 线程是否等待
    std::shared_ptr<std::thread> thread_; 
    pid_t tid_; // 线程ID
    ThreadFunc func_; //线程绑定的方法
    std::string name_;  // 线程名
    static std::atomic_int32_t numCreated_; //  线程索引
};