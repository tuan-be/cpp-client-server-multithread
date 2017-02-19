#include <iostream>
#include "mythread.h"
#include "server.h"

using namespace std;

int main() {
  cout << "Starting server at host 127.0.0.1 and port 30696!" << endl;

  Server *s;
  s = new Server();

  //Main loop
  s->AcceptAndDispatch();

  return 0;
}
