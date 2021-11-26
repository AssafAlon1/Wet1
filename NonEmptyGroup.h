#ifndef _DS_WET1_NONEMPTYGROUP_H
#define _DS_WET1_NONEMPTYGROUP_H

#include "Group.h"

namespace mtm
{
    class NonEmptyGroup
    {
    private:
        int GroupID;
        Group* GroupPTR;
    public:
        NonEmptyGroup(int id, Group* ptr);
        ~NonEmptyGroup() = default;

        bool operator>(const NonEmptyGroup& other);
    };
    
    NonEmptyGroup::NonEmptyGroup(int id, Group* ptr) : GroupID(id), GroupPTR(ptr)
    {
    }
    
    bool NonEmptyGroup::operator>(const NonEmptyGroup& other)
    {
        return GroupID > other.GroupID;
    }
    
}


#endif // _DS_WET1_NONEMPTYGROUP_H