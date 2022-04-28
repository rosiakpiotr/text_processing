#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
  char *line;
  while ((line = readline()) != NULL)
  {
    int startPos, endPos;
    startPos = endPos = lineSize;
    while (startPos > 0)
    {
      // Find location of space, or start of the line if no space is left.
      while (--startPos)
      {
        if (line[startPos] == ' ')
          break;
      }
      // Artificially add space before last word because
      // normally there isn't one at the beginning of the line.
      if (startPos == 0 && endPos != lineSize)
        printf(" ");

      // Print word form between spaces (or beginning and first space)
      // and skip whitespace on the beginning and new line characters
      // after first word.
      for (size_t pos = startPos; pos < endPos; pos++)
      {
        if (line[pos] == '\n' || ((endPos == lineSize) && line[pos] == ' '))
          continue;
        printf("%c", line[pos]);
      }

      endPos = startPos;
    }
    printf("\n");
    free(line);
  }
  return 0;
}
