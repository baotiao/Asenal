#!/usr/bin/env python
def monkey_trouble(a_smile, b_smile):
    if a_smile == True and b_smile == True:
        return True
    if a_smile == False and b_smile == False:
        return True
    return False
def sum_double(a, b):
    if a == b:
        return (a + b) * 2
    return a + b
def diff21(n):
    if n > 21:
        return (n - 21) * 2
    return 21 - n
def parrot_trouble(talking, hour):
    return (talking and (hour < 7 or hour > 20))
def makes10(a, b):
    if a == 10 or b == 10 or a + b == 10:
        return True
    return False
def near_hundred(n):
    if abs(n - 100) <= 10 or abs(n-200) <= 10:
        return True
    return False
def same_first_last(nums):
    n = len(nums)
    if n >= 1 and nums[0] == nums[n-1]:
        return True
    return False
def make_pi():
    l = [3, 1, 4]
    return l
def common_end(a, b):
    la = len(a)
    lb = len(b)
    if a[0] == b[0] or a[la-1] == b[lb-1]:
        return True
    return False
def sum3(nums):
    return sum(nums)

def count_evens(nums):
    cnt = 0
    for num in nums:
        if num % 2 == 0:
            cnt += 1
    return cnt
def big_diff(nums):
    maxn = 0
    minn = 10000
    for num in nums:
        maxn = max(maxn, num)
        minn = min(minn, num)
    return maxn - minn

def centered_average(nums):
    maxn = 0
    minn = 10000
    for num in nums:
        maxn = max(maxn, num)
        minn = min(minn, num)
    sum_num = sum(nums) - maxn - minn
    n = len(nums)
    n -= 2
    return sum_num / n
    
