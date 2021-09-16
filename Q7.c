#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define MAX_INPUT_SIZE 1024

struct Vetor {
  unsigned long *elementos;
  size_t tamanho;
};

struct Vetor *criar_vetor()
{
  struct Vetor *vetor = malloc(sizeof(*vetor));

  vetor->elementos = NULL;
  vetor->tamanho = 0;

  return vetor;
}

void adicionar_elemento_ao_vetor(struct Vetor *vetor, unsigned long elemento)
{
  vetor->elementos = realloc(vetor->elementos, (vetor->tamanho + 1) * sizeof(elemento));

  vetor->elementos[vetor->tamanho] = elemento;

  vetor->tamanho++;
}

unsigned long pegar_elemento_do_vetor(struct Vetor *vetor, size_t indice)
{
  return vetor->elementos[indice];
}

void destruir_vetor(struct Vetor *vetor)
{
  if (vetor->elementos != NULL)
    free(vetor->elementos);
  
  free(vetor);
}

int main()
{
  struct Vetor *resultados = criar_vetor();
  unsigned long elemento, soma = 0, media;
  size_t i;

  printf("Digite 5 resultados do piloto:\n");
  fflush(stdout);

  for (i = 0; i < 5; i++) {
    scanf("%ld", &elemento);

    soma += elemento;

    adicionar_elemento_ao_vetor(resultados, elemento);
  }

  media = soma / (resultados->tamanho);

  printf("Resumo de resultados: ");

  for (i = 0; i < 5; i++) {
    elemento = pegar_elemento_do_vetor(resultados, i);

    if (i != 4) {
      printf("%ld ", elemento);
    } else {
      printf("%ld\n", elemento);
    }
  }

  printf("Média dos resultados: %ld\n", media);

  destruir_vetor(resultados);

  return EXIT_SUCCESS;
}
