#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
  if (fork() == 0) {
    execl(
      "/usr/bin/g++",
      "g++",
      "--std=c++20",
      argv[1],
      "-o",
      "out.o",
      NULL
    );
  }
  wait(NULL);
  execl(
    "./out.o",
    NULL
  );
}
