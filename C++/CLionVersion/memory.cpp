//
// Created by Yang Shuangzhen on 2019/9/14.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

void get_memory(){

}

//考题，设计get_memory()函数，给p分配内存，使程序能正常运行。
int main()
{
    int a = 1;
    char* p = nullptr;
    get_memory();  //这里调用get_memory()函数
    strcpy_s(p, 100, "hello world");
    printf("%s\n", p);
    free(p);
    p = nullptr;
}
