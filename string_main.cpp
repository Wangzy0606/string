// 包含之前定义的头文件，获取所需的库和类型
#include "../include/string_headers.h"

// 声明 isAcronym 函数，用于判断一个字符串是否是一组单词的首字母缩写
bool isAcronym(const std::string& s, const std::vector<std::string>& words);
// 声明 isPalindrome 函数，用于判断一个字符串是否是回文串
bool isPalindrome(const std::string& str);
// 声明 maxScoreWords 函数，用于计算使用给定字母能组成单词的最大得分
int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score);

// 主函数，程序的入口点
int main() {
    // 进入一个无限循环，直到用户选择退出
    while (true) {
        // 输出菜单选项，提示用户选择功能
        std::cout << "\nSelect a function:\n"
                  << "1. Check acronym\n"
                  << "2. Check palindrome\n"
                  << "3. Calc word score\n"
                  << "0. Exit\n"
                  << "Enter your choice: ";
        // 用于存储用户的选择
        int choice;
        // 读取用户输入的选择
        std::cin >> choice;
        // 忽略输入缓冲区中的换行符，避免影响后续输入
        std::cin.ignore();

        // 根据用户的选择执行相应的操作
        switch (choice) {
        case 1: {
            // 提示用户输入缩写
            std::cout << " abbr: ";
            // 用于存储用户输入的缩写
            std::string abbr;
            // 读取用户输入的缩写
            std::cin >> abbr;
            // 忽略输入缓冲区中的换行符
            std::cin.ignore();
            // 提示用户输入单词组
            std::cout << " the words: ";
            // 用于存储用户输入的一行字符串
            std::string input;
            // 读取用户输入的一行字符串，包含多个单词
            std::getline(std::cin, input);
            // 使用字符串流将输入的字符串分割成多个单词
            std::istringstream iss(input);
            // 将分割后的单词存储到向量中
            std::vector<std::string> words(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
            // 调用 isAcronym 函数判断缩写是否是单词组的首字母缩写，并输出结果
            std::cout << "Result: " << (isAcronym(abbr, words) ? "It is an acronym." : "It is not an acronym.") << std::endl;
            // 跳出当前 case 语句
            break;
        }
        case 2: {
            // 提示用户输入字符串
            std::cout << " string: ";
            // 用于存储用户输入的字符串
            std::string input;
            // 读取用户输入的一行字符串
            std::getline(std::cin, input);
            // 调用 isPalindrome 函数判断字符串是否是回文串，并输出结果
            if (isPalindrome(input)) {
                std::cout << "The string is a palindrome." << std::endl;
            } else {
                std::cout << "The string is not a palindrome." << std::endl;
            }
            // 跳出当前 case 语句
            break;
        }
        case 3: {
            // 提示用户输入单词的数量
            std::cout << " the number of words: ";
            // 用于存储用户输入的单词数量
            int wordCount;
            // 读取用户输入的单词数量
            std::cin >> wordCount;
            // 忽略输入缓冲区中的换行符
            std::cin.ignore();
            // 初始化一个向量，用于存储用户输入的单词，大小为 wordCount
            std::vector<std::string> words(wordCount);
            // 提示用户逐行输入每个单词
            std::cout << " each word on a new line: " << std::endl;
            // 循环读取用户输入的每个单词
            for (int i = 0; i < wordCount; ++i) {
                std::getline(std::cin, words[i]);
            }
            // 提示用户输入字母的数量
            std::cout << " the number of letters: ";
            // 用于存储用户输入的字母数量
            int letterCount;
            // 读取用户输入的字母数量
            std::cin >> letterCount;
            // 忽略输入缓冲区中的换行符
            std::cin.ignore();
            // 初始化一个向量，用于存储用户输入的字母，大小为 letterCount
            std::vector<char> letters(letterCount);
            // 提示用户逐行输入每个字母
            std::cout << " each letter on a new line: " << std::endl;
            // 循环读取用户输入的每个字母
            for (int i = 0; i < letterCount; ++i) {
                std::cin >> letters[i];
            }
            // 初始化一个长度为 26 的向量，用于存储每个字母的得分
            std::vector<int> score(26);
            // 提示用户逐行输入 26 个字母的得分
            std::cout << " the scores for the 26 letters, one score per line: " << std::endl;
            // 循环读取用户输入的每个字母的得分
            for (int i = 0; i < 26; ++i) {
                std::cin >> score[i];
            }
            // 调用 maxScoreWords 函数计算最大得分
            int result = maxScoreWords(words, letters, score);
            // 输出计算得到的最大得分
            std::cout << "The maximum score is: " << result << std::endl;
            // 跳出当前 case 语句
            break;
        }
        case 0:
            // 提示用户程序即将退出
            std::cout << "Exiting the program." << std::endl;
            // 返回 0 表示程序正常结束
            return 0;
        default:
            // 若用户输入的选择无效，提示用户重新输入
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}    