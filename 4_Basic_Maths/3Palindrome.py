#       Q.1) 
'''
Given an integer x, return true if x is a palindrome, and false otherwise.
'''
def palindrome(x):
    if x>=0 : 
        num = 0
        orig_num = x
        while x>0:
            a = x%10     
            x //= 10
            num = (num*10) +a

        if orig_num==num:
            return True
        else: 
            return False
    else: return False

print(palindrome(-2))