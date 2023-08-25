#pragma once
#include "mComputeShader.h"
#include "mStructedBuffer.h"
#include "mMaterial.h"
namespace m::graphics
{
    class TileComputeShader :
        public ComputeShader
    {
    public:
        TileComputeShader();
        virtual ~TileComputeShader();

        virtual void Binds() override;
        virtual void Clear() override;

        void SetTileBuffer(StructedBuffer* buffer) { mTileBuffer = buffer; }
        void SetSharedBuffer(StructedBuffer* buffer) { mSharedBuffer = buffer; }
        void SetTileCoordBuffer(StructedBuffer* buffer) { mTileCoordBuffer = buffer; }
        void SetMonsterBuffer(StructedBuffer* buffer) { mMonsterBuffer = buffer; }
        void SetMonsterCoordBuffer(StructedBuffer* buffer) { mMonsterCoordBuffer = buffer; }

        virtual void OnExcute(ComputedTileCoord** data, int size, ComputedMonsterCoord** data2, int size2);

        void SetCamera(Camera* camera) { mCamera = camera; }
        Camera* GetCamera() { return mCamera; }

    private:
        StructedBuffer* mTileBuffer;
        StructedBuffer* mSharedBuffer;
        StructedBuffer* mTileCoordBuffer;
        StructedBuffer* mMonsterBuffer;
        StructedBuffer* mMonsterCoordBuffer;
        Camera* mCamera;
    };
}

