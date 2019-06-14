#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

double funcion(double x){
    return asin(x);
}

void difProgresivas(long double rows,long double h,long double n,bool central){

    vector<long double> pascal;
    vector<long double> evaluaciones;

    for (int i = 0; i < rows+1; i++)
    {
        long double val = 1.0;
        for (int k = 0; k <= i; k++)
        {
            if(i==rows){
                pascal.push_back(val);
            }
            val = val * (i - k) / (k + 1);
        }
    }

    long double contador;

    if (central){
        contador=(long double)rows/2.0;
    } else{
        contador=rows;
    }

    for (int j = 0; j < pascal.size(); ++j) {
        evaluaciones.push_back(pascal.at(j)*funcion(n+(contador*h)));
        contador = contador-1;
    }



    bool bandera = true;
    long double numerador=0.0;

    for (int l = 0; l < evaluaciones.size(); ++l) {
        if(bandera==true){
            numerador=numerador+evaluaciones.at(l);
            bandera=false;
        }else{
            numerador=numerador-evaluaciones.at(l);
            bandera=true;
        }
    }
    cout<< setprecision(8) << numerador/pow(h,rows);
}

void integracionTrapezoidal(double limInf,double limSup, int intervalos){
    double h = (limSup-limInf)/intervalos;

    double resultado=0;

    for (int i = 2; i <= intervalos ; ++i) {
        resultado = resultado + funcion(limInf+(i-1)*h);
    }

    cout<< setprecision(8) <<h*((funcion(limInf)/2)+resultado+(funcion(limSup)/2));
}

void integracionSimpson(double limInf,double limSup, int intervalos){
    double h = (limSup-limInf)/intervalos;

    double resultadoUno=0;
    double resultadoDos=0;

    for (int i = 1; i <= (intervalos/2)-1 ; ++i) {
        resultadoUno = resultadoUno + funcion(limInf+((2*i)*h));

    }

    for (int e = 1; e <= intervalos/2 ; ++e) {
        resultadoDos = resultadoDos + funcion(limInf+((2*e-1)*h));
    }

    cout<< setprecision(8) <<(h/3)*(funcion(limInf)+(2*resultadoUno)+(4*resultadoDos)+funcion(limSup));
}

int main() {
    difProgresivas(5.0,0.001,0.0,false);
    //integracionTrapezoidal(0,1,5);
    //integracionSimpson(-1,0,4);
    return 0;
}
