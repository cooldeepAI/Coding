//
// Created by Yang Shuangzhen on 2019/9/19.
// Reference: https://www.jyt0532.com/2016/12/23/c++-multi-thread-p2/
//

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string>
#include <vector>

using namespace std;

//class Thread{
//public:
//    Thread(thread& th){
//        t = th;
//    }
//    void new_sample_thread();
//    void detach_thread();
//    void add_param_thread();
//
//private:
//    thread t;
//};


void new_sample_thread(){
    cout << "I am a new thread" << endl;
}

/**
 * join() : add thread to process
 */
void test_new_sample_thread(){
    cout << "*********************create new thread*********************" << endl;
    thread t1(new_sample_thread);
    t1.join(); //without this line, program will abort
    cout << "I am the master thread" << endl;
}

void detach_thread(){
    cout << "I am a new thread" << endl;
    usleep(2000);
    cout << "This message is unlikely to show" << endl;
}

/**
 * detach(): detach child thread and master thread
 */
void test_detach_thread(){
    cout << "*********************detach child thread*********************" << endl;
    thread t1(detach_thread);
    cout << "I am the master thread" << endl;
    t1.detach();
    cout << "I am master thread and I am about to finish" << endl;
}

int a = 0;
void func(int i, const string s){
    //cout << i << ", " << s << this_thread::get_id() << endl;
    a++;
    cout << "a: " << a << endl;
}

void add_param_thread(){
    cout << "*********************add param for thread*********************" << endl;
    vector<thread> threads;
    threads.reserve(10);
    for (int i=0; i < 10; i++){
        threads.emplace_back(func, i, "test");
    }
    for (auto & thread : threads){
        thread.join();
    }
}

void test_thread(){
    test_new_sample_thread();
    test_detach_thread();
    add_param_thread();
}

//int main() {
//    test_thread();
//}