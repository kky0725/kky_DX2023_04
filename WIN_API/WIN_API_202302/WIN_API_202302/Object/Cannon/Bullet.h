#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render(HDC hdc);

	void SetPos(const Vector2& pos) { _collider->SetCenter(pos); }
	void Shoot(const Vector2& dir, float speed);

	bool IsAtcive() { return _isActive; }

	const shared_ptr<Collider>& GetCollider() const { return _collider; }
	bool IsCollision(shared_ptr<class Cannon> cannon);

	void SetActive(bool value) { _isActive = value; }

private:
	bool _isActive = false;
	float _speed = 30.0f;
	Vector2 _direction = Vector2(0.0f, 0.0f);

	shared_ptr<Collider> _collider;
};

