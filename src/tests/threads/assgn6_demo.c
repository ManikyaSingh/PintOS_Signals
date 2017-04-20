#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/init.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "devices/timer.h"
#include "threads/signal.h"

struct semaphore sem; 

static void sleeper1(void* t) {
  struct thread* curr = thread_current();
  tid_t id = curr->parent;
  kill(id,SIG_USR);
  timer_msleep(2000);
}

static void sleeper2(void* t){
  setlifetime(100);
  while(1);
}

static void sleeper3(void* t){
  // sema_init (&sem, 0);
  // sema_down(&sem);
  enum intr_level old_level;
  old_level = intr_disable ();

  thread_block();

  intr_set_level (old_level);
  printf("\n\nunblocked\n\n");
  while(1);
}

void ass6_1(){
  thread_create("1", 0, sleeper1, NULL);
  while(1);
}

void ass6_2(){
  thread_create("1", 0, sleeper1, NULL);
  Signal(SIG_USR,SIG_IGN);
  Signal(SIG_CHLD,SIG_IGN);
  while(1);
}

void ass6_3(){
  thread_create("1", 0, sleeper2, NULL);
  while(1);
}

void ass6_4(){
  tid_t id = thread_create("1", 0, sleeper3, NULL);
  printf("%d\n",id);
  timer_sleep(40);
  printf("\nsent\n");
  kill(id,SIG_UBLOCK);
  timer_sleep(40);
  kill(id,SIG_KILL);
  timer_sleep(40);
}

void ass6_5(){
  int8_t x = 15; //01111
  sigprocmask(SIG_BLOCK,&x,NULL);
  setlifetime(1000);
  ass6_1();
}