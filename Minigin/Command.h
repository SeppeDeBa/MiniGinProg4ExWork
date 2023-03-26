#pragma once
#include "GameObject.h"
namespace dae
{
	class Command
	{
	public:
		virtual ~Command() = default;
		virtual void Execute(float[[maybe_unused]] deltaTime) = 0;
	};
}

