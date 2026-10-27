#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

class Time {
    int h, m;
public:
    Time(int hh, int mm) : h(hh), m(mm) {}
    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};
inline int minutesBetween(const Time& a, const Time& b) {
    int am = a.h * 60 + a.m, bm = b.h * 60 + b.m;
    return abs(am - bm);
}
inline bool earlier(const Time& a, const Time& b) {
    return a.h < b.h || (a.h == b.h && a.m < b.m);
}
int main() {
    Time departure(9, 45), arrival(13, 10);
    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';
    Time beforeNoon(11, 59), afterNoon(12, 1), same(12, 1);
    cout << minutesBetween(beforeNoon, afterNoon) << ' '
         << earlier(beforeNoon, afterNoon) << ' '
         << earlier(same, afterNoon) << '\n';
}