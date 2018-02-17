class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (str == NULL || pattern == NULL)
            return false;
        return matchRecursively(str, pattern);
    }
    
    bool matchRecursively(char* str, char* pattern) {
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
        if (*(pattern+1)=='*') {
            if (*pattern == *str || (*pattern=='.' && *str!='\0')) {
                return matchRecursively(str+1, pattern+2) ||
                       matchRecursively(str+1, pattern) ||
                       matchRecursively(str, pattern+2);
            }
            else {
                return matchRecursively(str, pattern+2);
            }
        }
        if (*str == *pattern || (*pattern=='.' && *str!='\0')) {
            return matchRecursively(str+1, pattern+1);
        }
        return false;
    }
};