Example 1 – cairo & hwloc

* I installed the necessary packages for graphical display of hardware topology.
Downloaded and installed the cairo library (2D graphics).
Downloaded and installed the hwloc tool that uses cairo to draw hardware topology.
I ran `lstopo` which shows me the topology of CPU, cache, NUMA nodes and devices on the computer.

Example 2 – STREAM benchmark

* I cloned the STREAM benchmark from GitHub.
Compiled the benchmark and ran `stream_c.exe`.
I got the measurement of maximum memory bandwidth.

Example 3 – Roofline Toolkit

* I cloned the Roofline Toolkit performance tool.
Configured the parameter file according to my hardware (Intel Xeon CPU, MPI, OpenMP, etc.).
Run the tool that measures maximum FLOP/s and memory bandwidth for different arithmetic intensities.
I got a graphical representation of the Roofline model (`roofline.ps`) that shows the performance limits of my machine.

Example 4 – CloverLeaf

* Installed Valgrind and KCacheGrind for profiling.
* Cloned the CloverLeaf mini-app and compiled a batch version.
Ran CloverLeaf using the Valgrind Callgrind tool to generate a call graph to identify “hot spot” functions.
Visualized the results in KCacheGrind to see which functions were taking the most time.
