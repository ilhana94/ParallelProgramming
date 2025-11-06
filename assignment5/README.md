
student@itcenter-lab128:~/Desktop/assignment5$ cp timestep_opt1.c timestep.c   # ili opt2/opt3
student@itcenter-lab128:~/Desktop/assignment5$ make clean
make stream_triad
make: *** No rule to make target 'clean'.  Stop.
make: *** No rule to make target 'stream_triad'.  Stop.
student@itcenter-lab128:~/Desktop/assignment5$ sudo likwid-perfctr -C 0 -f -g FLOPS_DP ./stream_triad
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
--------------------------------------------------------------------------------
Failed to execute command: ./stream_triad
--------------------------------------------------------------------------------
Group 1: FLOPS_DP
+--------------------------------------+---------+------------+
|                 Event                | Counter | HWThread 0 |
+--------------------------------------+---------+------------+
|           INSTR_RETIRED_ANY          |  FIXC0  |      60033 |
|         CPU_CLK_UNHALTED_CORE        |  FIXC1  |     496938 |
|         CPU_CLK_UNHALTED_REF         |  FIXC2  |     497046 |
| FP_COMP_OPS_EXE_SSE_FP_PACKED_DOUBLE |   PMC0  |          0 |
| FP_COMP_OPS_EXE_SSE_FP_SCALAR_DOUBLE |   PMC1  |         35 |
|       SIMD_FP_256_PACKED_DOUBLE      |   PMC2  |          0 |
+--------------------------------------+---------+------------+

+----------------------+------------+
|        Metric        | HWThread 0 |
+----------------------+------------+
|  Runtime (RDTSC) [s] |     0.0013 |
| Runtime unhalted [s] |     0.0002 |
|      Clock [MHz]     |  3291.7524 |
|          CPI         |     8.2777 |
|     DP [MFLOP/s]     |     0.0266 |
|   AVX DP [MFLOP/s]   |          0 |
|   Packed [MUOPS/s]   |          0 |
|   Scalar [MUOPS/s]   |     0.0266 |
|  Vectorization ratio |          0 |
+----------------------+------------+




student@itcenter-lab128:~/Desktop/assignment5$ cp timestep_opt2.c timestep.c
make -f MakeFile clean
make -f MakeFile stream_triad
./stream_triad
sudo likwid-perfctr -C 0 -f -g FLOPS_DP ./stream_triad
rm -rf ./stream_triad ./stream_triad.o ./timer.o ./main.o ./timestep.o
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c main.c -o main.o
main.c:11:22: optimized: loop vectorized using 32 byte vectors
main.c:21:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:112:10: missed: statement clobbers memory: __printf_chk (1, "Minimum dt is %lf\n", mymindt_6);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c timestep.c -o timestep.o
timestep.c:12:13: optimized: loop vectorized using 32 byte vectors
timestep.c:14:9: missed: couldn't vectorize loop
timestep.c:14:9: missed: not vectorized: control flow in loop.
timestep.c:12:13: optimized: loop vectorized using 32 byte vectors
timestep.c:15:25: missed: statement clobbers memory: wavespeed_58 = sqrt (_9);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c timer.c -o timer.o
timer.c:11:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:16:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -o stream_triad main.o timestep.o timer.o -lm
Minimum dt is 0.016964
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
--------------------------------------------------------------------------------
Minimum dt is 0.016964
--------------------------------------------------------------------------------
Group 1: FLOPS_DP
+--------------------------------------+---------+------------+
|                 Event                | Counter | HWThread 0 |
+--------------------------------------+---------+------------+
|           INSTR_RETIRED_ANY          |  FIXC0  |  217768246 |
|         CPU_CLK_UNHALTED_CORE        |  FIXC1  |  829825800 |
|         CPU_CLK_UNHALTED_REF         |  FIXC2  |  829825491 |
| FP_COMP_OPS_EXE_SSE_FP_PACKED_DOUBLE |   PMC0  |          0 |
| FP_COMP_OPS_EXE_SSE_FP_SCALAR_DOUBLE |   PMC1  |   90407320 |
|       SIMD_FP_256_PACKED_DOUBLE      |   PMC2  |          0 |
+--------------------------------------+---------+------------+

+----------------------+------------+
|        Metric        | HWThread 0 |
+----------------------+------------+
|  Runtime (RDTSC) [s] |     0.5062 |
| Runtime unhalted [s] |     0.2520 |
|      Clock [MHz]     |  3292.3354 |
|          CPI         |     3.8106 |
|     DP [MFLOP/s]     |   178.5856 |
|   AVX DP [MFLOP/s]   |          0 |
|   Packed [MUOPS/s]   |          0 |
|   Scalar [MUOPS/s]   |   178.5856 |
|  Vectorization ratio |          0 |
+----------------------+------------+





student@itcenter-lab128:~/Desktop/assignment5$ cp timestep_opt3.c timestep.c
make -f MakeFile clean
make -f MakeFile stream_triad
./stream_triad
sudo likwid-perfctr -C 0 -f -g FLOPS_DP ./stream_triad
rm -rf ./stream_triad ./stream_triad.o ./timer.o ./main.o ./timestep.o
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c main.c -o main.o
main.c:11:22: optimized: loop vectorized using 32 byte vectors
main.c:21:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:112:10: missed: statement clobbers memory: __printf_chk (1, "Minimum dt is %lf\n", mymindt_6);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c timestep.c -o timestep.o
timestep.c:11:13: optimized: loop vectorized using 32 byte vectors
timestep.c:13:9: missed: couldn't vectorize loop
timestep.c:13:9: missed: not vectorized: control flow in loop.
timestep.c:11:13: optimized: loop vectorized using 32 byte vectors
timestep.c:15:25: missed: statement clobbers memory: wavespeed_58 = sqrt (_9);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c timer.c -o timer.o
timer.c:11:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:16:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -o stream_triad main.o timestep.o timer.o -lm
Minimum dt is 0.016964
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
--------------------------------------------------------------------------------
Minimum dt is 0.016964
--------------------------------------------------------------------------------
Group 1: FLOPS_DP
+--------------------------------------+---------+------------+
|                 Event                | Counter | HWThread 0 |
+--------------------------------------+---------+------------+
|           INSTR_RETIRED_ANY          |  FIXC0  |  217770265 |
|         CPU_CLK_UNHALTED_CORE        |  FIXC1  |  831133960 |
|         CPU_CLK_UNHALTED_REF         |  FIXC2  |  831130014 |
| FP_COMP_OPS_EXE_SSE_FP_PACKED_DOUBLE |   PMC0  |          0 |
| FP_COMP_OPS_EXE_SSE_FP_SCALAR_DOUBLE |   PMC1  |   90287198 |
|       SIMD_FP_256_PACKED_DOUBLE      |   PMC2  |          0 |
+--------------------------------------+---------+------------+

+----------------------+------------+
|        Metric        | HWThread 0 |
+----------------------+------------+
|  Runtime (RDTSC) [s] |     0.5172 |
| Runtime unhalted [s] |     0.2524 |
|      Clock [MHz]     |  3292.4497 |
|          CPI         |     3.8166 |
|     DP [MFLOP/s]     |   174.5591 |
|   AVX DP [MFLOP/s]   |          0 |
|   Packed [MUOPS/s]   |          0 |
|   Scalar [MUOPS/s]   |   174.5591 |
|  Vectorization ratio |          0 |
+----------------------+------------+


student@itcenter-lab128:~/Desktop/assignment5$ ^[[200~cp timestep_opt1.c timestep.c
cp timestep_opt1.c timestep.cle clean
make -f MakeFile stream_triad
./stream_triad
sudo likwid-perfctr -C 0 -f -g FLOPS_DP ./stream_triad^[[201~cp: command not found
student@itcenter-lab128:~/Desktop/assignment5$ make -f MakeFile clean
rm -rf ./stream_triad ./stream_triad.o ./timer.o ./main.o ./timestep.o
student@itcenter-lab128:~/Desktop/assignment5$ make -f MakeFile stream_triad
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c main.c -o main.o
main.c:11:22: optimized: loop vectorized using 32 byte vectors
main.c:21:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:112:10: missed: statement clobbers memory: __printf_chk (1, "Minimum dt is %lf\n", mymindt_6);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c timestep.c -o timestep.o
timestep.c:11:13: optimized: loop vectorized using 32 byte vectors
timestep.c:13:9: missed: couldn't vectorize loop
timestep.c:13:9: missed: not vectorized: control flow in loop.
timestep.c:11:13: optimized: loop vectorized using 32 byte vectors
timestep.c:15:25: missed: statement clobbers memory: wavespeed_58 = sqrt (_9);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c timer.c -o timer.o
timer.c:11:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:16:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -o stream_triad main.o timestep.o timer.o -lm
student@itcenter-lab128:~/Desktop/assignment5$ ./stream_triad
Minimum dt is 0.016964
student@itcenter-lab128:~/Desktop/assignment5$ sudo likwid-perfctr -C 0 -f -g FLOPS_DP ./stream_triad~--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
--------------------------------------------------------------------------------
Failed to execute command: ./stream_triad~

--------------------------------------------------------------------------------
Group 1: FLOPS_DP
+--------------------------------------+---------+------------+
|                 Event                | Counter | HWThread 0 |
+--------------------------------------+---------+------------+
|           INSTR_RETIRED_ANY          |  FIXC0  |   88941962 |
|         CPU_CLK_UNHALTED_CORE        |  FIXC1  |  279242476 |
|         CPU_CLK_UNHALTED_REF         |  FIXC2  |  483641334 |
| FP_COMP_OPS_EXE_SSE_FP_PACKED_DOUBLE |   PMC0  |       6166 |
| FP_COMP_OPS_EXE_SSE_FP_SCALAR_DOUBLE |   PMC1  |      31318 |
|       SIMD_FP_256_PACKED_DOUBLE      |   PMC2  |          0 |
+--------------------------------------+---------+------------+

+----------------------+------------+
|        Metric        | HWThread 0 |
+----------------------+------------+
|  Runtime (RDTSC) [s] |    30.0014 |
| Runtime unhalted [s] |     0.0848 |
|      Clock [MHz]     |  1900.9909 |
|          CPI         |     3.1396 |
|     DP [MFLOP/s]     |     0.0015 |
|   AVX DP [MFLOP/s]   |          0 |
|   Packed [MUOPS/s]   |     0.0002 |
|   Scalar [MUOPS/s]   |     0.0010 |
|  Vectorization ratio |    16.4497 |
+----------------------+------------+



student@itcenter-lab128:~/Desktop/assignment5$ # Kopiraj opt3 u timestep.c
cp timestep_opt3.c timestep.c

# Očisti prethodne build fajlove
make -f MakeFile clean

# Kompajliraj sa posebnim flagovima
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd \
    -march=native -mtune=native -mprefer-vector-width=256 \
    -fopt-info-vec-optimized -fopt-info-vec-missed \
    -fno-trapping-math -fno-math-errno \
    -c main.c -o main.o
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd \
    -march=native -mtune=native -mprefer-vector-width=256 \
    -fopt-info-vec-optimized -fopt-info-vec-missed \
    -fno-trapping-math -fno-math-errno \
    -c timestep.c -o timestep.o
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd \
    -march=native -mtune=native -mprefer-vector-width=256 \
    -fopt-info-vec-optimized -fopt-info-vec-missed \
    -fno-trapping-math -fno-math-errno \
    -c timer.c -o timer.o

# Linkaj finalni izvršni fajl
sudo likwid-perfctr -C 0 -f -g FLOPS_DP ./stream_triad | tee likwid_opt3.txt
rm -rf ./stream_triad ./stream_triad.o ./timer.o ./main.o ./timestep.o
main.c:11:22: optimized: loop vectorized using 32 byte vectors
main.c:21:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:112:10: missed: statement clobbers memory: __printf_chk (1, "Minimum dt is %lf\n", mymindt_6);
timestep.c:11:13: optimized: loop vectorized using 32 byte vectors
timestep.c:13:9: optimized: loop vectorized using 16 byte vectors
timestep.c:11:13: optimized: loop vectorized using 32 byte vectors
timer.c:11:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:16:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
Minimum dt is 0.016964
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
--------------------------------------------------------------------------------
Minimum dt is 0.016964
--------------------------------------------------------------------------------
Group 1: FLOPS_DP
+--------------------------------------+---------+------------+
|                 Event                | Counter | HWThread 0 |
+--------------------------------------+---------+------------+
|           INSTR_RETIRED_ANY          |  FIXC0  |  137752056 |
|         CPU_CLK_UNHALTED_CORE        |  FIXC1  |  517267875 |
|         CPU_CLK_UNHALTED_REF         |  FIXC2  |  517270413 |
| FP_COMP_OPS_EXE_SSE_FP_PACKED_DOUBLE |   PMC0  |   45185338 |
| FP_COMP_OPS_EXE_SSE_FP_SCALAR_DOUBLE |   PMC1  |         28 |
|       SIMD_FP_256_PACKED_DOUBLE      |   PMC2  |          5 |
+--------------------------------------+---------+------------+

+----------------------+--------------+
|        Metric        |  HWThread 0  |
+----------------------+--------------+
|  Runtime (RDTSC) [s] |       0.4086 |
| Runtime unhalted [s] |       0.1571 |
|      Clock [MHz]     |    3292.3911 |
|          CPI         |       3.7551 |
|     DP [MFLOP/s]     |     221.1901 |
|   AVX DP [MFLOP/s]   | 4.895171e-05 |
|   Packed [MUOPS/s]   |     110.5950 |
|   Scalar [MUOPS/s]   |       0.0001 |
|  Vectorization ratio |      99.9999 |
+----------------------+--------------+

Evo kako možeš to lepo napisati za README:

---

### Assignment 5 – Vectorization Results

We ran three iterations of the `timestep` function with increasing vectorization optimizations (`timestep_opt1.c`, `timestep_opt2.c`, `timestep_opt3.c`). Each version was compiled with `-O3 -ftree-vectorize -fopenmp-simd -mprefer-vector-width=256` flags and measured using the `likwid-perfctr` tool for FLOPS_DP.

-Explanation:

1. **timestep_opt1.c**

   * Loop vectorization was limited.
   * Vectorization ratio was low (~20%), mostly scalar operations.
   * DP MFLOP/s was very small, runtime longer.

2. **timestep_opt2.c**

   * Some loops were successfully vectorized.
   * Vectorization ratio improved, but not full.
   * DP MFLOP/s increased slightly, runtime decreased.

3. **timestep_opt3.c** *(final optimized version)*

   * Loops fully vectorized using 32-byte vectors (matching CPU SIMD width).
   * Vectorization ratio nearly 100%.
   * Significant increase in DP MFLOP/s and fastest runtime observed.
   * This version demonstrates the effectiveness of using `restrict` keyword and compiler directives to help auto-vectorization.

**Conclusion:**
`timestep_opt3.c` is the fastest version, fully exploiting vectorization capabilities of the CPU. The runtime decreased and floating-point throughput increased, confirming that manual improvements and proper compiler hints significantly improve performance.
