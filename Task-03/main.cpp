#include <iostream>
#include <string>
using namespace std;

struct Parcel { double weightKg; bool express; bool insured; };

double charge(double weightKg, bool express = false, bool insured = false) {
    double total = 40.0 + weightKg * 20.0;
    if (express) total += 30.0;
    if (insured) total += 15.0;
    return total;
}
double charge(int weightGrams) {
    return charge(weightGrams / 1000.0, false, false);
}
double charge(const Parcel& p) {
    return charge(p.weightKg, p.express, p.insured);
}
int main() {
    cout << "charge(2)       = " << charge(2) << '\n';
    cout << "charge(2.0)     = " << charge(2.0) << '\n';
    cout << "charge(2.0f)    = " << charge(2.0f) << '\n';
    cout << "charge(2000)    = " << charge(2000) << '\n';
    cout << "charge(2,true)  = " << charge(2.0, true) << '\n';
    cout << "charge(Parcel)  = " << charge(Parcel{2.0, true, true}) << '\n';
}