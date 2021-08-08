#include <stdio.h>
#include <string.h>

int main ()
{
   char src[40]="sam";
   char dest[20]="hey there";
  
   //memset(dest, '\0', sizeof(dest));
   //strcpy(src, "This is tutorialspoint.com");
   strcat(src, dest);
   puts(src);

  // printf("Final copied string : %s\n", dest);

   
   return 0;
}