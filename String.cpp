#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;

bool isAcronym(const string& s, const vector<string>& words) {
	if (s.size() != words.size()) return false;
	for (size_t i = 0; i < words.size(); i++)
		if (words[i].empty() || s[i] != words[i][0]) return false;
	return true;
}

bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        while (left < right && str[left] == ' ') {
            left++;
        }
        while (left < right && str[right] == ' ') {
            right--;
        }
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
	vector<int> lettersCount(26, 0);
	for (size_t i = 0; i < letters.size(); i++) {
		lettersCount[letters[i] - 'a']++;
	}

	int maxScore = 0;
	int n = words.size();
	for (int mask = 0; mask < (1 << n); mask++) {
		vector<int> currentCount(26, 0);
		int currentScore = 0;
		bool isValid = true;

		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				for (size_t j = 0; j < words.size(); j++) {
					char c = words[i][j];
					currentCount[c - 'a']++;
					currentScore += score[c - 'a'];

					if (currentCount[c - 'a'] > lettersCount[c - 'a']) {
						isValid = false;
						break;
					}
				}
				if (!isValid) break;
			}
		}
		if (isValid) maxScore = max(maxScore, currentScore);
	}
	return maxScore;
}

int main() {
    while (true) {
        cout << "\nSelect a function:\n"
            << "1. Check acronym\n"
            << "2. Check palindrome\n"
            << "3. Calc word score\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();


        switch (choice) {
        case 1: {
            cout << " abbr: ";
            string abbr;
            cin >> abbr;
            cin.ignore();
            cout << " the words: ";
            string input;
            getline(cin, input);
            istringstream iss(input);
            vector<string> words(istream_iterator<string>{iss}, istream_iterator<string>());
            cout << "Result: " << (isAcronym(abbr, words) ? "It is an acronym." : "It is not an acronym.") << endl;
            break;
        }
        case 2: {
            string input;
            cout << " string: ";
            getline(cin, input);
            if (isPalindrome(input)) {
                cout << "The string is a palindrome." << endl;
            }
            else {
                cout << "The string is not a palindrome." << endl;
            }
            break;
        }
        case 3: {
            int wordCount;
            cout << " the number of words: ";
            cin >> wordCount;
            cin.ignore();
            vector<string> words(wordCount);
            cout << " each word on a new line: " << endl;
            for (int i = 0; i < wordCount; ++i) {
                getline(cin, words[i]);
            }
            int letterCount;
            cout << " the number of letters: ";
            cin >> letterCount;
            cin.ignore();
            vector<char> letters(letterCount);
            cout << " each letter on a new line: " << endl;
            for (int i = 0; i < letterCount; ++i) {
                cin >> letters[i];
            }
            vector<int> score(26);
            cout << " the scores for the 26 letters, one score per line: " << endl;
            for (int i = 0; i < 26; ++i) {
                cin >> score[i];
            }
            int result = maxScoreWords(words, letters, score);
            cout << "The maximum score is: " << result << endl;
            break;
        }
        case 0:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}