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

