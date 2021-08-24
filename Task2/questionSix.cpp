#include <iostream>

using namespace std;

int find_sum(const int *table, int length);

int main(){
    cout << "\nQuestion 6:" <<endl;
    int length = 20;
    int table[length];
    for (int i = 0; i < length; ++i) {
        table[i] = i+1;
    }
    const int amount_of_last_numbers = 5;
    cout << "Sum of ten first numbers: " << find_sum(table, 10) << endl;
    cout << "Sum of five next numbers: " << find_sum(table+10, amount_of_last_numbers) << endl;
    cout << "Sum of five last numbers: " << find_sum((table+(length-amount_of_last_numbers)), amount_of_last_numbers) << endl;
    return 0;
}

int find_sum(const int *table, int length){
    int sum = 0;
    for(int i = 0; i < length; ++i){
        sum += *(table + i);
    }
    return sum;
}


