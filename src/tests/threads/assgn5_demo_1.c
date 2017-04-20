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

  printf("Starting Test Malloc - 1\n\n");
  printMemory();
  int* a, b, c, d, e, f;

  printf("\n\n");
  a = malloc(16);
  if(a == NULL) return 0;
  printMemory();

  printf("\n\n");
  b = malloc(16);
  if(b == NULL) return 0;
  printMemory();

  printf("\n\n");
  c = malloc(130);
  if(c == NULL) return 0;
  printMemory();

  printf("\n\n");
  d = malloc(600);
  if(d == NULL) return 0;
  printMemory();

  printf("\n\n");
  e = malloc(600);
  if(e == NULL) return 0;
  printMemory();

  printf("\n\n");
  f = malloc(200);
  if(f == NULL) return 0;
  printMemory();

  printf("\n\n");
  free(f);
  printMemory();

  printf("\n\n");
  free(e);
  printMemory();

  printf("\n\n");
  free(d);
  printMemory();

  printf("\n\n");
  free(c);
  printMemory();

  printf("\n\n");
  free(b);
  printMemory();

  printf("\n\n");
  free(a);
  printMemory();

  // a[0] = 5;
  // printf("Size : %d\n", sizeof(a[0]));
}

void ass5_4(void) {

  printf("Starting Test Malloc - 2\n\n");
  printMemory();
  int* a;
  int* b;
  int* c;

  printf("\n\n");
  a = malloc(16);
  if(a == NULL) return 0;
  a[0] = 121;
  printf("Test 1 : %d\n", a[0]);
  printMemory();

  free(a);

  printf("\n\n");
  printMemory();
  
  c = malloc(128);
  if(c == NULL) return 0;
  c[0] = 131;
  printf("Test 2 : %d\n", c[0]);
  printMemory();

  printf("\n\n");
  printMemory();
  
  b = malloc(32);
  if(b == NULL) return 0;
  b[0] = 141;
  printf("Test 3 : %d\n", b[0]);

  printMemory();

  free(b);
  printMemory();
  free(c);
  printMemory();
}

void ass5_5(void) {

  printf("Starting Test Malloc - 3\n\n");
  printMemory();
  int* a;
  int i;

  printf("\n\n");
  a = malloc(64);
  if(a == NULL) return 0;
  
  for(i = 0; i < 16 ; i++){
    a[i] = i*i;
  }

  printf("Array : ");
  for(i = 0; i < 16 ; i++){
    printf("%d ", a[i]);
  }
  printf("\n");

  printMemory();

  a = realloc(a, 500);

  printf("\n");
  printf("Array : ");
  for(i = 0; i < 16 ; i++){
    printf("%d ", a[i]);
  }

  printf("\n");
  printMemory();
}