#include <bits/stdc++.h>


void multiply(double **A, double **B, double **C, int length)
{
    for (int i = 0; i < length; i++)
        for (int j = 0; j < length; j++)
            for (int k = 0; k < length; k++)
                C[i][j] += A[i][k] * B[k][j];
}

void execute(int length)
{
    const int MAX = length;
    int i, j;

    double **A, **B, **C;
    A = new double*[MAX];
    B = new double*[MAX];
    C = new double*[MAX];

    for (i = 0; i < MAX; i++)
    {
        A[i] = new double[MAX];
        B[i] = new double[MAX];
        C[i] = new double[MAX];
        for (j = 0; j < MAX; j++)
        {
            A[i][j] = std::rand() % 100;
            B[i][j] = std::rand() % 100;
        }
    }
    


    auto begin = std::chrono::high_resolution_clock::now();
    multiply(A, B, C, MAX);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl;

    for (i = 0; i < MAX; i++)
    {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;
}




int main()
{

    for (int i = 100; i <= 2000; i += 100)
    {
        std::cout << "Length: " << i << "\t";
        execute(i);
    }
    return 0;
}