#include <iostream>
#include <iomanip>
using namespace std;

void imprimirMatriz(int **pMat, int t );
int  sumarDiagonal( int ** pMatriz, int tam);
int sumaSuperior( int **pMatriz, int tam);


int main()
{ int tam;
    int* *pMatriz= nullptr;

  srand(time(nullptr));
  cout << "Tamanio: ";
  cin >> tam;
  //----dimensionamos la matriz dinamica
  pMatriz = new int*[tam];
  for(int f=0; f<tam; f++)
      pMatriz[f] = new int[tam];
  //---llenamos con datos a la matriz
  for(int f=0; f<tam; f++)
      for(int c=0; c<tam; c++)
          pMatriz[f][c] = rand() % 99 + 1;
  imprimirMatriz(pMatriz, tam);
  cout << "\nLa suma de la diagonal principal es: " << sumarDiagonal(pMatriz,tam) << "\n";
  cout << "\nLa suma de los elementos que estan por encima de la diagonal : " << sumaSuperior(pMatriz, tam) << "\n";
  //-----liberamos memoria
  for(int f=0; f<tam; f++)
      delete []pMatriz[f];
  delete []pMatriz;
  pMatriz = nullptr;
    return 0;
}

int sumaSuperior( int **pMatriz, int tam)
{
    int suma=0;
    for(int f=0; f<tam-1; f++)
        for(int c=f+1; c<tam; c++)
            suma += pMatriz[f][c];
    return suma;
}



int  sumarDiagonal( int ** pMatriz, int tam)
{
    int suma = 0;
    for(int f=0; f<tam; f++)
        suma += pMatriz[f][f];
    return suma;
}


void imprimirMatriz(int **pMat, int t )
{
   for(int f=0; f<t; f++)
   {
       for(int c=0; c<t; c++)
           cout << setw(4) << pMat[f][c];
       cout << "\n";
   }
}