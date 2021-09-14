#include <iostream>

using namespace std;

int main() {

int n;

  cout << "Digite um número\n";
  cin >> n;

  cout << "Números ímpares da sequência\n";

    for(int i=0;i<=n;i++){
      if(i%2!=0){
      cout << i << "\n";
    }

  }
}