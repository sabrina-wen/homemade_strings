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
  return dest;
}

char * my_strcat (char *dest, char *source){
  int len = my_strlen(dest);
  my_strcpy(dest + len, source);
  return dest;
}

char * my_strncat (char *dest, char *source, int n){
  int len = my_strlen(dest);
  my_strncpy(dest + len, source, n);
  return dest;
}

// "aaa" < "b"
int my_strcmp(char * s1, char * s2) {
  int min_strlen = 0;
  int ret_val = 0;
  if (my_strlen(s1) < my_strlen(s2)) {
    min_strlen = my_strlen(s1);
  } else {
    min_strlen = my_strlen(s2);
  }
  while (min_strlen >= 0) {
    if (*s1 - *s2 > 0) {
      ret_val = 1;
      break;
    } else if (*s1 - *s2 < 0){
      ret_val = -1;
      break;
    } else {
      s1++;
      s2++;
      min_strlen--;
    }
  }
  return ret_val;
}

char * my_strchr(char * s, char c) {
  int counter = 0;
  while(*s) {
    if (*s == c) {
      return s;
    }
    s++;
  }
  if (*s == c) {
    return s;
  } else {
    return NULL;
  }
}

int main() {
  char s[] = "Tuesday";
  char t[] = "hey";
  char u[] = "alaa";
  char v[] = "kaah";
  char w[] = "wizard";
  char x = 'b';

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
  
  printf("Testing my_strcmp\n");
  printf("String 1 is \"%s\" and String 2 is \"%s\"\nCompare value is %d\n", u, v, my_strcmp(u, v));
  printf("Using strcmp: %d\n\n", strcmp(u,v)); // ret negative since w (wizard) comes AFTER v (whaat) in the alphabet

  printf("Testing my_strchr\n");
  printf("String is \"%s\" and char is \"%c\"\nFirst instance of char is \"%s\"\n", w, x, my_strchr(w, x));
  printf("Using strchr: %s\n\n", strchr(w,x));

  return 0;
}
