#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAX 2
void fillMatrix(int **&A);
void fillMatrixWithZeros(int **&A);

double *gen(int n)
{
	double *arr = new double[n];
	for(int i=0; i!=n; i++){
		arr[i] = rand() % n;
	} 
	return arr;
}

int main(int argc, char **argv)
{

    time_t t_ini, t_fin, t_ini2, t_fin2;
    int **A, **B, **C;

    // initialize A and B
    fillMatrix(A);
    fillMatrix(B);

    // initialize C, fill matrix with zeros
    fillMatrixWithZeros(C);

    t_ini = clock();
    for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j)
            for (int k = 0; k < MAX; ++k)
                *(*(C + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
    t_fin = clock();
    cout << MAX << " " << static_cast<double>(t_fin - t_ini) / CLOCKS_PER_SEC << "s\n";
}

void fillMatrix(int **&A)
{
    A = new int *[MAX];
    for (int i = 0; i < MAX; i++)
    {
        *(A+i)= new int [MAX]();
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
