#include <stdio.h>

#define INTRO "\nWelcome to Zmar-G's Crappy text editor\n\n"

#define RED "\x1b[31m"
#define YELLOW "\x1b[33m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"

#define size 1024

// TODO: make it arguable, if argument is empty it asks for file within running
// process.

char upper(char myChar) {
  if (myChar >= 'a' && myChar <= 'z')
    return myChar &= ~0x20;
  else
    return myChar;
}

void removeNl(char myString[], int *cCount) {
  int pos = 0;
  while (myString[pos] != 10 && myString[pos] != 0)
    pos++;
  myString[pos] = 0;

  if (cCount != (void *)0)
    *cCount += pos;
}

int main(int argc, char *argv[]) {

  printf(INTRO);

  char myFile[size / 32];
  char buf[size][size];

  if (argc == 1) {
    printf(RESET "\nWhat is your file name?\n\t~> ");
    if (fgets(myFile, sizeof(myFile), stdin) == (void *)0) {
      printf(RED "\nInput Error!\n" RESET);
      return 1;
    }
  } else if (argc == 2) {
    for (int i = 0; argv[1][i] != 0 && argv[1][i] != 10; i++)
      myFile[i] = argv[1][i];
  } else {
    printf(RED "\nToo Many Arguments!\n" RESET);
    return 1;
  }

  removeNl(myFile, (void *)0);

  FILE *readMyFile = fopen(myFile, "r");
  int lineCount = 0;

start:
  if (readMyFile == (void *)0) {
    printf(YELLOW "\nFile Doesn't Exist!\n");
    printf(RESET "\nWould you like to create it?\n[" GREEN "y" RESET "/" RED
                 "n" RESET "]\t~> " YELLOW);
    char choice;
    if ((scanf(" %c", &choice)) == 0) {
      printf(RED "\nInput Error!\n" RESET);
      return 1;
    }
    choice = upper(choice);
    switch (choice) {
    case 'Y':
      printf("");
      FILE *writeMyFile = fopen(myFile, "w");
      fclose(writeMyFile);
      readMyFile = fopen(myFile, "r");
      break;
    case 'N':
      goto end;
      break;
    default:
      printf(RED "\n[ERROR]: Invalid Input!\n" RESET);
      return 1;
    }
  } else {
    printf(RESET "\n--------------------------------\n");
    printf("\nFile Contents:\n");
    printf("\n");
    rewind(readMyFile);
    lineCount = 0;
    int characterCount = 0;
    for (int i = 0; fgets(buf[i], size, readMyFile); i++) {
      printf("\t%s", buf[i]);
      removeNl(buf[i], &characterCount);
      lineCount++;
    }
    printf("\n--------------------------------\n");
    printf("Line Count: [" GREEN "%d" RESET "]", lineCount);
    printf("\nCharacter Count: [" GREEN "%d" RESET "]\n", characterCount);
    printf("\n");
  }

  printf("\nWould You Like to Edit it?\n[" GREEN "y" RESET "/" RED "n" RESET
         "]\t~> " YELLOW);
  {
    char choice;
    if ((scanf(" %c", &choice)) == 0) {
      printf(RED "\nInput Error!\n" RESET);
      fclose(readMyFile);
      return 1;
    }
    choice = upper(choice);

    switch (choice) {
    case 'Y':
      break;
    case 'N':
      goto end;
      break;
    default:
      printf(RED "\nInvalid Input!\n" RESET);
      fclose(readMyFile);
      return 1;
    }
  }
  printf(RESET);

  getchar(); // for good luck

  int line = 0, pos = 0, ch;

  printf(
      "\nNew Contents: [Press ESC in a new line and ENTER to save and exit]\n");
  printf("[%d]\t%s\n[~]\t", line + 1, buf[line]);

  while ((ch = fgetc(stdin)) != 27) {
    if (ch == 10) {
      printf("\x1b[2A\x1b[2K");
      int isPreserved = 0;
      if (pos == 0) {
        while (buf[line][pos] != 10 && buf[line][pos] != 0)
          pos++;
        isPreserved = 1;
      }
      printf("[%d]\t%s%s", line + 1, buf[line],
             (isPreserved && pos >= 1 && buf[line][pos] != 32)
                 ? GREEN BOLD " [Preserved!]\n" RESET
                 : "\n"); // need to adjust the logic of this to better fit more
                          // edge cases.
      buf[line][pos++] = 10;
      buf[line][pos] = 0;
      line++;
      lineCount--;
      pos = 0;
      printf("[%d]\x1b[K\t%s\x1b[K", line + 1, buf[line]);
      printf("\n[~]\t");
    } else {
      if (pos == 0)
        for (int i = 0; buf[line][i] != 0; i++)
          buf[line][i] = 0;
      buf[line][pos++] = ch;
    }
  }

  while (lineCount > 0) {
    pos = 0;
    while (buf[line][pos] != 10 && buf[line][pos] != 0)
      pos++;
    buf[line++][pos] = 10;
    lineCount--;
  }

  printf("\n--------------------------------\n");

  FILE *writeMyFile = fopen(myFile, "w");

  if (writeMyFile == (void *)0) {
    printf(RED "\n[ERROR]: Unable to save file! Check permissions...\n");
  } else {
    for (int i = 0; i < line; i++)
      fputs(buf[i], writeMyFile);
  }

  fclose(writeMyFile);

  goto start;

end:
  printf(RESET);
  if (readMyFile != (void *)0)
    fclose(readMyFile);
  return 0;
}
