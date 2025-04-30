# 1. binary search

```
FUNCTION binary_search1(arr[], low, high, x):
    WHILE low <= high:  # 持续搜索直到搜索区间无效
        mid = (low + high) >> 1  # 位运算计算中间索引 (等价于/2但更快)
        
        IF arr[mid] == x:        # 找到目标元素
            PRINT "Found at index " + mid
            RETURE
        ELSE IF arr[mid] < x:    # 目标在右半区
            low = mid + 1        # 调整左边界
        ELSE:                    # 目标在左半区
            high = mid - 1       # 调整右边界
    END WHILE
    PRINT "Element not found"    # 搜索空间耗尽未找到
RETURE

# 时间复杂度 O(log n)，空间复杂度 O(1)

```

# 2. Large integer multiplication

```
# 大整数加法
FUNCTION add(num1, num2):
    carry = 0                  # 进位初始化
    result = ""                # 结果字符串
    i = len(num1)-1            # 从个位开始处理num1
    j = len(num2)-1            # 从个位开始处理num2
    
    WHILE i >=0 OR j >=0 OR carry >0:
        digit1 = num1[i] - '0' if i >=0 else 0  # 获取当前位数字
        digit2 = num2[j] - '0' if j >=0 else 0
        
        sum = digit1 + digit2 + carry
        carry = sum // 10       # 计算进位
        result = str(sum % 10) + result  # 注意结果从高位插入
        
        i -= 1; j -= 1          # 移动指针
RETURN result
# 结果拼接顺序是反向的，最后需要处理剩余进位

# 大整数减法
FUNCTION subtract(num1, num2):
    borrow = 0                 # 借位初始化
    result = ""
    i = len(num1)-1            # 从个位开始处理
    j = len(num2)-1
    
    WHILE i >=0:
        digit1 = num1[i] - '0'
        digit2 = num2[j] - '0' if j >=0 else 0
        
        diff = digit1 - digit2 - borrow
        IF diff <0:            # 需要借位
            diff +=10
            borrow =1
        ELSE:
            borrow =0
            
        result = str(diff) + result
        i -=1; j -=1
    
    # 去除前导零
    result = result.lstrip('0')
RETURN "0" if result == "" else result

# 大整数乘法
FUNCTION multiply(num1, num2):
    IF num1=="0" OR num2=="0": RETURN "0"      # 边界条件处理
    IF num1=="1": RETURN num2
    IF num2=="1": RETURN num1
    
    # 小数字直接计算
    IF len(num1)<=2 OR len(num2)<=2:
        RETURN str(int(num1)*int(num2))
    
    # 分割数字为高低位
    mid = min(len(num1), len(num2)) // 2
    high1 = num1[:-mid] or "0"   # 高位部分
    low1 = num1[-mid:] 
    high2 = num2[:-mid] or "0"
    low2 = num2[-mid:]
    
    # 递归计算三个乘积
    z0 = multiply(high1, high2)            # 高位相乘
    z1 = multiply(low1, low2)              # 低位相乘
    sum1 = add(high1, low1)                # 高低位和
    sum2 = add(high2, low2)
    z2 = multiply(sum1, sum2)              # 和的乘积
    
    # 组合计算结果
    z3 = subtract(subtract(z2, z1), z0)    # z2 - z1 - z0
    part0 = z0 + "0"*(2*mid)               # 左移2mid位
    part1 = z3 + "0"*mid                   # 左移mid位
RETURN add(add(part0, part1), z1)  
# 时间复杂度O(n^log3)
```



# 3. Merge sort

```
# 归并排序主函数
FUNCTION mergeSort(nums[], left, right):
    IF left >= right:                     # 递归终止条件（子数组长度为1）
        RETURN
    
    mid = left + (right - left) // 2      # 计算中点（避免整数溢出）
    mergeSort(nums, left, mid)            # 递归排序左半部 [left, mid]
    mergeSort(nums, mid+1, right)         # 递归排序右半部 [mid+1, right]
    merge(nums, left, mid, right)         # 合并两个有序子数组

# 合并两个有序子数组
FUNCTION merge(nums[], left, mid, right):

    tmp = new array of size (right - left + 1)
    
    i = left      # 左子数组起始指针 [left, mid]
    j = mid + 1   # 右子数组起始指针 [mid+1, right]
    k = 0         # 临时数组指针
    
    # 合并操作：当两个子数组都有元素时
    WHILE i <= mid AND j <= right:
        IF nums[i] <= nums[j]:
            tmp[k] = nums[i]
            i += 1
        ELSE:
            tmp[k] = nums[j]
            j += 1
        k += 1
    
    # 处理左子数组剩余元素
    WHILE i <= mid:
        tmp[k] = nums[i]
        i += 1; k += 1
    
    # 处理右子数组剩余元素
    WHILE j <= right:
        tmp[k] = nums[j]
        j += 1; k += 1
    
    # 将合并结果拷贝回原数组
    FOR m FROM 0 TO k-1:
        nums[left + m] = tmp[m]

# 时间复杂度：O(n log n)
# 空间复杂度：O(n) 需要临时数组
# 稳定排序：当元素相等时优先取左子数组元素

```



# 4. Quick sort

```
# 快速排序主函数
FUNCTION quick_sort(q[], l, r):
    IF l >= r: RETURN
    
    # 初始化双指针和基准值
    i = l - 1
    j = r + 1
    x = q[(l + r) >> 1]                 # 选择中间元素为基准（位运算代替除法）
    
    WHILE True:                         
        REPEAT i += 1 UNTIL q[i] >= x    # 找左边第一个 >=x 的元素
        REPEAT j -= 1 UNTIL q[j] <= x    # 找右边第一个 <=x 的元素
        IF i < j:                        # 当指针未交叉时交换元素
            swap(q[i], q[j])
        ELSE:                            # 分区完成退出循环
            BREAK
    
    # 递归处理子区间
    quick_sort(q, l, j)                 # 处理左半区 [l, j]
    quick_sort(q, j + 1, r)             # 处理右半区 [j+1, r]

# 时间复杂度：平均O(n log n)，最坏O(n²)（取决于基准选择）
# 空间复杂度：O(log n) 递归栈深度
# 不稳定排序：元素交换可能改变相等元素的顺序
```



# 5. Linear time selection algorithm

```
# 分区函数（Hoare分区方案变体）
FUNCTION partition(a[], left, right, pivot) -> int:
    i = left                      # 左扫描指针 [关键注释：初始化为左边界]
    j = right                     # 右扫描指针 [初始化为右边界]
    
    WHILE i <= j:                 # 扫描直到指针交叉
        WHILE a[i] < pivot:       # 找左边第一个 >= pivot的元素
            i += 1
        WHILE a[j] > pivot:       # 找右边第一个 <= pivot的元素
            j -= 1
        
        IF i < j:                 # 当指针未交叉时交换元素
            swap(a[i], a[j])
        ELSE:                     # 分区完成返回分界点
            RETURN j              # [注意] j是最终右分区的右边界
    RETURN -1                     # 无效情况（通常不会发生）

# 快速选择算法（寻找第k小元素）
FUNCTION quickSelect(a[], left, right, k) -> int:
    IF left == right:             # 递归终止条件：只剩一个元素
        RETURN a[left]
    
    # 选择中间元素作为基准（可能溢出，建议用left + (right-left)/2）
    pivot = a[(left + right) >> 1] 
    
    # 执行分区操作 [关键注释：pos是分界点索引]
    pos = partition(a, left, right, pivot)
    
    IF pos == k - 1:             # 找到第k小元素
        RETURN a[pos]
    ELIF pos > k - 1:            # 目标在左分区 [left, pos-1]
        RETURN quickSelect(a, left, pos-1, k)
    ELSE:                        # 目标在右分区 [pos+1, right]
        RETURN quickSelect(a, pos+1, right, k)

# 时间复杂度：平均O(n)，最坏O(n²)（依赖pivot选择）
# 空间复杂度：O(1) 原地操作（递归栈深度O(log n)）
```





# 6. Closest point pair algorithm



