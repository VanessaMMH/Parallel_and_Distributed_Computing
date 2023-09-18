#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAX 2
void fillMatrix(int **&A);
void fillMatrixWithZeros(int **&A);

int main(int argc, char **argv)
{

    time_t t_ini, t_fin, t_ini2, t_fin2;
    int **A, **B, **C;
    int blockSize = MAX / 2;

    // initialize A and B
    fillMatrix(A);
    fillMatrix(B);

    // initialize C, fill matrix with zeros
    fillMatrixWithZeros(C);


    t_ini = clock();
    for (int ii = 0; ii < MAX; ii += blockSize)
        for (int jj = 0; jj < MAX; jj += blockSize)
            for (int kk = 0; kk < MAX; kk += blockSize)
                for (int i = ii; i < ii + blockSize; i++)
                    for (int j = jj; j < jj + blockSize; j++)
                        for (int k = kk; k < kk + blockSize; k++)
                            *(*(C + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
    t_fin = clock();
    cout << MAX << " " << static_cast<double>(t_fin - t_ini) / CLOCKS_PER_SEC << "s\n";
}

void fillMatrix(int **&A)
{
    A = new int *[MAX];
    for (int i = 0; i < MAX; i++)
    {
        *(A + i) = new int[MAX]();
        for (int j = 0; j < MAX; j++)
        {
            A[i][j] = (rand() % (100 * MAX)) / (float)(MAX);
        }
    }
}

void fillMatrixWithZeros(int **&A)
{
    A = new int *[MAX];
    for (int i = 0; i < MAX; i++)
        *(A + i) = new int[MAX]();
}

// void matrix_2d_ptr__create(int **&M, int rows, int cols){
//     M = new int *[rows];
//     for(int i=0 ; i < rows ; i++)
//         *(M+i)= new int [cols];
// }

// void matrix_2d_ptr__create_and_fill__0s(int **&M, int rows, int cols){
//     M = new int *[rows];
//     for(int i=0 ; i < rows ; i++)
//         *(M+i)= new int [cols]();
// }

// void matrix_2d_ptr__print(int **&M, int rows, int cols){
//     for(int i=0 ; i < rows ; i++){
//         for(int j=0 ; j < cols ; j++)
//             std::cout <<"\t"<< *(*(M+i)+j);
//         std::cout << std::endl;
//     }
// }

// void matrix_2d_ptr__fill__input(int **&M, int rows, int cols){
//     for(int i=0 ; i < rows ; i++){
//         for(int j=0 ; j < cols ; j++){
//             std::cin>>*(*(M+i)+j);
//         }
//     }
// }

// void matrix_2d_ptr__fill__random_values(int **&M, int rows, int cols, int rand_range_floor, int rand_range_ceil){
//     srand (time(NULL));
//     int rand_range_lenght = rand_range_ceil-rand_range_floor+1;
//     for(int i=0 ; i < rows ; i++){
//         for(int j=0 ; j < cols ; j++){
//             *(*(M+i)+j) = rand() % rand_range_lenght + rand_range_floor;
//         }
//     }
// }

// void matrix_2d_ptr__create_and_fill__random_values(int **&M, int rows, int cols, int rand_range_floor, int rand_range_ceil){
//     srand (time(NULL));
//     int rand_range_lenght = rand_range_ceil-rand_range_floor+1;
//     M = new int *[rows];
//     for(int i = 0; i < rows ; i++){
//         *(M+i)= new int [cols]();
//         for(int j=0 ; j < cols ; j++)
//             *(*(M+i)+j) = rand() % rand_range_lenght + rand_range_floor;
//     }
// }
