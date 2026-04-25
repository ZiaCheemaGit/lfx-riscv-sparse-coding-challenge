# include <sparse.h>

// Note: 
// The following functions can potentially be implemented via rvv
// but not done so because coding challenge has no such requirement.
// Also coding challenge forces to compile using gcc and not using  
// riscv-unknown-elf toolchain. Thus I am assuming this generalized
// approach is expected from mentee.


// Implementation of sparse algebra from book 
// Programming Massively Parallel Processors: A Hands-on Approach


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

    int number_of_non_zero_elements = 0; 
    row_ptrs[0] = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double element = row_major_matrix[(i * cols) + j];
            if (element != 0) {
                values[number_of_non_zero_elements] = element;
                column_indices[number_of_non_zero_elements] = j;
                number_of_non_zero_elements++;
            }
        }
        row_ptrs[i + 1] = number_of_non_zero_elements;
    }

    *nnz = number_of_non_zero_elements;
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

    for (int row = 0; row < rows; row++) {
        out_vector[row] = 0;
        for (int k = row_ptrs[row]; k < row_ptrs[row + 1]; k++) {
            int col = column_indices[k];
            double value = csr_values[k];
            out_vector[row] += value * in_vector[col];
        }
    }
}

