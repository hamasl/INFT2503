#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>

//Adding namespace std because this is a tiny project
using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
    char buf[255];
    getcwd(buf, sizeof(buf));
    cout << "Current working directory is " << buf << endl;

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

    //Task B
    double temps[length];
    read_temperatures(temps, length);
    underTen = 0;
    between = 0;
    overTwenty = 0;
    for (int i = 0; i < length; ++i){
        if(temps[i] < 10) underTen++;
        else if(temps[i] > 20) overTwenty++;
        else between++;
    }
    cout << "Antall fra fil: " << endl;
    cout << "Antall under 10 er " << underTen << endl;
    cout << "Antall mellom 10 og 20 er : " << between << endl;
    cout << "Antall over 20 er " << overTwenty << endl;
    return 0;
}

void read_temperatures(double temperatures[], int length) {
    const char file_name[] = "temperatures.txt";
    ifstream file;
    file.open(file_name);
    if(!file){
        cerr << "Could not open file." << endl;
        file.close();
        exit(1);
    }
    for (int i = 0; i < length; ++i) {
        file >> temperatures[i];
    }
    file.close();
}
