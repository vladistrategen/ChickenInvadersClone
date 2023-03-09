#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

#include "windows.h"
#define _CRTDBG_MAP_ALLOC //to get more details
#include <stdlib.h>  
#include <crtdbg.h>   //for malloc and free
int main()
{
    /*
    _CrtMemState sOld;
    _CrtMemState sNew;
    _CrtMemState sDiff;
     _CrtMemCheckpoint(&sOld); //take a snapshot
     */ // memory leak checks
     
    Game game;
    game.initialize();
    game.run();
      
        
        

    //memory leak checks
    
    /*
    _CrtMemCheckpoint(&sNew); //take a snapshot 
    if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
    {
        OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
        _CrtMemDumpStatistics(&sDiff);
        OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
        _CrtMemDumpAllObjectsSince(&sOld);
        OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
        _CrtDumpMemoryLeaks();
    }*/ 

    return 0;
}