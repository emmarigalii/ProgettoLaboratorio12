#include "Collezione.h"
#include <iostream>
using namespace std;

Collezione::Collezione(const string& n): nome(n){}

const string& Collezione::getNome() const {return nome;}

void Collezione::AggiungiNota(shared_ptr<Note> nota){
    note.push_back(nota);
    notify();
}

void Collezione::EliminaNota(shared_ptr<Note> nota){
    if (nota->IsBlocked()){
        cout<< "impossibile eliminare nota. \n";
    } else {
        note.remove(nota);
        notify();
    }
}

int Collezione::size() const { return note.size(); }

void Collezione::aggiungi(Observer* obs) { observers.push_back(obs); }
void Collezione::rimuovi(Observer* obs) { observers.remove(obs); }
void Collezione::notify() {
    for (auto obs : observers)
        obs->update(size());
}

CollezioneObserver::CollezioneObserver(const string& n) : nomeCollezione(n) {}
void CollezioneObserver::update(int count) {
    cout << "La collezione " << nomeCollezione << " contiene ora " << count << " note.\n";
}
