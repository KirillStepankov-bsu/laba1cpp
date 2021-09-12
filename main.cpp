#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int k; double x;
    cout << "Enter k and x: "; cin >> k >> x;

    if (k<=1 || x<=-1 || x>=1){ //проверка на корректность введенных данных
        cout << "NaN"; return 1;
    }

    const long double epsilon = pow(10, -k)/2;
    const double standart_result = 1/sqrt(1+x); //результат при помощи стандартных функций

    double part = 1; // очередное слагаемое 
    int i = 1, var = 1;
    double result=0;
    while(abs(part) >= epsilon){
        part = part*i/(i+1)*x;
        result = result + pow(-1, var)*part;
        i+=2;
        var++;
    }

    result++;

    cout << result << " " << standart_result;
}