#      Reverse a given array using   -    RECURSION       

#   1.   using 2 pointers/variables  
arr =[2,5,6,7,3,1]
class Solut :
    
    def reverseArray(self,l,r):
        
        if(l>=r):
            return 
        else:
            arr[l], arr[r] = arr[r] , arr[l]
            self.reverseArray(l+1, r-1)


sol = Solut()
sol.reverseArray(0,len(arr)-1)
print(arr)


#   2.   using 1 pointer/variable   =   r ko "l" ke hi terms me likhkar
class Solution:
   
    def reverseArray(self,arr, i=0):
        
        if(i>=len(arr)/2):
            return 
        else:
            arr[i], arr[len(arr)-i-1] = arr[len(arr)-i-1] , arr[i]
            self.reverseArray(arr,i+1)


sol = Solution()
sol.reverseArray(arr)
print(arr)