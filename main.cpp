#include <iostream>
#include "Matrix.h"
#include "tests.cpp"

using namespace std;

int main() {

    if (tests() > 0) {
        cout << "Tests failed" << endl;
    } else {
        cout << "Tests passed" << endl;
    }

    return 0;
}
