/* 
 * File:   main.cpp
 * Author: Delunado
 *
 * Created on 22 de marzo de 2018, 19:06
 */

#include <cstdlib>
#include <iostream>
#include "Map.h"
#include "Room.h"



int main() {
    //Main menu
    
    int option;
    Map * m = new Map();
    
    
    do{
    std::cout << std::endl;
    std::cout << "--- Choose an option: --- " << std::endl;
    std::cout << "1. Generate a new map." << std::endl;
    std::cout << "2. Draw the actual map." << std::endl;
    std::cout << "3. Help." << std::endl;
    std::cout << "0. Exit." << std::endl;
    std::cout << "> ";
    std::cin >> option;
    
    
    switch (option){
        
        case 1:
            delete m;
            int x, y, size, nRooms;
            do{
                std::cout << "Enter the map size (between 2 and 20, both included): " << std::endl;
                std::cin >> size;
            } while (size < 2 || size > 20);
    
            do{
                std::cout << "Enter the initial X coordinate (between 0 and " << size-1 << "):" << std::endl;
                std::cin >> x;
            } while (x < 0 || x > size-1);
    
            do{
                std::cout << "Enter the initial Y coordinate (between 0 and " << size-1 << "):" << std::endl;
                std::cin >> y;
            } while (y < 0 || y > size-1);

            do{
                std::cout << "Write the max room number (limit: " << (size+1) <<  ") to create a new map or 0 to exit" << std::endl;
                std::cout << "> ";
                std::cin >> nRooms;
                if (nRooms == 0)
                return 0;
            } while (nRooms < 1 || nRooms > size+1);
            
            m = new Map(x, y, size);
        
        m->GenerateRandomMap(nRooms);
        break;
            
        case 2:
            std::cout << std::endl;
            m->DrawMap();
            break;
            
        case 3:
            std::cout << "\nUse 1.Create new map to generate a new map. Use 2.Draw the actual map" << std::endl;
            std::cout << "to draw the map you created with 1. If you dont create any map, you will" << std::endl;
            std::cout << "see a default empty map. Use 0.Exit to close the aplication." << std::endl;
            std::cout << "\n Note: when you select the rooms number, you are selecting the MAX rooms number." << std::endl;
            std::cout << "It's not always sure you are going to have all that rooms in your map." << std::endl;
            break;
        }
    
        
    } while (option != 0);   
}

