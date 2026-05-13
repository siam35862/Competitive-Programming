def findduplicates(nums):
    t=nums[1]
    h=nums[1]
    while True:
        t=nums[t]
        h=nums[nums[h]]
        if h==t:
            break
        
  
    p1=nums[1]
    p2=t
    while p1!=p2:
      
        p1=nums[p1]
        p2=nums[p2]

    return p1
    
print(findduplicates([1,2,4,2,3,5]))