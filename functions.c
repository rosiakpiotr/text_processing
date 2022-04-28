#include "functions.h"

char *readline()
{
    char *line = NULL;
    int c;
    size_t bufsize = 0;
    size_t size = 0;

    while ((c = getchar()) != EOF)
    {
        if (size >= bufsize)
        {
            char *newbuf;
            // Determine new buffer size
            if (bufsize == 0)
                bufsize = 2;
            // Check for overflows in bufsize
            else if (bufsize <= (((size_t)-1) / 2))
                bufsize = 2 * size;
            else
            {
                free(line);
                abort();
            }

            newbuf = realloc(line, bufsize);
            if (newbuf == NULL)
            {
                free(line);
                abort();
            }
            line = newbuf;
        }

        line[size++] = c;
        if (c == '\n')
            break;
    }

    if ((c == EOF) && (size == 0))
        return NULL;

    if (size >= bufsize)
    {
        char *newbuf;
        if (size < (size_t)-1)
            bufsize = size + 1;
        else
        {
            free(line);
            abort();
        }
        newbuf = realloc(line, bufsize);
        if (newbuf == NULL)
        {
            free(line);
            abort();
        }
        line = newbuf;
    }
    line[size] = '\0';
    lineSize = size;
    return line;
}
