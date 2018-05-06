/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Habitacion.cpp
 * Author: Delunado
 * 
 * Created on 22 de marzo de 2018, 19:18
 */

#include "Room.h"

Room::Room(char shape, std::string description):   
    description(description), shape(shape)
{}

Room::Room(const Room& other) :
    description(other.description), shape(other.shape) {
    }



