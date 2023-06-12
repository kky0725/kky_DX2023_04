#include "framework.h"
#include "Cup_Ani.h"

using namespace tinyxml2;

Cup_Ani::Cup_Ani()
{
	CreateAction(L"Resource/CupHead/Idle.png", "Resource/CupHead/Idle.xml", "CUP_IDLE", Vector2(250, 250));
	CreateAction(L"Resource/CupHead/Jump.png", "Resource/CupHead/Jump.xml", "CUP_JUMP", Vector2(120, 120));
	CreateAction(L"Resource/CupHead/Run.png", "Resource/CupHead/Run.xml", "CUP_RUN", Vector2(120, 140));
	CreateAction(L"Resource/CupHead/AimStraightShot.png", "Resource/CupHead/AimStraightShot.xml", "CUP_SHOT", Vector2(250, 250));
	CreateAction(L"Resource/CupHead/RunShot.png", "Resource/CupHead/RunShot.xml", "CUP_RUNSHOT", Vector2(120, 120));

	_transform = make_shared<Transform>();
	_transform->SetPosition(Vector2(0.0f, 9.76f));

	SetRight();
}

Cup_Ani::~Cup_Ani()
{
}

void Cup_Ani::Update()
{
	SelectState();

	_actions[_state]->Update();
	_sprites[_state]->Update();
	_transform->Update();
}

void Cup_Ani::Render()
{
	_transform->SetBuffer(0);

	_sprites[_state]->SetCurFrmae(_actions[_state]->GetCurClip());
	_sprites[_state]->Render();
}

void Cup_Ani::PostRender()
{
	ImGui::SliderFloat2("FixedPos", (float*)&_fixedPos, 0, 100);
	_transform->SetPosition(_fixedPos);
}


void Cup_Ani::CreateAction(wstring srvPath, string xmlPath, string actionName, Vector2 size)
{
	shared_ptr<SRV> srv = ADD_SRV(srvPath);

	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	document->LoadFile(xmlPath.c_str());

	XMLElement* texturAtlas = document->FirstChildElement();
	XMLElement* row = texturAtlas->FirstChildElement();

	vector<Action::Clip> clips;

	while (true)
	{
		if (row == nullptr)
			break;

		int x = row->FindAttribute("x")->IntValue();
		int y = row->FindAttribute("y")->IntValue();
		int w = row->FindAttribute("w")->IntValue();
		int h = row->FindAttribute("h")->IntValue();
		
		Action::Clip clip = Action::Clip(x, y, w, h, srv);
		clips.push_back(clip);

		row = row->NextSiblingElement();
	}

	shared_ptr<Action> action = make_shared<Action>(clips, actionName);
	action->Play();
	shared_ptr<Sprite> sprite = make_shared<Sprite>(srvPath, size);
	_actions.push_back(action);
	_sprites.push_back(sprite);
}

void Cup_Ani::SelectState()
{
	if (KEY_DOWN('Z'))
	{
		_state = State::JUMP;
	}

	if (!_isGround)
		return;

	if (KEY_UP(VK_LEFT))
	{
		_state = State::IDLE;
	}
	if (KEY_PRESS(VK_LEFT))
	{
		_state = State::RUN;
		_isRight = false;
		SetLeft();
	}

	if (KEY_UP(VK_RIGHT))
	{
		_state = State::IDLE;
	}
	if (KEY_PRESS(VK_RIGHT))
	{
		_state = State::RUN;
		_isRight = true;
		SetRight();
	}

	if (KEY_UP('X'))
	{
		_state = State::IDLE;
	}
	if (KEY_PRESS('X'))
	{
		_state = State::SHOT;
	}

	if (KEY_PRESS('X') && KEY_PRESS(VK_RIGHT))
	{
		_state = State::RUN_SHOT;
	}

	if (KEY_PRESS('X') && KEY_PRESS(VK_LEFT))
	{
		_state = State::RUN_SHOT;
	}
}

void Cup_Ani::SetLeft()
{
	for (auto sprite : _sprites)
		sprite->SetLeft();
}

void Cup_Ani::SetRight()
{
	for (auto sprite : _sprites)
		sprite->SetRight();
}
