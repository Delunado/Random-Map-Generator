
/* 
 * File:   Map.cpp
 * Author: Delunado
 * 
 * Created on 22 de marzo de 2018, 19:07
 */

#include "Map.h"
#include <ctime>

Map::Map(int xStart, int yStart, int totalRooms): 
        xStart(xStart), yStart(yStart), totalRooms(totalRooms), numRooms(0)   
{
    for (int i = 0; i < Map::MAX_ROOM; i++){
        this->vRoom[i] = 0;
    }
    
    for (int i = 0; i < Map::MAX_ROOM; i++){
        for (int j = 0; j < Map::MAX_ROOM; j++){
            this->vMap[i][j] = 0;
        }
    }
    
    srand(time(0));
}

void Map::AddRoom() {
    Room* h = new Room();
    this->vRoom[this->numRooms] = h;
    this->numRooms++;
}

void Map::DeleteRoom(int pos) {
    delete this->vRoom[0];
    vRoom[0] = this->vRoom[this->numRooms-1];
    this->vRoom[this->numRooms-1] = 0;
    this->numRooms--;
}


void Map::GenerateRandomMap(int tRooms) {
    /**
     * @toDo it doesnt work properly sometimes. fix it.
     * @param tRooms
     */
    //if (tRooms = MAX_ROOM)
        //throw std::out_of_range("The number of rooms is greater than permitted");
    
    //First you have to generate the rooms.
    for (int i = 1; i < tRooms; i++){
        AddRoom();
    }
    
    //Here you fill the first position in the new map with the first room.
    Room* h = new Room(*this->vRoom[0]);
    this->vMap[this->xStart][this->yStart] = h;
    tRooms--;
    
    this->MatrixRoomFiller(tRooms, this->xStart, this->yStart);
    
}

void Map::MatrixRoomFiller(int auxRooms, int auxX, int auxY) {
    //Here you fill the matrix with rooms, spreading in horizontal or vertical position
    
    int direction = 0;
    
    while(this->numRooms != 0){
        if (this->vMap[auxX+1][auxY] != 0 && this->vMap[auxX-1][auxY] != 0 && 
            this->vMap[auxX][auxY+1] != 0 && this->vMap[auxX][auxY-1] != 0){
            return;
        }
        
        direction = rand() % 4 + 1;
        
        //1 = Up, 2 = Down, 3 = Left, 4 = Right
        switch (direction){
            case 1:
                if (auxY-1 < 0){
                    break;
                }
                if (this->vMap[auxX][auxY-1] == 0){
                    auxY -= 1;
                    Room* h = new Room(*this->vRoom[0]);
                    h->SetShape('X');
                    this->vMap[auxX][auxY] = h;
                    this->DeleteRoom(0);
                } else {
                    break;
                }
                break;
            case 2:
                if (auxY+1 > Map::MAX_ROOM){
                    break;
                }
                if (vMap[auxX][auxY+1] == 0){
                    auxY += 1;
                    Room* h = new Room(*this->vRoom[0]);
                    h->SetShape('X');
                    this->vMap[auxX][auxY] = h;
                    this->DeleteRoom(0);
                } else {
                    break;
                }
                break;
            case 3:
                if (auxX-1 < 0){
                    break;
                }
                if (vMap[auxX-1][auxY] == 0){
                    auxX -= 1;
                    Room* h = new Room(*this->vRoom[0]);
                    h->SetShape('X');
                    this->vMap[auxX][auxY] = h;
                    this->DeleteRoom(0);
                } else {
                    break;
                }
                break;
            case 4:
                if (auxX+1 > Map::MAX_ROOM){
                    break;
                }
                if (vMap[auxX+1][auxY] == 0){
                    auxX += 1;
                    Room* h = new Room(*this->vRoom[0]);
                    h->SetShape('X');
                    this->vMap[auxX][auxY] = h;
                    this->DeleteRoom(0);
                } else {
                    break;
                }
                break;
        }
        
    }
    
}

void Map::DrawMap() {
    for (int i = 0; i < this->totalRooms; i++){
        for (int j = 0; j < this->totalRooms; j++){
            if (this->vMap[i][j] == 0)
                std::cout << " . ";
            else
                std::cout << " " << this->vMap[i][j]->GetShape() << " ";          
        }
        std::cout << std::endl;
    }
}

void Map::CleanMap(){
for (int i = 0; i < Map::MAX_ROOM; i++){
        this->vRoom[i] = 0;
    }
    
    for (int i = 0; i < Map::MAX_ROOM; i++){
        for (int j = 0; j < Map::MAX_ROOM; j++){
            this->vMap[i][j] = 0;
        }
    }
}


