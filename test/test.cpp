#include <cctype>   // char-behandling
#include <cstring>  // strengbehandling
#include <iostream> // innlesing/utskrift

using namespace std; // bruker standard navnerom

int main() {                // ikke void her!
  char text[5];             // en streng med maks lengde 5
  cout << "Skriv et ord: "; // utskrift, bruker <iostream>
  cin >> text;              // innlesing, bruker <iostream>

  for (int i = 0; i < strlen(text); i++) { // strlen() fins i <cstring>
    text[i] = toupper(text[i]);            // gjør om til store bokstaver, bruker <cctype>
  }
  cout << "Bare store bokstaver: " << text << endl;

  for (int j = 0; j < strlen(text); j++) {
    text[j] = tolower(text[j]); // gjør om til små bokstaver, bruker <cctype>
  }
  cout << "Bare små bokstaver: " << text << endl;
}