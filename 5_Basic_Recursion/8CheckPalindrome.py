'''
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 
Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
'''

#  SOLUTIONS which were not accepted for few cases jahan bohot lambi string provide ki thi to time limit exceeded

s= 'tenet'
class Solution1:                                       #  single pointer/variable
    def isPalindrome(self, s: str, i=0) -> bool:
        cleaned_s = "".join(c.lower() for c in s if c.isalnum())               #    cleaned_s = re.sub(r'[^a-zA-Z0-9]', '', s)
                                                                               #    cleaned_s = re.sub(r'[^a-zA-Z0-9]', '', s).lower()
        if(i>=(len(cleaned_s))/2):
            return True
        if(cleaned_s[i] != cleaned_s[len(cleaned_s)-i-1]):
            return False  
        return self.isPalindrome(s,i+1)

'''
cleaned_s = "".join(c.lower() for c in s if c.isalnum())        
  what this line does? -   It removes non-alphanumeric characters from s and converts all letters to lowercase.

c.lower():
    c represents each character in the string s.
    lower() converts uppercase letters (A-Z) to lowercase (a-z).
    If c is already lowercase or a number, it remains unchanged.
for c in s:
    This iterates over every character in s.
    Example:     If s = "A1!bC", it processes "A", "1", "!", "b", "C" one by one.
if c.isalnum():
    Filters out non-alphanumeric characters.
    isalnum() returns True only if c is a letter (A-Z or a-z) or a digit (0-9).
    Spaces, punctuation (!@#), and special symbols are ignored.
"".join(...):
    It combines all filtered characters into a new string.
    The "" (empty string) means we join them without spaces.
    Example:
        "".join(["a", "b", "c"])  # Output: "abc"

'''

#                 ACCEPTED SOLUTION 

class Solution:
    def isPalindrome(self, s: str, left=0, right=None) -> bool:
        if right is None:
            s = "".join(c.lower() for c in s if c.isalnum())
            right = len(s) - 1  # Set right pointer after cleaning

        # Base case: if pointers cross, it's a palindrome
        if left >= right:
            return True

        # Compare characters
        if s[left] != s[right]:
            return False

        # Recursive call
        return self.isPalindrome(s, left + 1, right - 1)
    

#                   DIFFERENCE BETWEEN THEM 
'''
  1st CODE =  This creates a new string every time isPalindrome(s, i+1) is called.
              Since Python strings are immutable, every recursion step creates a new copy.
              If s.length = n, this repeats O(n) times, leading to O(n²) time complexity.

  2nd CODE =  Cleans the string once before recursion starts.
              Uses the original string s with indices instead of recreating a new string.
              Time Complexity: O(n) (single pass through s).
              jab tk right=none tabhi clean hoga string and then right will be altered.
'''