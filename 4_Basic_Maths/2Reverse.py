#   Q.1)
'''
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
''' 

def reverse(x):
        int_max = 2**31 - 1          #   2147483647     
        int_min = - 2**31            #  -2147483648 

        if x<0: sign = -1 
        else : sign = 1

        x = abs(x)
        num = 0

        while x>0:
            a = x%10     # last digit
            x //= 10
            # limit on num 
            if (num > int_max//10) or (num == int_max//10 and a > int_max%10): 
                return 0

            num = (num*10) +a
             
        return num*sign
    
print(reverse(123))
