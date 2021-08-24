#include <iostream>

using namespace std;
int main(){
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    cout << "Value of i: " << i << endl;
    cout << "Value of j: " << j << endl;
    cout << "Value of p: " << p << endl;
    cout << "Value of q: " << q << endl;

    cout << "Address of i: " << &i << endl;
    cout << "Address of j: " << &j << endl;
    cout << "Address of p: " << &p << endl;
    cout << "Address of q: " << &q << endl;

    return 0;
}
