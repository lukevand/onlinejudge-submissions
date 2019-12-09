#include <bits/stdc++.h>
using namespace std;

int main() {
    int duration, numDepreciation;
    double downPayment, amount;
    int monthNumber;
    double depPercent;
    while (scanf("%d %lg %lg %d", &duration, &downPayment, &amount, &numDepreciation), duration >=0) {
        double monthPay = amount/duration;
        double currentLoan = amount;
        vector<double> depre(101);
        int currentMonth = 0;
        for (int i=0;i<numDepreciation; i++) {
            scanf("%d %lg", &monthNumber, &depPercent);
            fill(depre.begin()+monthNumber, depre.end(), depPercent);
        }

        double currentVal = (amount+downPayment)*(1-depre[0]);
        while (currentVal < currentLoan) {
            currentMonth++;
            currentLoan -= monthPay;
            currentVal *= (1-depre[currentMonth]);
        }
        printf("%d month%s\n", currentMonth, (currentMonth!=1 ? "s" : ""));
    }


    return 0;
}

