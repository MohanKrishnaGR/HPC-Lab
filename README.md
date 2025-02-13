# HPC Lab Experiments Repository

This repository contains lab experiments for the **High Performance Computing (HPC)** course (20CS257). The experiments, implemented in C with OpenMP, cover topics such as basic OpenMP usage, loop parallelization, and array/matrix operations.

---

## Table of Contents
- [Experiment 1: Introduction to OpenMP](#experiment-1-introduction-to-openmp)
- [Experiment 2: Parallelization using OpenMP](#experiment-2-parallelization-using-openmp)
- [Experiment 3: For Loop Parallelization with OpenMP](#experiment-3-for-loop-parallelization-with-openmp)
- [Experiment 4: Array and Matrix Operations using OpenMP](#experiment-4-array-and-matrix-operations-using-openmp)
- [Compilation and Execution](#compilation-and-execution)
- [Future Additions](#future-additions)

---

## Experiment 1: Introduction to OpenMP
- **Directory:** `intro-to-openmp/`
- **Source File:** `ex1_openmp.c`
- **Description:** A basic OpenMP program demonstrating the creation of a parallel region.

---

## Experiment 2: Parallelization using OpenMP
- **Directory:** `parallelization-using-openmp/`
- **Source File:** `ex2.c`
- **Description:** Compares serial and parallel execution, highlighting performance differences using OpenMP.

---

## Experiment 3: For Loop Parallelization with OpenMP
- **Directory:** `for-loop-parallelization-openmp/`
- **Source Files:** `ex3.c`, `ex3_1.c`, `ex3_2.c`
- **Description:** Implements loop parallelization with performance measurement and analysis.

---

## Experiment 4: Array and Matrix Operations using OpenMP
- **Directory:** `array-matrix-openmp/`
- **Source Files:** 
  - `ex4_1.c` (Array Addition)
  - `ex4_2.c` (Matrix Multiplication)
- **Description:** Demonstrates parallel array addition and matrix multiplication, along with performance analysis.

---

## Compilation and Execution
Make sure you have **GCC with OpenMP support** installed. To compile, use:
```bash
gcc -fopenmp -o <executable_name> <source_file.c>
```
Example:

```bash
gcc -fopenmp -o ex1_openmp intro-to-openmp/ex1_openmp.c
```
To run the executable:

```bash
./ex1_openmp
```

Set the number of threads (if needed) via:

```bash
export OMP_NUM_THREADS=4   
```
Or for Windows (PowerShell):

```powershell
$env:OMP_NUM_THREADS = "4"
```
---

## Future Additions

More experiments and exercises related to HPC and parallel programming with OpenMP will be added in the future. Contributions and suggestions are welcome!

<i>This repository is part of the HPC course (20CS257) lab work on High Performance Computing.</i>


Feel free to update or expand sections as you add new experiments. Enjoy coding!