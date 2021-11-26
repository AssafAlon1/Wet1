#ifndef _DS_WET1_PLAYERSMANAGER_H
#define _DS_WET1_PLAYERSMANAGER_H

#include "library1.h"
#include "MyTree.h"
#include "Group.h"
#include "NonEmptyGroup.h"
#include "SinglePlayer.h"
#include "Players.h"

namespace mtm
{
    class PlayersManager
    {
    private:
        AVLTree<Group> Groups;
        Players AllPlayers;
    public:
        PlayersManager()  = default;
        ~PlayersManager() = default;

        StatusType AddGroup(int GroupID);
        StatusType AddPlayer(int PlayerID, int GroupID, int Level);
        StatusType RemovePlayer(int PlayerID);
        StatusType ReplaceGroup(int GroupID, int ReplacementID);
        StatusType IncreaseLevel(int PlayerID, int LevelIncrease);
        StatusType GetHighestLevel(int GroupID, int* PlayerID);
        StatusType GetAllPlayersByLevel(int GroupID, int** Players, int* numOfPlayers);
        StatusType GetGroupsHighestLevel(int numOfGroups, int** Players);
    };

    // StatusType AddGroup(int GroupID)
    // StatusType AddPlayer(int PlayerID, int GroupID, int Level)
    // StatusType RemovePlayer(int PlayerID)
    // StatusType ReplaceGroup(int GroupID, int ReplacementID)
    // StatusType IncreaseLevel(int PlayerID, int LevelIncrease)
    // StatusType GetHighestLevel(int GroupID, int* PlayerID)
    // StatusType GetAllPlayersByLevel(int GroupID, int** Players, int* numOfPlayers)
    // StatusType GetGroupsHighestLevel(int numOfGroups, int** Players)

}

#endif // _DS_WET1_PLAYERSMANAGER_H