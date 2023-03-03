#include <semaphore.h>
#include "Thread.h"
#include "CurrentThread.h"

// 声明了一个原子整型变量，用于跟踪已创建的线程数
std::atomic_int32_t Thread::numCreated_(0);

/* Thread类的构造函数。它接受ThreadFunc对象（函数指针）和字符串作为参数。
构造函数初始化成员变量，设置默认线程名称，并将ThreadFunc对象移动到类成员变量中 
*/

Thread::Thread(ThreadFunc func, const std::string &name):
    started_(false),
    joined_(false),
    tid_(0),
    func_(std::move(func)),
    name_(name){
        setDefaultName();
    }

/* 

Thread类的析构函数。它检查线程是否已启动但未加入，如果是，则将线程分离。

 */

Thread::~Thread(){
    if(started_ && !joined_){
        thread_->detach();
    }   
}
/* 

该方法是启动线程的方法。
在该方法中，使用了 POSIX 中的信号量来实现线程同步。
该方法首先将 started_ 标志设置为 true，然后创建一个 sem_t 类型的信号量对象。
接着使用 std::shared_ptr<std::thread> 类创建一个新的线程，并在新线程中执行 ThreadFunc 函数。
在新线程中，线程 ID 由 CurrentThread::tid() 获取。最后，使用 sem_post() 来通知主线程线程已经启动。
 
 */
void Thread::start(){
    started_ = true;
    sem_t sem;
    sem_init(&sem, false, 0);
    thread_ = std::shared_ptr<std::thread>(new std::thread([&](){
        tid_ = CurrentThread::tid();
        sem_post(&sem);
        func_();
    }));

    sem_wait((&sem));
}


void Thread::join(){
    joined_ = true;
    thread_->join();
}

void Thread::setDefaultName(){
    int num = ++numCreated_;
    if(name_.empty()){
        char buf[32] = {0};
        snprintf(buf, sizeof(buf), "Thread%d", num);
        name_ = buf;
    }
}
