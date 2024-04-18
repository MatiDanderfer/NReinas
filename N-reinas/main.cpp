#include <iostream>
#include <cmath>


using namespace std;

void ImprimeSolucion (int solucion[],int Reinas)
{
    for (int i=0; i<Reinas; i++){
        cout << "Reina: " << i+1 << " Columna: " << solucion[i]+1 << endl ;
    }
}

bool Poda (int Solucion[] , int NroReinas)
{
    int j = 0;
    while (j < NroReinas){
        if ( (Solucion[NroReinas] == Solucion[j]) || ( (NroReinas-j) == abs(Solucion[j]-Solucion[NroReinas]))){
            return true;
        }else
            j++;
    }
    return false;
}

bool BackNesima (int Solucion[], int NroReinas, int & cantidad,int Reinas,int & vias)
{
    bool Encontre = false;
    if (NroReinas == Reinas){
        vias++;
        cout << "Solucion numero:" << vias << "\n" <<endl;
        ImprimeSolucion(Solucion,Reinas);
        Encontre = true;
        cout << "\n";
    }else{
        for(int col =0 ;col < Reinas; col++){
            Solucion[NroReinas] = col;
            if(!(Poda(Solucion,NroReinas))){
                cantidad++;
                Encontre = BackNesima(Solucion,NroReinas + 1,cantidad,Reinas,vias);
            }
        }
    }
    return Encontre;
}


int main()
{
    int queens;
     cout << "De el numero de Reinas a buscar: " ;
    cin >> queens;
    int solve[queens];
    cout << "Va a entrar en BackNesima \n";
    int ca = 0 ;
    int vias =0;
    cout << "\n";
    BackNesima(solve,0,ca,queens,vias);
    cout << "Numero de pasos: " << ca << "\n" ;
    cout << "Numero de soluciones: " << vias << "\n";

    return 0;
}
