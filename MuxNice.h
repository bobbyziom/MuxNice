#ifndef MuxNice_h
#define MuxNice_h

#include <Arduino.h> 

#define MUX_16_PINS 4 
#define MUX_8_PINS 4
#define CHANNELS16 16 
#define CHANNELS8 8

class MuxNice {

	public:

		MuxNice(int channels, int dataPin);
		void assignCtrlPins(int pin1, int pin2, int pin3);
		void assignCtrlPins(int pin1, int pin2, int pin3, int pin4);
		void assignDataPin(int dataPin);
		void open(int channel);
		void write(int channel, int toWrite);
		int read(int channel);	
		void demuxMe();
		void goDigital();
		void runTest();

	private:

		char _channels;
		char _controlPin[4];
		int _dataPin;
		bool _demux;

};

#endif