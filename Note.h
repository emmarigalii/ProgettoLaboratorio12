
#ifndef PROGETTOLABORAATORIO12_NOTE_H
#define PROGETTOLABORAATORIO12_NOTE_H


#pragma once
#include <string>
using namespace std;

class Note {
private:
    string nome;
    string testo;
    bool bloccata = false;

public:
    Note(const string& n, const string& t);

    bool IsBlocked() const;
    const string& getNome() const;
    const string& getTesto() const;
    void Blocca();
    void Sblocca();
    void ModificaNota(string& nuovotesto);
    void EliminaNota(string& nome);
};


#endif //PROGETTOLABORAATORIO12_NOTE_H
