#include <iostream>
#include <stdio.h>
#include <semaphore.h>
#include <vector>
using namespace std;
#define SIZE 4
#define PTHREADCOUNT 4

class RingQueue{
public:
    RingQueue()
        :vec_(SIZE)
    {
        Capacity_ = SIZE;
        PosWrite_ = 0;
        PosRead_ = 0;
        // 同步
        sem_init(&PosSem_,0,SIZE);
        sem_init(&ConSem_,0,0);
        // 互斥
        sem_init(&LockSem_,0,1);
    }
    ~RingQueue(){
        sem_destroy(&PosSem_);
        sem_destroy(&ConSem_);
        sem_destroy(&LockSem_);
    }
    void Push(int& data){
        // 先等待然后上锁
        sem_wait(&PosSem_);
        sem_wait(&LockSem_);
        vec_[PosWrite_] = data;
        PosWrite_ = (PosWrite_+1)%Capacity_;
        // 先解锁然后通知
        sem_post(&LockSem_);
        sem_post(&ConSem_);
    }
    void Pop(int* data){
        sem_wait(&ConSem_);
        sem_wait(&LockSem_);
        *data = vec_[PosRead_];
        PosRead_ = (PosRead_+1)%Capacity_;
        sem_post(&LockSem_);
        sem_post(&PosSem_);
    }
private:
    //利用数组和两个指针实现环形队列
    vector<int>vec_;
    size_t Capacity_;
    int PosRead_;
    int PosWrite_;
    // 生成者和消费者信号量实现同步
    sem_t PosSem_;
    sem_t ConSem_;
    // 二值信号量实现互斥
    sem_t LockSem_;
};

void* ProStart(void* arg){
    RingQueue* rq = (RingQueue*)arg;
    int i = 0;
    while(1){
        rq->Push(i);
        printf("Pro[%p] make data [%d]\n",pthread_self(),i);
        i++;
    }
    return NULL;
}
void* ConStart(void* arg){
    RingQueue* rq = (RingQueue*)arg;
    int data;
    while(1){
        rq->Pop(&data);
        printf("Con[%p] cons data [%d]\n",pthread_self(),data);
    }
    return NULL;
}

int main(){
    pthread_t Protid[PTHREADCOUNT],Contid[PTHREADCOUNT];
    RingQueue* rq = new RingQueue();
    for(int i = 0;i < PTHREADCOUNT;++i){
        pthread_create(&Protid[i],NULL,ProStart,(void*)rq);
        pthread_create(&Contid[i],NULL,ConStart,(void*)rq);
    }
    for(int i = 0;i < PTHREADCOUNT;++i){
        pthread_join(Protid[i],NULL);
        pthread_join(Contid[i],NULL);
    }
    delete rq;
    return 0;
}
