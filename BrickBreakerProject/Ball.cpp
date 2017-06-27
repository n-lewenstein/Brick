#include "Ball.h"
#include "Constants.h"

Ball::Ball()
{
	Animation::start();
	//take care of the sprite size.
	textures::bl_txtr.loadFromFile(paths::ball_path);
	Drawable::m_sprite.setTexture(textures::bl_txtr);
	Drawable::m_sprite.setOrigin({ (float)sizes::bl_rds, (float)sizes::bl_rds });

	//trial
	Drawable::m_sprite.setPosition(m_center);
}

Ball::Ball(const sf::Vector2f & center, float radius)
	:
	Animation(sizes::bl_frm_wd, sizes::bl_frm_ht, sizes::bl_txtr_wd, sizes::bl_txtr_ht, sf::seconds(0.5)),
	m_center(center),
	m_radius(radius)
{
	Animation::stop();
	//take care of the sprite size.
	textures::bl_txtr.loadFromFile(paths::ball_path);
	Drawable::m_sprite.setTexture(textures::bl_txtr);
	Drawable::m_sprite.setOrigin({ (float)sizes::bl_rds, (float)sizes::bl_rds });

	//trial
	Drawable::m_sprite.setPosition(m_center);
}

Ball::~Ball()
{}

void Ball::draw(sf::RenderWindow & win)
{
	Drawable::m_sprite.setTextureRect(Animation::nextFrame());
	win.draw(Drawable::m_sprite);
}

bool Ball::contains(const sf::Vector2f & point) const
{
	double distance = pow(point.x - m_center.x, 2) + pow(point.y - m_center.y, 2);
	distance = sqrt(distance);

	return distance <= m_radius;
}

void Ball::move()
{
	float A = sin(Movable::getDirection() * sizes::d2r);
	float B = cos(Movable::getDirection() * sizes::d2r);

	sf::Vector2f offset = { float(B*Movable::getSpeed()), float(A*Movable::getSpeed()) };

	m_center.x += offset.x;
	m_center.y += offset.y;

	Drawable::m_sprite.move(offset);
}

void Ball::expand(float mul)
{}

Collision Ball::collide(const Bound & obj) const
{
	Collision clsn;
	bool upHit = false, btmHit = false, leftHit = false, rightHit = false;

	//	Up, down, Left and Right are relative to the other object.
	sf::Vector2f up		{ m_center.x,m_center.y - m_radius };
	sf::Vector2f btm	{ m_center.x,m_center.y + m_radius };
	sf::Vector2f left	{ m_center.x + m_radius,m_center.y };
	sf::Vector2f right	{ m_center.x - m_radius,m_center.y };

	upHit = !obj.contains(up);
	btmHit = !obj.contains(btm);
	leftHit = !obj.contains(left);
	rightHit = !obj.contains(right);

	clsn.collide = (upHit || btmHit || leftHit || rightHit);

	if (!clsn.collide)
		return clsn;

	clsn.hittingObjDir = Movable::getDirection();
	clsn.orient = (upHit || btmHit ? HV::Horizontal : HV::Vertical);

	return clsn;
}

Collision Ball::collide(const Paddle & obj) const
{
	Collision clsn;
	sf::FloatRect bounds = obj.bounds();
	bool upHit = false, btmHit = false, leftHit = false, rightHit = false, lCnrHit = false, rCnrHit = false;

	//	Up, down, Left and Right are relative to the other object.
	sf::Vector2f up{ m_center.x,m_center.y + m_radius };
	sf::Vector2f btm{ m_center.x,m_center.y - m_radius };
	sf::Vector2f left{ m_center.x + m_radius,m_center.y };
	sf::Vector2f right{ m_center.x - m_radius,m_center.y };

	upHit = obj.contains(up);
	btmHit = obj.contains(btm);
	leftHit = obj.contains(left);
	rightHit = obj.contains(right);
	lCnrHit = Ball::contains({ bounds.left, bounds.top });
	rCnrHit = Ball::contains({ bounds.left + bounds.width, bounds.top });

	clsn.collide = (upHit || btmHit || leftHit || rightHit || lCnrHit || rCnrHit);

	if (!clsn.collide)
		return clsn;

	clsn.orient = (upHit || btmHit ? HV::Horizontal : HV::Vertical);

	auto relative_hit = [](float high, float low, float hit) -> int
	{
		return int(((hit - low) / (high - low)) * 100);
	};
	
	if (upHit || btmHit)
		clsn.relativeHit = relative_hit(bounds.width, 0.f, m_center.x - bounds.left);
	else if (leftHit || rightHit)
		clsn.relativeHit = relative_hit(bounds.height, 0.f, m_center.y - bounds.top);
	else if (lCnrHit)
		clsn.relativeHit = 0;
	else
		clsn.relativeHit = 100;

	return clsn;
}

Collision Ball::collide(const Brick & obj) const
{
	Collision clsn;
	bool upHit = false, btmHit = false, leftHit = false, rightHit = false;

	//	Up, down, Left and Right are relative to the other object.
	sf::Vector2f up{ m_center.x,m_center.y + m_radius };
	sf::Vector2f btm{ m_center.x,m_center.y - m_radius };
	sf::Vector2f left{ m_center.x + m_radius,m_center.y };
	sf::Vector2f right{ m_center.x - m_radius,m_center.y };

	upHit = obj.contains(up);
	btmHit = obj.contains(btm);
	leftHit = obj.contains(left);
	rightHit = obj.contains(right);

	clsn.collide = (upHit || btmHit || leftHit || rightHit);

	if (!clsn.collide)
		return clsn;

	clsn.hittingObjDir = Movable::getDirection();
	clsn.orient = ((upHit || btmHit) ? HV::Horizontal : HV::Vertical);

	return clsn;
}

Collision Ball::collide(const std::shared_ptr<Drawable>& obj) const
{
	Collision clsn;
	bool upHit = false, btmHit = false, leftHit = false, rightHit = false;

	//	Up, down, Left and Right are relative to the other object.
	sf::Vector2f up{ m_center.x,m_center.y - m_radius };
	sf::Vector2f btm{ m_center.x,m_center.y + m_radius };
	sf::Vector2f left{ m_center.x + m_radius,m_center.y };
	sf::Vector2f right{ m_center.x - m_radius,m_center.y };

	upHit = obj->contains(up);
	btmHit = obj->contains(btm);
	leftHit = obj->contains(left);
	rightHit = obj->contains(right);

	clsn.collide = (upHit || btmHit || leftHit || rightHit);

	if (!clsn.collide)
		return clsn;

	clsn.hittingObjDir = Movable::getDirection();
	clsn.orient = (upHit || btmHit ? HV::Horizontal : HV::Vertical);

	auto relative_hit = [](float high, float low, float hit) -> int
	{
		return int(((hit - low) / (high - low)) * 100);
	};

	sf::FloatRect bounds = (*obj).bounds();

	if (upHit || btmHit)
		clsn.relativeHit = relative_hit(bounds.width, 0.f, m_center.x - bounds.left);
	else if (leftHit || rightHit)
		clsn.relativeHit = relative_hit(bounds.height, 0.f, m_center.y - bounds.top);

	return clsn;
}
