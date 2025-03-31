#include <stdio.h>
#include <stdlib.h>

int diagonal_difference(int** nums, int nums_size) {
    int diag_prin = 0;
    int diag_sec = 0;
    for(int i = 0; i < nums_size; i++){
    diag_prin += nums[i][i];
      }
    for(int j = 0; j < nums_size; j++){
      diag_sec += nums[j][nums_size-1-j];
    }
    return abs(diag_prin-diag_sec);
}

// TESTS
typedef struct {
  int **matrix;
  int size;
  int expected;
} TestCase;
void run_tests() {
  // Caso 1
  int m1[3][3] = {{1, 2, 3}, {4, 5, 6}, {9, 8, 9}};
  int* test_1[] = {m1[0], m1[1], m1[2]};

  // Caso 2
  int m2[2][2] = {{1, 2}, {3, 4}};
  int* test_2[] = {m2[0], m2[1]};

  // Caso 3
  int m3[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  int* test_3[] = {m3[0], m3[1], m3[2], m3[3]};

  // Caso 4 (matriz de 1x1)
  int m4[1][1] = {{5}};
  int* test_4[] = {m4[0]};

  TestCase tests[] = {
      {test_1, 3, 2},
      {test_2, 2, 0},
      {test_3, 4, 0},
      {test_4, 1, 0}
  };

  int num_tests = sizeof(tests) / sizeof(tests[0]);

  // Ejecutamos las pruebas
  for (int i = 0; i < num_tests; i++) {
      int result = diagonal_difference(tests[i].matrix, tests[i].size);
      printf("Prueba %d: Diferencia obtenida = %d (Esperado: %d) %s\n", 
             i + 1, result, tests[i].expected, 
             result == tests[i].expected ? "✔️" : "❌");
  }
}

int main() {
  run_tests();
  return 0;
}