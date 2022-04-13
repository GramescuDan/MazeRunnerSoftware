#include <iostream>
#include <avr/interrupt.h>
#include <Adafruit_NeoPixel.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Led{
long _color;
public:
    Led(long color){
        _color = color;
    }
};

class Player :Led{
    int _position;
public:
    Player(int position, int color):Led(color){
        _position = position;
    }
    void moveDown(){

    }
    void moveLeft(){

    }
    void moveUp(){

    }
    void moveRight(){

    }

};
class Wall :Led{
    Wall( int color):Led(color){
    }
};

class Enemy :Led{
    int _position;
public:
    Enemy(int position, int color):Led(color){
        _position = position;
    }
    //Trebuie implementat cum se misca
    void doAction(int type_action){
       switch(type_action){
           case 0:
               leftWrite();
               break;

               case 1:
                   upDown();
                   break;
       }
    }
    void leftWrite(){

    }
    void upDown(){

    }
};

class LedMatrix{
    int _pin;
    int _crtLed;
    Led _ledarray[];
public:

    LedMatrix(int pin, int crtLed){
        _pin = pin;
        _crtLed = crtLed;//Cate Leduri are matricea in total(patrate please)
        _ledarray = NULL;//trebuie facut cum trebuie
    }
    void changeMap(Led ledarray[]){
        _ledarray = ledarray;
    }


    void setup(){
        Adafruit_NeoPixel ledMatrix = Adafruit_NeoPixel(_crtLed,_pin, NEO_GRB + NEO_KHZ800);
    }
};


void setup(){

}

void loop(){

}