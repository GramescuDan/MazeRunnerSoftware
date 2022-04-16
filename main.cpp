#include <iostream>
#include <avr/interrupt.h>
#include <Adafruit_NeoPixel.h>
#include <vector>

class Led{
long _color;
public:
    Led(long color){
        _color = color;
    }
};

class Wall :public Led{
public:
    Wall():Led(0xC5C5C5){
    }
};

class Player : public Led{
Joystic *joystick;
int _joystick_pin_x = 14;
int _joystick_pin_y = 15;
int _joystick_pin_sw = 2;
int _lowrange = 0;
int _high_range = 1023;
int _range_division = 100;

public: int _position;

public:
    Player(int position): Led(0x000089)
    {

    }

    void setup(){
        joystick = new AxisJoystick(_joystick_pin_sw,_joystick_pin_x,_joystick_pin_y);
        joystick->calibrate(_lowrange,_high_range,_range_division);
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

    void loop(){

        if(joystick->isDown()){
            moveDown();
        }else if(joystick->isUp()){
            moveUp();
        }else if(joystick->isLeft()){
            moveLeft();
        }else if(joystick->isRight()){
            moveRight();
        }
    }
};

class Enemy :Led{
public: int _position;
public:
    Enemy(int position):Led(0X890000){
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

    //Trebuie implementat cum se misca
    void aiMovement(){

    }
};

class LedMatrix{
    int _pin;
    int _crtLed;
    std::vector<Led> _ledarray;
    //Led _ledarray;
public:

    LedMatrix(int pin, int crtLed){
        _pin = pin;
        _crtLed = crtLed;//Cate Leduri are matricea in total(patrate please)
        //_ledarray[1] = *new Led(0X890000);
        _ledarray =

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
                //_ledarray[i] = *new Wall();
                _ledarray.push_back(*new Wall);
                break;
            case 2:
                //_ledarray[i] = *new Player(i);
                //Se adauga player in matrice
                _ledarray.push_back(*new Player(i));
                 break;
            case 3:
                //Se adauga inamic in matrice
                 break;
        }
    }

    }


    void setup(){
        Adafruit_NeoPixel ledMatrix = Adafruit_NeoPixel(_crtLed,_pin, NEO_GRB + NEO_KHZ800);
        ledMatrix.begin();


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