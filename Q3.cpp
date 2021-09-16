#include <iostream>

using namespace std;

int main() {

  struct pessoa{
   char nome[50];
   int idade;
   char email[50];
  };

  struct pessoa Pessoa1;


  cout << "Digite o seu nome\n";
  cin >> Pessoa1.nome;
  cout << "Digite a sua idade\n";
  cin >> Pessoa1.idade;
  cout << "Digite o seu email\n";
  cin >> Pessoa1.email;

  cout << Pessoa1.nome << "\n";
  cout << Pessoa1.idade << "\n";
  cout << Pessoa1.email;
}