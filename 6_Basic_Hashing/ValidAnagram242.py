from collections import defaultdict               # defaultdict sets initial value to 0 like in an unordered map


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        if len(s) !=  len(t):
            return False
        
        h_dict_s = defaultdict(int)
        h_dict_t = defaultdict(int)        
        
        # storing frequency of each letter of s in h_dict_s
        for elem in s:
            h_dict_s[elem]+=1

        # storing frequency of each letter of t in h_dict_t
        for elem in t:
            h_dict_t[elem]+=1

        # check if both dictionaries are same
        return h_dict_s == h_dict_t
            
        


sol = Solution()
res =sol.isAnagram('anagram','nagaram')
print(res)
