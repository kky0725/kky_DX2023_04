#pragma once
class RectCollider
{
public:
	RectCollider(Vector2 center, Vector2 size);
	~RectCollider();

	void Update();
	void Render(HDC hdc);

	void MoveCenter(const Vector2& value);

	void SetCenter(const Vector2 value);
	const Vector2& GetCenter() { return _center; }

	void SetSize(Vector2 size);
	const Vector2& GetSize() { return _size; }

	void SetGreen() { _curPenIndex = 0; }
	void SetRed() { _curPenIndex = 1; }

	float Left() const		{return _center.x - _halfSize.x; }
	float Right() const		{return _center.x + _halfSize.x; }
	float Top() const		{return _center.y - _halfSize.y; }
	float Bottom() const	{return _center.y + _halfSize.y; }


	bool IsCollision(Vector2 pos);
	bool IsCollision(shared_ptr<CircleCollider> other);
	bool IsCollision(shared_ptr<RectCollider> other);

private:
	vector<HPEN> _pens;
	UINT _curPenIndex = 0;

	Vector2 _center = { 0.0f, 0.0f };
	Vector2 _size = { 0.0f, 0.0f };
	Vector2 _halfSize = { 0.0f, 0.0f };
};

