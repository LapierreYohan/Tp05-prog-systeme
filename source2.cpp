#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

using namespace std;

void handler(int sig);

int main(int argc, char const *argv[])
{
    int sec = 0;
    cout << "Rentrez un nombre de secondes : ";
    cin >> sec;
    cout << endl;

    signal (SIGALRM, handler);

    alarm(sec);

    cout << "Zzzzz...." << endl;
    pause();

    return EXIT_SUCCESS;
}

void handler(int sig) {
    cout << "Recu signal " << sig << " " << sys_siglist[sig] << endl;
    cout << "Je me reveille" << endl;
 
    return;
}
