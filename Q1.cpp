#include <iostream>

using namespace std;

int main(){

int n, soma=0;

cout << "Digite um número\n";
cin >> n;

if(n<0){
  cout << "Contagem encerrada: Número negativo\n";
} else{
  for(;n>0;){
    cout << "Digite um número\n";
    soma = soma+n;
    cin >> n;
  }
  cout << "Contagem encerrada: Número negativo\nSoma dos números digitados: " << soma;
}

}