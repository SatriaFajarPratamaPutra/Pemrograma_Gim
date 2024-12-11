#include "MainMenu.h"

Engine::MainMenu::MainMenu()
{
	text = NULL;
}

void Engine::MainMenu::Init()
{
	// Create a Texture
	Texture* texture = new Texture("GUI.png");
	Sprite* playSprite = (new Sprite(texture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()))
		->SetNumXFrames(6)->SetNumYFrames(1)->AddAnimation("normal", 5, 5)->AddAnimation("hover", 3, 4)
		->AddAnimation("press", 3, 4)->SetAnimationDuration(400);

	Sprite* exitSprite = (new Sprite(texture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()))
		->SetNumXFrames(6)->SetNumYFrames(1)->AddAnimation("normal", 2, 2)->AddAnimation("hover", 0, 1)
		->AddAnimation("press", 0, 1)->SetAnimationDuration(400);
}


void Engine::MainMenu::Update()
{
	

}

void Engine::MainMenu::Draw()
{
	
}
