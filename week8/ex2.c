#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*Exercise 2: Comment from the  Andrew S. Tanenbaum and Herbert Bos. Modern Operating Systems, Pearson
"There is a need to run programs that
are too large to fit in memory, and there is certainly a need to have systems that can
support multiple programs running simultaneously, each of which fits in memory
but all of which collectively exceed memory. A solution adopted in the 1960s was to split programs into little pieces,
called overlays. The overlays were kept on the disk and swapped in and out of memory by the OS."
Since there was not enough memory, si and so have been changed:
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 0  0 150096 3237304      0      0    1    1     1     1    1    0  8  6 86  0             0
 0  0 150096 3222532      0      0   64    0     1     0 4941 8069  2  6 92  0             0
 0  0 150096 3218180      0      0    0    0     0     0 2616 4361  2  3 95  0             0
 0  0 150096 3203956      0      0    0    0     0     0 2607 4652  1  4 95  0             0

Exercise 3:
BEFORE:

Process Name           PID  PPID  CPU Mem(KB) IO/s Prio Threa Started Owner          Command
System                   4     0   0%    7820    0   8   182 20-09-10 Unknown        NULL
Registry                96     4   0%   53624    0   8     4 20-09-10 Unknown        NULL
smss                   536     4   0%     572    0  11     2 20-09-10 Unknown        NULL
csrss                  788   776   0%    2412    0  13    16 20-09-10 Unknown        NULL
wininit                888   776   0%    3032    0  13     2 20-09-10 Unknown        NULL
services                76   888   0%    7380    0   9    11 20-09-10 Unknown        NULL
lsass                  292   888   0%   16240    0   9     9 20-09-10 Unknown        NULL
svchost                700    76   0%     644    0   8     2 20-09-10 Unknown        NULL
WUDFHost               712    76   0%    6756    0   8    10 20-09-10 Unknown        NULL
svchost                768    76   0%   46864    0   8    22 20-09-10 Unknown        NULL
fontdrvhost            792   888   0%     844    0   8     5 20-09-10 Unknown        NULL
WUDFHost              1060    76   0%    1792    0   8     6 20-09-10 Unknown        NULL
svchost               1124    76   0%   15368    0   8    13 20-09-10 Unknown        NULL
svchost               1176    76   0%    5040    0   8     6 20-09-10 Unknown        NULL
svchost               1324    76   0%    2744    0   8     4 20-09-10 Unknown        NULL
svchost               1332    76   0%    4048    0   8     4 20-09-10 Unknown        NULL
svchost               1344    76   0%    4672    0   8     8 20-09-10 Unknown        NULL
svchost               1368    76   0%    4996    0   8     7 20-09-10 Unknown        NULL
svchost               1456    76   0%    6076    0   8     2 20-09-10 Unknown        NULL
svchost               1512    76   0%    4212    0   8     3 20-09-10 Unknown        NULL
svchost               1744    76   0%    7848    0   8     3 20-09-10 Unknown        NULL
svchost               1816    76   0%   12476    0   8    13 20-09-10 Unknown        NULL

AFTER:

Process Name           PID  PPID  CPU Mem(KB) IO/s Prio Threa Started Owner          Command
System                   4     0   0%    7820    0   8   182 20-09-10 Unknown        NULL
Registry                96     4   0%   53620    0   8     4 20-09-10 Unknown        NULL
smss                   536     4   0%     572    0  11     2 20-09-10 Unknown        NULL
csrss                  788   776   0%    2412    0  13    16 20-09-10 Unknown        NULL
wininit                888   776   0%    3028    0  13     2 20-09-10 Unknown        NULL
services                76   888   0%    7376    0   9    11 20-09-10 Unknown        NULL
lsass                  292   888   0%   16240    0   9     9 20-09-10 Unknown        NULL
svchost                700    76   0%     644    0   8     2 20-09-10 Unknown        NULL
WUDFHost               712    76   0%    6748    0   8    10 20-09-10 Unknown        NULL
svchost                768    76   0%   46852    0   8    21 20-09-10 Unknown        NULL
fontdrvhost            792   888   0%     844    0   8     5 20-09-10 Unknown        NULL
WUDFHost              1060    76   0%    1792    0   8     6 20-09-10 Unknown        NULL
svchost               1124    76   0%   15348    0   8    13 20-09-10 Unknown        NULL
svchost               1176    76   0%    5040    0   8     6 20-09-10 Unknown        NULL
svchost               1324    76   0%    2740    0   8     4 20-09-10 Unknown        NULL
svchost               1332    76   0%    4044    0   8     4 20-09-10 Unknown        NULL
svchost               1344    76   0%    4668    0   8     8 20-09-10 Unknown        NULL
svchost               1368    76   0%    4996    0   8     7 20-09-10 Unknown        NULL
svchost               1456    76   0%    6072    0   8     2 20-09-10 Unknown        NULL
svchost               1512    76   0%    4208    0   8     3 20-09-10 Unknown        NULL
svchost               1744    76   0%    7844    0   8     3 20-09-10 Unknown        NULL
svchost               1816    76   0%   12472    0   8    13 20-09-10 Unknown        NULL



*/
int main() {

    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int i;
    for(int i=0;i<10;i++) {
    // Dynamically allocate memory using calloc()
        ptr = (int*)calloc(1, 10485760);
        memset(ptr, 0, 10*1024*1024);
        sleep(1);
    }
    // Free the memory
    free(ptr);
    return 0;
}
