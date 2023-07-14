#pragma once
#include "mItem.h"

#include "..\engine_source\mSceneManager.h"
#include "..\engine_source\mLayer.h"

namespace m
{
    class ItemPlaced;
    class InvenItem :
        public Item
    {
    public:
        InvenItem(eItem item, ItemPlaced* inventory);
        virtual ~InvenItem();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render() override;
        bool MouseFollow() { return bSetMouseFollow; }
        void SetClickFunction() { SceneManager::GetActiveScene()->GetLayer(eLayerType::Item).ChangeOrderGameObject(this); }
    private:
        bool bSetMouseFollow;
        int curInvenIndex;
        Vector3 prevPosition;
        ItemPlaced* mInventory;
        eItem mItem;
    };
}

