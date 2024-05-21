enum CompResult { DIFFERENT, EQUAL };
enum Result {OK, ERROR};

enum CompResult eCompareString(char pcStr1[], char pcStr2[]);
enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue);
void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar);
