#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

/**
 * Finds the length of the longest substring without repeating characters.
 * Time Complexity: O(n) - where n is the length of the string.
 * Space Complexity: O(min(m, n)) - where m is the size of the character set.
 */
int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<char, int> lastSeenIndex;
    int maxLength = 0;
    int left = 0; // Left pointer of the sliding window

    for (int right = 0; right < s.length(); ++right) {
        char currentChar = s[right];

        // If the character was seen before and is within the current window, move the left pointer
        if (lastSeenIndex.find(currentChar) != lastSeenIndex.end() && lastSeenIndex[currentChar] >= left) {
            left = lastSeenIndex[currentChar] + 1;
        }

        // Update the last seen position of the character
        lastSeenIndex[currentChar] = right;

        // Calculate maximum length so far
        maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    std::string testStr = "abcabcbb";
    int result = lengthOfLongestSubstring(testStr);

    std::cout << "Input String: \"" << testStr << "\"\n";
    std::cout << "Length of Longest Non-Repeating Substring: " << result << std::endl;

    return 0;
}