#pragma once
#include <Command.h>
#include "ISoundSystem.h"
#include "SoundServiceLocator.h"
class SoundCommand final : public dae::Command
{
public:
	SoundCommand(sound_id id)
		:m_SoundID{ id }
	{

	}
	virtual ~SoundCommand() = default;
	virtual void Execute( float ) override
	{
		auto& soundService = SoundServiceLocator::Get_Sound_System();
		soundService.Play(m_SoundID);
	};
private:
	sound_id m_SoundID;
	

};

