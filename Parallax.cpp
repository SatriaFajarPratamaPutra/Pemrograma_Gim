#include "Parallax.h"

Engine::Parallax::Parallax(Setting* setting) :Engine::Game(setting)
{
	setting->windowTitle = "Parallax Scrolling";
}

Engine::Parallax::~Parallax()
{
}

void Engine::Parallax::Init()
{
		AddToLayer(backgrounds, "sky.png");
		AddToLayer(backgrounds, "far-clouds.png");
		AddToLayer(middlegrounds, "far-mountains.png");
		AddToLayer(middlegrounds, "mountains.png");
		AddToLayer(middlegrounds, "near-clouds.png");
		AddToLayer(foregrounds, "trees.png");

	offset = 2;
}

void Engine::Parallax::Update()
{
	MoveLayer(backgrounds, 0.005f);
	MoveLayer(middlegrounds, 0.03f);
	MoveLayer(foregrounds, 0.5f);
}

void Engine::Parallax::Render()
{
	DrawLayer(backgrounds);
	DrawLayer(middlegrounds);
	DrawLayer(foregrounds);
}

void Engine::Parallax::MoveLayer(vector<Sprite*>& bg, float speed)
{
	for (Sprite* s : bg) {
		if (s->GetPosition().x < -setting->screenWidth + offset) {
			s->SetPosition(setting->screenWidth + offset - 1, 0);
		}
		s->SetPosition(s->GetPosition().x - speed * GetGameTime(), s->GetPosition().y);
		s->Update(GetGameTime());
	}
}

void Engine::Parallax::DrawLayer(vector<Sprite*>& bg)
{
	for (Sprite* s : bg) {
		s->Draw();
	}
}

void Engine::Parallax::AddToLayer(vector<Sprite*>& bg, string name)
{
	Texture* texture = new Texture(name);

	Sprite* s = new Sprite(texture, defaultSpriteShader, defaultQuad);
	s->SetSize(setting->screenWidth + offset, setting->screenHeight);
	bg.push_back(s);

	Sprite* s2 = new Sprite(texture, defaultSpriteShader, defaultQuad);
	s2->SetSize(setting->screenWidth + offset, setting->screenHeight)->SetPosition(setting->screenWidth + offset - 1, 0);
	bg.push_back(s2);
}

