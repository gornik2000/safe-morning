#define ERR_DEF(num, name, decription) ERR_##name = (num),
enum ERRORS
{
  #include "errors.h"
};
#undef ERR_DEF