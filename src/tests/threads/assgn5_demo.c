/*
Instructions for scheduler part:
1. We have increase tick time to 50 ms i.e, TIMER_FREQ is 20 in timer.h
2. ass5_1 and ass5_2 are test functions for scheduler part. We are only concerned with the transition of states for each thread. We are also going to check the code, so come prepared with that.
3. There is no marks for blocked state output. But we will check your code whether you have implemented for blocked state.

Memory management part:
ass5_3, ass5_4 and ass5_5 are test functions for memory management part.
*/


#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/init.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "devices/timer.h"

static void
sleeper (void* t) 
{
	long long i = 1;
	while(1) if(i&&(i++)&&(++i)) i--;
}

struct semaphore sem; 

static void sleeper1(void* t) {
  sema_init (&sem, 0);
  int j;
  for(j=0; j<10; j++){
    int a=1, b=2, c=3, d=4;
    while(a<=100000000) {
      b = c+d;
      b = c-d;
      c++;
      d++;
      a++;
    }
    sema_down(&sem);
  }
    
}

static void sleeper2(void* t) {
  int j;
  for(j=0; j<10; j++){
    int a=1, b=2, c=3, d=4;
    while(a<=200000000) {
      b = c+d;
      b = c-d;
      c++;
      d++;
      a++;
    }
    sema_up(&sem);
  } 
}

void ass5_1(void) {
    printf("creating 8 threads\n");
    int i;
    char *names[]={"1","2","3","4","5","6","7","8"};
    for(i=0;i<8;i++) 
      thread_create(names[i], 0, sleeper, NULL);
    timer_sleep (1e6);
}

void ass5_2(void) {
    thread_create("1", 0, sleeper1, NULL);
    thread_create("2", 0, sleeper2, NULL);
    timer_sleep (1e6);
}

void ass5_3(void) {

 
  // a[0] = 5;
  // printf("Size : %d\n", sizeof(a[0]));
}

void ass5_4(void) {

  
}

void ass5_5(void) {

 
}