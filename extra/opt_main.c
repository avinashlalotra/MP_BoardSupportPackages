/**
 * Efficient Bare-Metal Matrix Multiplication Driver for RISC-V RV32IMC
 * For optimized systolic array hardware acceleration
 */

 #include <stdint.h>

 // Memory-mapped register definitions for systolic array
 #define SYSTOLIC_BASE_ADDR     0x30000000
 
 // Register offsets
 #define CONTROL_REG     0x00
 #define STATUS_REG      0x04
 #define NORTH_0_REG     0x08
 #define NORTH_1_REG     0x0C
 #define WEST_0_REG      0x10
 #define WEST_1_REG      0x14
 #define RESULT_00_REG   0x18
 #define RESULT_01_REG   0x1C
 #define RESULT_10_REG   0x20
 #define RESULT_11_REG   0x24
 
 // Control bits
 #define LOAD_INPUTS     0x01
 #define START_COMPUTE   0x02
 #define DONE_BIT        0x01
 
 // Direct register access macros for efficient access
 #define REG_WRITE(addr, value) (*(volatile uint32_t*)(addr) = (value))
 #define REG_READ(addr) (*(volatile uint32_t*)(addr))
 
 // Matrix size definitions
 #define SUBMATRIX_SIZE 2
 #define MAX_MATRIX_SIZE 16  // Maximum size of matrices to multiply
 
 // Function prototypes
 void multiply_2x2_matrices(int32_t A[2][2], int32_t B[2][2], int32_t C[2][2]);
//  void multiply_large_matrices(int32_t* A, int32_t* B, int32_t* C, int size);
//  void print_matrix(int32_t* matrix, int size);
//  void init_matrix(int32_t* matrix, int size, int pattern);
 
//  // UART output functions for debugging
//  void uart_init(void);
//  void uart_putchar(char c);
//  void uart_puts(const char* str);
//  void print_int(int32_t val);
//  void print_hex(uint32_t val);
 
 // Bare-metal entry point
 void main(void) {
     // Initialize UART for debugging output
    //  uart_init();
    //  uart_puts("RV32IMC Systolic Array Matrix Multiplication\r\n");
     
     // Test small matrices first to verify hardware
     int32_t A_small[2][2] = {{1, 2}, {3, 4}};
     int32_t B_small[2][2] = {{5, 6}, {7, 8}};
     int32_t C_small[2][2] = {{0, 0}, {0, 0}};
     
    //  uart_puts("Testing 2x2 matrix multiplication:\r\n");
     multiply_2x2_matrices(A_small, B_small, C_small);
     
    //  uart_puts("Result: \r\n");
    //  for (int i = 0; i < 2; i++) {
    //      for (int j = 0; j < 2; j++) {
    //          print_int(C_small[i][j]);
    //          uart_puts(" ");
    //      }
    //      uart_puts("\r\n");
    //  }
     
     // Test with larger matrices (using tiling)
    //  int size = 4;  // 4x4 matrix example
     
    //  // Allocate matrices on stack (keep sizes reasonable for bare-metal)
    //  int32_t A_large[MAX_MATRIX_SIZE * MAX_MATRIX_SIZE];
    //  int32_t B_large[MAX_MATRIX_SIZE * MAX_MATRIX_SIZE];
    //  int32_t C_large[MAX_MATRIX_SIZE * MAX_MATRIX_SIZE];
     
    //  // Initialize matrices with test patterns
    //  init_matrix(A_large, size, 1); // Fill with incremental values
    //  init_matrix(B_large, size, 2); // Fill with another pattern
     
    //  uart_puts("\r\nMultiplying 4x4 matrices using 2x2 systolic array tiling:\r\n");
     
    //  // Multiply the matrices
    //  multiply_large_matrices(A_large, B_large, C_large, size);
     
    //  // Print result
    //  uart_puts("Result matrix:\r\n");
    //  print_matrix(C_large, size);
     
    //  uart_puts("\r\nMatrix multiplication complete!\r\n");
     
    //  // Halt
    //  while(1);
 }
 
 /**
  * Multiply two 2×2 matrices using the systolic array hardware
  * Optimized for RV32IMC with minimal cycles
  */
 void multiply_2x2_matrices(int32_t A[2][2], int32_t B[2][2], int32_t C[2][2]) {
     // Base addresses for efficient access
     volatile uint32_t* control_reg = (volatile uint32_t*)(SYSTOLIC_BASE_ADDR + CONTROL_REG);
     volatile uint32_t* status_reg = (volatile uint32_t*)(SYSTOLIC_BASE_ADDR + STATUS_REG);
     volatile uint32_t* north0_reg = (volatile uint32_t*)(SYSTOLIC_BASE_ADDR + NORTH_0_REG);
     volatile uint32_t* north1_reg = (volatile uint32_t*)(SYSTOLIC_BASE_ADDR + NORTH_1_REG);
     volatile uint32_t* west0_reg = (volatile uint32_t*)(SYSTOLIC_BASE_ADDR + WEST_0_REG);
     volatile uint32_t* west1_reg = (volatile uint32_t*)(SYSTOLIC_BASE_ADDR + WEST_1_REG);
     volatile uint32_t* result00_reg = (volatile uint32_t*)(SYSTOLIC_BASE_ADDR + RESULT_00_REG);
     volatile uint32_t* result01_reg = (volatile uint32_t*)(SYSTOLIC_BASE_ADDR + RESULT_01_REG);
     volatile uint32_t* result10_reg = (volatile uint32_t*)(SYSTOLIC_BASE_ADDR + RESULT_10_REG);
     volatile uint32_t* result11_reg = (volatile uint32_t*)(SYSTOLIC_BASE_ADDR + RESULT_11_REG);
     
     // Reset hardware
     *control_reg = 0;
     
     // Load input matrices (A transposed for systolic operation)
     *north0_reg = A[0][0];
     *north1_reg = A[1][0];
     *west0_reg = B[0][0];
     *west1_reg = B[1][0];
     
     // Signal to load inputs
     *control_reg = LOAD_INPUTS;
     
     // Load second column of inputs 
     *north0_reg = A[0][1];
     *north1_reg = A[1][1];
     *west0_reg = B[0][1];
     *west1_reg = B[1][1];
     
     // Start computation
     *control_reg = START_COMPUTE;
     
     // Wait for computation to complete using tight polling loop
     // (Optimized for RV32IMC with minimal instruction count)
     while ((*status_reg & DONE_BIT) == 0) {
         // Compiler barrier to prevent optimization removing the loop
         __asm__ volatile("" ::: "memory");
     }
     
     // Read results
     C[0][0] = *result00_reg;
     C[0][1] = *result01_reg;
     C[1][0] = *result10_reg;
     C[1][1] = *result11_reg;
 }
 
//  /**
//   * Multiply larger matrices by tiling them into 2x2 submatrices
//   * Uses systolic array for each tile operation
//   */
//  void multiply_large_matrices(int32_t* A, int32_t* B, int32_t* C, int size) {
//      // Clear result matrix
//      for (int i = 0; i < size * size; i++) {
//          C[i] = 0;
//      }
     
//      // Calculate how many 2x2 tiles we need
//      int tile_count = size / SUBMATRIX_SIZE;
     
//      // Use 2x2 submatrices to compute the full matrix product
//      int32_t A_tile[2][2], B_tile[2][2], C_tile[2][2];
     
//      // Using tiling approach for matrix multiplication
//      for (int i = 0; i < tile_count; i++) {
//          for (int j = 0; j < tile_count; j++) {
//              // Reset C_tile for accumulating results
//              C_tile[0][0] = C_tile[0][1] = C_tile[1][0] = C_tile[1][1] = 0;
             
//              // Compute C(i,j) = sum_k(A(i,k) * B(k,j))
//              for (int k = 0; k < tile_count; k++) {
//                  // Load A tile (i,k)
//                  for (int ti = 0; ti < SUBMATRIX_SIZE; ti++) {
//                      for (int tj = 0; tj < SUBMATRIX_SIZE; tj++) {
//                          A_tile[ti][tj] = A[(i * SUBMATRIX_SIZE + ti) * size + (k * SUBMATRIX_SIZE + tj)];
//                      }
//                  }
                 
//                  // Load B tile (k,j)
//                  for (int ti = 0; ti < SUBMATRIX_SIZE; ti++) {
//                      for (int tj = 0; tj < SUBMATRIX_SIZE; tj++) {
//                          B_tile[ti][tj] = B[(k * SUBMATRIX_SIZE + ti) * size + (j * SUBMATRIX_SIZE + tj)];
//                      }
//                  }
                 
//                  // Temporary result for this iteration
//                  int32_t temp_result[2][2] = {{0, 0}, {0, 0}};
                 
//                  // Multiply tiles using systolic array hardware
//                  multiply_2x2_matrices(A_tile, B_tile, temp_result);
                 
//                  // Accumulate into C_tile
//                  for (int ti = 0; ti < SUBMATRIX_SIZE; ti++) {
//                      for (int tj = 0; tj < SUBMATRIX_SIZE; tj++) {
//                          C_tile[ti][tj] += temp_result[ti][tj];
//                      }
//                  }
//              }
             
//              // Store C tile back to C matrix
//              for (int ti = 0; ti < SUBMATRIX_SIZE; ti++) {
//                  for (int tj = 0; tj < SUBMATRIX_SIZE; tj++) {
//                      C[(i * SUBMATRIX_SIZE + ti) * size + (j * SUBMATRIX_SIZE + tj)] = C_tile[ti][tj];
//                  }
//              }
//          }
//      }
//  }
 
//  /**
//   * Initialize matrix with specified pattern
//   */
//  void init_matrix(int32_t* matrix, int size, int pattern) {
//      for (int i = 0; i < size; i++) {
//          for (int j = 0; j < size; j++) {
//              if (pattern == 1) {
//                  // Pattern 1: Sequential numbers
//                  matrix[i * size + j] = i * size + j + 1;
//              } else if (pattern == 2) {
//                  // Pattern 2: Row + column
//                  matrix[i * size + j] = i + j + 1;
//              } else {
//                  // Default pattern: All 1's
//                  matrix[i * size + j] = 1;
//              }
//          }
//      }
//  }
 
//  /**
//   * Print matrix for debugging
//   */
//  void print_matrix(int32_t* matrix, int size) {
//      for (int i = 0; i < size; i++) {
//          for (int j = 0; j < size; j++) {
//              print_int(matrix[i * size + j]);
//              uart_puts(" ");
//          }
//          uart_puts("\r\n");
//      }
//  }
 
//  // UART implementation for RV32IMC bare metal (placeholder - replace with your UART configuration)
//  #define UART_BASE 0x10010000
//  #define UART_THR  0x00  // Transmitter Holding Register
//  #define UART_LSR  0x14  // Line Status Register
//  #define UART_LSR_THRE 0x20  // Transmitter Holding Register Empty bit
 
//  void uart_init(void) {
//      // Configure UART (baud rate, etc.) - implementation specific to your hardware
//      // This is just a placeholder
//  }
 
//  void uart_putchar(char c) {
//      volatile uint32_t* lsr = (volatile uint32_t*)(UART_BASE + UART_LSR);
//      volatile uint32_t* thr = (volatile uint32_t*)(UART_BASE + UART_THR);
     
//      // Wait for transmitter ready
//      while ((*lsr & UART_LSR_THRE) == 0);
     
//      // Send character
//      *thr = c;
//  }
 
//  void uart_puts(const char* str) {
//      while (*str) {
//          uart_putchar(*str++);
//      }
//  }
 
//  void print_int(int32_t val) {
//      char buffer[12]; // Max 10 digits + sign + null terminator
//      int idx = 0;
//      int negative = 0;
     
//      // Handle negative numbers
//      if (val < 0) {
//          negative = 1;
//          val = -val;
//      }
     
//      // Convert to string (in reverse)
//      do {
//          buffer[idx++] = '0' + (val % 10);
//          val /= 10;
//      } while (val > 0);
     
//      // Add negative sign if needed
//      if (negative) {
//          buffer[idx++] = '-';
//      }
     
//      // Print in correct order
//      while (idx > 0) {
//          uart_putchar(buffer[--idx]);
//      }
//  }
 
//  void print_hex(uint32_t val) {
//      const char hex_chars[] = "0123456789ABCDEF";
//      char buffer[10]; // "0x" + 8 hex digits
//      buffer[0] = '0';
//      buffer[1] = 'x';
     
//      // Convert to hex string
//      for (int i = 0; i < 8; i++) {
//          buffer[9 - i] = hex_chars[val & 0xF];
//          val >>= 4;
//      }
     
//      // Print all characters
//      for (int i = 0; i < 10; i++) {
//          uart_putchar(buffer[i]);
//      }
//  }