#include <iostream>

using namespace std;
int main(){
    cout << "\nQuestion 5:" <<endl;
    double number;
    double *numberPtr = &number;
    double &numberRef = number;

    number = 1.0;

    cout << number << endl;
    cout << *numberPtr << endl;
    cout << numberRef << endl;

    *numberPtr = 2.0;

    cout << number << endl;
    cout << *numberPtr << endl;
    cout << numberRef << endl;


    numberRef = 3.0;

    cout << number << endl;
    cout << *numberPtr << endl;
    cout << numberRef << endl;

    return 0;
}