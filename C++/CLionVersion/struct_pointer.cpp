//
// Created by Yang Shuangzhen on 2019/9/22.
//
#include <iostream>

using namespace std;

typedef struct _S
{
    int i;
    int *p;
}S, *PS;


int main()
{
    S s;
    int *p = &(s.i);
    p[0] = 4;
    p[1] = 3;
    s.p = p;

    cout << &p[0] << ":" << p[0] << endl;
    cout << &p[1] << ":" << p[1] << endl;
    cout << &p << endl;
    cout << "s.i: " << &s.i << " " << s.i << endl;
    cout << "s.p: " << s.p << endl;
    cout << "s: " << &s << endl;


    s.p[1] = 1;
    s.p[0] = 2;
    std::cout << "successed" << std::endl;
    return 0;
}