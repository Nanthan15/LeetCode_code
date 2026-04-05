class Solution:
    @staticmethod
    def majorityElement(nums: List[int]) -> int:
        majority = len(nums) // 2
        cnt= 0
        el = 0
        for num in nums :
            if cnt == 0:
                el = num
                cnt+=1
            elif num != el :
                cnt -=1
            else:
                cnt+=1

        return el                           