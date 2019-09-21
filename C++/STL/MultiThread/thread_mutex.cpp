#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <mutex>

using namespace std;

struct Sum{
    int sum = 0;
    float strategy = 0.1;
    int regret_1 = 20;
    int regret_2 = 30;

    mutex mu;
    void update(){
        mu.lock();
        sum++;
        regret_1 += 10;
        regret_2 -= 5;
        strategy += regret_1 / (regret_1+regret_2);

        mu.unlock();
    }
};

mutex mu;
void read_data(Sum &s){
    //mu.lock();
    cout << "read sum: " << s.sum << endl;
    cout << "sum: " << s.sum << endl;
    cout << "regret_1: " << s.regret_1
         << "\tregret_2: " << s.regret_2
         << "\tstrategy: " << s.strategy << endl;
    //mu.unlock();
}

void func(Sum &s)
{
    mu.lock();
    s.update();
    read_data(s);
    mu.unlock();
    cout << "***********************************" << endl;
}

int main()
{
    vector<thread> threads;
    Sum s;

    threads.reserve(10);
    for(int i = 0; i < 10; i++){
        threads.emplace_back(func, ref(s));
    }

    for(auto & thread : threads){
        thread.join();
    }

    cout << s.sum << endl;
    return 0;
}