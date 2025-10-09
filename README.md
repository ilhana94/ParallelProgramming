# ParallelProgramming
student@itcenter-lab128:~/new1$ make valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./memory_demo
==7988== Memcheck, a memory error detector
==7988== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7988== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==7988== Command: ./memory_demo
==7988== 
==7988== Invalid write of size 4
==7988==    at 0x1091C6: main (main.c:7)
==7988==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==7988==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==7988==    by 0x109185: main (main.c:5)
==7988== 
==7988== Conditional jump or move depends on uninitialised value(s)
==7988==    at 0x1091F4: main (main.c:9)
==7988==  Uninitialised value was created by a stack allocation
==7988==    at 0x109169: main (main.c:3)
==7988== 
==7988== Invalid read of size 4
==7988==    at 0x1091EF: main (main.c:9)
==7988==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==7988==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==7988==    by 0x109185: main (main.c:5)
==7988== 
==7988== 
==7988== HEAP SUMMARY:
==7988==     in use at exit: 40 bytes in 1 blocks
==7988==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==7988== 
==7988== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==7988==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==7988==    by 0x109185: main (main.c:5)
==7988== 
==7988== LEAK SUMMARY:
==7988==    definitely lost: 40 bytes in 1 blocks
==7988==    indirectly lost: 0 bytes in 0 blocks
==7988==      possibly lost: 0 bytes in 0 blocks
==7988==    still reachable: 0 bytes in 0 blocks
==7988==         suppressed: 0 bytes in 0 blocks
==7988== 
==7988== For lists of detected and suppressed errors, rerun with: -s
==7988== ERROR SUMMARY: 14 errors from 4 contexts (suppressed: 0 from 0)
student@itcenter-lab128:~/new1$ make
make: Nothing to be done for 'all'.
student@itcenter-lab128:~/new1$ main
Command 'main' not found, did you mean:
  command 'man' from deb man-db (2.10.2-1)
  command 'maim' from deb maim (5.6.3-1)
  command 'mail' from deb mailutils (1:3.14-1)
  command 'amin' from deb orville-write (2.55-3build1)
  command 'rain' from deb bsdgames (2.17-29)
Try: apt install <deb name>
student@itcenter-lab128:~/new1$ main.c
main.c: command not found
student@itcenter-lab128:~/new1$ ./main.c
bash: ./main.c: Permission denied
student@itcenter-lab128:~/new1$ make valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./memory_demo
==8172== Memcheck, a memory error detector
==8172== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8172== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==8172== Command: ./memory_demo
==8172== 
==8172== Invalid write of size 4
==8172==    at 0x1091C6: main (main.c:7)
==8172==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==8172==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8172==    by 0x109185: main (main.c:5)
==8172== 
==8172== Conditional jump or move depends on uninitialised value(s)
==8172==    at 0x1091F4: main (main.c:9)
==8172==  Uninitialised value was created by a stack allocation
==8172==    at 0x109169: main (main.c:3)
==8172== 
==8172== Invalid read of size 4
==8172==    at 0x1091EF: main (main.c:9)
==8172==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==8172==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8172==    by 0x109185: main (main.c:5)
==8172== 
==8172== 
==8172== HEAP SUMMARY:
==8172==     in use at exit: 40 bytes in 1 blocks
==8172==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==8172== 
==8172== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==8172==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8172==    by 0x109185: main (main.c:5)
==8172== 
==8172== LEAK SUMMARY:
==8172==    definitely lost: 40 bytes in 1 blocks
==8172==    indirectly lost: 0 bytes in 0 blocks
==8172==      possibly lost: 0 bytes in 0 blocks
==8172==    still reachable: 0 bytes in 0 blocks
==8172==         suppressed: 0 bytes in 0 blocks
==8172== 
==8172== For lists of detected and suppressed errors, rerun with: -s
==8172== ERROR SUMMARY: 14 errors from 4 contexts (suppressed: 0 from 0)
student@itcenter-lab128:~/new1$ make
gcc -Wall -Wextra -g -std=c99 -o memory_demo main.c
main.c: In function ‘main’:
main.c:7:39: warning: ‘ipos’ may be used uninitialized [-Wmaybe-uninitialized]
    7 | for (int i = 0; i<10; i++){ iarray[i] = ipos; }
      |                             ~~~~~~~~~~^~~~~~
student@itcenter-lab128:~/new1$ make valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./memory_demo
==8267== Memcheck, a memory error detector
==8267== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8267== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==8267== Command: ./memory_demo
==8267== 
==8267== Conditional jump or move depends on uninitialised value(s)
==8267==    at 0x1091F4: main (main.c:9)
==8267==  Uninitialised value was created by a stack allocation
==8267==    at 0x109169: main (main.c:3)
==8267== 
==8267== 
==8267== HEAP SUMMARY:
==8267==     in use at exit: 40 bytes in 1 blocks
==8267==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==8267== 
==8267== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==8267==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8267==    by 0x109185: main (main.c:5)
==8267== 
==8267== LEAK SUMMARY:
==8267==    definitely lost: 40 bytes in 1 blocks
==8267==    indirectly lost: 0 bytes in 0 blocks
==8267==      possibly lost: 0 bytes in 0 blocks
==8267==    still reachable: 0 bytes in 0 blocks
==8267==         suppressed: 0 bytes in 0 blocks
==8267== 
==8267== For lists of detected and suppressed errors, rerun with: -s
==8267== ERROR SUMMARY: 11 errors from 2 contexts (suppressed: 0 from 0)
student@itcenter-lab128:~/new1$ ^C
student@itcenter-lab128:~/new1$ make
gcc -Wall -Wextra -g -std=c99 -o memory_demo main.c
student@itcenter-lab128:~/new1$ make valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./memory_demo
==8385== Memcheck, a memory error detector
==8385== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8385== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==8385== Command: ./memory_demo
==8385== 
==8385== 
==8385== HEAP SUMMARY:
==8385==     in use at exit: 40 bytes in 1 blocks
==8385==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==8385== 
==8385== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==8385==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8385==    by 0x109193: main (main.c:5)
==8385== 
==8385== LEAK SUMMARY:
==8385==    definitely lost: 40 bytes in 1 blocks
==8385==    indirectly lost: 0 bytes in 0 blocks
==8385==      possibly lost: 0 bytes in 0 blocks
==8385==    still reachable: 0 bytes in 0 blocks
==8385==         suppressed: 0 bytes in 0 blocks
==8385== 
==8385== For lists of detected and suppressed errors, rerun with: -s
==8385== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
student@itcenter-lab128:~/new1$ 
student@itcenter-lab128:~/new1$ make
gcc -Wall -Wextra -g -std=c99 -o memory_demo main.c
student@itcenter-lab128:~/new1$ make valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./memory_demo
==8469== Memcheck, a memory error detector
==8469== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8469== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==8469== Command: ./memory_demo
==8469== 
==8469== 
==8469== HEAP SUMMARY:
==8469==     in use at exit: 0 bytes in 0 blocks
==8469==   total heap usage: 1 allocs, 1 frees, 40 bytes allocated
==8469== 
==8469== All heap blocks were freed -- no leaks are possible
==8469== 
==8469== For lists of detected and suppressed errors, rerun with: -s
==8469== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


- I used Valgrind to fix the errors in this code:
1. The first error it reported was the loop for initializing the array, originally the condition was i<=10, which means that the loop goes from 1 to 10 including 10, i.e. a total of 11 iterations, while the size of the array is 10, which leads to a memory overflow. I corrected it to i < 10, and now it is correct because the array now goes from 0 to 9.
2. The second error was the memory release, in the original code the memory was not freed by the malloc function. The result was a memory leak. I added the line of code free(iarray); at the end of the function before return 0; to free the memory.
   - These changes in the code removed the errors that Valgrind reported and now everything works correctly.
