#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;

    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;

    //Task a
    cout << endl << "Task a:" << endl;
    auto it = find_if(v1.begin(), v1.end(), [](int e){ return e > 15; });
    cout << "First element larger than 15 is " << *it << " at index " << (it-v1.begin()) << "." << endl;

    //Task b
    cout << endl << "Task b:" << endl;
    //Equality in this context allows a difference of 2 per element
    auto equals = [](int e1, int e2){return abs(e1-e2) <= 2;};
    auto bool_to_str = [](bool val){return val ? "true" : "false";};
    cout << "[v1.begin(), v1.begin() + 5> equal to v2: " << bool_to_str(equal(v1.begin(), v1.begin()+5, v2.begin(), equals)) << endl;
    cout << "[v1.begin(), v1.begin() + 4> equal to v2: " << bool_to_str(equal(v1.begin(), v1.begin()+4, v2.begin(), equals)) << endl;


    //Task c
    cout << endl << "Task c:" << endl;
    vector<int> res;
    res.resize(v1.size());
    replace_copy_if(v1.begin(), v1.end(), res.begin(), [](int e){return (e%2) == 1;}, 100);
    cout << "res vector is: " << res << endl;
    return 0;
}
