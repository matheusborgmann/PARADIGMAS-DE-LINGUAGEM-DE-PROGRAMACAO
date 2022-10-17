/*
Nomes: Gustavo Teixeira da Silva, Juan Menin Herrera, Matheus Estevam Borgmann e
Vinicius Selau da Silva Turno: noturno
*/
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits> 

#include "header.hh"

using namespace std;

typedef struct {
  string nome;
  int idade;
  float media;
  string nivel;
} aluno;

aluno lista_Alunos[30];

void menu();
void registrarAluno(int contadorDeAlunos);
void imprimirAlunos(int i);
void exibirCalouros(int contadorDeAlunos);
void exibirVeteranos(int contadorDeAlunos);
void mediaGeral(int contadorDeAlunos);
void mediaCalouros(int contadorDeAlunos);
void mediaVeteranos(int contadorDeAlunos);
void listarAlunosSuperiores(int contadorDeAlunos);
void listarCalourosSuperiores(int contadorDeAlunos);
void listarVeteranosSuperiores(int contadorDeAlunos);

void mediaCalouros(int contadorDeAlunos);
void mediaVeteranos(int contadorDeAlunos);
void listarAlunosSuperiores(int contadorDeAlunos);
void listarCalourosSuperiores(int contadorDeAlunos);
void listarVeteranosSuperiores(int contadorDeAlunos);

int main() { menu(); }

void menu() {
  int opcao, contadorDeAlunos = 0;

  do {
    cout << "\n0 - Encerrar sistema\n1 - Registrar um(a) aluno(a) "
            "\n2 - Listar todos os alunos registrados\n3 - "
            "Listar alunos calouros registrados\n4 - Listar alunos veteranos "
            "registrados\n5 - Mostrar a media de todas as notas registradas\n6 "
            "- Apresentar a media de notas referente aos calouros\n7 - "
            "Apresentar a media de notas referentes aos veteranos\n8 - Listar "
            "alunos com  medias superiores ou inferiores a seis\n9 - Listar "
            "calouros com medias iguais ou superiores a seis\n10 - Listar "
            "veteranos com medias iguais ou superiores a seis"
         << endl;
    cin >> opcao;

    switch (opcao) {
    case 0:
      cout << "Encerrando sistema..." << endl;
      break;
    case 1:
      registrarAluno(contadorDeAlunos);
      contadorDeAlunos++;
      break;
    case 2:
      for (int contador = 0; contador < contadorDeAlunos; contador++) {
        
        imprimirAlunos(contador);
      }
      break;
    case 3:
      exibirCalouros(contadorDeAlunos);
      break;
    case 4:
      exibirVeteranos(contadorDeAlunos);
      break;
    case 5:
      mediaGeral(contadorDeAlunos);
      break;
    case 6:
      mediaCalouros(contadorDeAlunos);
      break;
    case 7:
      mediaVeteranos(contadorDeAlunos);
      break;
    case 8:
      listarAlunosSuperiores(contadorDeAlunos);
      break;
    case 9:
      listarCalourosSuperiores(contadorDeAlunos);
      break;
    case 10:
      listarVeteranosSuperiores(contadorDeAlunos);
      break;
    default:
      cout << "\nOpcao invalida\n" << endl;
      break;
    }
  } while (opcao != 0);
}
/*
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
*/  
void registrarAluno(int contadorDeAlunos) {
  int i = contadorDeAlunos, idadeInt;
  string nome, nivel;
  float nota;
  cin.ignore();

  cout << "\nDigite o nome do(a) aluno(a)" << endl;
  getline(cin, nome);

  nome = caixaAlta(nome);
  lista_Alunos[i].nome = nome;

  cout << "\nDigite a quantos anos o(a) aluno(a) tem" << endl;
  cin >> idadeInt;
  

  while(true){
  
  if(cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "\nPonha uma idade válida e em números!\n" << endl;
    cin>>idadeInt;
  }
  if(!cin.fail()){
    lista_Alunos[i].idade = idadeInt;
    break;
  }
  }

  cin.clear();

  lista_Alunos[i].nivel = nivelDoAluno();

  cout << "Digite a media: " << endl;
  cin >> nota;
 
  while(true){
    if(cin.fail()){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "Media inválida. Insira um valor entre 0 e 10\n";
      cin >> nota;
  }
     if(!cin.fail()){
    lista_Alunos[i].media = nota;
    break;
  }
  }
}
/*
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
*/  
void imprimirAlunos(int i){

  cout << endl
           << lista_Alunos[i].nome << endl
           << lista_Alunos[i].idade << " anos" << endl
           <<lista_Alunos[i].nivel << endl
           <<"Media: " << fixed << setprecision(2) << lista_Alunos[i].media << endl;
}


void exibirCalouros(int contadorDeAlunos) {

  for (int i = 0; i < contadorDeAlunos; i++) {
    
    if (lista_Alunos[i].nivel == "Calouro") {
      imprimirAlunos(i);
    }
  }
}

void exibirVeteranos(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {
    
    if (lista_Alunos[i].nivel == "Veterano") {
      imprimirAlunos(i);
      
    }
  }
}
/*
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
*/  
void mediaGeral(int contadorDeAlunos) {
  float mediaTotal = 0;
  int alunos = 0;

  for (int i = 0; i < contadorDeAlunos; i++) {
    alunos++;
      
    mediaTotal += lista_Alunos[i].media;
  }
  
  mediaTotal = mediaTotal / alunos;

  cout << endl << "Media total da media dos alunos: " << mediaTotal << endl;
}

void mediaCalouros(int contadorDeAlunos) {
  float mediaTotal = 0;
  int calouros = 0;

  for (int i = 0; i < contadorDeAlunos; i++) {
    
    if (lista_Alunos[i].nivel == "Calouro") {
      calouros++;
      mediaTotal += lista_Alunos[i].media;
    }
  }
  
  mediaTotal = mediaTotal / calouros;

  cout << endl << "Media total da media dos calouros: " << mediaTotal << endl;
}

void mediaVeteranos(int contadorDeAlunos) {
  float mediaTotal = 0;
  int veteranos = 0;

  for (int i = 0; i < contadorDeAlunos; i++) {

    if (lista_Alunos[i].nivel == "Veterano") {
      
      veteranos++;
      mediaTotal += lista_Alunos[i].media;
      
    }
  }
  mediaTotal = mediaTotal / veteranos;

  cout << endl << "Media total da media dos veteranos: " << mediaTotal << endl;
}
/*
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
*/  
void listarAlunosSuperiores(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {
    
    if (lista_Alunos[i].media >= 6) {
      
      imprimirAlunos(i);
      
    }
  }
}

void listarCalourosSuperiores(int contadorDeAlunos) {
 for (int i = 0; i < contadorDeAlunos; i++) {

    if (lista_Alunos[i].nivel == "Calouro") {
      
    if (lista_Alunos[i].media >= 6) {
      imprimirAlunos(i);
    }
  }
}
}

void listarVeteranosSuperiores(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {
    
      if (lista_Alunos[i].nivel == "Veterano") {
    
        if (lista_Alunos[i].media >= 6) {
          imprimirAlunos(i);
        }
      }
  }
}