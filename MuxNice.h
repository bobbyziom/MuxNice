#ifndef MuxNice_h
#define MuxNice_h

#include <Arduino.h>  

class MuxNice {

	public:

		MuxNice(int channels);
		void assignCtrlPins(int pin1, int pin2, int pin3);
		void assignCtrlPins(int pin1, int pin2, int pin3, int pin4);
		void assignDataPin(int dataPin);
		void write(int channel, int toWrite);
		int read(int channel);	
		void runTest();

	private:

		char _channels;
		char _controlPin[4];
		int _dataPin;

};

#endif