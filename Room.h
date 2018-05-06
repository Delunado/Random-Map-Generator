/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Habitacion.h
 * Author: Delunado
 *
 * Created on 22 de marzo de 2018, 19:18
 */

#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room{
private:   
    std::string description;
    char shape;
public:
    Room(char shape = 'O', std::string description = "Empty description");
    Room(const Room& other);
    
    std::string GetDescription() const {
        return description;
    }

    void SetDescription(std::string description) {
        this->description = description;
    }
    
    char GetShape() const {
        return shape;
    }

    void SetShape(char shape) {
        this->shape = shape;
    }


    
    
};

#endif /* ROOM_H */
