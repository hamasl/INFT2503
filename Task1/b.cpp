#include <iostream>
#include <fstream>

using namespace std;
void read_temperatures(double temperatures[], int length);
int main(){
//Task B
const int length = 5;
double temps[length];
read_temperatures(temps, length);
int underTen = 0;
int between = 0;
int overTwenty = 0;
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
    //NOTE file has to be in the same directory as the built version of this file (b.cpp)
    //CMakeList.txt can automate this task, but then the path to the build directory has to be manually set.
    //This is done in the file() command
    const char file_name[] = "temperatures.txt";
    ifstream file;
    file.open(file_name);
    if(!file){
        cerr << "Could not open file.\nCheck that it is stored in the same directory as the built version of this file." << endl;
        file.close();
        exit(1);
    }
    for (int i = 0; i < length; ++i) {
        file >> temperatures[i];
    }
    file.close();
}