#pragma once
class DunPlayer;
class DunBullet;

class DungreedScene : public Scene
{
public:
	DungreedScene();
	virtual ~DungreedScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<DunPlayer> _player;

};

