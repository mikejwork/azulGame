class Tile {
    public:
        Tile(char identifier);
        Tile(const Tile& other);
        ~Tile();

        char getIdentifier();
    private:
        char identifier;
};