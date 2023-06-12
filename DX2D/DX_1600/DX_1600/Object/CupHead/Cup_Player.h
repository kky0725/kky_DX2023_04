#pragma once
class Cup_Ani;
class Cup_Bullet;

class Cup_Player
{
public:
	Cup_Player();
	~Cup_Player();

	void Update();
	void Render();
	void PosRender();

	void Move(Vector2 movePos) { _collider->GetTransform()->AddVector2(movePos); }
	void Input();
	void Fire();
	void Jump();

	bool IsCollision_Bullets(shared_ptr<Collider> col);

	void SetGrounded();

	void SetPosition(Vector2 pos) { _collider->SetPosition(pos); }
	shared_ptr<Collider> GetCollider() { return _collider; }

private:
	shared_ptr<Cup_Ani> _animation;
	shared_ptr<Collider> _collider;

	vector<shared_ptr<Cup_Bullet>> _bullets;

	float _speed = 200.0f;
	float _time = 0.0f;
	float _atkSpeed = 0.5f;
	bool _atkCool = false;

	float _jumpPower = 0.0f;
};

