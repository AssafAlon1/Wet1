#ifndef _DS_WET1_PLAYERS_H
#define _DS_WET1_PLAYERS_H

#include "library1.h"
#include "MyTree.h"
#include "SinglePlayer.h"

namespace mtm
{
    class Players
    {
    private:
        AVLTree<Players> PlayersByID;
        AVLTree<Players> PlayersByLvl;
    public:
        Players() = default;
        ~Players() = default;

        StatusType AddPlayer(int PlayerID, int Level, Group* GroupPtr);
        StatusType RemovePlayer(int PlayerID);
        StatusType IncreaseLevel(int PlayerID, int LevelIncrease);
        StatusType GetAllPlayersByLevel(int** Players, int *numOfPlayers);
        int GetHighestLevel();
    };
    
    
    StatusType Players::AddPlayer(int PlayerID, int Level, Group* GroupPtr)
    {
        PlayersByID.insert(SinglePlayer(PlayerID, Level, false, GroupPtr));
        PlayersByLvl.insert(SinglePlayer(PlayerID, Level, true, GroupPtr));
        
        // TODO MORE??
        // ERROR CODES??
        return SUCCESS;
    }

    
    StatusType RemovePlayer(int PlayerID)
    {
        // TODO
        // REMOVE FROM BOTH TREES
        return SUCCESS;
    }


    StatusType IncreaseLevel(int PlayerID, int LevelIncrease)
    {
        // TODO

        // Make sure player exists O(logn)

        // Save his ID, Level

        // Allocate player again with updated level O(1)

        // Remove old Player O(logn)

        // Insert new player O(logn)

        return SUCCESS;
    }


    StatusType GetAllPlayersByLevel(int** Players, int *numOfPlayers)
    {
        // TODO

        // Allocate array (error handling etc)

        // Scan the tree inorder and update the array

        // Update pointers

        return SUCCESS;
    }
    
    int GetHighestLevel()
    {
        // TODO
        // If tree ain't empty, return the value
        return -1; // DEFINE
    }


}

#endif //_DS_WET1_PLAYERS_H