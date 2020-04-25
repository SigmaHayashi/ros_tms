#include "keyboard.h"
#include <termios.h>
<<<<<<< HEAD
#include <unistd.h>  // for read()
=======
#include <unistd.h>   // for read()
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

static struct termios initial_settings, new_settings;
static int peek_character = -1;

void init_keyboard()
{
<<<<<<< HEAD
  tcgetattr(0, &initial_settings);
  new_settings = initial_settings;
  new_settings.c_lflag &= ~ICANON;
  new_settings.c_lflag &= ~ECHO;
  new_settings.c_lflag &= ~ISIG;
  new_settings.c_cc[VMIN] = 1;
  new_settings.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &new_settings);
=======
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

void close_keyboard()
{
<<<<<<< HEAD
  tcsetattr(0, TCSANOW, &initial_settings);
=======
    tcsetattr(0, TCSANOW, &initial_settings);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

int kbhit()
{
<<<<<<< HEAD
  unsigned char ch;
  int nread;

  if (peek_character != -1)
    return 1;
  new_settings.c_cc[VMIN] = 0;
  tcsetattr(0, TCSANOW, &new_settings);
  nread = read(0, &ch, 1);
  new_settings.c_cc[VMIN] = 1;
  tcsetattr(0, TCSANOW, &new_settings);
  if (nread == 1)
  {
    peek_character = ch;
    return 1;
  }
  return 0;
=======
unsigned char ch;
int nread;

    if (peek_character != -1) return 1;
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &new_settings);
    if(nread == 1)
    {
        peek_character = ch;
        return 1;
    }
    return 0;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

int readch()
{
<<<<<<< HEAD
  char ch;

  if (peek_character != -1)
  {
    ch = peek_character;
    peek_character = -1;
    return ch;
  }
  read(0, &ch, 1);
  return ch;
}

int _getch()
{
  init_keyboard();
  kbhit();
  char c = readch();
  close_keyboard();
  return c;
=======
char ch;

    if(peek_character != -1)
    {
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0,&ch,1);
    return ch;
}

int _getch() {
	init_keyboard();
	kbhit();
	char c = readch();
	close_keyboard();
	return c;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}
