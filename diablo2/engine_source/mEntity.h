#pragma once
#include "_Engine.h"

namespace m {
	class Entity {
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		void Update();

		std::wstring& GetName() { return mName; }
	private:
		std::wstring mName;
	};
}