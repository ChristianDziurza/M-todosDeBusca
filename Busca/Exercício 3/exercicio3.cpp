#include <iostream>
using namespace std;

void Merge(int *v, int inicio, int fim);
void Intercala(int *v, int inicio, int meio, int fim);
int BuscaSequencial(int *v, int n, int x);

int main(){
    int *v, x, n;
    cout << "Tamanho do vetor" << endl;
    cin >> n;
    if(!(v = new(nothrow) int[n])){
        cout << "Droga" << endl;
        return -1;
    }
    cout << "Preencha o vetor" << endl;
    for(int i=0;i<n;i++)
        cin >> v[i];
    Merge(v,0,n);
    cout << "Vetor ordenado" << endl;
    for(int i=0;i<n;i++)
        cout << v[i] << endl;
    cout << "Digite o numero para a busca" << endl;
    cin >> x;
    if(BuscaSequencial(v,n,x) == -1)
        cout << "Numero nao existe no vetor" << endl;
    else
        cout << "Numero encontrado no indice: " << BuscaSequencial(v,n,x) << endl;
    return 0;
}

int BuscaSequencial(int *v, int n, int x){
    if(n < 0)
        return -1;
    else if(v[n] == x)
        return n;
    BuscaSequencial(v,n-1,x);
}

void Merge(int *v, int inicio, int fim){
    if(inicio < (fim-1)){
        int meio = (inicio + fim)/2;
        Merge(v,inicio, meio);
        Merge(v,meio,fim);
        Intercala(v,inicio,meio,fim);
    }
}

void Intercala(int *v, int inicio, int meio, int fim){
    int *w, i = inicio, j = meio, k = 0;
    w = new(nothrow) int[fim];
    while(i < meio && j < fim){
        if(v[i] < v[j]){
            w[k] = v[i];
            i++;
        }
        else{
            w[k] = v[j];
            j++;
        }
        k++;
    }
    while(i < meio){
        w[k] = v[i];
        i++;
        k++;
    }
    while(j < fim){
        w[k] = v[j];
        j++;
        k++;
    }
    for(k = 0; k < fim - inicio; k++)
        v[inicio + k] = w[k];
    delete[] w;
    w = NULL;
}