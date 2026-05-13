def findTwoDuplicates(nums):
    duplicates = []
    for x in nums:
        index = abs(x) - 1
        if nums[index] <= 0:
            if(nums[index]!=0):
                duplicates.append(abs(x))
            nums[index]=0
        else:
            nums[index] = -nums[index]  # ভিজিট করা হলে নেগেটিভ করে দিন
    return duplicates

print(findTwoDuplicates([7,5,1,1, 2,2, 2, 1, 3, 4, 5, 6,3])) # Output: []