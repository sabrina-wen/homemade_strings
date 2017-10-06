#include <stdio.h>
#include <string.h>

int my_strlen(char * str) {
  int length = 0;
  while (*str) { // while you are not a null character (0 means false!!, don't need *str != 0)
    length++;
    str++;
  }
  return length;
}

char * my_strcpy(char * dest, char * source) {
  int counter = 0;
  while (*(source + counter)) {
    dest[counter] = source[counter];
    counter++;
  }
  return dest;
}

int main() {
  char s[] = "Tuesday";
  char t[] = "hey";
  
  printf("Testing my_strlen: \n");
  printf("Length of string \"%s\" is %d\nUsing default, length is %lu\n",s, my_strlen(s), strlen(s));
  printf("Length of string \"%s\" is %d\nUsing default, length is %lu\n\n",t, my_strlen(t), strlen(t));

  printf("Testing my_strcpy\n");
  printf("Dest string is \"%s\" and src string is \"%s\"\nNew dest is \"%s\"\n", s, t, my_strcpy(s, t));
  printf("Testing strcpy %s\n\n", strcpy(s, t));


  return 0;
}
