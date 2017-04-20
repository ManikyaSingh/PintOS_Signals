#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/init.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "devices/timer.h"
#include "threads/palloc.h"
#include "threads/switch.h"
#include "threads/synch.h"
#include "threads/vaddr.h"
#include "threads/signal.h"
#include "threads/interrupt.h"
#include "threads/intr-stubs.h"

static void
sleeper (void *test_) 
{
	// printf("\n\nBlocked\n\n");
	// enum intr_level old_level;
	// old_level = intr_disable ();

	// thread_block();

 // 	intr_set_level (old_level);
	
	// printf("\n\nUnblocked\n\n");

	
}



void test_demo(void) {

	// int tid = thread_create ("test", PRI_DEFAULT, sleeper, NULL);
	
	// timer_sleep(300);
	// kill(tid, SIG_UBLOCK);
	
	// printf("\nSignal sent\n");
	
	// while(1);
}

void test_demo2(void){
	
}