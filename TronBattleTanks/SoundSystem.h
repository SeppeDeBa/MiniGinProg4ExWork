#pragma once
#include "ISoundSystem.h"
#include <memory>
// ISoundSystem has: 
// using sound_id = unsigned short;

class SoundSystem final : public ISoundSystem
{
	class SoundSystemImpl;
	std::unique_ptr<SoundSystemImpl> m_pImpl;
public: 
	SoundSystem();
	virtual ~SoundSystem();
	void Play(const sound_id soundID) const override;
	void Pause() const override;
	void Resume() const override;
	void Stop() const override;
	void Load(const char* filePath) override; 

};

