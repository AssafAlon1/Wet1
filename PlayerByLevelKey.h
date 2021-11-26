#ifndef _DS_WET1_PLAYERBYLEVELKEY_H
#define _DS_WET1_PLAYERBYLEVELKEY_H

namespace mtm
{
    class PlayerByLevelKey
    {
    private:
        int PlayerID;
        int Level;
    public:
        PlayerByLevelKey(int id, int lvl);
        ~PlayerByLevelKey() = default;
        PlayerByLevelKey(const PlayerByLevelKey& other) = default;

        bool operator>(const PlayerByLevelKey& other);
    };

    PlayerByLevelKey::PlayerByLevelKey(int id, int lvl)  : PlayerID(id), Level(lvl);
    {
    }


    bool PlayerByLevelKey::operator>(const PlayerByLevelKey& other)
    {
        if (Level > other.Level)
        {
            return true;
        }

        if (other.Level > Level)
        {
            return false;
        }

        return other.PlayerID > PlayerID;
    }
}


#endif // _DS_WET1_PLAYERBYLEVELKEY_H