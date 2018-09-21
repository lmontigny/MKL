// Source: http://kernel118.rssing.com/chan-20519112/all_p44.html

#include "mkl_spblas.h"
#include <stdio.h>

void print_csr_sparse_s(const sparse_matrix_t csrA)
{
    // Read Matrix Data and Print it
    int row, col;
    sparse_index_base_t indextype;
    int * bi, *ei;
    int * j;
    float *rv;
    sparse_status_t status = mkl_sparse_s_export_csr(csrA, &indextype, &row, &col, &bi, &ei, &j, &rv);
    if (status==SPARSE_STATUS_SUCCESS)
    {
        printf("SparseMatrix(%d x %d) [base:%d]\n", row, col, indextype);
        for (int r = 0; r<row; ++r)
        {
            for (int idx = bi[r]; idx<ei[r]; ++idx)
            {
                printf("<%d, %d> \t %f\n", r, j[idx], rv[idx]);
            }
        }
    }
    return;
}

void print_csr_sparse_d(const sparse_matrix_t csrA)
{
    // Read Matrix Data and Print it
    int row, col;
    sparse_index_base_t indextype;
    int * bi, *ei;
    int * j;
    double *rv;
    sparse_status_t status = mkl_sparse_d_export_csr(csrA, &indextype, &row, &col, &bi, &ei, &j, &rv);
    if (status==SPARSE_STATUS_SUCCESS)
    {
        printf("SparseMatrix(%d x %d) [base:%d]\n", row, col, indextype);
        for (int r = 0; r<row; ++r)
        {
            for (int idx = bi[r]; idx<ei[r]; ++idx)
            {
                printf("<%d, %d> \t %f\n", r, j[idx], rv[idx]);
            }
        }
    }
    return;
}

// test addition of sparse matrix
void test_add_s()
{
    // Define sparse-matrix M
    int mi[5] = {0, 2, 5, 8, 10};
    int mj[10] = {0, 1, 0, 1, 2, 1, 2, 3, 2, 3};
    float mv[10] = {2.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 2.0f};
    sparse_matrix_t M;

    // Define sparse-matrix N
    int ni[5] = {0, 1, 2, 3, 4};
    int nj[4] = {0, 1, 2, 3};
    float nv[4] = {3.0f, 2.0f, 1.0f, -1.0f};
    sparse_matrix_t N;

    // create csr matrix
    mkl_sparse_s_create_csr(&M, SPARSE_INDEX_BASE_ZERO, 4, 4, mi, mi+1, mj, mv);
    mkl_sparse_s_create_csr(&N, SPARSE_INDEX_BASE_ZERO, 4, 4, ni, ni+1, nj, nv);
    // output matrix
    print_csr_sparse_s(M);
    print_csr_sparse_s(N);

    // do addition
    sparse_matrix_t C;
    mkl_sparse_s_add(SPARSE_OPERATION_NON_TRANSPOSE ,M, 2, N, &C);

    // output result
    print_csr_sparse_s(C);

    // free memory
    mkl_sparse_destroy(M);
    mkl_sparse_destroy(N);
    mkl_sparse_destroy(C);
}

void test_add_d()
{
    // Define sparse-matrix M
    int mi[5] = {0, 2, 5, 8, 10};
    int mj[10] = {0, 1, 0, 1, 2, 1, 2, 3, 2, 3};
    double mv[10] = {2.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 2.0f};
    sparse_matrix_t M;

    // Define sparse-matrix N
    int ni[5] = {0, 1, 2, 3, 4};
    int nj[4] = {0, 1, 2, 3};
    double nv[4] = {3.0f, 2.0f, 1.0f, -1.0f};
    sparse_matrix_t N;

    // create csr matrix
    mkl_sparse_d_create_csr(&M, SPARSE_INDEX_BASE_ZERO, 4, 4, mi, mi+1, mj, mv);
    mkl_sparse_d_create_csr(&N, SPARSE_INDEX_BASE_ZERO, 4, 4, ni, ni+1, nj, nv);
    // output matrix
    print_csr_sparse_d(M);
    print_csr_sparse_d(N);

    // do addition
    sparse_matrix_t C;
    mkl_sparse_d_add(SPARSE_OPERATION_NON_TRANSPOSE ,M, 2, N, &C);

    // output result
    print_csr_sparse_d(C);

    // free memory
    mkl_sparse_destroy(M);
    mkl_sparse_destroy(N);
    mkl_sparse_destroy(C);
}

int main()
{
    test_add_d();
	test_add_s();
    return 1;
}
