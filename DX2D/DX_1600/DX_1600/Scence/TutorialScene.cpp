#include "framework.h"
#include "TutorialScene.h"

#define LERP(s,e,t) s + (e - s)*t

TutorialScene::TutorialScene()
{
	_quad1 = make_shared<Quad>(L"Resource/Zelda.png");
	_quad2 = make_shared<Quad>(L"Resource/Goomba.png");

	_quad1->GetTransform()->SetParent(_quad2->GetTransform());

	_quad1->GetTransform()->SetPosition({1000, 0});

	//_quad1->GetTransform()->SetScale({ 0.5f, 0.5f });
	_quad2->GetTransform()->SetScale({ 0.1f, 0.1f });
}

TutorialScene::~TutorialScene()
{
	
}

void TutorialScene::Update()
{
	_angle1 += 0.0001f;
	_angle2 += 0.0003f;

	Vector2 lerpResult = LERP(_quad2->GetTransform()->GetPos(), mousePos, 0.001f);
	_quad2->GetTransform()->SetPosition(lerpResult);

	_quad1->GetTransform()->SetAngel(_angle1);
	_quad2->GetTransform()->SetAngel(_angle2);

	_quad1->Update();
	_quad2->Update();
}

void TutorialScene::Render()
{
	_quad1->Render();
	_quad2->Render();
}
