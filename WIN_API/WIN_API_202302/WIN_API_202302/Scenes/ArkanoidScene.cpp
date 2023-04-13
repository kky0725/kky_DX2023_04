#include "framework.h"
#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
{
	_stage = make_shared<ArkaStage>();
	_player = make_shared<ArkaPlayer>();
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_stage->Update();
	_player->Update();

	for (auto& blocksX : _stage->GetBlocks())
	{
		for (auto& block : blocksX)
		{
			shared_ptr<CircleCollider> playerCollider = dynamic_pointer_cast<CircleCollider>(_player->GetBall()->GetCollider());
			if (block->GetCollider()->IsCollision(playerCollider) && block->IsActive())
			{
				if ((playerCollider->GetCenter().x < dynamic_pointer_cast<RectCollider>(block->GetCollider())->Left() - playerCollider->GetRadius() ||
					playerCollider->GetCenter().x > dynamic_pointer_cast<RectCollider>(block->GetCollider())->Right()) + playerCollider->GetRadius())
				{
					_player->GetBall()->ReflectX();
					block->SetActive(false);
				}
				else
				{
					_player->GetBall()->ReflectY();
					block->SetActive(false);
				}
				
			}
		}
	}

}

void ArkanoidScene::Render(HDC hdc)
{
	_stage->Render(hdc);
	_player->Render(hdc);
}
