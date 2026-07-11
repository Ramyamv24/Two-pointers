class Solution:
    def nextPermutation(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)

        # Step 1: Find the first decreasing element from the right (pivot)
        i = n - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1

        # Step 2: Find the rightmost element greater than the pivot and swap
        if i >= 0:
            j = n - 1
            while nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]

        # Step 3: Reverse the suffix
        left, right = i + 1, n - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1


# Main
if __name__ == "__main__":
    nums = list(map(int, input("Enter elements separated by space: ").split()))

    sol = Solution()
    sol.nextPermutation(nums)

    print("Next Permutation:", nums)