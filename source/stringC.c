// stringC.c

#include <stdio.h>
#include <string.h>
 
int main( void ){
 
  char text[10];
 
  strcpy(text, "The Text is too long for text.");   // (1) text is too big
  printf("strlen(text): %u\n", strlen(text));       // (2) text has no termination character '\0'
  printf("%s\n", text);
 
  text[sizeof(text)-1] = '\0';
  printf("strlen(text): %u\n", strlen(text));
 
  return 0;
}

