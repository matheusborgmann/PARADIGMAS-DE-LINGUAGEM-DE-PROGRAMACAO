/*
Nomes: Gustavo Teixeira da Silva, Juan Menin Herrera, Matheus Estevam Borgmann e
Vinicius Selau da Silva Turno: noturno
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

#include "header.hh"

using namespace std;

string name[30];
int age[30];
float media[30];
string level[30];

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

void registrarAluno(int contadorDeAlunos) {
  int i = contadorDeAlunos, idadeInt;
  float nota;
  string nome, nivel;

  cout << "\nDigite o nome do(a) aluno(a)" << endl;
  cin.ignore();
  getline(cin, nome);

  nome = caixaAlta(nome);
  name[i] = nome;

  cout << "\nDigite quantos anos o(a) aluno(a) tem: ";
  cin >> idadeInt;

  if (idadeInt <= 0) {
    do {

      cout << "Idade errada, insira uma válida: ";
      cin >> idadeInt;

    } while (idadeInt <= 0);
  }

  level[i] = nivelDoAluno();

  cout << "Digite a media: " << endl;
  cin >> nota;

  if (nota < 0 || nota > 10) {
    while (nota < 0 || nota > 10) {

      cout << "Media inválida. Insira um valor entre 0 e 10\n";
      cin >> nota;
    }
  }

  media[i] = nota;
}

void imprimirAlunos(int i) {

  cout << endl
       << name[i] << endl
       << age[i] << " anos" << endl
       << level[i] << endl
       << "Media: " << fixed << setprecision(2) << media[i] << endl;
}

void exibirCalouros(int contadorDeAlunos) {

  for (int i = 0; i < contadorDeAlunos; i++) {

    if (level[i] == "Calouro") {
      imprimirAlunos(i);
    }
  }
}

void exibirVeteranos(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {

    if (level[i] == "Veterano") {
      imprimirAlunos(i);
    }
  }
}

void mediaGeral(int contadorDeAlunos) {

  float mediaTotal = 0;
  int alunos = 0;

  for (int i = 0; i < contadorDeAlunos; i++) {
    alunos++;

    mediaTotal += media[i];
  }

  mediaTotal = mediaTotal / alunos;

  if (alunos != 0) {
    cout << endl << "Media total da media dos alunos: " << mediaTotal << endl;
  } else {
    cout << endl << "Nenhum aluno registrado!" << endl;
  }
}

void mediaCalouros(int contadorDeAlunos) {

  float mediaTotal = 0;
  int calouros = 0;

  for (int i = 0; i < contadorDeAlunos; i++) {

    if (level[i] == "Calouro") {
      calouros++;
      mediaTotal += media[i];
    }
  }

  mediaTotal = mediaTotal / calouros;

  if (calouros != 0) {
    cout << endl << "Media total da media dos calouros: " << mediaTotal << endl;
  } else {
    cout << endl << "Nenhum calouro registrado!" << endl;
  }
}

void mediaVeteranos(int contadorDeAlunos) {
  float mediaTotal = 0;
  int veteranos = 0;

  for (int i = 0; i < contadorDeAlunos; i++) {

    if (level[i] == "Veterano") {

      veteranos++;
      mediaTotal += media[i];
    }
  }
  mediaTotal = mediaTotal / veteranos;

  if (veteranos != 0) {
    cout << endl
         << "Media total da media dos veteranos: " << mediaTotal << endl;
  } else {
    cout << endl << "Nenhum veterano registrado!" << endl;
  }
}

void listarAlunosSuperiores(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {

    if (media[i] >= 6) {

      imprimirAlunos(i);
    }
  }
}

void listarCalourosSuperiores(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {

    if (level[i] == "Calouro") {

      if (media[i] >= 6) {
        imprimirAlunos(i);
      }
    }
  }
}

void listarVeteranosSuperiores(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {

    if (level[i] == "Veterano") {

      if (media[i] >= 6) {
        imprimirAlunos(i);
      }
    }
  }
}
