#include "framework.h"
#include "Collider.h"

bool Collider::_isDebug = true;

Collider::Collider(ColliderType type)
    :_type(type)
{
}

Collider::~Collider()
{
}

void Collider::Update()
{
    _transform->Update();
}

void Collider::Render()
{
    if (!_isDebug)
        return;

    _vertexBuffer->Set(0);

    _transform->SetBuffer(0);

    _colorBuffer->SetPsBuffer(0);

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

    _vs->Set();
    _ps->Set();

    DC->Draw(_vertices.size(), 0);
}

void Collider::CreateData()
{
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());

    _vs = ADD_VS(L"Shader/ColliderVS.hlsl");
    _ps = ADD_PS(L"Shader/ColliderPS.hlsl");

    _transform = make_shared<Transform>();
    _colorBuffer = make_shared<ColorBuffer>();
    SetGreen();
}

bool Collider::IsCollision(shared_ptr<Collider> col, bool isObb)
{
    switch (col->_type)
    {
    case Collider::ColliderType::NONE:
        return false;
    case Collider::ColliderType::CIRCLE:
    { 
        auto circle = dynamic_pointer_cast<CircleCollider>(col);
        return IsCollision(circle, isObb);
    }
    case Collider::ColliderType::RECT:
    {
        auto rect = dynamic_pointer_cast<RectCollider>(col);
        return IsCollision(rect, isObb);
    }
    default:
        return false;
    }
}

bool Collider::Block(shared_ptr<Collider> col)
{
    switch (col->_type)
    {
    case Collider::ColliderType::NONE:
        return false;
    case Collider::ColliderType::CIRCLE:
    {
        auto circle = dynamic_pointer_cast<CircleCollider>(col);
        return Block(circle);
    }
    case Collider::ColliderType::RECT:
    {
        auto rect = dynamic_pointer_cast<RectCollider>(col);
        return Block(rect);
    }
    default:
        return false;
    }
}
