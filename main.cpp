#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int k; double x;
    cout << "Enter k and x: "; cin >> k >> x;

    if (k<=1 || x<=-1 || x>=1){ //проверка на корректность введенных данных
        cout << "NaN"; return 1;
    }

    int amount_dig_aft_point;
    cout << "Enter amount digits after point in result: ";
    cin >> amount_dig_aft_point;

    const long double epsilon = pow(10, -k)/2;
    const double standart_result = 1/sqrt(1+x); //результат при помощи стандартных функций

    double part = 1; // очередное слагаемое 
    int i = 1;
    double result=0;
    while(fabs(part) >= epsilon){
        part = -part*i/(i+1)*x;
        result += part;
        i+=2;
    }

    result++;

    cout << setprecision(amount_dig_aft_point) << result << " " << standart_result;
}