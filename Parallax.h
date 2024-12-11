#ifndef Parallax_H
#define Parallax_H

#include "Game.h"
#include "Setting.h"
#include <vector>
#include "Sprite.h"

namespace Engine {
	class Parallax :public Engine::Game
	{
	public:
		Parallax(Setting* setting);
		~Parallax();
		virtual void Init();
		virtual void Update();
		virtual void Render();
	private:
		vector<Sprite*> backgrounds, middlegrounds, foregrounds;
		void MoveLayer(vector<Sprite*>& bg, float speed);
		void DrawLayer(vector<Sprite*>& bg);
		void AddToLayer(vector<Sprite*>& bg, string name);
		float offset = 0;
	};
}

#endif

