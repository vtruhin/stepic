#include <stdio.h>
#include <unistd.h>

void who_wc() {
    int pfd[2];
    pipe(pfd);
    if(!fork()) {
        close(STDOUT_FILENO);
        dup2(pfd[1], STDOUT_FILENO);
        close(pfd[1]);
        close(pfd[0]);
        execlp("who", "who", NULL);
    } else {
        close(STDIN_FILENO);
        dup2(pfd[0], STDIN_FILENO);
        close(pfd[1]);
        close(pfd[0]);
        execlp("wc", "wc", "-l", NULL);
        // wait(NULL);
        // wait(NULL);
        }
}

int main (int argc, char ** argv) {
    who_wc();
    return 0;
}
