#include <string.h>
#include "common.h"

void decodeBytes(uint8_t in[], uint8_t out[])
{
    out[0] = '\0';
    out[1] = '\0';
    out[2] = '\0';

    out[0] = (in[0] << 2) | (in[1] >> 4);

    if (in[2] == '\0')
    {
        return;
    }
    out[1] = (in[1] << 4) | (in[2] >> 2);

    if (in[3] == '\0')
    {
        return;
    }
    out[2] = (in[2] << 6) | (in[3]);
}

int findIndex(const char *haystack, char needle)
{
    char *found = strchr(haystack, needle);
    if (found == NULL)
    {
        return -1;
    }
    return (int)(found - haystack);
}

/* convert ascii back to base64alphabet index used before encoding */
void decodeAscii(uint8_t in[], const int charsToRead)
{
    for (int i = 0; i < charsToRead; i++)
    {
        if (in[i] == '=')
        {
            in[i] = '\0'; // ignore '=' padding char
            continue;
        }

        int index = findIndex(alphabet, in[i]);
        if (index == -1)
        {
            printf(stderr, "decode() error: Invalid char input %c", in[i]);
            exit(1);
        }
        in[i] = index;
    }
}

void decode(char **text, FILE *inputStream)
{
    const int charsToRead = 4;
    uint8_t in[4];
    uint8_t out[3]; // base64 decodes 4 chars to 3
    int endOfFile = 0;

    while (endOfFile == 0)
    {
        size_t bytesRead = readNextBytes(inputStream, in, charsToRead);
        if (bytesRead < charsToRead)
        {
            break; // all bytes have been read from inputStream
        }

        decodeAscii(in, charsToRead);
        decodeBytes(in, out);

        // write the decoded text to the text string
        for (int i = 0; i < bytesRead; i++)
        {
            appendChar(text, (char)out[i]);
        }
    }
}