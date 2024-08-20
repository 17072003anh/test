#include "Friend.h"
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    PhanLoai phanLoai(n);
    phanLoai.inputFriends(n);
    phanLoai.displayStatistics();
    phanLoai.displayMostImportantFriends();

    return 0;
}
