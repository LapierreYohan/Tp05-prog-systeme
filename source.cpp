#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

using namespace std;

void handler(int sig);

int main(int argc, char const *argv[])
{
    signal (SIGINT, handler);

    while(true) {}

    return EXIT_SUCCESS;
}

void handler(int sig) {
    cout << "Recu signal " << sig << " " << sys_siglist[sig] << endl;
    cout << "Creation d'un nouveau procesus" << endl;
    pid_t pid = fork();

     
    return;
}
