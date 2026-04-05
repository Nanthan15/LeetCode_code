class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        maxi = float("-inf")
        sums = 0
        for num in nums:
            sums = max(num, num+sums)
            maxi = max(sums, maxi)
        return maxi





        
        