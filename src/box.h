#pragma once
#include "entitybase.h"
#include "log/log.h"
#include "game.h"

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <time.h>

namespace ent
{
    class Box : public EntityBase{
        protected:
            sf::RectangleShape rect;
            
            sf::Vector2f pos;
            sf::Vector2f size;
        public:
            Box(sf::Vector2f size, sf::Vector2f pos);
            ~Box();

            void Preload() override;
            void Start(sf::RenderWindow *window) override;
            void Update(sf::RenderWindow *window) override;
            void Draw(sf::RenderWindow *window) override;
    };

    class BoxGravity : public Box{
        private:
            b2Body* m_body;
            b2BodyDef m_bodyDef;
            b2PolygonShape m_bodyShape;
            b2FixtureDef m_bodyFix;

            b2World* m_world;
        public:
            BoxGravity(sf::Vector2f size, sf::Vector2f pos, b2World& world);

            virtual ~BoxGravity();

            void Update(sf::RenderWindow *window) override;
    };

    class BoxStatic : public Box{
        private:
            b2Body* m_body;
            b2BodyDef m_bodyDef;
            b2PolygonShape m_bodyShape;
            b2FixtureDef m_bodyFix;

            b2World* m_world;
        public:
            BoxStatic(sf::Vector2f size, sf::Vector2f pos, b2World& world);

            virtual ~BoxStatic();

            void Update(sf::RenderWindow *window) override;
    };
}
