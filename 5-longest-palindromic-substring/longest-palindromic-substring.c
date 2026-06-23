#include <stdlib.h>
#include <string.h>

// Expands around center and returns length of palindrome found
static int expandAroundCenter(const char *s, int left, int right) {
    while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
        left--;
        right++;
    }
    // Length = (right - 1) - (left + 1) + 1 = right - left - 1
    return right - left - 1;
}

char *longestPalindrome(char *s) {
    int n = strlen(s);
    if (n < 2) {
        char *res = (char *)malloc(n + 1);
        strcpy(res, s);
        return res;
    }

    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        // Odd-length palindrome centered at i
        int len1 = expandAroundCenter(s, i, i);
        // Even-length palindrome centered between i and i+1
        int len2 = expandAroundCenter(s, i, i + 1);

        int len = len1 > len2 ? len1 : len2;
        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }

    char *result = (char *)malloc(maxLen + 1);
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
}