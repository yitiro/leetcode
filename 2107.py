class Solution:
    # https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/
    # 2107
    def shareCandies(self, candies: List[int], k: int) -> int:
        # if k < 2:
        #     return min(len(set(candies)), len(candies) - k)
        if k == 0:
            return len(set(candies))
        from collections import defaultdict
        keeps = defaultdict(int)
        for i in range(k, len(candies)):
            keeps[candies[i]] += 1
        
        num_flavor = len(keeps.keys())
        max_flavor = num_flavor
      
        for i in range(k, len(candies)):
            if candies[i] == candies[i - k]:
                continue
            keeps[candies[i]] -= 1
            keeps[candies[i - k]] += 1
            if keeps[candies[i]] == 0:
                num_flavor -= 1
            if keeps[candies[i - k]] == 1:
                num_flavor += 1
                max_flavor = max(num_flavor, max_flavor)
            
            
        return max_flavor