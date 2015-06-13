#include <iostream>
#include "tests.cpp"

using namespace std;

int main() {

    int testsResult = tests();

    if (testsResult > 0) {
        cout << "Tests failed" << endl;
    } else {
        cout << "Tests passed" << endl;
    }

    return testsResult;
}

