/*
Nomes: Gustavo Teixeira da Silva, Juan Menin Herrera, Matheus Estevam Borgmann e Vinicius Selau da Silva 
Turno: noturno
*/
#include <iostream>
#include <string>
#include "header.hh"

using namespace std;

string name[30];
int age[30];
float media[30];
string level[30];
/* 
class Alunos {
public:
  string nome;
  int idade;
  float notas[5];
  string nivel;
};
Alunos aluno[30]; */

void menu();
void registrarAluno(int contadorDeAlunos);
string caixaAlta(string nome);
/* void registrarNotas(int contadorDeAlunos); */
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
      /* registrarNotas(contadorDeAlunos); */
      break;
    case 3:
      for (int contador = 0; contador < contadorDeAlunos; contador++) {

        cout << endl
             << name[contador] << endl
             << age[contador] << " anos" << endl
             << level[contador] << endl
             << media[contador] << endl;
              
        
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
  string nome, nivel, idadeString;
  
   
 
  cout << "\nDigite o nome do(a) aluno(a)" << endl;
  cin.ignore(); 
  getline(cin, nome);

  nome = caixaAlta(nome);
  name[i] = nome;



  cout << "\nDigite quantos anos o(a) aluno(a) tem: ";
  cin >> idadeString;
  cin.ignore(); 

  int idadeInt;

  if(idadeInt > 0 && idadeInt < 100){
    idadeInt = stoi(idadeString);
  } else {
    cin >> idadeString;
  }

  /* for(;;){ // ;; é equivalente de "até ser verdadeiro"
    cout << "\nDigite quantos anos o(a) aluno(a) tem" << endl;
    getline(cin, idadeString);

    try
        {
            i = stoi( idadeString, &pos );
        }
        catch ( invalid_argument& )
        {
            cout << "Por favor digite um número!\n";
            continue;
        }
        catch ( out_of_range& )
        {
            cout << "Ninguém é tão velho assim!!!\n";
            continue;
        }
    
  } */
  
  age[i] = idadeInt;

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
  
  level[i] = nivel;

  cout << "Digite a media: " << endl;
  cin >> media[i];
  if(media[i] > 10 || media[i] < 0){
    cout << "Media inválida. Insira um valor entre 0 e 10";
    cin >> media[i];
  }
  
}


 
void exibirCalouros(int contadorDeAlunos) {

  for (int i = 0; i < contadorDeAlunos; i++) {
    
    if (level[i] == "Calouro") {
      cout << endl
           << name[i] << endl
           << age[i] << " anos" << endl
           << level[i] << endl
           << "Media: " << media[i] << endl;
    }
  }
}


void exibirVeteranos(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {
    
    if (level[i] == "Veterano") {
      cout << endl
           << name[i] << endl
           << age[i] << " anos" << endl
           <<level[i] << endl
           <<"Media: " << media[i] << endl;
      
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

  cout << endl << "Media total da media dos alunos: " << mediaTotal << endl;
  
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

  cout << endl << "Media total da media dos calouros: " << mediaTotal << endl;
  
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

  cout << endl << "Media total da media dos veteranos: " << mediaTotal << endl;
}

void listarAlunosSuperiores(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {
    
    if (media[i] >= 6) {
      
      cout << endl << name[i] << endl << "Media: " << media[i] << endl;
      
    }
  }
}

void listarCalourosSuperiores(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {

    if (level[i] == "Calouro") {
      
    if (media[i] >= 6) {
      cout << endl << name[i] << endl << "Media: " << media[i] << endl;
    }
  }
}
}

void listarVeteranosSuperiores(int contadorDeAlunos) {
  for (int i = 0; i < contadorDeAlunos; i++) {
    
      if (level[i] == "Veterano") {
    
        if (media[i] >= 6) {
          cout << endl << name[i] << endl << "Media: " << media[i] << endl;
        }
      }
  }
}