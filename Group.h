#ifndef _DS_WET1_GROUP_H
#define _DS_WET1_GROUP_H

#include "library1.h"
#include "Players.h"

namespace mtm
{
    class Group
    {
    private:
        int GroupID;
        Players PlayersInGroup;
    public:
        Group(int id);
        ~Group() = default;

        StatusType AddPlayer(int PlayerID, int Level);

        bool operator>(const Group& other);
        
    };
    
    Group::Group(int id) : GroupID(id)
    {
    }
    

    StatusType Group::AddPlayer(int PlayerID, int Level)
    {
        return PlayersInGroup.AddPlayer(PlayerID, Level);
    }


    bool Group::operator>(const Group& other)
    {
        return GroupID > other.GroupID;
    }
    
}


#endif