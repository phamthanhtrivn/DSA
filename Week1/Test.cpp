#include<stdio.h>
#include <string.h>
 
int main() {
  char str[100] = "Day la mot vi du ve ham strstr() trong c, vi du...";
  char *sub;
  sub = strstr(str, "vi");
  printf("\nChuoi con la: %s", sub);
  return 0;
}
