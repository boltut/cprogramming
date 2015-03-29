/*Программа, выводящая самую длинную строку в тексте, даже превышающую лимит MAXLINE*/
#include <stdio.h>
#define MAXLINE 10 /*максимальная длина строки в потоке*/

int mygetline(char s[], int maxline);
void copy (char to[], char from[]);
/*Вывод самой длинной строки в потоке*/
main()
{
  int len; // длина текущей строки
  int max; // текущая максимальная длина
  int c; // буква
  char line[MAXLINE]; // текущая введенная строка
  char longest[MAXLINE]; // самая длинная строка из введенных

  max = 0;
  while((len = mygetline(line, MAXLINE)) > 0)
  {
    if(line[len-1] != '\n')
    {
      while((c = getchar()) != EOF && c != '\n')
      ++len;
    }
    if(len > max)
    {
      max = len;
      copy(longest, line);
    }
  }
  if(max < MAXLINE) // вычитаем нулевой символ вставленный в mygetline
  {
    --max;
  }
  if(max > 0) // была не пустая строка
  {
    printf("Max dlina stroki\n");
    if(max > MAXLINE)
    {
      printf("%s...\n", longest);
    }
    else
    {
      printf("%s\n", longest);
    }
  }
  printf("Dlina stroki - %d\n", max);
  return 0;

}

/*getline: считывает строку в s, возвращает ее длину*/
int mygetline(char s[], int lim)
{
  int c, i;

  for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
  }
  if(c == '\n')
  {
    s[i] = c;
    ++i;
  }
    s[i] = '\0';
  return i;
}

/*copy: копирует строку 'from' в 'to'; длина to считается достаточной*/
void copy (char to[], char from[])
{
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
  {
    ++i;
  }
}
112222222
