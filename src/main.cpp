#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <time.h>
#include <algorithm>

#include "entitybase.h"
#include "box.h"
#include "game.h"

void loadEntities();

std::vector<EntityBase*>* entities = new std::vector<EntityBase*>();

b2Vec2 Gravity(0.f, 9.8f);
b2World World(Gravity);


int main()
{
    srand(time(0));

    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(800, 500), "SFML works!");
    window.setFramerateLimit(1000);
    
    // starting
    loadEntities();

    
    for(const auto& ent : *entities){
        ent->Preload();
        ent->Start(&window);
    }
    /*
    for(auto ent = std::begin(entities); ent != std::end(entities); ++ent){
        ent->Preload();
        ent->Start(&window);
    }
    */

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if(event.type == sf::Event::MouseButtonPressed){
                int MouseX = sf::Mouse::getPosition(window).x;
                int MouseY = sf::Mouse::getPosition(window).y;

                if(event.mouseButton.button == sf::Mouse::Left)
                    entities->push_back(new ent::BoxGravity(sf::Vector2f(50,50), sf::Vector2f(MouseX,MouseY), World));
                else if(event.mouseButton.button == sf::Mouse::Right)
                    entities->push_back(new ent::BoxStatic(sf::Vector2f(50,50), sf::Vector2f(MouseX,MouseY), World));
            }
            
            else if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::K){
                    for(auto& ent : *entities){
                        // TODO: fix this plz
                        delete ent;
                    }
                    
                    entities->clear();
                    
                }
                    
            }
        }
        

        for(const auto& ent : *entities)
            ent->Update(&window);
        
        window.clear();

        for(const auto& ent : *entities)
            ent->Draw(&window);

        window.display();

        /** Simulate the world */
        World.Step(Game::getDelta(), 8, 3);
    }

    return 0;
}


void loadEntities()
{
    // rigidbody boxes
    //entities->push_back(new ent::BoxGravity(sf::Vector2f(50,50), sf::Vector2f(50,50), World));
    //entities.push_back(new ent::BoxGravity(sf::Vector2f(50,50), sf::Vector2f(30,0), World));

    // ground boxes
    //entities->push_back(new ent::BoxStatic(sf::Vector2f(600,150), sf::Vector2f(100,300), World));
}