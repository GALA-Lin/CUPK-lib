def calculate_letter_score():
    """生成字母得分字典"""
    return {chr(i + 96): i for i in range(1, 27)}

def get_prefix_score(prefix):
    """返回前缀的得分"""
    scores = {
        "l": 10,
        "la": 20,
        "lan": 30,
        "lanq": 40,
        "lanqi": 50,
        "lanqio": 60,
        "lanqio": 70,
        "lanqiobe": 80,
    }
    return scores.get(prefix, 0)

def find_max_substring_score(s):
    letter_score = calculate_letter_score()
    prefixes = ["l", "la", "lan", "lanq", "lanqi", "lanqio", "lanqiobe"]
    
    max_score = 0
    best_substring = ""

    n = len(s)
    
    for start in range(n):
        substring = ""
        unique_letters = set()

        for end in range(start, n):
            current_char = s[end]
            if current_char in unique_letters:
                break  # 发现重复字母，停止
            
            unique_letters.add(current_char)
            substring += current_char
            
            current_score = sum(letter_score[c] for c in substring)
            
            # 检查前缀
            current_prefix_score = 0
            for prefix in prefixes:
                if substring.startswith(prefix):
                    current_prefix_score = get_prefix_score(prefix)
            
            total_score = current_score + current_prefix_score
            
            # 更新最大得分和最佳子串
            if total_score > max_score:
                max_score = total_score
                best_substring = substring

    return best_substring

# 输入处理
n = int(input().strip())
s = input().strip()

result = find_max_substring_score(s)

# 输出结果
print(result)
