#include <vector>
#include <iostream>

using namespace std;
int main(){
    vector<double> vector = {1,2,3,4,5};
    cout << vector.front() << endl;
    cout << vector.back() << endl;

    vector.emplace(vector.begin()+1, 10);
    cout << vector.front() << endl;

    auto it = find(vector.begin(), vector.end(), 3);
    if(it != vector.end()){
        cout << "Success: " << *it << endl;
    } else {
        cout << "Not found" << endl;
    }
    return 0;
}

