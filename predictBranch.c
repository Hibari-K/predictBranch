#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

#define LOOP 10000

int add(int a, int b);
int add_array_asm_plus(int *arr);
int add_array_asm_minus(int *arr);

int main(){

    struct timeval s, e;
    double time;
    
    int i;
    int ans = 0;

    // init
    int arr[32767]; // 65536/2 - 1
    for(i=0; i<32767; i++) arr[i] = i+1;
    
    //bdnz-
    ans = add_array_asm_minus(arr);
    gettimeofday(&s, NULL);
    
    for(i=0; i<LOOP; i++) ans = add_array_asm_minus(arr);
    
    gettimeofday(&e, NULL);
    printf("add_array_asm_minus = %d\n", ans);
   
    time = (e.tv_sec - s.tv_sec) + (e.tv_usec - s.tv_usec)*1.0E-6;
    printf("time = %lf [s]\n", time);

    // bdnz+
    ans = add_array_asm_plus(arr);
    gettimeofday(&s, NULL);
    
    for(i=0; i<LOOP; i++) ans = add_array_asm_plus(arr);
    
    gettimeofday(&e, NULL);
    printf("add_array_asm_plus = %d\n", ans);
   
    time = (e.tv_sec - s.tv_sec) + (e.tv_usec - s.tv_usec)*1.0E-6;
    printf("time = %lf [s]\n", time);
    
    return 0;
}
