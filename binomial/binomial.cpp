#include <iostream>
#include <cmath>

using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long long combination(int n, int k) {
    if (k > n) return 0;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

double binomialProbability(int n, int k, double p) {
    return combination(n, k) * pow(p, k) * pow(1 - p, n - k);
}

double probabilityAtLeastK(int n, int k, double p) {
    double probability = 0.0;
    for (int i = k; i <= n; ++i) {
        probability += binomialProbability(n, i, p);
    }
    return probability;
}

int main() {
    int n, k;
    double p;
    cin >> n >> k >> p;
    double result = probabilityAtLeastK(n, k, p);
    cout << result;
    return 0;
}