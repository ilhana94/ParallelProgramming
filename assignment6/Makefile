# Compiler and flags
CC = gcc
CFLAGS = -fopenmp -Wall -std=c11 -march=native -O2
LDFLAGS = -lm -lrt

# Stencil source files (main programs)
SOURCES = stencil_opt2.c stencil_opt4.c stencil_opt6.c

# Generate executable names
EXECUTABLES = $(SOURCES:.c=)

# Utility object files
UTILS = timer.o malloc2D.o

# Default target: build all executables
all: $(EXECUTABLES)
	@echo "All stencil executables built successfully!"

# Generic rule: compile any stencil .c file into executable
%: %.c $(UTILS)
	@echo " Building $@..."
	$(CC) $(CFLAGS) $< $(UTILS) -o $@ $(LDFLAGS)

# Compile timer utility
timer.o: timer.c timer.h
	@echo "⏱ Compiling timer..."
	$(CC) $(CFLAGS) -c timer.c -o $@

# Compile malloc2D utility
malloc2D.o: malloc2D.c malloc2D.h
	@echo " Compiling malloc2D..."
	$(CC) $(CFLAGS) -c malloc2D.c -o $@

# Individual run targets
run-opt2: stencil_opt2
	@echo "Running stencil_opt2..."
	./stencil_opt2

run-opt4: stencil_opt4
	@echo " Running stencil_opt4..."
	./stencil_opt4

run-opt6: stencil_opt6
	@echo "Running stencil_opt6..."
	./stencil_opt6

# Run all and save results to results.txt
run-all: all
	@echo " Running all stencil programs and saving results..."
	@echo "Program        Init(s)    Flush(s)    Stencil(s)    Total(s)" > results.txt
	@echo "-------------------------------------------------------------" >> results.txt
	@for prog in stencil_opt2 stencil_opt4 stencil_opt6; do \
		echo "Running $$prog..."; \
		./$$prog | grep "Timing" | awk '{printf "%-14s %8s %8s %8s %8s\n", $$1, $$3, $$4, $$5, $$6}' >> results.txt; \
	done
	@echo "✅ Results saved to results.txt"

# Clean up
clean:
	@echo "Cleaning up..."
	@rm -f $(EXECUTABLES) $(UTILS) results.txt

# Clean and rebuild
rebuild: clean all

.PHONY: all clean rebuild run-opt2 run-opt4 run-opt6 run-all compare

compare: all
	@echo " Running stencil_opt2..." | tee results.txt
	@./stencil_opt2 | tee -a results.txt
	@echo "" | tee -a results.txt
	@echo " Running stencil_opt4..." | tee -a results.txt
	@./stencil_opt4 | tee -a results.txt
	@echo "" | tee -a results.txt
	@echo " Running stencil_opt6..." | tee -a results.txt
	@./stencil_opt6 | tee -a results.txt
	@echo "" | tee -a results.txt
	@echo " All results saved to results.txt"


