# https://leetcode.com/problems/smallest-value-of-the-rearranged-number/
# 2165
class Solution:
    def smallestNumber(self, num: int) -> int:
        if num > 0:
            digits = [None for _ in range(16)]
            num_zero = 0
            i = 0
            while(num > 0):
                m = num % 10
                num = num // 10
                if m == 0:
                    num_zero += 1
                else:
                    digits[i] = "%d" % m
                    i += 1
            digits = sorted(digits[:i])
            return int(digits[0] + "0" * num_zero + "".join(digits[1:]))
        elif num < 0:
            num = -num
            digits = [None for _ in range(16)]
            num_zero = 0
            i = 0
            while(num > 0):
                m = num % 10
                num = num // 10
                digits[i] = "%d" % m
                i+= 1
            digits = sorted(digits[0:i], reverse=True)
            return -int("".join(digits))
            
        else:
            return 0