#pragma once
#include "../engine_source/mScript.h"
#include "../engine_source/AnimLookUpTables.h"

namespace m
{
    class GameObject;
    class Animator;
    class PlayerScript :
        public Script
    {
    public:
        PlayerScript();
        ~PlayerScript();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render() override;

        void Complete();
        void AnimationStart(GameObject::eBattleState state);
        void AnimationComplete(GameObject::eBattleState state);
    private:
        Animator* mAnimator;
        eCharacterDirection mDirection;
        eSorceressAnimationType mAnimationType;
    };
}

