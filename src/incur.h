#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "ofxOsc.h"
#include "ofxJSON.h"
#include "ofBaseApp.h"
#ifdef TARGET_RASPBERRY_PI
#include "TerminalListener.h"
#endif

#ifdef TARGET_RASPBERRY_PI
class incur : public ofxMidiListener, public KeyListener {
#else
class incur : public ofxMidiListener {
#endif
    public:
        //incur();
        void setupThis(string mapPath);
        void exit();

        bool midiListening();
        bool oscListening();
        bool analogListening();
        vector<vector<string>> getActions();

    // key listening
    #ifdef TARGET_RASPBERRY_PI
    TerminalListener consoleListener;
    void onCharacterReceived(KeyListenerEventData& e);
    #endif
    bool isKeyListening;
    vector<vector<string>> keyActions;
    
    void onKeyPress(int e); // removed this for now KeyListenerEventData& e);


    // midi listening 

    bool isMidiListening;
    vector<vector<string>> midiActions;
    void newMidiMessage(ofxMidiMessage& eventArgs);
	ofxMidiIn midiIn;
	std::vector<ofxMidiMessage> midiMessages;
	std::size_t maxMessages = 10; //< max number of messages to keep track of

    // osc listening

    ofxOscReceiver receiver;
    bool isOscListening;
    vector<vector<string>> checkForOsc();
    ofxJSONElement result;

    // analog listening (not implemeted yet)

    bool isAnalogListening;
};
