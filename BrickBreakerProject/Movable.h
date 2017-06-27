#pragma once
#include "GameObject.h"
#include "Direction.h"

template<typename T>
class Movable :
	public virtual Drawable
{
public:
	Movable();
	virtual ~Movable();
	virtual void move() = 0;
	void setDirection(const Direction<T> & dir);
	void setSpeed(float speed);
	T getDirection() const;
	float getSpeed() const;
private:
	Direction<T> m_dir;
	float m_speed;
};

template<typename T>
inline Movable<T>::Movable()
{}

template<typename T>
inline Movable<T>::~Movable()
{}

template<typename T>
inline void Movable<T>::setDirection(const Direction<T>& dir)
{
	m_dir = dir;
}

template<typename T>
inline void Movable<T>::setSpeed(float speed)
{
	m_speed = speed;
}

template<typename T>
inline T Movable<T>::getDirection() const
{
	return m_dir.getDirection();
}

template<typename T>
inline float Movable<T>::getSpeed() const
{
	return m_speed;
}
