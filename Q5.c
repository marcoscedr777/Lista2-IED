#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

#define LIMITE_DE_ALUNOS_POR_DISCIPLINA 30

typedef char string[MAX_INPUT_SIZE + 1];

struct Endereco {
  string logradouro;
  unsigned long numero;
  string bairro;
  string cidade;
  string estado;
};

struct Professor {
  string nome;
  unsigned long idade;
  string cpf;
  string telefone;
  string email;
  string formacao;
  struct Endereco endereco;
};

struct Aluno {
  string nome;
  unsigned long idade;
  string cpf;
  string telefone;
  string email;
  struct Endereco endereco;
};

struct Curso {
  string codigo;
  string nome;
};

struct Disciplina {
  string codigo;
  string nome;
  struct Curso curso;
  unsigned long carga_horaria;
  struct Professor professor;
  struct Aluno alunos[LIMITE_DE_ALUNOS_POR_DISCIPLINA];
};

int main()
{
  struct Endereco endereco_professor;
  struct Endereco endereco_aluno;
  struct Curso curso;
  struct Professor professor;
  struct Aluno aluno;
  struct Disciplina disciplina;

  strcpy(endereco_professor.logradouro, "Rua João Silva");
  endereco_professor.numero = 369;
  strcpy(endereco_professor.bairro, "Operários");
  strcpy(endereco_professor.cidade, "São Paulo");
  strcpy(endereco_professor.estado, "São Paulo");

  strcpy(endereco_professor.logradouro, "Rua Edson Mota");
  endereco_professor.numero = 780;
  strcpy(endereco_professor.bairro, "Centro");
  strcpy(endereco_professor.cidade, "São Paulo");
  strcpy(endereco_professor.estado, "São Paulo");

  strcpy(curso.codigo, "INF");
  strcpy(curso.nome, "Integrado em Informática");

  strcpy(professor.nome, "José Ferreira");
  professor.idade = 26;
  strcpy(professor.cpf, "023.499.349-49");
  strcpy(professor.telefone, "+55 (11) 99283-1829");
  strcpy(professor.email, "jose.ferreira@gmail.com");
  strcpy(professor.formacao, "Mestre Tecnologia da Informação");
  professor.endereco = endereco_professor;

  strcpy(aluno.nome, "Victor Ernando");
  aluno.idade = 17;
  strcpy(aluno.cpf, "034.393.394-29");
  strcpy(aluno.telefone, "+55 (11) 93849-4934");
  strcpy(aluno.email, "victor.ernando@gmail.com");
  aluno.endereco = endereco_aluno;

  strcpy(disciplina.codigo, "IED");
  strcpy(disciplina.nome, "Introdução a Estruturas de Dados");
  disciplina.curso = curso;
  disciplina.carga_horaria = 80;
  disciplina.professor = professor;
  disciplina.alunos[0] = aluno;

  return EXIT_SUCCESS;
}
