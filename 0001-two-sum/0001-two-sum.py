class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        item = {}

        for ind, val in enumerate(nums):
            remain = target - val
            if remain in item:
                return[item[remain], ind]
            item[val] =  ind
        return []        
        