#include <stdio.h>
#include <string.h>

struct {
  char name[40];
  int age;
} person, person_copy;

int main()
{
  char message1[60] = "Four score and seven years ago ...";
  char message2[60] = "abcdefghijklmnopqrstuvwxyz";
  char temp[60];

  printf("message1[] before memset():\t%s", message1);
  memset(message1 + 5, '@', 10);
  printf("\nmessage1[] after memset():\t%s", message1);

  strcpy(temp, message2);
  printf("\n\nOriginal message: %s", temp);
  memcpy(temp + 4, temp + 16, 10);
  printf("\nAfter memcpy() without overlap:\t%s", temp);
  strcpy(temp, message2);
  memcpy(temp + 6, temp + 4, 10);
  printf("\nAfter memcpy() with overlap:\t%s", temp);

  strcpy(temp, message2);
  printf("\n\nOriginal message: %s", temp);
  memmove(temp + 4, temp + 16, 10);
  printf("\nAfter memmove() without overlap:%s", temp);
  strcpy(temp, message2);
  memmove(temp + 6, temp + 4, 10);
  printf("\nAfter memmove() with overlap:\t%s\n", temp);

  char myname[] = "Ben Hung";
  /* using memcpy to copy string: */
  memcpy ( person.name, myname, strlen(myname)+1 );
  person.age = 26;
  /* using memcpy to copy structure: */
  memcpy ( &person_copy, &person, sizeof(person) );
  printf ("\nperson_copy: %s, %d \n", person_copy.name, person_copy.age );

  return 0;
}
