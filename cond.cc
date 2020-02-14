#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <queue>

#define PTHREADCOUNT 4
pthread_mutex_t mutex_;
pthread_cond_t ProCond_;
pthread_cond_t ConCond_;

class RingQueue{
public:
    RingQueue(int Capacity){
        Capacity_ = Capacity;
        pthread_mutex_init(&mutex_,NULL);
        pthread_cond_init(&ConCond_,NULL);
        pthread_cond_init(&ProCond_,NULL);
    }
    ~RingQueue(){
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&ConCond_);
        pthread_cond_destroy(&ProCond_);
    }
    void Pop(int* data){
        pthread_mutex_lock(&mutex_);
        while(Que_.empty()){
            pthread_cond_wait(&ConCond_,&mutex_);
        }
        *data = Que_.front();
        Que_.pop();
        pthread_mutex_unlock(&mutex_);
        pthread_cond_signal(&ProCond_);
    }
    void Push(int &data){
        pthread_mutex_lock(&mutex_);
        while(Que_.size() == Capacity_){
            pthread_cond_wait(&ProCond_,&mutex_);
        }
        Que_.push(data);
        pthread_mutex_unlock(&mutex_);
        pthread_cond_signal(&ConCond_);
    }
private:
    size_t Capacity_;
    std::queue<int>Que_;
};

void* ProStart(void* arg){
    RingQueue* rq = (RingQueue*)arg;
    int i = 0;
    while(1){
        rq->Push(i);
        printf("i am [%p] thread,i Porspect a [%d]\n",
                pthread_self(),i);
        i++;
    }
    return NULL;
}
void* ConStart(void* arg){
    RingQueue* rq = (RingQueue*)arg;
    int data;
    while(1){
        rq->Pop(&data);
        printf("i am [%p] thread,i Con a [%d]\n",
                pthread_self(),data);
    }
    return NULL;
}

int main(){
    pthread_t ProPid[PTHREADCOUNT],ConPid[PTHREADCOUNT];
    RingQueue* rq = new RingQueue(5);
    for(int i = 0; i < PTHREADCOUNT;++i){
        pthread_create(&ProPid[i],NULL,ProStart,(void*)rq);
        pthread_create(&ConPid[i],NULL,ConStart,(void*)rq);
    }
    for(int i = 0; i < PTHREADCOUNT;++i){
        pthread_join(ProPid[i],NULL);
        pthread_join(ConPid[i],NULL);
    }
    delete rq;
    return 0;
}
