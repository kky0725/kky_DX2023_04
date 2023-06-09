#include "framework.h"
#include "Vector2.h"

bool Vector2::operator==(const Vector2& other) const
{
	if (abs(x - other.x) < 0.001 && abs(y - other.y) < 0.001)
		return true;
	return false;
}

bool Vector2::operator!=(const Vector2& other) const
{
	return !this->operator==(other);
}

int Vector2::MahattanDistance(const Vector2& other) const
{
	return int(abs(x - other.x) + abs(y - other.y));
}

bool Vector2::IsBetween(Vector2 v1, Vector2 v2)
{
	float cross1 = v1.Cross(*this);
	float cross2 = v2.Cross(*this);

	if ((cross1 * cross2) < 0.0f)
		return true;

	return false;
}

Vector2 Vector2::TransformCoord(XMMATRIX matrix)
{
	XMVECTOR temp = XMLoadFloat2(this);

	temp = XMVector2TransformCoord(temp, matrix);

	Vector2 result;
	XMStoreFloat2(&result, temp);

	return result;
}
