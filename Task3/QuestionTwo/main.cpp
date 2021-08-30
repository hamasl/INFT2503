#include <iostream>
// Circle is stored in questionOne.cpp, would normally call the file Circle.cpp, but it is called questionOne here because it is the first question of the task
#include "questionOne.cpp"

using namespace std;

int main() {
    Circle circle(5);

    int area = circle.get_area();
    cout << "Arealet er lik " << area << endl;

    double circumference = circle.get_circumference();
    cout << "Omkretsen er lik " << circumference << endl;
}

