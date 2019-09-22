//
// Created by Yang Shuangzhen on 2019/9/22.
//

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
    s.p[1] = 1;
    s.p[0] = 2;
    return 0;
}