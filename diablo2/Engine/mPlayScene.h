#pragma once
#include "../engine_source/mScene.h"
namespace m
{
    class Inventory;
    class Pocket;
    class SkillUp;
    class Tile;
    class BottomUI;
    class PlayScene :
        public Scene
    {
    public:
        PlayScene();
        virtual ~PlayScene();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render() override;
    private:
        GameObject* camera;
        Inventory* inventory;
        SkillUp* skillUp;
        BottomUI* uiBottomBar;
    };
}


