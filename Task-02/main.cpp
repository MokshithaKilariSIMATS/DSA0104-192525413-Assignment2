#include <iostream>
#include <algorithm>
using namespace std;

int& highest(int marks[], int n) {
    int index = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[index]) index = i;
    return marks[index];
}
// Deliberately unsafe demonstration: do not call this function.
int& danglingReference() {
    int local = 42;
    return local; // warning: reference to local variable returned
}
int highestIndex(const int marks[], int n) {
    int index = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[index]) index = i;
    return index;
}
int main() {
    int marks[] = {78, 91, 84, 88};
    highest(marks, 4) += 2;
    cout << "Moderated highest mark: " << highest(marks, 4) << '\n';
    cout << "Highest mark index: " << highestIndex(marks, 4) << '\n';
    cout << "Marks: ";
    for (int m : marks) cout << m << ' ';
    cout << '\n';
}