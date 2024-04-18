#include <iostream>
#include <cmath>

using namespace std;

bool esSolucion (int Solve[],int NroReinas)
{
    int i = 0;
    while (i < NroReinas){
       int j = 0;
        while (j < i){
            if ( (Solve[i] == Solve[j]) || ( (i-j) == abs(Solve[j]-Solve[i]))){
                return true;
            }else
                j++;
        }
        i++;
    }
    return false;
}

void ImprimeSolve(int Solve[],int N)
{
    for (int i = 0; i < N ;  i++){
        cout << "Reina:" << i+1 << " Col:" << Solve[i] << " | ";
    }
    cout << "\n";
}

void BackSinPoda (int Solucion[],int nroreinas,int N,int & estados)
{
    if (nroreinas == N){
       if (!esSolucion(Solucion,N)){
            ImprimeSolve(Solucion,N);
       }
    }else
        for(int col = 1; col <= N; col++){
            Solucion[nroreinas] = col;
            estados++;
            BackSinPoda(Solucion,nroreinas + 1 , N,estados);

        }
}



int main()
{
    int queens;
    cout << "De el numero de Reinas a buscar: " ;
    cin >> queens;
    int solve[queens];
    cout << "Va a entrar en BackNesima \n";
    int reinas = 0;
    int estados= 0;
    BackSinPoda(solve,0,queens,estados);
    cout << "Pasos: " << estados << "\n" ;

    return 0;
}
