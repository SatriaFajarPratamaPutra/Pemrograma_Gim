#include "movement.h"

Engine::movement::movement(Setting* setting) : Engine::Game(setting) {
    setting->windowTitle = "Movement";
    sprite = nullptr;
    velocityX = 0.0f;
    velocityY = 0.0f;
    gravity = 0.01f;   // Nilai gravitasi
    jumpStrength = 0.2f; // Kekuatan lompatan
    isJumping = false; // Status awal lompat
    mul = 1;           // Awalnya menghadap kanan
}

Engine::movement::~movement() {
    delete sprite;
    delete karakterSprite;
}

void Engine::movement::Init() {
    Texture* monsterTexture = new Texture("karakter.png");
    karakterSprite = new Sprite(monsterTexture, defaultSpriteShader, defaultQuad);
    karakterSprite->SetPosition(0, 0)
        ->SetNumXFrames(10)
        ->SetNumYFrames(8)
        ->SetAnimationDuration(70)
        ->SetScale(2.0f)
        ->AddAnimation("idle", 0, 5)
        ->AddAnimation("run", 10, 17)
        ->AddAnimation("jump", 20, 23);

    karakterSprite->SetBoundingBoxSize(
        karakterSprite->GetScaleWidth() - (16 * karakterSprite->GetScale()),
        karakterSprite->GetScaleHeight() - (4 * karakterSprite->GetScale())
    );

    sprite = karakterSprite; 


}

void Engine::movement::Update() {
    if (!sprite) return;

    float x = sprite->GetPosition().x;
    float y = sprite->GetPosition().y;

    // Input untuk gerakan horizontal
    if (IsKeyDown("A")) {
        velocityX = -0.1f;
        mul = -1;
    }
    else if (IsKeyDown("D")) {
        velocityX = 0.1f;
        mul = 1;
    }
    else {
        velocityX = 0.0f;
    }

    // Input untuk melompat
    if (IsKeyDown("W") && !isJumping) {
        isJumping = true;
        velocityY = -jumpStrength;
    }

    // Perbarui gravitasi dan posisi vertikal
    if (isJumping) {
        velocityY += gravity * GetGameTime();
        y += velocityY * GetGameTime();

        if (y >= 0) {
            y = 0;
            isJumping = false;
            velocityY = 0.0f;
        }
    }

    // Perbarui posisi horizontal
    x += velocityX * GetGameTime();

    // Batas layar
    float maxX = setting->screenWidth - sprite->GetScaleWidth();
    float minX = 0;
    if (x < minX) x = minX;
    if (x > maxX) x = maxX;

    // Perbarui sprite
    sprite->SetFlipHorizontal(mul == 1 ? false : true)
        ->SetPosition(x, y)
        ->Update(GetGameTime());
}


void Engine::movement::Render() {
    if (sprite) sprite->Draw();
}

// Fungsi untuk mengecek input keyboard
bool Engine::movement::IsKeyDown(const std::string& key) {
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if (key == "A") return keystates[SDL_SCANCODE_A];
    if (key == "D") return keystates[SDL_SCANCODE_D];
    if (key == "W") return keystates[SDL_SCANCODE_W]; // Ganti dari SPACE ke W
    return false;
}

