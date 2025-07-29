#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the sum of divisors of a number
int sumOfDivisors(int num) {
    int sum = 0;
    for (int i = 1; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    return sum;
}

// Function to calculate the sum of F(i) for all i from 1 to N
long long sumOfSumOfDivisors(int N) {
    long long totalSum = 0;
    for (int i = 1; i <= N; ++i) {
        totalSum += sumOfDivisors(i);
    }
    return totalSum;
}


int sumOfSumOfDivisors1(int N) {
    int totalSum = 0;
    
    for (int i = 1; i <= N; ++i) {
        int sum = 0;
        
        // Calculate the sum of divisors of i
        for (int j = 1; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                if (j == i / j) {
                    sum += j; // If both divisors are the same, add it once
                } else {
                    sum += j + i / j; // Otherwise, add both divisors
                }
            }
        }
        
        totalSum += sum;
    }
    
    return totalSum;
}

int main() {
    int N;
    cout << "Enter a positive integer N: ";
    cin >> N;

    long long result = sumOfSumOfDivisors1(N);
    cout << "The sum of F(i) for all i from 1 to " << N << " is: " << result << endl;

    return 0;
}
