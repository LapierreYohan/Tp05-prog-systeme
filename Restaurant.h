#include "sema.h"

class Restaurant {
private:
    bool isFull;
    int nbPlaces;
    int nbClient;
    CSemaphore* places;
    CSemaphore* protectVar;        
public:
    Restaurant(int);
    void arriver();
    void partir();
    ~Restaurant();
};