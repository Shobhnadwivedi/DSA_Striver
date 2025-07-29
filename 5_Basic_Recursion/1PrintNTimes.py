#        RECURSION 
'''
It is a phenomenon when a function calls itself indefinitely until a specified condition is fulfilled.
'''

#   Q.1)    A Function to print N numbers . let n= 3.
cnt = 1       # GLOBAL VARIABLE
def f(n):
    global cnt
    if cnt == n+1 :     #  agr 1st line(global cnt) nhi likhte to python considers cnt inside the function as LOCAL VARIABLE
        return
    else:              # Then error comes - " cannot access local variable 'cnt' where it is not associated with a value "
        print (cnt, end = ' ')    # mtlb cnt naamak local variable ki koi value assign nhi hui....cnt =0 to global variable h
        cnt+=1
        f(n)


f(10)
print()

#

class Solution:    
    def printNos(self,n, cnt=1): # here in a class, function me hi global variable define kr diya

        if cnt == n+1 :
            return
        else:
            print (cnt, end = ' ')
            cnt+=1
            self.printNos(n,cnt)    # self. lagana is important

result = Solution()
result.printNos(8)