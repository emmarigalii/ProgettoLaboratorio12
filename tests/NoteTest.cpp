#include <gtest/gtest.h>
#include "Note.h"
#include "Collezione.h"
#include <memory>

// Test della classe Note
TEST(NoteTest, ModificaQuandoSbloccata) {
Note n("Titolo", "Testo iniziale");
std::string nuovoTesto = "Testo modificato";
n.ModificaNota(nuovoTesto);
EXPECT_EQ(n.getTesto(), "Testo modificato");
}

TEST(NoteTest, NonModificaQuandoBloccata) {
Note n("Titolo", "Testo iniziale");
n.Blocca();
std::string nuovoTesto = "Testo modificato";
n.ModificaNota(nuovoTesto);
EXPECT_EQ(n.getTesto(), "Testo iniziale"); // non deve cambiare
}

TEST(NoteTest, BloccaESblocca) {
Note n("Titolo", "Testo");
n.Blocca();
EXPECT_TRUE(n.IsBlocked());
n.Sblocca();
EXPECT_FALSE(n.IsBlocked());
}

// Test della classe Collezione
TEST(CollezioneTest, AggiungiNota) {
Collezione c("TestCollezione");
auto n = std::make_shared<Note>("Titolo", "Testo");
c.AggiungiNota(n);
EXPECT_EQ(c.size(), 1);
}

TEST(CollezioneTest, EliminaNota) {
Collezione c("TestCollezione");
auto n = std::make_shared<Note>("Titolo", "Testo");
c.AggiungiNota(n);
c.EliminaNota(n);
EXPECT_EQ(c.size(), 0);
}

TEST(CollezioneTest, EliminaNotaBloccata) {
Collezione c("TestCollezione");
auto n = std::make_shared<Note>("Titolo", "Testo");
n->Blocca();
c.AggiungiNota(n);
c.EliminaNota(n);
EXPECT_EQ(c.size(), 1); // non deve essere eliminata
}
