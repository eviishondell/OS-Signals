#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

void handler(int signum){
    printf("Hello World! \n");
        alarm(1);
        }

        int main() {
          signal(SIGALRM,handler);
          alarm(1);
          while(1) {
            sleep(1);
            printf("Turing was right!\n");
                    }
            return 0;
                    }