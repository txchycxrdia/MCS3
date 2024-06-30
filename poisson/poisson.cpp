#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double poissonProbability(int lambda, int k) {
    return pow(lambda, k) * exp(-lambda) / factorial(k);
}

double calculateOptimalProbability(int lambda, int k1, int k2) {
    double probability = 0.0;
    for (int k = k1; k <= k2; ++k) {
        probability += poissonProbability(lambda, k);
        if(probability > 1) probability = 1;
    }
    return probability;
}

int main() {
    int lambda, k1, k2;
    cin >> lambda >> k1 >> k2;
    double result = calculateOptimalProbability(lambda, k1, k2);
    cout << fixed << setprecision(3) << result;
    return 0;
}