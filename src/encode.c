
#include "common.h"

void encodeBytes(uint8_t in[], uint8_t out[], int numBytes)
{
    // always encode one byte
    out[0] = (in[0] >> 2);
    out[1] = (in[0] & 0x03) << 4;

    // check if more bytes to encode
    if (numBytes == 1)
    {
        return;
    }
    out[1] |= in[1] >> 4; // second byte
    out[2] = (in[1] & 0x0F) << 2;

    // check if we need to encode third byte
    if (numBytes == 2)
    {
        return;
    }
    out[2] |= in[2] >> 6; // third byte
    out[3] = in[2] & 0x3F;
}

void encodeChars(uint8_t in[], uint8_t out[], int numBytes)
{
    // reset out bytes to "=" by default
    out[0] = 64;
    out[1] = 64;
    out[2] = 64;
    out[3] = 64;

    encodeBytes(in, out, numBytes);
}

void encode(char **outputText, FILE *inputStream)
{
    uint8_t in[3]; // base64 encodes 3 chars into 4 chars
    uint8_t out[4];
    int endOfFile = 0;

    while (endOfFile == 0)
    {
        size_t bytesRead = readNextBytes(inputStream, in, 3);
        if (bytesRead < 1)
        {
            break; // all bytes have been read from inputStream
        }

        encodeChars(in, out, bytesRead);

        // always write 4 bytes of output
        for (int i = 0; i < 4; i++)
        {
            appendChar(outputText, alphabet[out[i]]);
        }

        if (bytesRead < 3)
        {
            endOfFile = 1;
        }
    }
}