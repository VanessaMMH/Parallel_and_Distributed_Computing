#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAX 500

double A[MAX][MAX], x[MAX], y[MAX];

void fillArrays();

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    time_t t_ini, t_fin, t_ini2, t_fin2;

    // initialize A and x, assign y = 0
    fillArrays();

    // first pair of loops

    t_ini = clock();
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            y[i] += A[i][j] * x[j];
        }
    }
    t_fin = clock();
    cout << MAX << " " << static_cast<double>(t_fin - t_ini) / CLOCKS_PER_SEC << "s\t";


    // assign y = 0
    memset(y, 0, sizeof(y));


    t_ini2 = clock();
    for (int j = 0; j < MAX; j++)
    {
        for (int i = 0; i < MAX; i++)
        {
            y[i] += A[i][j] * x[j];
        }
    }
    t_fin2 = clock();
    cout << static_cast<double>(t_fin2 - t_ini2) / CLOCKS_PER_SEC << "s\n";

    return 0;
}

// Inicializa la matriz A y x, asigna y = 0
void fillArrays()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            A[i][j] = (rand() % (100 * MAX)) / (float)(MAX);
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        x[i] = (rand() % (100 * MAX)) / (float)(MAX);
    }

    for (int i = 0; i < MAX; i++)
    {
        y[i] = 0;
    }
}