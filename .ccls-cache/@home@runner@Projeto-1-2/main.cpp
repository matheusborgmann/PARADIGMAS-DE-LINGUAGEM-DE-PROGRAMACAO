/*
Nomes: Gustavo Teixeira da Silva, Juan Menin Herrera, Matheus Estevam Borgmann e Vinicius Selau da Silva 
Turno: noturno
*/
#include <iostream>
#include <string>

using namespace std;

string name[30];

class Alunos {
public:
  string nome;
  int idade;
  float notas[5];
  string nivel;
};
Alunos aluno[30];

void menu();
void registrarAluno(int contadorDeAlunos);
string caixaAlta(string nome);
void registrarNotas(int contadorDeAlunos);
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
    cout << "\n0 - Encerrar sistema\n1 - Registrar um(a) aluno(a)\n2 - "
            "Registrar notas\n3 - Listar todos os alunos registrados\n4 - "
            "Listar alunos calouros registrados\n5 - Listar alunos veteranos "
            "registrados\n6 - Mostrar a media de todas as notas registradas\n7 "
            "- Apresentar a media de notas referente aos calouros\n8 - "
            "Apresentar a media de notas referentes aos veteranos\n9 - Listar "
            "alunos com  medias superiores ou inferiores a seis\n10 - Listar "
            "calouros com medias iguais ou superiores a seis\n11 - Listar "
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
      registrarNotas(contadorDeAlunos);
      break;
    case 3:
      for (int contador = 0; contador < contadorDeAlunos; contador++) {
        float media = 0;
        bool temNotas = true;
        cout << endl
             << name[contador] << endl
             << aluno[contador].idade << " anos" << endl
             << aluno[contador].nivel << endl;

        for (int i = 0; i < 5; i++) {
          if (aluno[contador].notas[i] <= 0) {
            cout << aluno[contador].nome
                 << " não possui notas registradas ainda" << endl;
            temNotas = false;
            break;
          } else {
          }
          if (temNotas == true) {
            cout << "Notas " << i << ": " << aluno[contador].notas[i] << endl;
          }
        }
      }
      break;
    case 4:
      exibirCalouros(contadorDeAlunos);
      break;
    case 5:
      exibirVeteranos(contadorDeAlunos);
      break;
    case 6:
      mediaGeral(contadorDeAlunos);
      break;
    case 7:
      mediaCalouros(contadorDeAlunos);
      break;
    case 8:
      mediaVeteranos(contadorDeAlunos);
      break;
    case 9:
      listarAlunosSuperiores(contadorDeAlunos);
      break;
    case 10:
      listarCalourosSuperiores(contadorDeAlunos);
      break;
    case 11:
      listarVeteranosSuperiores(contadorDeAlunos);
      break;
    default:
      cout << "\nOpcao invalida\n" << endl;
      break;
    }
  } while (opcao != 0);
}

void registrarAluno(int contadorDeAlunos) {
  int i = contadorDeAlunos;
  string nome, nivel;
  cin.ignore();

  cout << "\nDigite o nome do(a) aluno(a)" << endl;
  getline(cin, nome);
 
  nome = caixaAlta(nome);
 name[i] = nome;

  cout << "\nDigite quantos anos o(a) aluno(a) tem" << endl;
  cin >> aluno[i].idade;

  cout << "\nDigite o nivel do(a) aluno(a) - calouro ou veterano" << endl;
  cin >> nivel;

  nivel = caixaAlta(nivel);

  do{
  if (nivel != "Calouro" && nivel != "Veterano") {
    cout << "Nivel invalido! Por favor, digite um nivel valido" << endl;
    cin >> nivel;
    nivel = caixaAlta(nivel);
  }
    }while(nivel != "Calouro" && nivel != "Veterano");
  aluno[i].nivel = nivel;

  for (int cont = 0; cont < 5; cont++)
    aluno[i].notas[cont] = -1;
}

string caixaAlta(string nome) {

  for (int x = 0; x < nome.length(); x++) {
    if (x == 0) {
      nome[x] = toupper(nome[x]);
    } else if (nome[x - 1] == ' ') {
      nome[x] = toupper(nome[x]);
    }
  }

  return nome;
}

void registrarNotas(int contadorDeAlunos) {
  string nomeAluno;
  int op, numeroDoAluno, cont;
  float notas;
  int totalDeAlunos = contadorDeAlunos;

  do {
    cout << "\n0 - Retornar para o menu anterior\n1 - Procurar aluno por nome"
         << endl;
    cin >> op;

    switch (op) {
    case 0:
      break;
    case 1:
      cin.ignore();
      cout << "\nDigite o nome do(a) aluno(a): " << endl;
      getline(cin, nomeAluno);
      nomeAluno = caixaAlta(nomeAluno);

      for (int i = 0; i <= totalDeAlunos; i++) {
        if (name[i] == nomeAluno) {
          numeroDoAluno = i;
          cout << "Aluno " << aluno[numeroDoAluno].nome;
          break;
        }
      }

      for (cont = 0; cont < 5; cont++) {
        cout << "\nDigite a nota " << cont + 1 << endl;
        cin >> notas;
        do {
          if (notas < 0 || notas > 10) {
            cout << "\nNotas não podem ser menores que 0 ou maiores que "
                    "10\nDigite a nota novamente: ";
            cin >> notas;
          }
        } while (notas < 0 || notas > 10);
        aluno[numeroDoAluno].notas[cont] = notas;
      }

      for (cont = 0; cont < 5; cont++) {
        cout << "Nota " << cont << ":" << aluno[numeroDoAluno].notas[cont]
             << endl;
      }

      break;
    default:
      cout << "Opcao invalida";
      break;
    }
  } while (op != 0);
}

void exibirCalouros(int contadorDeAlunos) {

  for (int i = 0; i < contadorDeAlunos; i++) {
    bool temNotas = true;
    float media = 0;
    if (aluno[i].nivel == "Calouro") {
      cout << endl
           << name[i] << endl
           << aluno[i].idade << " anos" << endl
           << aluno[i].nivel << endl;

      for (int j = 0; j < 5; j++) {
        if (aluno[i].notas[j] <= 0) {
          cout << name[i] << " não possui notas registradas ainda"
               << endl;
          temNotas = false;
          break;
        } else {
          media += aluno[i].notas[j];
        }
      }
      if (temNotas == true) {
        media = media / 5;
        cout << "Media: " << media << endl;
      }
    }
  }
}

void exibirVeteranos(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {
    float media = 0;
    bool temNotas = true;
    if (aluno[i].nivel == "Veterano") {
      cout << endl
           << name[i] << endl
           << aluno[i].idade << " anos" << endl
           << aluno[i].nivel << endl;

      for (int j = 0; j < 5; j++) {
        if (aluno[i].notas[j] <= 0) {
          cout << name[i] << " não possui notas registradas ainda"
               << endl;
          temNotas = false;
          break;
        } else {
          media += aluno[i].notas[j];
        }
      }
      if (temNotas == true) {
        media = media / 5;
        cout << "Media: " << media << endl;
      }
    }
  }
}

void mediaGeral(int contadorDeAlunos) {
  float mediaTotal = 0;
  int alunos = 0;

  for (int i = 0; i < contadorDeAlunos; i++) {
    float media = 0;
    alunos++;
    for (int j = 0; j < 5; j++) {
      media += aluno[i].notas[j];
    }
    media = media / 5;
    mediaTotal += media;
  }
  mediaTotal = mediaTotal / alunos;

  cout << endl << "Media total da media dos alunos: " << mediaTotal << endl;
}

void mediaCalouros(int contadorDeAlunos) {
  float mediaTotal = 0;
  int calouros = 0;

  for (int i = 0; i < contadorDeAlunos; i++) {
    float media = 0;
    if (aluno[i].nivel == "Calouro") {
      calouros++;
      for (int j = 0; j < 5; j++) {
        media += aluno[i].notas[j];
      }
      media = media / 5;
      mediaTotal += media;
    }
  }
  mediaTotal = mediaTotal / calouros;

  cout << endl << "Media total da media dos calouros: " << mediaTotal << endl;
}

void mediaVeteranos(int contadorDeAlunos) {
  float mediaTotal = 0;
  int veteranos = 0;

  for (int i = 0; i < contadorDeAlunos; i++) {
    float media = 0;
    if (aluno[i].nivel == "Veterano") {
      veteranos++;
      for (int j = 0; j < 5; j++) {
        media += aluno[i].notas[j];
      }
      media = media / 5;
      mediaTotal += media;
    }
  }
  mediaTotal = mediaTotal / veteranos;

  cout << endl << "Media total da media dos veteranos: " << mediaTotal << endl;
}

void listarAlunosSuperiores(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {
    float media = 0;
    for (int j = 0; j < 5; j++) {
      media += aluno[i].notas[j];
    }
    media = media / 5;
    if (media >= 6) {
      cout << endl << name[i] << endl << "Media: " << media << endl;
    }
  }
}

void listarCalourosSuperiores(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {
    float media = 0;
    if (aluno[i].nivel == "Calouro") {
      for (int j = 0; j < 5; j++) {
        media += aluno[i].notas[j];
      }
    }
    media = media / 5;
    if (media >= 6) {
      cout << endl << name[i] << endl << "Media: " << media << endl;
    }
  }
}

void listarVeteranosSuperiores(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {
    float media = 0;
    if (aluno[i].nivel == "Veterano") {
      for (int j = 0; j < 5; j++) {
        media += aluno[i].notas[j];
      }
    }
    media = media / 5;
    if (media >= 6) {
      cout << endl << name[i] << endl << "Media: " << media << endl;
    }
  }
}