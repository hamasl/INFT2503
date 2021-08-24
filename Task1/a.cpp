#include <iostream>

//Adding namespace std because this is a tiny project
using namespace std;

int main() {
    //Task A
    const int length = 5;
    cout << "Du skal skrive inn 5 temperaturer. " << endl;

    double placeholder;
    int underTen = 0;
    int between = 0;
    int overTwenty = 0;
    for (int i = 0; i < length; ++i) {
        cout << "Temperatur " << (i+1) << ": ";
        cin >> placeholder;
        if(placeholder < 10) underTen++;
        else if(placeholder > 20) overTwenty++;
        else between++;
    }

    cout << "Antall under 10 er " << underTen << endl;
    cout << "Antall mellom 10 og 20 er : " << between << endl;
    cout << "Antall over 20 er " << overTwenty << endl;

    return 0;
}
