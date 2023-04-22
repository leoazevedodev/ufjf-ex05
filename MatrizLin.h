#ifndef MatrizLin_H_INCLUDED
#define MatrizLin_H_INCLUDED

class MatrizLin
{
    private:
        int nl, nc; // numero de is e js
        float *vet; // vetor de tamanho nl*nc
        int detInd(int i, int j);
        int maiorvalor;
        int **matrizTransposta;

    public:
        MatrizLin(int mm, int nn);
        ~MatrizLin();
        void set(int i, int j, float val);
        float get(int i, int j);
        void imprimeMatriz();
        int getNl(){return nl;};
        int getNc(){return nc;};
        int encontramaior();
        void setMaiorvalor(int n);
        int** transposta();
};

#endif // MatrizLin0_H_INCLUDED
