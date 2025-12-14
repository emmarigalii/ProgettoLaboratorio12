//
// Created by Samsung on 14/12/2025.
//

#ifndef PROGETTOLABORAATORIO12_COLLEZIONE_H
#define PROGETTOLABORAATORIO12_COLLEZIONE_H


#pragma once
#include <list>
#include <memory>
#include <string>
#include "Note.h"
using namespace std;

class Observer {
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

class Collezione : public Subject {
private:
    string nome;
    list<shared_ptr<Note>> note;
    list<Observer*> observers;

public:
    Collezione(const string& n);
    const string& getNome() const;
    void AggiungiNota(shared_ptr<Note> nota);
    void EliminaNota(shared_ptr<Note> nota);
    int size() const;
    void aggiungi(Observer* obs) override;
    void rimuovi(Observer* obs) override;
    void notify() override;
};

class CollezioneObserver : public Observer {
    string nomeCollezione;
public:
    CollezioneObserver(const string& n);
    void update(int count) override;
};


#endif //PROGETTOLABORAATORIO12_COLLEZIONE_H
