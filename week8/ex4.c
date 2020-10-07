#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
//int getrusage(int RUSAGE_SELF, struct rusage *ru_maxrss);
int main(){

    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int i;
    for(int i=0;i<10;i++) {
    // Dynamically allocate memory using calloc()
        ptr = (int*)calloc(1, 10485760);
        memset(ptr, 0, 10*1024*1024);
        struct rusage ru_maxrss;
        getrusage(RUSAGE_SELF, &ru_maxrss);
        sleep(1);
    }
    // Free the memory
    free(ptr);
    return 0;
}
