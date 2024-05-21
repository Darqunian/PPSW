#include "string.h"
#define NULL 0x00

enum CompResult eCompareString(char pcStr1[], char pcStr2[]) {
	
	unsigned char ucCharLocation;
	
	for(ucCharLocation = 0; pcStr1[ucCharLocation] != NULL; ucCharLocation++) {
		if(pcStr1[ucCharLocation] != pcStr2[ucCharLocation]) {
			return DIFFERENT;
		}
	}
	if(pcStr1[ucCharLocation] == pcStr2[ucCharLocation]) {
		return EQUAL;
	} else {
		return DIFFERENT;
	}
}

enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue) {
	
	unsigned char ucCharCounter;
	unsigned char ucCurrentChar;
	
	*puiValue = 0;
	
	if(pcStr[0] != '0' || pcStr[1] != 'x' || pcStr[2] == NULL) {
		return ERROR;
	}
	for(ucCharCounter = 2; ucCharCounter <= 6; ucCharCounter++) {
		ucCurrentChar = pcStr[ucCharCounter];
		
		if(ucCurrentChar == NULL) {
			return OK;
		} else if(ucCharCounter == 6) {
			return ERROR;
		}
		
		*puiValue = *puiValue << 4;
		
		if((ucCurrentChar <= '9') && (ucCurrentChar >= '0')) {
			ucCurrentChar = ucCurrentChar - '0';
		} else if(ucCurrentChar <= 'F' && ucCurrentChar >= 'A') {
			ucCurrentChar = ucCurrentChar - 'A' + 10;
		} else {
			return ERROR;
		}
		*puiValue = *puiValue | ucCurrentChar;
	}
	return OK;
}

void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar) {
	
	unsigned char ucCharLocation;
	
	for(ucCharLocation = 0; pcString[ucCharLocation] != NULL; ucCharLocation++) {
		if(pcString[ucCharLocation] == cOldChar) {
			pcString[ucCharLocation] = cNewChar;
		}
	}
}
