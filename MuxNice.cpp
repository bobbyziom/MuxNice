#include <MuxNice.h>

int _muxChannel16[16][4] = {
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
};

int _muxChannel8[8][3] = {
    {0,0,0}, //channel 0
    {1,0,0}, //channel 1
    {0,1,0}, //channel 2
    {1,1,0}, //channel 3
    {0,0,1}, //channel 4
    {1,0,1}, //channel 5
    {0,1,1}, //channel 6
    {1,1,1}, //channel 7
};

MuxNice::MuxNice(int channels) {

	_channels = channels;

}

void MuxNice::assignCtrlPins(int pin1, int pin2, int pin3) {

	assignCtrlPins(pin1, pin2, pin3, 0);

}

void MuxNice::assignCtrlPins(int pin1, int pin2, int pin3, int pin4) {

	_controlPin[0] = pin1;
	_controlPin[1] = pin2;
	_controlPin[2] = pin3;
	_controlPin[3] = pin4;

	for(int i = 0; i < 4; i++) {

		pinMode(_controlPin[i], OUTPUT); 

	}

}

void MuxNice::assignDataPin(int dataPin) {

	_dataPin = dataPin;
	pinMode(_dataPin, OUTPUT);

}

void MuxNice::write(int channel, int toWrite) {

	if(_channels == 8) {

	    for(int i = 0; i < 3; i ++){
	      	digitalWrite(_controlPin[i], _muxChannel8[channel][i]);
	    }
	  
	    digitalWrite(_dataPin, toWrite);
		    
	}

	if(_channels == 16) {

	    for(int i = 0; i < 4; i ++){
	      	digitalWrite(_controlPin[i], _muxChannel16[channel][i]);
	    }
	  
	    digitalWrite(_dataPin, toWrite);
		    
	}

}

int MuxNice::read(int channel) {

	if(_channels == 8) {

		for(int i = 0; i < 3; i ++){
	    	digitalWrite(_controlPin[i], _muxChannel8[channel][i]);
	  	}

	  	int value = analogRead(_dataPin);

	  	return value;
 	}

 	if(_channels == 16) {

 		for(int i = 0; i < 4; i ++){
	    	digitalWrite(_controlPin[i], _muxChannel16[channel][i]);
	  	}

	  	int value = analogRead(_dataPin);

	  	return value;

 	}

}

void MuxNice::runTest() {

	if(_channels == 8) {

		for(int channel = 0; channel < 8; channel++) {
		  
		    for(int i = 0; i < 3; i ++){
		      	digitalWrite(_controlPin[i], _muxChannel8[channel][i]);
		    }
		  	
		    digitalWrite(_dataPin, HIGH);
		    delay(100);
		    digitalWrite(_dataPin, LOW);
		    
		}	

	}

	if(_channels == 16) {

		for(int channel = 0; channel < 16; channel++) {
		  
		    for(int i = 0; i < 4; i ++){
		      	digitalWrite(_controlPin[i], _muxChannel16[channel][i]);
		    }
		  
		    digitalWrite(_dataPin, HIGH);
		    delay(100);
		    digitalWrite(_dataPin, LOW);
		    
		}

	}

}