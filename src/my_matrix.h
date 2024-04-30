#ifndef MY_MY_MATRIX
#define MY_MY_MATRIX

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

#define TRUE 0
#define FALSE 1

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int my_create_matrix(int rows, int columns, matrix_t *result);
void my_remove_matrix(matrix_t *A);          
int my_eq_matrix(matrix_t *A, matrix_t *B);  
int my_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int my_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int my_mult_number(matrix_t *A, double number, matrix_t *result);
int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int my_transpose(matrix_t *A, matrix_t *result);
int my_determinant(matrix_t *A, double *result);
int my_calc_complements(matrix_t *A, matrix_t *result);
int my_inverse_matrix(matrix_t *A, matrix_t *result);

int my_are_equal(matrix_t *A, matrix_t *B);
void my_find_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void my_find_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void my_find_mult_num_matrix(matrix_t *A, double number, matrix_t *result);
void my_find_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void my_find_transpose(matrix_t *A, matrix_t *result);
void my_fill_minor_for_determinant(matrix_t *A, matrix_t *minor, int x);
void my_calc_det_for_matrix_3x3_n_large(matrix_t *A, double *result);
void my_fill_minor_for_complement(matrix_t *A, matrix_t *minor, int i, int j);
void my_find_complements(matrix_t *A, matrix_t *result);

#endif