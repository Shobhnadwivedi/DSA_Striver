/*             268 LEETCODE - > https://leetcode.com/problems/missing-number/description/ 

BEST sol is of  "sum of n numbers" or "xor" -

1.                                                        xor properties :             

XOR gives 1 only when the bits are different.
If yes -> 1          if no -> 0
E.g:           5 ^ 3 =   0101  ^ 0011  =  0110 = 6

2.  same numbers xor gives zero ALWAYS   ->         2 ^ 2 = 0010 ^ 0010 = 0000

3. xor of a number with zero is the number itself ALWAYS  ->       6 ^ 0 =  0110 ^ 0000 = 0110 = 6 

SOLUTION->    when we do xor of all numbers from 0 to n    
        ->    then we do xor of all elements of array 
        ->    then we xor these both      
        ->    the same numbers get cancelled to 0 and only 1 is left that is missing bcuz uska pair nhi ban paya . so the answer is the missing number.


*/