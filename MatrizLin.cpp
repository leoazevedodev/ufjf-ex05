#include <iostream>
#include <cstdlib>

#include "MatrizLin.h"

using namespace std;

MatrizLin::MatrizLin(int mm, int nn)
{
    cout << "Criando um objeto MatrizLin" << endl;
    nl = mm;
    nc = nn;
    vet = new float[nl*nc];
}

MatrizLin::~MatrizLin()
{
    cout << "Destruindo um objeto MatrizLin" << endl;
    delete [] vet;
    for (int i = 0; i < nl; i++) {
    delete[] matrizTransposta[i];
    }
    delete[] matrizTransposta;

}

int MatrizLin::detInd(int i, int j)
{
    if(i >= 0 && i < nl && j >= 0 && j < nc)
        return nc*i + j;
    else
        return -1;
}

float MatrizLin::get(int i, int j)
{
    int k = detInd(i, j);
    if(k != -1)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void MatrizLin::set(int i, int j, float val)
{
    int k = detInd(i, j);
    if(k != -1)
        vet[k] = val;
    else
        cout << "ERRO: Indice invalido!" << endl;
}

void MatrizLin::imprimeMatriz()
{

    for(int i = 0; i < nl; i++)
    {
        for(int j = 0; j < nc; j++)
        {
            float val = get(i, j);
            cout << val << "\t";
        }
        cout << endl;
    }
}


int MatrizLin::encontramaior()
{
    int maior = get(0,0);
    for(int i = 0; i < nl; i++)
    {
        for(int j = 0; j < nc; j++)
        {
            if(get(i,j) > maior)
            {
                maior = get(i,j);
            }
        }
    }
    return maior;
}

int** MatrizLin::transposta(){
    matrizTransposta = new int*[nc];

    for(int i = 0; i < nc; i++)
    {
        matrizTransposta[i] = new int[nl];
    }

    for (int i = 0; i < nc; i++) {
        for (int j = 0; j < nl; j++) {
            matrizTransposta[i][j] = get(j,i);
        }
    }

    for(int i = 0; i < nc; i++)
    {
        for(int j = 0; j < nl; j++)
        {
            float val = matrizTransposta[i][j];
            cout << val << "\t";
        }
        cout << endl;
    }

    return matrizTransposta;
}


