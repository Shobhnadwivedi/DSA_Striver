def euclidean(a,b):

    #  jb tak koi ek zero na ho jaye
    while(a>0 and b>0):
        if(a>b):  a = a%b 

        else: b = b%a 
    
    # agr a zero ho jaye then gcd = b
    if(a==0): return b
    # vrna b==0 hoga to return a
    return a


print(euclidean(798,7))