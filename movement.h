#ifndef movement_H
#define movement_H

#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include <vector>

namespace Engine {
	class movement : public Engine::Game {
	public:
		movement(Setting* setting);
		~movement();

		virtual void Init();
		virtual void Update();
		virtual void Render();

	private:
		// Fungsi tambahan
		bool IsKeyDown(const std::string& key);

		// Variabel sprite dan tekstur
		Engine::Texture* texture = NULL;
		Engine::Sprite* sprite = NULL;
		Engine::Sprite* karakterSprite = NULL;
		Engine::Sprite* backgroundSprite = NULL;

		// Variabel untuk gerakan dan gravitasi
		float velocityX = 0.0f;       // Kecepatan horizontal
		float velocityY = 0.0f;       // Kecepatan vertikal
		float gravity = 0.01f;        // Nilai gravitasi
		float jumpStrength = 0.2f;    // Kekuatan lompatan
		bool isJumping = false;       // Status lompat

		// Variabel lainnya
		float mul = 1;                // Arah gerakan (1 = kanan, -1 = kiri)
		bool debug = false;           // Mode debug
	};
}

#endif
