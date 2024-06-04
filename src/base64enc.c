#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdint.h> // *should* typedef uint8_t
// Check that uint8_t type exists
#ifndef UINT8_MAX
#error "No support for uint8_t"
#endif

#include "encode.h"
#include "decode.h"

FILE *getInputStream(int numArgs, char *inputArgs[])
{
  FILE *inputStream = stdin;

  if (numArgs > 2)
  {
    printf(stderr, "Invalid number of arguments\n");
    exit(1);
  }

  // max one argument given. Check if it is default or a file path
  char *inputText = inputArgs[1];
  if (numArgs == 0 || strcmp(inputText, "-") == 0 || strcmp(inputText, "-d") == 0)
  {
    // get user input
    return inputStream;
  }

  // open file as input stream
  inputStream = fopen(inputText, "r");
  if (inputStream == NULL)
  {
    printf(stderr, "Unable to open file%s\n", inputText);
    exit(1);
  }

  // file stream successfully opened
  return inputStream;
}

int main(int argc, char *argv[])
{
  FILE *inputStream = getInputStream(argc - 1, argv);

  char *outputText = calloc(1, sizeof(char));

  if ((argc > 1 && strcmp(argv[1], "-d") == 0) || (argc > 2 && strcmp(argv[2], "-d") == 0))
  {
    decode(&outputText, inputStream);
  }
  else
  {
    encode(&outputText, inputStream);
  }

  printf("\n%s\n", outputText);

  // we're done; close the stream
  if (fclose(inputStream) != 0)
  {
    printf(stderr, "Could not close input stream\n");
    return EXIT_FAILURE;
  }

  free(outputText);
  return EXIT_SUCCESS;
}
