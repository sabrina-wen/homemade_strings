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
  dest[counter] = 0;
  return dest;
}

char * my_strncpy(char * dest, char * source, int n) {
  int counter = 0;
  while (*(source + counter) && counter < n) {
    dest[counter] = source[counter];
    counter++;
  }
  //dest[counter] = 0;
  return dest;
}

char * my_strcat (char *dest, char *source){
  /*
  int i = 0;
  int len = my_strlen(dest);
  while ( *(source + i) ){
    dest[len + i] = source[i];
    i++;
  }
  dest[i] = 0;*/
  int len = my_strlen(dest);
  my_strcpy(dest + len, source);
  return dest;
}

char * my_strncat (char *dest, char *source, int n){
  /*
  int i = 0;
  int len = my_strlen(dest);
  while ( *(source + i) && i < n ){
    dest[len + i] = source[i];
    i++;
  }
  dest[i] = 0;*/
  int len = my_strlen(dest);
  my_strncpy(dest + len, source, n);
  return dest;
}

int main() {
  char s[] = "Tuesday";
  char t[] = "hey";
  
  printf("Testing my_strlen: \n");
  printf("Length of string \"%s\" is %d\nUsing default, length is %lu\n",s, my_strlen(s), strlen(s));
  printf("Length of string \"%s\" is %d\nUsing default, length is %lu\n\n",t, my_strlen(t), strlen(t));

  printf("Testing my_strcpy\n");
  printf("Dest string is \"%s\" and src string is \"%s\"\n", s, t);
  printf("New dest is \"%s\"\n", my_strcpy(s, t));
  
  char s2[] = "Tuesday";
  char t2[] = "hey";
  printf("Testing strcpy %s\n\n", strcpy(s2, t2));

  char f[] = "Tuesday";
  char g[] = "Sunny";
  
  printf("Testing my_strncpy\n");
  printf("Dest string is \"%s\" and src string is \"%s\" and n is 3\n", f, g);
  printf("New dest is \"%s\"\n", my_strncpy(f, g, 3));
  
  char f2[] = "Tuesday";
  char g2[] = "Sunny";
  printf("Testing strncpy %s\n\n", strncpy(f2, g2, 3));

  char a[50] = "source";
  char b[50] = "destin";
  
  printf("Testing my_strcat\n");
  printf("Dest string is \"%s\" and src string is \"%s\"\n", a, b);
  printf("New dest is \"%s\"\n", my_strcat(a, b));
  

  char a2[50] = "source";
  char b2[50] = "destin";
  printf("Testing strcat %s\n\n", strcat(a2, b2));
  
  char c[50] = "source";
  char d[50] = "destin";
  
  printf("Testing my_strncat\n");
  printf("Dest string is \"%s\" and src string is \"%s\" and n is 4\n", c, d);
  printf("New dest is \"%s\"\n", my_strncat(c, d, 4));
  

  char c2[50] = "source";
  char d2[50] = "destin";
  printf("Testing strncat %s\n\n", strncat(c2, d2, 4));
  

  return 0;
}
