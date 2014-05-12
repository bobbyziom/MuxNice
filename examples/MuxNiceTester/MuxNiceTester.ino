//
// Mux library for arduino
//
// - bobbyziom
//

#include <MuxNice.h>

// instanciate a mux (8 channel (write 16 for 16 channel)
MuxNice myMux(8);

void setup() {
  
  // assign control pins
  myMux.assignCtrlPins(2,3,4);
  
  // assign datapin (works both for in and out)
  myMux.assignDataPin(A5);
  
}

void loop() {
  
  // connect LED to all pins and test it
  myMux.runTest();
  
  // other methods:
  // myMux.write(channel, whatToWrite);
  // myMux.read(channel);
  
}
