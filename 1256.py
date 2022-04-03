# https://leetcode.com/problems/encode-number/
# 1256
class Solution:
    def encode(self, num: int) -> str:
        import math
        if num == 0:
            return ""
        
        num += 1
        num_digits = int(math.log2(num))
        diff = num - (1 << num_digits)

        
        return f'{diff:0{num_digits}b}'