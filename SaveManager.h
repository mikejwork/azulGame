#include <string>
#include <iostream>
#include <fstream>
#include <istream>

class SaveManager {
public:
    SaveManager();

    void NewSave(std::string saveName);
    void LoadSave(std::string saveName);

private:
    int saveCount;
};