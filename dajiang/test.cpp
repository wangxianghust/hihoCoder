#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    char str[]  = "aa,bb,cc,dd";
    char str2[] = "e,f,g";
    char* s;
    s = strtok(str, ","); // convert , to \0
    while(s != NULL){
        std::cout << s << std::endl;
        s = strtok(str2, ",");
    }
}


/*
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }
  return 0;
}
*/
