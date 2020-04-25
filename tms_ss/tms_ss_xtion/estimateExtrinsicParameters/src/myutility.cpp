#include <iostream>
#include <vector>
//#include <OpenNI.h>

#ifdef __linux__
#include <termios.h>
#include <unistd.h>
#endif

#include "myutility.h"

<<<<<<< HEAD
=======

>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
/**--------------------------------------------------
 * \class KeyboardEventReader
 */
KeyboardEventReader::KeyboardEventReader()
{
  kfd = 0;
  tcgetattr(kfd, &cooked);
  memcpy(&raw, &cooked, sizeof(struct termios));
<<<<<<< HEAD
  raw.c_lflag &= ~(ICANON | ECHO);
=======
  raw.c_lflag &=~ (ICANON | ECHO);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

  raw.c_cc[VEOL] = 1;
  raw.c_cc[VEOF] = 2;
  tcsetattr(kfd, TCSANOW, &raw);
}

KeyboardEventReader::~KeyboardEventReader()
{
  tcsetattr(kfd, TCSANOW, &cooked);
}

bool KeyboardEventReader::getKeycode(char &c)
{
<<<<<<< HEAD
  if (read(kfd, &c, 1) < 0)
=======
  if(read(kfd, &c, 1) < 0)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    perror("read():");
    return false;
  }
  return true;
}
/*---------------------------------------------------*/
