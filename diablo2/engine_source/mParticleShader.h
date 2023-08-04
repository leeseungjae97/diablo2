#pragma once
#include "mComputeShader.h"
#include "mStructedBuffer.h"

namespace m::graphics
{
    class ParticleShader :
        public ComputeShader
    {
	public:
		ParticleShader();
		~ParticleShader();

		virtual void Binds() override;
		virtual void Clear() override;

		void SetParticleBuffer(StructedBuffer* particleBuffer);

	private:
		StructedBuffer* mParticleBuffer;

    };
}

