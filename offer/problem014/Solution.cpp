class Solution {
public:
    bool isNumeric(char* string)
    {
        if (string == NULL) return false;
        if (*string == '+' || *string == '-')
            string++;
        bool numeric = isInteger(&string);
        if (*string == '.') {
            string++;
            numeric = isInteger(&string) || numeric;
        }
        if (*string == 'e' || *string == 'E') {
            string++;
            if (*string == '+' || *string == '-')
                string++;
            numeric = numeric && isInteger(&string);
        }
        return numeric && *string=='\0';
    }

    bool isInteger(char** string) {
        const char* init = *string;
        while (**string>='0' && **string<='9') {
            (*string)++;
        }
        return *string > init;
    }
};