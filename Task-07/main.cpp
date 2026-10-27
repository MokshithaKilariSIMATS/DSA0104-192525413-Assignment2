#include <iostream>
#include <chrono>
using namespace std;
using Clock = chrono::steady_clock;

// Original: shifting every existing transaction costs O(k) per insertion.
class ShiftHistory {
    static const int CAP = 10;
    long long data[CAP]{};
    int count = 0;
public:
    void add(long long value) {
        if (count < CAP) data[count++] = value;
        else {
            for (int i = 1; i < CAP; ++i) data[i - 1] = data[i];
            data[CAP - 1] = value;
        }
    }
    long long at(int i) const { return data[i]; }
};

// Redesigned: circular buffer overwrites the oldest item in O(1).
class CircularHistory {
    static const int CAP = 10;
    long long data[CAP]{};
    int count = 0, next = 0;
public:
    void add(long long value) {
        data[next] = value;
        next = (next + 1) % CAP;
        if (count < CAP) ++count;
    }
    int size() const { return count; }
    long long chronologicalAt(int i) const {
        int start = (count == CAP) ? next : 0;
        return data[(start + i) % CAP];
    }
};
int main() {
    ShiftHistory oldVersion;
    CircularHistory newVersion;
    for (int i = 1; i <= 12; ++i) {
        oldVersion.add(i);
        newVersion.add(i);
    }
    cout << "Original retained: ";
    for (int i = 0; i < 10; ++i) cout << oldVersion.at(i) << ' ';
    cout << "\nRedesigned retained: ";
    for (int i = 0; i < newVersion.size(); ++i) cout << newVersion.chronologicalAt(i) << ' ';
    cout << "\nBoth retain the latest 10 values; circular insertion is O(1).\n";
}