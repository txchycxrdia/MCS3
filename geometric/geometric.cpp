#include <iostream>
#include <cmath>

using namespace std;

double geometricProbability(double p, int n){
    return 1 - pow(1 - p, n);
}

double findDefectiveProbability(double p, double m, int n, int k) {
    double totalProbability = 0.0;
    for(int i = 0; i < k; ++i) {
        double dailyProbability = geometricProbability(p, n);
        totalProbability += (1 - totalProbability) * dailyProbability;
        p += m;
        if(p > 1) p = 1;
    }
    return totalProbability;
}

int main() {
    int n, k;
    double p, m;
    cin >> n >> k >> p >> m;
    double result = findDefectiveProbability(p, m, n, k);
    cout << result;
    return 0;
}