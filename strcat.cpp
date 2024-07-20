/* strcat- strcat(char* dest, char* src);
   concatenate string src to the end of dest
*/

#include <iostream>

char dest[100] = "hi bro";
char src[] = " how are you";

void strcat(char* dest, char* src){
  
    int i=0;
    int j=0;
    while(dest[i]!='\0'){
   	  i++;                 //this loop to find size of dest
    }
    std::cout<<"sad i = "<<i<<std::endl;
    while(src[j]!='\0'){
      dest[i] = src[j];    //this loop is to copy values from src to dest at ending.
      i++;
      j++;
      std::cout<<"one time \n";
    }
  
    src[i] = '\0';       //proper closing of string
}


int main() {
    strcat(dest, src);
    std::cout<<"dest : "<<dest<<std::endl;
    std::cout<<"src : "<<src<<std::endl;
    return 0;
}
