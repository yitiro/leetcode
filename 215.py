# 215. Kth Largest Element in an Array
# https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def findKthSmallestMain(nums, lo, hi, k):
            if lo >= hi:
                return nums[lo]
            elif hi - lo < 15:
                return sorted(nums[lo:hi+1])[k-lo]
            lt, gt = lo, hi
            
            pivot_idx = getMedianOf3(nums, lo, hi)
            pivot = nums[pivot_idx]
            myswap(nums, lo, pivot_idx)
            
            i = lo
            
            while i <= gt:
                cmp = nums[i] - pivot
                if cmp < 0 :
                    myswap(nums, lt, i)
                    lt += 1
                    i += 1
                elif cmp > 0:
                    myswap(nums, i, gt)
                    gt -= 1
                else:
                    i+=1
            
            # print("---- pivot:", pivot)
            # print(lt, gt, nums[lt], nums[gt], k)
            # print(nums)
            if k < lt:
                return findKthSmallestMain(nums, lo, lt-1, k)
            elif k > gt:
                return findKthSmallestMain(nums, gt+1, hi, k)
            else:
                return pivot
            
            
        def getMedianOf3(nums, lo, high):
            candidates = [lo, high, lo + (high-lo)//2]
            candidates.sort(key=lambda i: nums[i])
            return candidates[1]
        def myswap(nums, i, j):
            nums[i], nums[j] = nums[j], nums[i]
        # nums.sort()
        # return nums[len(nums) - k]
        random.shuffle(nums)
        return findKthSmallestMain(nums, 0, len(nums)-1, len(nums) - k)
        