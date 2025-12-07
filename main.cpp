#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Note {
private:
    string nome;
    string testo;
    bool bloccata=false;

public:
    Note(const string n, const string t) : nome(n), testo(t){}

    bool IsBlocked() const {return bloccata;}

    const string getNome() const {return nome;}
    const string getTesto() const {return testo;}


    void Blocca(){ bloccata=true;}
    void Sblocca(){ bloccata=false;}

    void ModificaNota(string nuovotesto){
        if (!bloccata) testo = nuovotesto;
        else cout<< "Nota bloccata, impossibile modificare.\n";

    }





};
int main() {
    std::cout << "Ciaooooo"<< std::endl;
    return 0;
}
