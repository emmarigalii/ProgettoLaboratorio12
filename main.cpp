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
    Note(const string& n, const string& t) : nome(n), testo(t) {}

    bool IsBlocked() const { return bloccata; }

    bool IsImportante() const { return importante; }

    const string& getNome() const { return nome; }

    const string& getTesto() const { return testo; }


    void Blocca() { bloccata = true; }

    void Sblocca() { bloccata = false; }

    void Importante() { importante = true; }

    void NonImportante() { importante = false; }

    void ModificaNota(string& nuovotesto) {
        if (!bloccata) testo = nuovotesto;
        else cout << "Nota bloccata, impossibile modificare.\n";

    }

    void EliminaNota(string& nome){
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
    Collezione(const string& n): nome(n){}

    const string& getNome() const {return nome;}

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

    int size() const {return note.size(); }

};





int main() {
    //crazione collezioni
    Collezione lavoro("lavoro");
    Collezione casa("Casa");
    Collezione importanti("Importanti");

    //creazione note
    auto n1 = make_shared<Note> ("Meeting", "Riunione alle 10");
    auto n2 = make_shared<Note>("Spesa", "Latte, pane, pasta");

    //aggiunta a collezioni
    lavoro.AggiungiNota(n1);
    casa.AggiungiNota(n2);

    //aggiunta nota importante
    importanti.AggiungiNota(n1);

    n1->Blocca();
    lavoro.EliminaNota(n1); //non deve essere eliminata
    return 0;

}
