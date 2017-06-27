#include "Board.h"
#include "ExpandPad.h"
#include "ShortenPad.h"
#include "SlowBall.h"
#include "RapidBall.h"
#include "TwoBalls.h"

Board::Board()
{
	textures::backrnd_txtr.loadFromFile(paths::backrnd_path);
	m_backgrnd.setTexture(textures::backrnd_txtr);

	Ball bl({ sizes::win_wd / 2.0,sizes::win_ht / 2.0 }, (float)sizes::bl_rds);
	bl.setDirection(30);
	bl.setSpeed(0.9f);
	m_balls.push_back(bl);

	m_pad.setSpeed(1);
	
	for (int i = 0; i < 7; ++i)
		for (int j = 0; j < 8; ++j)
			m_bricks.push_back(Brick({ (float)(j*sizes::brk_frm_wd), (float)((i*sizes::brk_frm_ht)+155) }, 2));
	m_info.setBrickAmount(m_bricks.size());
}

Board::~Board()
{}

void Board::setLevel(const Level & level)
{}

void Board::draw(sf::RenderWindow & win)
{
	win.draw(m_backgrnd);
	m_info.draw(win);
	m_pad.draw(win);

	std::for_each(m_bricks.begin(), m_bricks.end(), [&win](Brick & br) { br.draw(win); });
	std::for_each(m_fall.begin(), m_fall.end(), [&win](auto & fo) { if(!fo->finished()) fo->draw(win); });
	std::for_each(m_balls.begin(), m_balls.end(), [&win](Ball & bl) { bl.draw(win); });
}

void Board::update()
{
	for (size_t i = 0; i < m_balls.size(); i++) //(auto & m_balls[i] : m_m_balls[i]s)
	{
		Collision bndCol = m_balls[i].collide(m_bnd);
		Collision pdlCol = m_balls[i].collide(m_pad);
	
		if (bndCol.collide)
		{
			m_balls[i].setDirection(m_bnd.calc(bndCol));
			if (bndCol.orient == HV::Horizontal &&
				bndCol.hittingObjDir.getDirection() >= 0
				&& bndCol.hittingObjDir.getDirection() <= 180)
			{
				m_balls.erase(m_balls.begin() + i--);
				continue;
			}
		}
		if (pdlCol.collide)
			m_balls[i].setDirection(m_pad.calc(pdlCol));

		auto brick = m_bricks.begin();
		for (; brick != m_bricks.end(); ++brick)
		{
			Collision brkCol = m_balls[i].collide(*brick);

			if (brkCol.collide)
			{
				m_balls[i].setDirection((*brick).calc(brkCol));
				break;
			}
		}

		if (brick != m_bricks.end())
		{
			brick->hit();
			if (brick->hitsLeft() == 0)
			{
				m_info.addScore(brick->getVal());///
				sf::FloatRect bounds = brick->bounds();
				sf::Vector2f pos(bounds.left + bounds.width / 2 - sizes::fo_frm_wd / 2, bounds.top);
				m_fall.emplace_back(randomFalling(pos));
				m_bricks.erase(brick);
			}
		}
	}

	for (int i = 0; i < m_fall.size(); ++i)
	{
		Collision foColPad = m_fall[i]->collide(m_pad);
		Collision foColBnd = m_fall[i]->collide(m_bnd);

		if (foColPad.collide || foColBnd.collide)
		{
			
			m_fall[i]->start();
			m_info.addScore(m_fall[i]->getVal());
			if (foColPad.collide)
				m_fall[i]->action(*this);
		}
		if (m_fall[i]->finished())
			m_fall.erase(m_fall.begin() + i--);
	}

	m_info.setBrickAmount(m_bricks.size());
}

void Board::moveAll()
{
	std::for_each(m_fall.begin(), m_fall.end(), [](auto & fo) { fo->move(); });
	std::for_each(m_balls.begin(), m_balls.end(), [](Ball & bl) { bl.move(); });
}

void Board::boardEvents(sf::RenderWindow & win)
{
	sf::Vector2f left{ m_pad.bounds().left + m_pad.bounds().width /2 , m_pad.bounds().top };
	sf::Vector2f right{ m_pad.bounds().left + 3*m_pad.bounds().width /2 , m_pad.bounds().top };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_bnd.contains(left))
	{
		m_pad.setDirection(LR::Left);
		m_pad.move();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_bnd.contains(right))
	{
		m_pad.setDirection(LR::Right);
		m_pad.move();
	}
}

std::shared_ptr<FallingObject> Board::randomFalling(const sf::Vector2f & pos) const
{
	using std::make_shared;
	int limit = Fallings::_num_of_fallings;
	int rnd = rand() % limit;
	Fallings fo = static_cast<Fallings>(rnd);

	switch (fo)
	{
	case Fallings::ExpandPadType:
		return make_shared<ExpandPad>(pos);
	case Fallings::ShortenPadType:
		return make_shared<ShortenPad>(pos);
	case Fallings::RapidBallType:
		return make_shared<RapidBall>(pos);
	case Fallings::SlowBallType:
		return make_shared<SlowBall>(pos);
	case Fallings::TwoBallsType:
		return make_shared<TwoBalls>(pos);
	default:
		throw;	//handle this.
	}
}
