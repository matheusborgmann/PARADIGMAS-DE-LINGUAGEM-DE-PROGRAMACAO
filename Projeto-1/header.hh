using namespace std;

string caixaAlta(string palavra) {

  for (int x = 0; x < palavra.length(); x++) {
    if (x == 0) {
      palavra[x] = toupper(palavra[x]);
    } else if (palavra[x - 1] == ' ') {
      palavra[x] = toupper(palavra[x]);
    }
  }

  return palavra;
}

string nivelDoAluno(){
  string nivel;
  
  cout << "\nDigite o nivel do(a) aluno(a) - calouro ou veterano" << endl;
  cin >> nivel;
  
  nivel = caixaAlta(nivel);
  
  while(nivel != "Calouro" && nivel != "Veterano"){
      
      cout << "Nivel invalido! Por favor, digite um nivel valido" << endl;
      cin >> nivel;
      
      nivel = caixaAlta(nivel);
    
  }

  return nivel;
  
}