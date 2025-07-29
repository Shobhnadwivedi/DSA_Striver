#   Q.1)
'''
Given two integers a and b, write a function lcmAndGcd() to compute their LCM and GCD. The function inputs two integers a and b and returns a list containing their LCM and GCD.

Examples:

Input: a = 5 , b = 10
Output: [10, 5]
Explanation: LCM of 5 and 10 is 10, while their GCD is 5.
'''
def lcmgcd(a,b):
    for i in range(min(a,b),0,-1):
        if ( a%i==0 and b%i==0):
            hcf = i
            break
    lcm = int((a*b)/hcf)
    return hcf



#   Q.2)
'''
Given an array A[ ] of N numbers, your task is to find LCM of it modulo 1000000007

Example 1:

Input:
N = 4
A = {1 , 2 , 8 , 3}
Output:
24
Explanation:
LCM of the given array is 24.
24 % 1000000007 = 24

Expected Time Complexity: O(N*log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 10**5
1 <= A[i] <= 10**5
'''

def lcm(N,A):
    for i in range(N-1):
        lcm2 = A[0]
        
        for j in range(min(lcm2,A[i+1]),0,-1):
            if ( lcm2%j==0 and A[i+1]%j==0):
                hcf = j
                break
        lcm2 = int((lcm2*A[i+1])/hcf)
    return 0







def lcmarr(N,A):
    m = 10**9 +7
    
    def lcmgcd(a,b):
        for i in range(min(a,b),0,-1):
            if ( a%i==0 and b%i==0):
                hcf = i
                break
        lcm = int((a*b)/hcf)
        return hcf

    temp = A[0]
    for i in range(1, N):
        gcd = lcmgcd(temp, A[i])
        lcm = temp//gcd * A[i]%m
        temp = lcm
    return lcm



print(lcmarr(4,[1,2,8,3]))


#  hint 
'''
Write a one-line function to return the position of the first 1 from right to left, in the binary representation of an Integer. 

Examples:

Input: n = 18
Output: 2
Explanation: Binary Representation of 18 is 010010, hence position of first set bit from right is 2.

Input:  n = 19
Output: 1
Explanation: Binary Representation of 19 is 010011, hence position of first set bit from right is 1.

Position of rightmost set bit using two's complement:
(n&~(n-1)) always return the binary number containing the rightmost set bit as 1. if N = 12 (1100) then it will return 4 (100). Here log2 will return, the number of times we can express that number in a power of two. For all binary numbers containing only the rightmost set bit as 1 like 2, 4, 8, 16, 32.... Find that position of rightmost set bit is always equal to log2(Number) + 1.

Follow the steps to solve the given problem:

Let input be 12 (1100)
Take two's complement of the given no as all bits are reverted except the first '1' from right to left (0100)
Do a bit-wise & with original no, this will return no with the required one only (0100)
Take the log2 of the no, you will get (position - 1) (2)
Add 1 (3)
Below is the implementation of the above approach:

// C++ program for Position
// of rightmost set bit
#include <iostream>
#include <math.h>
using namespace std;

class gfg {

public:
    unsigned int getFirstSetBitPos(int n)
    {
        return log2(n & -n) + 1;
    }
};

// Driver code
int main()
{
    gfg g;
    int n = 18;
    cout << g.getFirstSetBitPos(n);
    return 0;
}
'''

