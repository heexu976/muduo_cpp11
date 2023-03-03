#include "CurrentThread.h"
/* 
这段代码定义了一个命名空间 CurrentThread，其中包含了一个 __thread 修饰的变量 t_cachedTid 和一个函数 cacheTid。

__thread 关键字是 GCC 提供的一种线程局部存储 (TLS) 的机制，它用于声明一个变量是线程局部的。这意味着每个线程都有一个该变量的独立实例，线程间互不干扰。

变量 t_cachedTid 的作用是缓存当前线程的线程 ID (TID)，这里使用了 pid_t 类型表示 TID。缓存 TID 的原因是因为获取 TID 的系统调用 syscall(SYS_gettid) 比较耗时，为了减少系统调用的次数，可以将 TID 缓存在线程局部变量中。

函数 cacheTid 用于在需要使用 TID 的时候，从线程局部变量中获取 TID，如果线程局部变量中没有缓存 TID，则通过系统调用 syscall(SYS_gettid) 获取当前线程的 TID，并将其缓存在线程局部变量中。

总之，这段代码提供了一种在 C++ 中获取当前线程 TID 的方法，通过使用线程局部变量缓存 TID，避免了频繁调用系统调用的开销。

 */
namespace CurrentThread{
    __thread int t_cachedTid = 0;
    void cacheTid(){
        if(t_cachedTid == 0){
            t_cachedTid = static_cast<pid_t>(::syscall((SYS_gettid)));
        }
    }
}