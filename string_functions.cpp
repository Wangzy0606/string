// 包含之前定义的头文件，获取所需的库和类型
#include "../include/string_headers.h"

/**
 * 判断一个字符串是否是一组单词的首字母缩写
 * @param s 待判断的字符串
 * @param words 单词组
 * @return 如果 s 是 words 的首字母缩写返回 true，否则返回 false
 */
bool isAcronym(const std::string& s, const std::vector<std::string>& words) {
    // 若字符串 s 的长度和单词组的数量不相等，说明 s 不可能是首字母缩写，返回 false
    if (s.size() != words.size()) return false;
    // 遍历单词组中的每个单词
    for (std::size_t i = 0; i < words.size(); i++) {
        // 若单词为空或者 s 对应位置的字符与单词的首字母不相同，返回 false
        if (words[i].empty() || s[i] != words[i][0]) return false;
    }
    // 若以上条件都不满足，说明 s 是首字母缩写，返回 true
    return true;
}

/**
 * 判断一个字符串是否是回文串（忽略大小写和空白字符）
 * @param str 待判断的字符串
 * @return 如果是回文串返回 true，否则返回 false
 */
bool isPalindrome(const std::string& str) {
    // 初始化左指针，指向字符串开头
    int left = 0;
    // 初始化右指针，指向字符串末尾
    int right = str.length() - 1;
    // 只要左指针小于右指针，就继续循环比较
    while (left < right) {
        // 跳过字符串开头的空白字符
        while (left < right && std::isspace(str[left])) {
            left++;
        }
        // 跳过字符串末尾的空白字符
        while (left < right && std::isspace(str[right])) {
            right--;
        }
        // 若忽略大小写后，左右指针指向的字符不相等，说明不是回文串，返回 false
        if (std::tolower(str[left]) != std::tolower(str[right])) {
            return false;
        }
        // 左指针右移一位
        left++;
        // 右指针左移一位
        right--;
    }
    // 若循环结束都未返回 false，说明是回文串，返回 true
    return true;
}

/**
 * 计算使用给定字母能组成单词的最大得分
 * @param words 单词组
 * @param letters 可用的字母
 * @param score 每个字母对应的得分
 * @return 能组成单词的最大得分
 */
int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {
    // 初始化一个长度为 26 的向量，用于记录每个字母的可用数量，初始值都为 0
    std::vector<int> lettersCount(26, 0);
    // 遍历可用字母，统计每个字母的数量
    for (std::size_t i = 0; i < letters.size(); i++) {
        // 将字母转换为对应的索引（a 对应 0，b 对应 1，以此类推），并增加该索引位置的计数
        lettersCount[letters[i] - 'a']++;
    }

    // 初始化最大得分，初始值为 0
    int maxScore = 0;
    // 获取单词组的数量
    int n = words.size();
    // 通过位运算枚举所有可能的单词组合，2^n 种组合
    for (int mask = 0; mask < (1 << n); mask++) {
        // 初始化一个长度为 26 的向量，用于记录当前组合中每个字母的使用数量，初始值都为 0
        std::vector<int> currentCount(26, 0);
        // 初始化当前组合的得分，初始值为 0
        int currentScore = 0;
        // 标记当前组合是否有效，初始值为 true
        bool isValid = true;

        // 遍历每个单词
        for (int i = 0; i < n; i++) {
            // 若当前位为 1，表示选择了该单词
            if (mask & (1 << i)) {
                // 遍历该单词的每个字符
                for (std::size_t j = 0; j < words[i].size(); j++) {
                    // 获取当前字符
                    char c = words[i][j];
                    // 增加当前字符的使用数量
                    currentCount[c - 'a']++;
                    // 累加当前字符的得分
                    currentScore += score[c - 'a'];

                    // 若当前字符的使用数量超过了可用数量，说明该组合无效，标记为 false 并跳出循环
                    if (currentCount[c - 'a'] > lettersCount[c - 'a']) {
                        isValid = false;
                        break;
                    }
                }
                // 若该组合无效，跳出内层循环
                if (!isValid) break;
            }
        }
        // 若该组合有效，更新最大得分
        if (isValid) maxScore = std::max(maxScore, currentScore);
    }
    // 返回最大得分
    return maxScore;
}    