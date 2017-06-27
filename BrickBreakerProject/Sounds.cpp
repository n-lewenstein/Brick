#include "Sounds.h"

Sounds::Sounds()
{
	m_brk_hit_buf.loadFromFile(paths::hit_snd_path);
	m_brk_hit.setBuffer(m_brk_hit_buf);
}

void Sounds::playSound(const SoundType & soundType)
{
	switch (soundType)
	{
	case SoundType::BrickHit:
		m_brk_hit.play();
		break;
	default:
		break;
	}
}

sf::Sound Sounds::m_brk_hit = sf::Sound{};