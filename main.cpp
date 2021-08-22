#include <iostream>
#include <random>

void preencherMatriz(int** m, int linha, int coluna){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,60); 

    
    for(int l = 0; l < linha; l++){
      for(int c = 0; c < coluna; c++){
        m[l][c] = dist6(rng);
      }
    }
}

void retornaSomaeMaiorElemento(int** m, int linha, int coluna, int* soma, int* maiorElemento){
  *maiorElemento = 0;
  *soma = 0;
  for(int l = 0; l < linha; l++){
    for(int c = 0; c < coluna; c++){
      *soma += m[l][c];
      if(m[l][c] > *maiorElemento){
        *maiorElemento = m[l][c];
      }
    }
  }
}
void deletarMatriz(int** m, int linha){
  for (int i = 0; i < linha; ++i)
    delete [] m[i];
delete [] m;
}

int main() {
    int linha, coluna, soma, maiorElemento;

    //Exercício 2
    std::cout << "Digite o tamanho da linha: ";
    std::cin >> linha;
    std::cout << "Digite o tamanho da coluna: ";
    std::cin >> coluna;

    int** matriz = new int*[linha];

    for(int i=0; i < linha; i++){
      matriz[i] = new int[coluna];
    }
    
    preencherMatriz(matriz, linha, coluna);
    retornaSomaeMaiorElemento(matriz, linha, coluna, &soma, &maiorElemento);
    for(int l = 0; l < linha; l++){
        for(int c = 0; c < coluna; c++){
          std::cout << "Matriz["<<l<<"]["<<c<<"] = " << matriz[l][c]<<"\n";
        }
      }
    std::cout << "Valor da soma: " << soma <<"\n"<< "Valor do maior Elemento: " << maiorElemento;
    deletarMatriz(matriz, linha);


    
}