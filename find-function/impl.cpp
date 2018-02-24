#include <iostream>
#include <cstring>
#include <regex>

using namespace std;

// First approach : Using Regular expression for better flexiblity and performance
// Requires C++11 or higher compiler support
unsigned int FindFunctionDefn(const char* strFunctionName, const char* strSourceCode) {
  string funName(strFunctionName);
  funName = "("+funName+"\\s*\\([\\w, ]*\\)\\s*\\{)";                           // Regular expression
  regex r(funName);

  int line = 1, i = 0, sourceCodeLen = strlen(strSourceCode);

  while (i < sourceCodeLen) {
    char tmp[sourceCodeLen];                                                    // Store each line
    int k = 0;
    while (!(strSourceCode[i]=='\\' && strSourceCode[i+1]=='n') && i<sourceCodeLen) {
      tmp[k++] = strSourceCode[i];
      i++;
    }
    if (regex_search(tmp,r))                                                    // Check using regex
      return line;
    while (strSourceCode[i]=='\\' && strSourceCode[i+1]=='n' && i<sourceCodeLen) {
      i+=2;
      line++;
    }
  }
  return 0;
}

// Second approach : custom code
unsigned int FindFunctionDefnCustom(const char* strFunctionName, const char* strSourceCode) {
  unsigned int line = 1;
  int i = 0, j = 0, sourceCodeLen = strlen(strSourceCode), functionNameLen = strlen(strFunctionName);

  while (i<sourceCodeLen) {
    if (strSourceCode[i] == '\\' && strSourceCode[i+1] == 'n')                  // Check new line
      line++;
    while (strFunctionName[j] == strSourceCode[i] && j < functionNameLen) {     // Match strFunctionName
      j++;
      i++;
    }
    if (j == functionNameLen) {                                                 // If all characters matched
      while (strSourceCode[i] == ' ' && i<sourceCodeLen)                        // Check for spaces
        i++;
      if (strSourceCode[i] == '(') {                                            // Check for (
        while (strSourceCode[i] != ')' && i<sourceCodeLen)                      // Check for arguments or spaces
          i++;
        if (i != sourceCodeLen-1) {
          i++;
          while (strSourceCode[i] == ' ' && i<sourceCodeLen)                    // Check for spaces
            i++;
          if (strSourceCode[i] == '{')
            return line;
        }
      }
      i--;
      j = 0;
    } else {                                                                    // If all characters not matched
      j = 0;
      i++;
    }
  }
  return 0;
}


int main() {
  char strFunctionName[] = "func2";
  char strSourceCode[] = "int func1(){ return 0; }\\n int func2(){ return 1; }\\n" "int main(int argc, char*argv[]){ return func2(); }\\n";
  char strSourceCode2[] = "int func2 (int a, int b) { return 0; }\\n int func1 (int a) { return 1; }\\n" "int main(int argc, char*argv[]){ return func2(); }\\n";
  cout << "Regex approach: " << FindFunctionDefn( strFunctionName, strSourceCode ) << endl;
  cout << "Custom approach: " << FindFunctionDefnCustom( strFunctionName, strSourceCode ) << endl;
  return 0;
}
