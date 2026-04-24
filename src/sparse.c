# include <sparse.h>

void csr_format(const double* row_major_matrix, int rows, int cols, int* row_ptrs, int* column_indices, double* values, int* nnz) {
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

void csr_sparse_multply(double* csr_values, const double* in_vector, int* row_ptrs, int* column_indices, int rows, double* out_vector) {
    for (int row = 0; row < rows; row++) {
        out_vector[row] = 0;
        for (int k = row_ptrs[row]; k < row_ptrs[row + 1]; k++) {
            int col = column_indices[k];
            double value = csr_values[k];
            out_vector[row] += value * in_vector[col];
        }
    }
}

