class Solution(object):
    def sortColors(self, nums):
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] > nums[j]:
                    nums[i], nums[j] = nums[j], nums[i]


# Main part
nums = list(map(int, input("Enter the numbers: ").split()))

obj = Solution()
obj.sortColors(nums)

print("Sorted array:", nums)