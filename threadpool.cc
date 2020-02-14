#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <queue>

typedef void (*Hander_t)(int);
#define PTHREADCOUNT 4

// 定义一个任务类
class ThreadTask{
public:
    ThreadTask(){
        data_ = -1;
        hander_ = NULL;
    }
    ThreadTask(int data,Hander_t hander){
        data_ = data;
        hander_ = hander;
    }
    // 任务执行函数
    void Run(){
        hander_(data_);
    }
private:
    int data_;
    Hander_t hander_;
};

class PthreadPool{
public:
    PthreadPool(){
        PthreadCapacity_ = PTHREADCOUNT; 
        PthreadCurNum_ = PTHREADCOUNT; 
        pthread_mutex_init(&mutex_,NULL);
        pthread_cond_init(&cond_,NULL);
        IsEsc = false;
        // 创建线程函数
        ThreadCreate();
    }
    ~PthreadPool(){
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&cond_);
    }
    // 线程的清理
    void ClearPool(){
        PoolClear();
    }
private:
    // 创建线程
    void ThreadCreate(){
        pthread_t pid[PTHREADCOUNT];
        for(int i =0;i < PTHREADCOUNT;++i){
            pthread_create(&pid[i],NULL,StartCon,(void*)this);
        }
    }
    // 线程入口函数
    static void* StartCon(void* arg){
       PthreadPool* tp = (PthreadPool*)arg; 
       while(1){
           pthread_mutex_lock(&tp->mutex_);
           while(tp->Que_.empty()){
               if(tp->IsEsc){
                   tp->ThreadQuit();
               }
                pthread_cond_wait(&tp->cond_,&tp->mutex_);
           }
           pthread_mutex_unlock(&tp->mutex_);
           ThreadTask* tt;
           tp->Pop(&tt);
           pthread_mutex_unlock(&tp->mutex_);
           tt->Run();
           delete tt;
       }
    }
public:
    // 队列插入的数据
    void Push(ThreadTask* Tt) {
        pthread_mutex_lock(&mutex_);
        if(IsEsc){
            pthread_mutex_unlock(&mutex_);
            return;
        }
        Que_.push(Tt);
        pthread_mutex_unlock(&mutex_);
        pthread_cond_signal(&cond_);
    }
    // 队列取数据
    void Pop(ThreadTask** Tt){
        *Tt = Que_.front();
        Que_.pop();
    }

    // 清理线程池
    // 唤醒等待队列中的线程
    void PoolClear(){
        pthread_mutex_lock(&mutex_);
        IsEsc = true;
        pthread_mutex_unlock(&mutex_);
        if(PthreadCurNum_ > 0){
            pthread_cond_broadcast(&cond_);
        }
    }
private:
    // 线程的退出
    void ThreadQuit(){
        PthreadCurNum_ --;
        pthread_mutex_unlock(&mutex_);
        pthread_exit(NULL);
    }
private:
    // 线程池初始化的线程数量
    size_t PthreadCapacity_;
    size_t PthreadCurNum_;
    // 线程池队列
    std::queue<ThreadTask*>Que_;
    // 同步与互斥
    pthread_mutex_t mutex_;
    pthread_cond_t cond_;
    // 退出标志
    bool IsEsc;
};

void Print(int data){
    printf("i am Hander func ,i print [%d]\n",data);
}

int main(){
    PthreadPool* tp = new PthreadPool();
    for(int i =0; i < 10; ++i){
        ThreadTask* tt = new ThreadTask(i,Print);
        tp->Push(tt);
    }
    sleep(4);
    // 清理线程池
    tp->ClearPool();
    delete tp;
    return 0;
}
