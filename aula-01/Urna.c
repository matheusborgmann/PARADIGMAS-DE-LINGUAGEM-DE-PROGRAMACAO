/*
Integrantes: Juan Menin Herrera, Matheus Estevam Borgmann, Vinicius Selau da Silva 
Professora: Adriana Neves 
Turno: noturno 
*/
#include <stdio.h>

struct Candidatos{
    char *nome;
    int votos;
};

typedef struct Candidatos candidato;

void menu(struct Candidatos candidato[6]);

void contagemDeVotos(struct Candidatos candidato[6]);

int main(void) {
  struct Candidatos candidato[6];
      
  menu(candidato);
  contagemDeVotos(candidato);
  return 0;
}

void menu(struct Candidatos candidato[]) {
  int op;
  int lovelace = 0, einstein = 0, jobs = 0, turing = 0, nulo = 0, branco = 0;
  
  do {
    printf("\n-----Urna da Computacao-----\n\n\t 1 - Ada Lovelace\n\t 2 - Albert Einstein\n\t 3 - Steve Jobs\n\t 4 - Alan Turing\n\t 5 - Voto Nulo\n\t 6 - Voto branco\n\t 0 - Encerrar votacao\n\n\t ");
    scanf("%d", &op);
    switch (op) {
    case 0:
      candidato[0].nome = "Ada Lovelace";
      candidato[0].votos = lovelace;
      candidato[1].nome = "Albert Einstein";
      candidato[1].votos = einstein;
      candidato[2].nome = "Steve Jobs";
      candidato[2].votos = jobs;
      candidato[3].nome = "Alan Turing";
      candidato[3].votos = turing;
      candidato[4].nome = "Voto nulo";
      candidato[4].votos = nulo;
      candidato[5].nome = "Voto branco";
      candidato[5].votos = branco;
      
      printf("Terminando contagem...\n");
      break;
    case 1:
      printf("Ada Lovelace");
      lovelace++;
      break;
    case 2:
      printf("Albert Einstein");
      einstein++;
      break;
    case 3:
      printf("Steve Jobs");
      jobs++;
      break;
    case 4:
      printf("Alan Turing");
      turing++;
      break;
    case 5:
      printf("Voto nulo");
      nulo++;
      break;
    case 6:
      printf("Voto branco");
      branco++;
      break;
    default:
      printf("Opção inválida");
      break;
    }
  } while (op != 0);
}

void contagemDeVotos(struct Candidatos candidato[]) {
  struct Candidatos temp;
  int total = 0,  i, j;
  float totalBranco;
   
  for (i = 0; i < 6; ++i){
     total += candidato[i].votos ; 
    } 
  
  totalBranco = ( (float)candidato[5].votos / (float)total ) * 100;
   
  
  for (i = 0; i < 5; ++i){
      for (j = i + 1; j < 5; ++j){
          if (candidato[i].votos < candidato[j].votos){
            temp = candidato[i];
            candidato[i] = candidato[j];
            candidato[j] = temp;
          }
      }    
    printf("\n%s %s %d %s\n", candidato[i].nome, "recebeu um total de", candidato[i].votos, "votos");
  }
  
  printf("\nTotal de votos brancos %.2f%%\n", totalBranco);
 
}
