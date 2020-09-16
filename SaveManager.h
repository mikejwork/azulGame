#ifndef SAVE_MANAGER_H
#define SAVE_MANAGER_H

#include <string>
#include <iostream>
#include <fstream>
#include <istream>

class SaveManager {
public:
    SaveManager();

    void NewSave(std::string saveName);
    void LoadSave(std::string saveName);

    void interactive();

private:

    int saveCount;
};


#endif // SAVE_MANAGER_H
