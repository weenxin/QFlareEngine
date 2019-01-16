#ifndef ITEMSTORAGE_H
#define ITEMSTORAGE_H

#include "CommonIncludes.h"

class ItemManager;
class ItemStack;

class ItemStorage {
protected:
    int slot_number;

public:
    static const int NO_SLOT = -1;
    ItemStorage();
    ~ItemStorage();
    void init(int _slot_number);

    ItemStack & operator [] (int slot);

    void setItems(const std::string& s);
    void setQuantities(const std::string& s);
    int getSlotNumber();
    std::string getItems();
    std::string getQuantities();
    ItemStack add(ItemStack stack, int slot);
    void subtract(int slot, int quantity);
    bool remove(int item, int quantity);
    void sort();
    void clear();
    void clean();
    bool empty();

    bool full(ItemStack stack);
    int count(int item);
    bool contain(int item, int quantity);

    ItemStack * storage;
};

#endif // ITEMSTORAGE_H
