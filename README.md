student@itcenter-lab128:~/Desktop/assignment1/ParallelProgramming$ make
gcc -Wall -Wextra -g -std=c99 -o memory_demo assignment1.c
assignment1.c: In function ‘main’:
assignment1.c:7:42: warning: ‘ipos’ may be used uninitialized [-Wmaybe-uninitialized]
    7 |   for (int i = 0; i<=10; i++){ iarray[i] = ipos; }
      |                                ~~~~~~~~~~^~~~~~
student@itcenter-lab128:~/Desktop/assignment1/ParallelProgramming$ make valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./memory_demo 5
==20271== Memcheck, a memory error detector
==20271== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==20271== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==20271== Command: ./memory_demo 5
==20271== 
==20271== Invalid write of size 4
==20271==    at 0x1091C6: main (assignment1.c:7)
==20271==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==20271==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==20271==    by 0x109185: main (assignment1.c:5)
==20271== 
==20271== Conditional jump or move depends on uninitialised value(s)
==20271==    at 0x1091F4: main (assignment1.c:9)
==20271==  Uninitialised value was created by a stack allocation
==20271==    at 0x109169: main (assignment1.c:3)
==20271== 
==20271== Invalid read of size 4
==20271==    at 0x1091EF: main (assignment1.c:9)
==20271==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==20271==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==20271==    by 0x109185: main (assignment1.c:5)
==20271== 
==20271== 
==20271== HEAP SUMMARY:
==20271==     in use at exit: 40 bytes in 1 blocks
==20271==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==20271== 
==20271== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==20271==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==20271==    by 0x109185: main (assignment1.c:5)
==20271== 
==20271== LEAK SUMMARY:
==20271==    definitely lost: 40 bytes in 1 blocks
==20271==    indirectly lost: 0 bytes in 0 blocks
==20271==      possibly lost: 0 bytes in 0 blocks
==20271==    still reachable: 0 bytes in 0 blocks
==20271==         suppressed: 0 bytes in 0 blocks
==20271== 
==20271== For lists of detected and suppressed errors, rerun with: -s
==20271== ERROR SUMMARY: 13 errors from 4 contexts (suppressed: 0 from 0)
student@itcenter-lab128:~/Desktop/assignment1/ParallelProgramming$




#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int ipos = -1;
    int ival = 0;
    int *iarray = malloc(10 * sizeof(int));

    if (!iarray) {
        perror("malloc failed");
        return 1;
    }

    if (argc == 2)
        ival = atoi(argv[1]);

    for (int i = 0; i < 10; i++) {
        iarray[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        if (ival == iarray[i])
            ipos = i;
    }

    printf("Position: %d\n", ipos);

    free(iarray);
    return 0;
}
student@itcenter-lab128:~/Desktop/assignment1/ParallelProgramming$ make clean
rm -f memory_demo
student@itcenter-lab128:~/Desktop/assignment1/ParallelProgramming$ make
gcc -Wall -Wextra -g -std=c99 -o memory_demo assignment1.c
assignment1.c: In function ‘main’:
assignment1.c:7:42: warning: ‘ipos’ may be used uninitialized [-Wmaybe-uninitialized]
    7 |   for (int i = 0; i<=10; i++){ iarray[i] = ipos; }
      |                                ~~~~~~~~~~^~~~~~
student@itcenter-lab128:~/Desktop/assignment1/ParallelProgramming$ make clean
rm -f memory_demo
student@itcenter-lab128:~/Desktop/assignment1/ParallelProgramming$ make
gcc -Wall -Wextra -g -std=c99 -o memory_demo assignment1.c
student@itcenter-lab128:~/Desktop/assignment1/ParallelProgramming$ ^C
student@itcenter-lab128:~/Desktop/assignment1/ParallelProgramming$ ./memory_demo 5
Position: 5
student@itcenter-lab128:~/Desktop/assignment1/ParallelProgramming$ 


OBJAŠNJENJE:
Before my correction, the variables ipos and ival had no values, I gave them values ​​(ipos=-1,ival=-0) so that the program always had initial values.
At the beginning, the code used a loop with the condition i<=10 which was one number more than the limit. I changed the loop condition to i<10, which fixed the code so that the program does not go into memory outside the scope.
The array was previously filled with ipos which had no value and I filled it so that the values ​​go from 0 to 9 and now it gives the correct values.
The code previously did not have a check to see if malloc succeeded, which can cause errors if the memory is not specified. I added a check (perror) to show a message in case of that error.
The memory specified by the program was never freed. I added free(iarray) to free the memory after it is no longer needed, and thus I prevented a memory leak.
The code at the beginning did not have a complete main function so the program could not be executed. I wrote the entire main function so that the program could run normally.
The program did not display the search results. I added a printf so that the position of the searched value is correctly displayed to the user.


