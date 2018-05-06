/* 
 * File:   Map.h
 * Author: Delunado
 *
 * Created on 22 de marzo de 2018, 19:07
 */

#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include <stdlib.h>
#include <iostream>
#include <stdexcept>

class Map{
private:
    static int const MAX_ROOM = 20;
    static int const MIN_ROOM = 2;
    
    Room* vRoom[MAX_ROOM];
    int numRooms;
    
    Room* vMap[MAX_ROOM][MAX_ROOM];
    
    int xStart;
    int yStart;
    int totalRooms;
    
    
public:
    Map(int xStart = 0, int yStart = 0, int totalRooms = 3);
    
    /**
     * @brief Generate a random map with different rooms locations
     * @param tRooms Denotes the number of rooms. It must be equal or lower than the map size.
     */
    void GenerateRandomMap(int tRooms);
    
    /**
     * @brief It fills the map matrix with the number of rooms indicated
     * @param auxRooms Denotes the total rooms that are in vRoom
     * @param auxX Denotes the relative position respect xStart
     * @param auxY Denotes the relative position respect yStart
     */
    void MatrixRoomFiller(int auxRooms, int auxX, int auxY);   
    
    /**
     * @brief Adds a new room to vRoom
     */
    void AddRoom();
    
    /**
     * @brief Delete the room in the indicated position of vRoom
     * @param pos The position you want to delete
     */
    void DeleteRoom(int pos);
    
    /**
     * @brief Draws the map matrix (vMap) in the console.
     */
    void DrawMap();
    
    /**
     * @TODO making rooms look like arrows, looking at the next room
     * @brief Clean the map, filling each position with 0
     */
    void CleanMap(); 

};

#endif /* MAP_H */
