![CI](https://github.com/ZiaCheemaGit/lfx-riscv-sparse-coding-challenge/actions/workflows/CI.yml/badge.svg)
![License](https://img.shields.io/github/license/ZiaCheemaGit/lfx-riscv-sparse-coding-challenge?style=for-the-badge)

# LFX-RISCV-sparse-coding-challenge
This repo contains solution of coding challenge for lfx riscv mentorship summer 2026 - rv-sparse: Open-source RISC-V Vector accelerated sparse linear algebra library 

## Links
- [Coding Challenge](https://docs.google.com/document/d/15LcAv0bXG6-J-n7p6rQUkhout0UnwftpRGL43cbOrUg/edit?tab=t.0#heading=h.hsyi6o28hltp)
- [LFX Mentorship](https://mentorship.lfx.linuxfoundation.org/project/deb25137-a736-4f6f-a673-a02e52e55758)
- [Solution Reference](https://www.youtube.com/watch?v=H6YGKNukGMo&t=2210s)
- [Programming Massively Parallel Processors](https://www.google.com/search?client=ubuntu-sn&channel=fs&q=Programming+Massively+Parallel+Processors)
---

# Testing and CI
CI is based on the passing tests output string at the end of Test Harness

---

# Build and Run
To build just execute command `make` in the root directory. The same build command which is given in Coding Challenge, is used in the project Makefile.   
```bash
make
```
OR
```bash
gcc challenge.c src/sparse.c -Iinclude -lm -o run
```
# Documentation
```C
// Note: The following functions can potentially be implemented via rvv extension but not done so because coding challenge has no such requirement. Also coding challenge forces to compile using gcc and not using riscv-unknown-elf toolchain. Thus I am assuming this generalized approach is expected from mentee.

// Implementation of sparse algebra from book "Programming Massively Parallel Processors: A Hands-on Approach"

// fills provided buffers according to CSR format
void csr_format(const double* row_major_matrix, int rows, int cols, int* row_ptrs, int* column_indices, double* values, int* nnz) {
    // provided data (Inputs)
    // row_major_matrix: Sparse Matrix
    // rows: number of rows in matrix
    // cols: number of column in matrix

    // buffers (Outputs)
    // row_ptrs: start addresses of rows in vector values
    // column_indices: corresponding column addresses
    // values: vector containing all non zero elements
    // nnz: number of non zero elemenets or size of vector values
}

// // matrix vector multiplication using CSR format
void csr_sparse_multiply(double* csr_values, const double* in_vector, int* row_ptrs, int* column_indices, int rows, double* out_vector) {
    // provided data(Inputs):
    // csr_values       : Non-zero matrix elements in CSR format
    // in_vector        : Input vector to multiply
    // row_ptrs         : Row pointer array (CSR)
    // column_indices   : Column indices array (CSR)
    // rows             : Number of matrix rows
    //
    // result buffer(Output):
    // out_vector       : Result of matrix-vector multiplication
}
```
