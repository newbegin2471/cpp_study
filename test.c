#include <stdio.h>
int func(int x){
    int count = 0;
    while (x){
        count++;
        x = x&(x - 1);//ÓëÔËËã
    }
    return count;
}
int main(int argc, char const *argv[])
{
    printf("%d\n",func(9999));
    return 0;
}
