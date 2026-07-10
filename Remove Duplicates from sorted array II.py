from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 2

        for i in range(2, len(nums)):
            if nums[i] != nums[k - 2]:
                nums[k] = nums[i]
                k += 1

        return k


# Main part
nums = list(map(int, input("Enter sorted array elements: ").split()))

if len(nums) <= 2:
    k = len(nums)
else:
    sol = Solution()
    k = sol.removeDuplicates(nums)

print("Length after removing duplicates:", k)
print("Modified array:", nums[:k])