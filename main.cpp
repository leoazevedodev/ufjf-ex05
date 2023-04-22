#include <iostream>
#include "MatrizLin.h"

using namespace std;

bool quadaraSimetrica(MatrizLin *mat)
{
    for(int i = 0; i < mat->getNl() ; i++)
    {
        for(int j = 0; j < mat->getNc() ; j++)
        {
            if(mat->get(i,j) != mat->get(j,i))
                return false;
        }
    }
}

int main()
{
    int m = 7, n = 8;
    MatrizLin mat(m, n);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            float val = j + n*i; /// sequencia numerica no intervalo 0..(m*n-1)
            mat.set(i, j, val);
        }

    mat.imprimeMatriz();


    cout << "Ela e simetrica e quadrada ? : " << quadaraSimetrica(&mat) << endl;

    cout << "O Maior valor e: " << mat.encontramaior() << endl;


    mat.transposta();
    return 0;
}
