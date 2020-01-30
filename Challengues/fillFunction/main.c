#include "Functions/coreFunction.h"
#include "Functions/fillAux.h"

int main(){
#ifdef _WIN64
coreFunctionWin();
#endif
#ifdef __unix__
coreFunctionLinux();
#endif
return 0;
}
