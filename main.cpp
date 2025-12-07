#include <iostream>
#include <string>
#include <memory>
#include <list>
using namespace std;

class Note {
private:
    string nome;
    string testo;
    bool bloccata = false;
    bool importante = false;

public:
    Note(const string n, const string t) : nome(n), testo(t) {}

    bool IsBlocked() const { return bloccata; }

    bool IsImportante() const { return importante; }

    const string getNome() const { return nome; }

    const string getTesto() const { return testo; }


    void Blocca() { bloccata = true; }

    void Sblocca() { bloccata = false; }

    void Importante() { importante = true; }

    void NonImportante() { importante = false; }

    void ModificaNota(string nuovotesto) {
        if (!bloccata) testo = nuovotesto;
        else cout << "Nota bloccata, impossibile modificare.\n";

    }

    void EliminaNota(){
        if (bloccata) cout<< "Nota bloccata, impossibile eliminare. \n";
        else{
            nome.clear();
            testo.clear();
            cout << "Nota eliminata con successo. \n";
        }


    }


};

class Collezione {
    string nome;
    list<shared_ptr<Note>> note;

public:
    Collezione(const string n): nome(n){}

    void AggiungiNota( shared_ptr<Note> nota){
        note.push_back(nota);

    }

    void EliminaNota ( shared_ptr<Note> nota){
        if (nota->IsBlocked()){
            cout<< "impossibile eliminare nota. \n";
        }
        else
            note.remove(nota);

    }

};





int main() {
    std::cout << "Ciaooooo"<< std::endl;
    return 0;
}
