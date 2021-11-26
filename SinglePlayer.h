#ifndef _DS_WET1_SINGLEPLAYER_H
#define _DS_WET1_SINGLEPLAYER_H

#include "Group.h"

namespace mtm
{
    class SinglePlayer
    {
    private:
        int PlayerID;
        int Level;
        bool SortByLvl;
        
    public:
        
        SinglePlayer(int PlayerID, int Level, bool SortByLvl, Group* ptr);
        ~SinglePlayer() = default;

        Group* PlayerGroup;
        
        bool operator>(const SinglePlayer& other);
    };

    SinglePlayer::SinglePlayer(int PlayerID, int Level, bool SortByLvl, Group* ptr) : 
        PlayerID(PlayerID), Level(Level),  SortByLvl(SortByLvl), PlayerGroup(ptr)
    {
    }

    bool SinglePlayer::operator>(const SinglePlayer& other)
    {
        // Case: Sorting by ID
        if (!SortByLvl)
        {
            return PlayerID > other.PlayerID;
        }

        // Sorting by LVL
        if (Level > other.Level)
        {
            return true;
        }
        
        if (other.Level > Level)
        {
            return false;
        }

        // Level is equal - reverse sort by ID
        if (other.PlayerID > PlayerID)
        {
            return true;
        }

        return false;
    }
    

}


#endif // _DS_WET1_SINGLEPLAYER_H