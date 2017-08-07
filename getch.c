#include <stdio.h>

#define BUFFER_SIZE 100

char buffer[BUFFER_SIZE];
int buffer_position = 0;

int getch() {
  int character;
  if (buffer_position > 0) {
    buffer_position--;
    return buffer[buffer_position];
  } else {
    // return getchar();
    character = getchar();
    printf("%c - %u\n", character, character);
    return character;
  }
}

void ungetch(int character) {
  if (buffer_position >= BUFFER_SIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buffer_position++;
    buffer[buffer_position] = character;
  }
}
