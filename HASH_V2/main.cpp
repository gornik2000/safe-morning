const char *FILE_DATA_NAME = "data.txt";

#include <stdio.h>
#include "errors.cpp"
#include "hash_table.cpp"
#include "FileIO.cpp"
#include "hashFunctions.cpp"

const char *FILE_OUT_NAME = "out4.CSV";

#define CHOSEN_HASH_FUNCTION                            \
{                                                       \
                    hashFunction4                       \
}

//-----------------------------------------------------------------------------

int main ()
{
  printf (" # Start\n");
  printf (" # Hash functions program\n");

  int fileSize  = 0;
  int fileLines = 0;

  char **text = createTextFromFile (FILE_DATA_NAME, &fileSize, &fileLines);
  if (text == NULL)
  {
    printf (" # Problem with memory giving \n");
    return 0;
  }

  map *m = mapCtor (CHOSEN_HASH_FUNCTION);


  for (int i = 0; i < fileLines; i++)
  {
    mapAdd (m, text[i]);
  }
  mapPrint (m);

  FILE *fileOut = fopen (FILE_OUT_NAME, "w");
  mapToFile (m, fileOut);
  fclose (fileOut);

  free (text[0]);
  memset (text, 0, fileLines);
  free (text);
  text = NULL;

  m = mapDtor (m);

  printf (" # Program finished correctly\n");

  return 0;
  //*/
}