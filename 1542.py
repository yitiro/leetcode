# https://leetcode.com/problems/find-longest-awesome-substring/
# 1542
class Solution:
    def longestAwesome(self, s: str) -> int:
        status = 0
        record = {0:0}
        res = 1
        for i in range(len(s)):
            digit = int(s[i])
            status = status ^ (1 << digit)
            
            if status in record:
                res = max(res, i - record[status] + 1)
            else:
                record[status] = i + 1
            for change in range(10):
                possible_status = status ^ (1 << change)
                if possible_status in record:
                    res = max(res, i - record[possible_status] + 1)
        return res