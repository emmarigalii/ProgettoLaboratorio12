#include <iostream>
#include <string>
#include <memory>
#include <list>
using namespace std;

class Observer{
public:
    virtual void update(int count) =0;
    virtual ~Observer()=default;
};

class Subject {
public:
    virtual void aggiungi(Observer* obs)= 0;
    virtual void rimuovi(Observer* obs)= 0;
    virtual void notify()= 0;
    virtual ~Subject()= default;
};

class Note {
private:
    string nome;
    string testo;
    bool bloccata = false;

public:
    Note(const string& n, const string& t) : nome(n), testo(t) {}

    bool IsBlocked() const { return bloccata; }


    const string& getNome() const { return nome; }

    const string& getTesto() const { return testo; }


    void Blocca() { bloccata = true; }

    void Sblocca() { bloccata = false; }


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

class Collezione : public Subject {
    string nome;
    list<shared_ptr<Note>> note;
    list<Observer*> observers;

public:
    Collezione(const string& n): nome(n){}

    const string& getNome() const {return nome;}

    void AggiungiNota( shared_ptr<Note> nota){
        note.push_back(nota);
        notify();

    }

    void EliminaNota ( shared_ptr<Note> nota){
        if (nota->IsBlocked()){
            cout<< "impossibile eliminare nota. \n";
        }
        else
            note.remove(nota);
            notify();
    }

    int size() const {return note.size(); }

    void aggiungi(Observer* obs) override {
        observers.push_back(obs);
    }

    void rimuovi(Observer* obs) override {
        observers.remove(obs);
    }

    void notify() override {
        for (auto obs : observers)
            obs->update(size());
    }

};

class CollezioneObserver : public Observer {
    string nomeCollezione;

public:
    CollezioneObserver(const string& n) : nomeCollezione(n){}

    void update(int count ) override {
        cout << "La collezione " << nomeCollezione << "  contiene ora " << count << " note.\n";
    }
};





int main() {
    //crazione collezioni
    Collezione lavoro("lavoro");
    Collezione casa("Casa");
    Collezione importanti("Importanti");
    Collezione personali("Personali");

    CollezioneObserver obsLavoro("Lavoro");
    CollezioneObserver obsCasa("Casa");
    CollezioneObserver obsImportanti ("Importanti");
    CollezioneObserver obsPersonali ("Personali");

    lavoro.aggiungi(&obsLavoro);
    casa.aggiungi(&obsCasa);
    importanti.aggiungi(&obsImportanti);
    personali.aggiungi(&obsPersonali);

    //creazione note
    auto n1 = make_shared<Note> ("Meeting", "Riunione alle 10");
    auto n2 = make_shared<Note>("Spesa", "Latte, pane, pasta");
    auto n3 = make_shared<Note>("Ricorda","appuntamento venerdi 18:30" );
    auto n4 = make_shared<Note>("Lista regali natale", "1.scarpe, 2.cornice, 3.felpa");

    //aggiunta a collezioni
    lavoro.AggiungiNota(n1);
    casa.AggiungiNota(n2);
    personali.AggiungiNota(n4);
    personali.AggiungiNota(n3);

    //aggiunta nota importante
    importanti.AggiungiNota(n1);
    importanti.AggiungiNota(n3);

    n1->Blocca();
    lavoro.EliminaNota(n1); //non deve essere eliminata
    personali.EliminaNota(n4);
    return 0;

}
