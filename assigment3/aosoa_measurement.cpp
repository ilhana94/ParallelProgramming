//
// Created by Adnan Hajro on 17. 10. 2025..
//
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>

// V je definisan u Makefile-u, npr. -DV=4
#ifndef V
#define V 4
#endif

// Definicija SoA strukture (Structure of Arrays unutar jednog bloka)
struct SoA_type {
    int R[V], G[V], B[V];
};

void run_aos_aoa_kernel(long len) {
    // Broj blokova – koliko "pločica" (AoSoA blokova) imamo
    long num_blocks = (len + V - 1) / V;

    // ✅ Alokacija memorije za niz SoA_type struktura
    SoA_type *AoSoA = new SoA_type[num_blocks];

    // Početak mjerenja vremena
    auto start = std::chrono::high_resolution_clock::now();

    // Popunjavanje podataka unutar AoSoA strukture
    for (long j = 0; j < num_blocks; j++) {
        for (int i = 0; i < V; i++) {
            if ((j * V + i) < len) {
                AoSoA[j].R[i] = rand();
                AoSoA[j].G[i] = rand();
                AoSoA[j].B[i] = rand();
            }
        }
    }

    // Kraj mjerenja vremena
    auto end = std::chrono::high_resolution_clock::now();

    // ✅ Oslobađanje memorije
    delete[] AoSoA;

    // Izračun trajanja
    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    double total_time_ms = duration_ns.count() / 1e6;

    // Ispis rezultata (u CSV formatu)
    std::cout << len << ", " << V << ", " << total_time_ms << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <length>" << std::endl;
        return 1;
    }

    long len = std::atol(argv[1]);
    if (len <= 0) {
        std::cerr << "Invalid length value!" << std::endl;
        return 1;
    }

    run_aos_aoa_kernel(len);
    return 0;
}
