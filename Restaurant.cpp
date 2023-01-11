#include "Restaurant.h"

using namespace std;

Restaurant::Restaurant(int nbPlace) {
    this->places = new CSemaphore(nbPlace);
    this->protectVar = new CSemaphore(1);
    this->nbClient = 0;
    this->nbPlaces = nbPlace;
    this->isFull = false;
}

void Restaurant::arriver() {

    this->places->wait();
    this->protectVar->wait();
    nbClient++;
    if (this->nbClient == this->nbPlaces) {
        cout << "Le restaurant est plein !" << endl;
        this->isFull = true;
    }
    this->protectVar->notify();
}

void Restaurant::partir() {

    this->protectVar->wait();
    nbClient--;
    if (this->isFull == true && this->nbClient == 0) {
        cout << "Je libère le restaurant !" << endl;
        for (int i = 0; i < this->nbPlaces; i++) {
            this->places->notify();
        }
        this->isFull = false;
    } 
    
    this->protectVar->notify();
}

Restaurant::~Restaurant() {
    delete this->places;
    delete this->protectVar;
}