#include "Animation.h"


Animation::Animation()
{}

Animation::Animation(int frmWd, int frmHt, int txtrWd, int txtrHt, const sf::Time & time)
	:
	m_curFrame(0),
	m_running(false),
	m_repeat(true),
	m_delay(time)
{
	int w = txtrWd / frmWd, h = txtrHt / frmHt;
	
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			m_frames.emplace_back(sf::IntRect{ j * frmWd, i * frmHt, frmWd, frmHt });
}

Animation::~Animation()
{}

void Animation::start()
{
	if (!m_running)
	{
		m_running = true;
		m_clock.restart();
	}
}

void Animation::stop()
{
	m_running = false;
}

void Animation::step()
{
	m_curFrame++;

	if (m_repeat && m_curFrame == m_frames.size())
		m_curFrame = 0;
}

void Animation::setRepeat(bool repeat)
{
	m_repeat = repeat;
}

bool Animation::finished() const
{
	return (m_running && !m_repeat && (m_curFrame == m_frames.size() - 1));
}

const sf::IntRect & Animation::nextFrame()
{
	if (m_running && m_clock.getElapsedTime() >= m_delay)
	{
		m_curFrame++;
		m_clock.restart();
	}

	if (m_curFrame == m_frames.size())
	{
		if (m_repeat)
			m_curFrame = 0;
		else
			throw;	//	throw out-of-range exception.
	}

	return m_frames[m_curFrame];
}
