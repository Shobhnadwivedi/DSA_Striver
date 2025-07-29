#   Q.1)    Function to print all digits of a number.  

def digits(num):
    listt = []
    while num>0 :
        a = num%10
        num = num//10 
        listt.append(a)
    return listt




#   Q.2)       
'''
Given a positive integer n, count the number of digits in n that divide n evenly (i.e., without leaving a remainder). Return the total number of such digits.

A digit d of n divides n evenly if the remainder when n is divided by d is 0 (n % d == 0).
Digits of n should be checked individually. If a digit is 0, it should be ignored because division by 0 is undefined.
'''

def evenlydivide(n):
    count =0
    num = n
    while n>0:
        a = n%10
        if (a != 0 and num%a == 0):
            count += 1
        n= n//10
    return count


n = int(input("Digit = "))
print(digits(n))
print(evenlydivide(n))
