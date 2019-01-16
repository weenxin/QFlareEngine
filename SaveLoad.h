#ifndef SAVELOAD_H
#define SAVELOAD_H

class SaveLoad {
public:
    SaveLoad();
    ~SaveLoad();

    int getGameSlot() {
        return game_slot;
    }
    void setGameSlot(int slot) {
        game_slot = slot;
    }

    void saveGame();
    void loadGame();
    void loadClass(int index);
    void loadStash();

private:
    void applyPlayerData();
    void loadPowerTree();

    int game_slot;
};

#endif // SAVELOAD_H
