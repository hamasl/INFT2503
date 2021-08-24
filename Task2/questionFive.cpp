#include <iostream>

using namespace std;
int main(){
    cout << "\nQuestion 5:" <<endl;
    double number = 5;
    double *numberPtr = &number;
    double &numberRef = number;

    cout << number << endl;
    cout << *numberPtr << endl;
    cout << numberRef << endl;

    return 0;
}