#pragma once

#include "ofMain.h"
#ifdef TARGET_RASPBERRY_PI
#include "ofxOMXVideoGrabber.h"
#endif

class captur{

    public:
        void setup(string type);
        void update();
        void draw(int x=0, int y=0);
        ofPixels getPixels();
        ofTexture getTexture();
        bool isReady();
        void close();

        // for now i will not implement recording here since in some cases recording may be seperate from capturing
        // void startRecording();
        // void stopRecording();

        string grabberType;
        int width, height;
        float framerate;

        ofVideoGrabber vidGrabber;
        #ifdef TARGET_RASPBERRY_PI
        ofxOMXVideoGrabber vidGrabber;
        #endif
};