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

class Wall :Led{
    Wall( int color):Led(0xC5C5C5){
    }
};

class MovableObject :Led{
    int _position;
public:
    MovableObject(int position, int color):Led(color){
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

class Player :MovableObject{

    
public:
    Player(int position):Led(0x000089){
        _position = position;
    }

    void setup(){

    }
}

class Enemy :MovableObject{
public:
    Enemy(int position):Led(0X890000){
        _position = position;
    }
    //Trebuie implementat cum se misca
    void aiMovement(){

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
        _ledarray = new Led[];//trebuie facut cum trebuie
    }
    // functie ii dam un array de inturi, iar fiecare valoare reprezinta ceva
    // 0 - spatiu gol
    // 1 - perete
    // 2 - player
    // 3 - enemy(left-write)
    // 4 - enemy(up-down)
    void changeMap(int ledarray[]){
        _ledarray = ledarray;
    }


    void setup(){
        Adafruit_NeoPixel ledMatrix = Adafruit_NeoPixel(_crtLed,_pin, NEO_GRB + NEO_KHZ800);
    }
};

class Game{
    LedMatrix _map;
    Player _player;

}




void setup(){

}

void loop(){

}