#include <SFML/Graphics/RenderWindow.hpp>

class EntityBase
{
private:
    /* data */
public:
    virtual ~EntityBase();

    virtual void Preload()=0;
    virtual void Start(sf::RenderWindow *window)=0;
    virtual void Draw(sf::RenderWindow *window)=0;
    virtual void Update(sf::RenderWindow *window)=0;
};




