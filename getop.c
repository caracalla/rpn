#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char container[]) {
  int i = 0;
  int character = getch();
  int return_value;

  // skip spaces
  // for some reason, spaces are being turned into \0???
  while (character == ' ' || character == '\t' || character == '\0') {
    character = getch();
  }

  container[0] = character;

  if (character == '-') {
    // if it's a minus sign, we aren't sure if this is a number or not
    return_value = character;
    i++;
    character = getch();
  } else if (!isdigit(character) && character != '.') {
    // otherwise just return it
    container[1] = '\0';
    return character;
  }

  if (isdigit(character)) {
    // it's a number, so collect the digits and the optional period
    return_value = NUMBER;
    while (isdigit(character)) {
      container[i] = character;
      i++;
      character = getch();
    }

    if (character == '.') {
      container[i] = character;
      i++;
      character = getch();
    }

    while (isdigit(character)) {
      container[i] = character;
      i++;
      character = getch();
    }
  }

  container[i] = '\0';

  if (character != EOF) {
    ungetch(character);
  }

  return return_value;
}
