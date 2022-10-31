#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

// If you change the alarm to another value greater than 1, say 5, this doesn't work. The alarm counter should be incremented in the signalrrm handler
int num_alarms = 0;
time_t start_time,end_time,total_secs; 

void handler(int signum)
{ 
  printf("Hello World!\n");
  num_alarms += 1;
}

void handler_sigint(int sec){
  end_time = time(NULL);
  total_secs = end_time - start_time;
  printf("\nNumber of alarms : %d \n", num_alarms);
  printf("The program was executing for: %ld seconds \n", total_secs);
  exit(1);
}

int main(int argc, char * argv[])
{
  start_time = time(NULL); 
  signal(SIGALRM,handler); 
  signal(SIGINT, handler_sigint); 
  while(1) { 
  alarm(1);
  // num_alarms += 1;
  sleep(1);
  printf("Turning was right!\n");
  }  
  return 0; 
}
