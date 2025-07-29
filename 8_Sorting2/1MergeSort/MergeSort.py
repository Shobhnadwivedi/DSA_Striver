def merge(arr , l, mid, h):
    temp=[]
    left=l      # agr left use na krke l hi use karenge to l ki value change hogi aage aane wale 
    r =mid+1    # operations me aur fir temp se arr me add krte time l ki value galat hogi
    while(left<=mid and r<=h):
        if(arr[left]<=arr[r]):
            temp.append(arr[left])
            left+=1

        else:
            temp.append(arr[r])
            r+=1

    while(left<=mid):
        temp.append(arr[left])
        left+=1

    while(r<=h):
        temp.append(arr[r])
        r+=1

    # now adding elements of temp to actual arr
    for i in range (l,h+1):
        arr[i]= temp[i-l]



def mergeSort(arr,l,h):
    mid = (l+h)//2

    if(l>=h):
        return
    
    mergeSort(arr,l,mid)
    mergeSort(arr,mid+1,h)
    merge(arr,l,mid,h)






arr  = [3,1,2,4,1,5,6,2,4]

mergeSort(arr,0,len(arr)-1)
print(arr)