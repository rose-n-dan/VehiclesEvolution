//
// Created by SpiritStudio on 01.12.18.
//

#include <Physics/CarBody.h>

CarBody::CarBody(b2World &world, const b2Vec2 &position, const std::vector<b2Vec2> &vertices) {
    body_def_.type = b2_dynamicBody;
    body_def_.position.Set(position.x, position.y);
    body_ = world.CreateBody(&body_def_);

    auto vertices_tab = new b2Vec2 [vertices.size()];

    int32 i = 0;
    for (const auto &vertex : vertices) {
        vertices_tab[i] = vertex;
        ++i;
    }

    dynamic_box_.Set(vertices_tab, i);

    delete [] vertices_tab;

    fixture_def_.shape = &dynamic_box_;

    // Set the box density to be non-zero, so it will be dynamic.
    fixture_def_.density = DENSITY_;

    // Override the default friction.
    fixture_def_.friction = FRICTION_;

    fixture_def_.restitution = RESTITIUTION_;

    // Collision detection masks from box2d
    fixture_def_.filter.categoryBits = 0x0001;
    fixture_def_.filter.maskBits = 0x0002;

    // Add the shape to the body.
    body_->CreateFixture(&fixture_def_);
}

b2Body* CarBody::getBody() {
    return body_;
}

std::vector<b2Vec2> CarBody::getPolygon() const {
    std::vector<b2Vec2> vertices(static_cast<unsigned long>(dynamic_box_.GetVertexCount()));

    int32 i = 0;
    for (auto &vertex : vertices)
    {
        vertex = dynamic_box_.GetVertex(i);
        ++i;
    }

    return vertices;
}

const b2Vec2& CarBody::getPosition() const {
    return body_->GetPosition();
}

const b2Vec2 CarBody::getVelocity() const {
    return body_->GetLinearVelocity();
}

const double CarBody::getAngle() const {
    return body_->GetAngle();
}
