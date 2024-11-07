#include <iostream>
#include <string>

class Texture
{
    public:
    Texture() {
        std::cout << "Chargement de la texture\n";
        textureName = "randomTexture";
    }

    Texture(std::string textureName) {
        std::cout << "Chargement de la texture" << textureName << "\n";
        textureName = textureName; 
    }

    void display() {
        std::cout << "Affichage de la texture\n";
    }

    private:
    std::string textureName;
};

class Unit 
{
    public :
    Unit()
    {
        texture = new Texture();
    }

    Unit(std::string textureName)
    {
        texture = new Texture(textureName);
    }

    void DisplayTexture()
    {
        texture->display();
    }

    ~Unit()
    {
        delete texture;
    }

    private :
    Texture* texture;
};

int main()
{
    Unit u1;
    u1.DisplayTexture();
    
    Unit u2;
    u2.DisplayTexture();

    return 0;
    
}