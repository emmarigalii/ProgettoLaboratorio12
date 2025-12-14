#include "Note.h"
#include "Collezione.h"
#include <memory>
using namespace std;

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
