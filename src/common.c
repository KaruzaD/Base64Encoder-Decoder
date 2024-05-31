#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <err.h>
#include <errno.h>

const char const alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                              "abcdefghijklmnopqrstuvwxyz"
                              "0123456789+/=";

size_t readNextBytes(FILE *inputStream, uint8_t in[], size_t bytesToRead)
{
    size_t count = fread(in, sizeof *in, bytesToRead, inputStream);
    if (ferror(inputStream))
    {
        err(errno, "Could not read file. fread error.\n");
    }

    return count;
}

void strcat_c(char *str, char c)
{
    for (; *str; str++)
        ;
    *str++ = c;
    *str++ = '\0';
}

void appendChar(char **str, char letter)
{
    *str = realloc(*str, sizeof(char) * (strlen(*str) + 2));
    strcat_c(*str, letter);
}