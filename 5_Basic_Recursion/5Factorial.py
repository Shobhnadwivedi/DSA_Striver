#  Factorial of N  =  1*2*3...*N    

#   1.  FUNCTIONAL WAY =   

def fac(n):
    if(n==0):
        return 1
    return n* fac(n-1)


print(fac(6))


#   2.   PARAMETERIZED WAY  = 
def factorial(n,prod=1):
    if(n==0):
        print(prod)
        return 1
                                #   prod = prod * n             
    factorial(n-1, prod*n)      #   n =n-1 
                                #   factorial(n, prod)

factorial(5)
