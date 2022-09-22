#include "box.h"



namespace ent{

    const int SCALE = 30;
    // box
    Box::Box(sf::Vector2f size, sf::Vector2f pos){
        Logging::Print("Instanced box");
        rect.setSize(size);
        rect.setPosition(pos);

        this->pos = pos;
        this->size = size;
    }

    Box::~Box(){

    }

    void Box::Preload(){
        // ...
    }

    void Box::Start(sf::RenderWindow *window){
        // ...
    }

    void Box::Update(sf::RenderWindow *window){
        // ...
    }

    void Box::Draw(sf::RenderWindow *window){
        window->draw(rect);
    }
    


    // box gravity
    BoxGravity::BoxGravity(sf::Vector2f size, sf::Vector2f pos, b2World& world) : Box(size, pos){
        b2BodyDef BodyDef;
        BodyDef.position = b2Vec2(pos.x/SCALE, pos.y/SCALE);
        BodyDef.type = b2_dynamicBody;
        this->m_bodyDef = BodyDef;

        b2Body* Body = world.CreateBody(&BodyDef);
        this->m_body = Body;

        b2PolygonShape Shape;
        //Shape.SetAsBox((32.f/2)/SCALE, (32.f/2)/SCALE);
        Shape.SetAsBox((size.x/2)/SCALE, (size.y/2)/SCALE);
        this->m_bodyShape = Shape;

        b2FixtureDef FixtureDef;
        FixtureDef.density = 1.f;
        FixtureDef.friction = 0.7f;
        FixtureDef.shape = &Shape;
        Body->CreateFixture(&FixtureDef);
        this->m_bodyFix = FixtureDef;

        this->rect.setFillColor(sf::Color(std::rand() % 256,std::rand() % 256,std::rand() % 256));
    }

    void BoxGravity::Update(sf::RenderWindow *window){
        this->rect.setOrigin(this->rect.getSize().x/2, this->rect.getSize().y/2);
        this->rect.setPosition(m_body->GetPosition().x*SCALE,m_body->GetPosition().y*SCALE);
        this->rect.setRotation(m_body->GetAngle()*180/b2_pi);
    }

    b2Body* BoxGravity::GetBody() {
        return m_body;
    }


    BoxStatic::BoxStatic(sf::Vector2f size, sf::Vector2f pos, b2World& world) : Box(size,pos){
        b2BodyDef BodyDef;
        BodyDef.position = b2Vec2(pos.x/SCALE, pos.y/SCALE);
        BodyDef.type = b2_staticBody;
        this->m_bodyDef = BodyDef;

        b2Body* Body = world.CreateBody(&BodyDef);
        this->m_body = Body;

        b2PolygonShape Shape;
        Logging::Print(std::to_string(size.x/2)+" "+std::to_string(size.y/2));
        Shape.SetAsBox((size.x/2)/SCALE, (size.y/2)/SCALE); // Creates a box shape. Divide your desired width and height by 2.
        this->m_bodyShape = Shape;

        b2FixtureDef FixtureDef;
        FixtureDef.density = 0.f;  // Sets the density of the body
        FixtureDef.shape = &Shape; // Sets the shape
        Body->CreateFixture(&FixtureDef); // Apply the fixture definition
        this->m_bodyFix = FixtureDef;
    }

    void BoxStatic::Start(sf::RenderWindow *window){
        this->rect.setOrigin(this->rect.getSize().x/2, this->rect.getSize().y/2);
        this->rect.setPosition(m_body->GetPosition().x*SCALE,m_body->GetPosition().y*SCALE);
        this->rect.setRotation(m_body->GetAngle() * 180/b2_pi);
    }
}