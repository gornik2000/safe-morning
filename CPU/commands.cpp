#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int ASM_MAX_CMD_SIZE  = 50;
const int ASM_FLAGS_NUMBER  = 100;
const int ASM_MAX_FLAG_SIZE = 3;
const int ASM_MAX_PAR_SIZE  = 10;
const int ASM_REG_NUMBER = 4;
const int ASM_RAM_SIZE = 512;

/* asm commands */
enum commands
{
  /* BASE COMMANDS CONSTANTS */
  END  = 1,
  IN   = 2,
  OUT  = 3,
  ADD  = 4,
  SUB  = 5,
  MUL  = 6,
  DIV  = 7,
  PUSH = 8,
  POP  = 9,

  /* MATH COMMANDS CONSTANTS */
  SIN  = 20,
  COS  = 21,
  TAN  = 22,
  LN   = 23,
  SQRT = 24,
  SQR  = 25,
  PWR  = 26,

  /* MACRO COMMANDS CONSTANTS */
  JMP = 40,
  JA  = 41,
  JB  = 42,
  JAE = 43,
};

/* asm registers */
enum registers
{
  AX = 1,
  BX = 2,
  CX = 3,
  DX = 4,
};

/* asm push types */
enum pushTypes
{
  VAL = 1,
  REG = 2,
  RAM = 3,
};

char getCommand(const char *s);

int pushPopToByteCode (char *par, int *type, int *value);

/* asm get command number from str */
char getCommand(const char *s)
{
  char command[ASM_MAX_CMD_SIZE] = "";
  int parNumber = sscanf (s, "%s", command);
  //printf ("%s\n", command);
  /* empty command string */
  if (parNumber = 0)
  {
    return 0;
  }

  if (!strcmp (command, "END"))  return END;
  if (!strcmp (command, "IN"))   return IN;
  if (!strcmp (command, "OUT"))  return OUT;
  if (!strcmp (command, "ADD"))  return ADD;
  if (!strcmp (command, "SUB"))  return SUB;
  if (!strcmp (command, "MUL"))  return MUL;
  if (!strcmp (command, "DIV"))  return DIV;
  if (!strcmp (command, "PUSH")) return PUSH;
  if (!strcmp (command, "POP"))  return POP;

  if (!strcmp (command, "SIN"))  return SIN;
  if (!strcmp (command, "COS"))  return COS;
  if (!strcmp (command, "TAN"))  return TAN;
  if (!strcmp (command, "LN"))   return LN;
  if (!strcmp (command, "SQRT")) return SQRT;
  if (!strcmp (command, "SQR"))  return SQR;
  if (!strcmp (command, "PWR"))  return PWR;

  if (!strcmp (command, "JMP")) return JMP;
  if (!strcmp (command, "JA"))  return JA;
  if (!strcmp (command, "JB"))  return JB;
  if (!strcmp (command, "JAE")) return JAE;

  /* command was not identified */
  return 0;
}

/* give information about current push/pop command */
int pushPopToByteCode (char *par, int *type, int *value)
{
  assert (par != NULL);
  assert (type != NULL);
  assert (value != NULL);

  //printf("push-pop %s\n", par);
  if (isdigit(par[0]))
  {
    *type = VAL;
    //printf("type %d\n", *type);
    *value = atoi (par);
    return 0;
  }

  if (par[0] == '[')
  {
    *type = RAM;
    //printf ("parameter %s\n", par);
    par ++;
    //printf ("parameter %s\n", par);
    //par[strlen(par)] = '\0';
    *value = atoi(par);
    return 0;
  }

  if (!strcmp (par, "AX"))
  {
    *type = REG;
    *value = AX;
  }

  if (!strcmp (par, "BX"))
  {
    *type = REG;
    *value = BX;
  }

  if (!strcmp (par, "CX"))
  {
    *type = REG;
    *value = CX;
  }

  if (!strcmp (par, "DX"))
  {
    *type = REG;
    *value = DX;
  }
}
