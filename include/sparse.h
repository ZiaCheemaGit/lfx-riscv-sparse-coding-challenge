void csr_format(const double* row_major_matrix, int rows, int cols, int* row_ptrs, int* column_indices, double* values, int* nnz);
void csr_sparse_multply(double* csr_values, const double* in_vector, int* row_ptrs, int* column_indices, int rows, double* out_vector);

