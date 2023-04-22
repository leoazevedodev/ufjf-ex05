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

float* prodMatVetor(MatrizLin *m, float *v)
{
    float *resultado = new float[m->getNl()];
    v = new float[m->getNc()];

    for(int i = 0; i < m->getNc(); i++)
    {
        v[i] = i+1;
    }

    for(int i = 0; i < m->getNl(); i++)
    {
        float soma = 0;

        for(int j = 0; j < m->getNc(); j++)
        {
            soma = soma + m->get(i, j) * v[j];
            //cout << "( " << i << " )" << "( " << j << " )" << m->get(i, j) * v[j] << " ";
        }
        resultado[i] = soma;
    }

    return resultado;

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

    float valores;
    float *resutladofinal = prodMatVetor(&mat, &valores);

    for(int i = 0; i < mat.getNl(); i++)
    {
        cout << endl;
        cout << "----------------" << endl;
        cout << resutladofinal[i] << " ";
    }
    return 0;
}
