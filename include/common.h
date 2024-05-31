#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdint.h>

size_t readNextBytes(FILE *inputStream, uint8_t in[], size_t bytesToRead);
void appendChar(char **str, char letter);
extern const char const alphabet[];

#endif