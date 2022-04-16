#include <iostream>
#include <avr/interrupt.h>
#include <Adafruit_NeoPixel.h>

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
public: int _position;
public:
    MovableObject(int position, int color):Led(color){
        _position = position;
    }

    void moveDown(){
        _position +=8;
    }
    void moveLeft(){
        _position -=1;
    }
    void moveUp(){

        _position -=8;
    }
    void moveRight(){
        _position +=1;
    }
};

class Player :public MovableObject{
Joystic *joystick;
int _joystick_pin_x = 14;
int _joystick_pin_y = 15;
int _joystick_pin_sw = 2;
int _lowrange = 0;
int _high_range = 1023;
int _range_division = 100;

MovableObject _movableObject;

public:
    Player( MovableObject x) : MovableObject(x._position, 0x000089), _movableObject(x) {

    }

    void setup(){
        joystick = new AxisJoystick(_joystick_pin_sw,_joystick_pin_x,_joystick_pin_y);
        joystick->calibrate(_lowrange,_high_range,_range_division);
    }
    void loop(){

        if(joystick->isDown()){
            _movableObject.moveDown();
        }else if(joystick->isUp()){
            _movableObject.moveUp();
        }else if(joystick->isLeft()){
            _movableObject.moveLeft();
        }else if(joystick->isRight()){
            _movableObject.moveRight();
        }
    }
};

class Enemy :MovableObject{
public:
    Enemy(int position):MovableObject(position,0X890000){
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
    // 3 - enemy
    void changeMap(int ledarray[]){

    for(int i=0;i<strlen(ledarray);i++){
        switch(ledarray[i]){
            case 0:
                //Se adauga gol in matrice
                break;
            case 1:
                //Se adauga perete in matrice
                break;
            case 2:
                //Se adauga player in matrice
                 break;
            case 3:
                //Se adauga inamic in matrice
                 break;
        }
    }

    }


    void setup(){
        Adafruit_NeoPixel ledMatrix = Adafruit_NeoPixel(_crtLed,_pin, NEO_GRB + NEO_KHZ800);
    }
};

class Game{
    Game() {}

    LedMatrix _map;
    Player _player;

};

// newPlayer(*new MovableObject(1,0x000089));


void setup(){
    //newPlayer.setup();
}

void loop(){
    //newPlayer.loop();
}