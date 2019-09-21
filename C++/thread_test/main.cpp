#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <mutex>

using namespace std;
struct Sum{
    int sum = 0;
    mutex mu;
    void incre(){
        mu.lock();
        sum++;
        cout << "sum: " << sum << endl;
        mu.unlock();
    }
};
void func(Sum &s)
{
    s.incre();
}
int main()
{
    vector<thread> threads;
    Sum s;
    threads.reserve(10000);
    for(int i = 0; i < 10000; i++){
        threads.emplace_back(func, ref(s));
    }
    for(auto & thread : threads){
        thread.join();
    }
    cout << s.sum << endl;
    return 0;
}