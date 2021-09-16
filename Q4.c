#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define MAX_INPUT_SIZE 1024

// scanf é bugado, usem fgets

bool read_string(char * restrict buf)
{
  size_t buflen;

  if (!fgets(buf, MAX_INPUT_SIZE, stdin))
    return false;

  buflen = strlen(buf);

  buf[strcspn(buf, "\n")] = '\0';

  return true;
}

bool read_uint(unsigned long * restrict dest)
{
  char input[MAX_INPUT_SIZE + 1] = { 0 };

  if (!read_string(input))
    return false;

  *dest = strtoul(input, NULL, 10);

  if (*dest == 0)
    return false;

  return true;
}

struct Pessoa {
  char nome[MAX_INPUT_SIZE];
  unsigned long idade;
  char email[MAX_INPUT_SIZE];
};

int main()
{
  struct Pessoa pessoas[3];
  size_t i, real;

  for (i = 0; i < 3; i++) {
    real = i + 1;

    printf("Digite o nome da pessoa %zd: ", real);

    read_string(pessoas[i].nome);

    printf("Digite a idade da pessoa %zd: ", real);

    read_uint(&pessoas[i].idade);

    printf("Digite o e-email da pessoa %zd: ", real);

    read_string(pessoas[i].email);
  }

  for (i = 0; i < 3; i++) {    
    printf("\nPessoa %zd:\n\n", i + 1);

    printf("Nome: %s\n", pessoas[i].nome);
    printf("Idade: %ld\n", pessoas[i].idade);
    printf("E-Mail: %s\n", pessoas[i].email);
  }

  

  return EXIT_SUCCESS;
}
