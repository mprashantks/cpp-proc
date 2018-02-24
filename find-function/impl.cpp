#include <iostream>
#include <cstring>
#include <regex>

using namespace std;

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

int main() {
  char strFunctionName[] = "func2";
  char strSourceCode[] = "int func2s(){ return 0; }\\n\\n\\n\\nint func2()      {}\n\nint fun()";
  cout << FindFunctionDefn( strFunctionName, strSourceCode ) << endl;
  return 0;
}
