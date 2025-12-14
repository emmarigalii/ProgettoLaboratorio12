#include "Note.h"
#include <iostream>
using namespace std;

Note::Note(const string& n, const string& t) : nome(n), testo(t) {}

bool Note::IsBlocked() const { return bloccata; }
const string& Note::getNome() const { return nome; }
const string& Note::getTesto() const { return testo; }
void Note::Blocca() { bloccata = true; }
void Note::Sblocca() { bloccata = false; }
void Note::ModificaNota(string& nuovotesto) {
    if (!bloccata) testo = nuovotesto;
    else cout << "Nota bloccata, impossibile modificare.\n";
}
void Note::EliminaNota(string& nome){
    if (bloccata) cout<< "Nota bloccata, impossibile eliminare. \n";
    else{
        nome.clear();
        testo.clear();
        cout << "Nota eliminata con successo. \n";
    }
}
