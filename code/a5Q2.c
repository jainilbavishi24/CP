#include <stdio.h>
#include <string.h>

void reverse(char *str)
{
   int len = strlen(str);
   for (int i = 0; i < len / 2; i++)
   {
      char temp = str[i];
      str[i] = str[len - i - 1];
      str[len - i - 1] = temp;
   }
}

void add_char(char *str, char c, int pos)
{
   int len = strlen(str);
   if (pos == 1)
   {
      memmove(str + 1, str, len + 1);
      str[0] = c;
   }
   else
   {
      str[len] = c;
      str[len + 1] = '\0';
   }
}

int main()
{
   char str[1000000];

   scanf("%s", str);

   int t;

   scanf("%d", &t);
   int arr[t];

   int foo = 1;
   int l[t];
   char j[t];
   
   for (int i = 0; i < t; i++)
   {
       l[i]=-1;
   }

   for (int i = 0; i < t; i++)
   {
      scanf("%d", &arr[i]);
      if (arr[i] == 2)
      {
         scanf("%d %c", &l[i], &j[i]);
      }
   }
  // scanf("%d %c", &l, &j);

   for (int i = 0; i < t; i++)
   {

      if (arr[i] == 1)
      {
         if ( arr[i + 1] != 1)
         {
            if (foo % 2 != 0)
            {
               reverse(str);
            }
            foo = 1;
         }
         else
         {
            foo++;
         }
      }
      else if (arr[i] == 2)
      {

         add_char(str,j[i] ,l[i]);
      }

      // printf("Current string: %s\n", str);
   }
   printf("%s",str);
   return 0;
}