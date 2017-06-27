#pragma once

//	Left/Right direction.
enum LR : int
{
	Left = -1, Right = 1
};

enum UD : int
{
	Up = -1, Down = 1
};

enum class HV
{
	Horizontal, Vertical
};

template<typename T>
class Direction
{
public:
	Direction();
	Direction(const T & dir);
	~Direction();
	void setDirection(const T & t);
	T getDirection() const;
private:
	T m_dir;
};

template<typename T>
inline Direction<T>::Direction()
{}

template<typename T>
inline Direction<T>::Direction(const T & dir)
	:
	m_dir(dir)
{}

template<typename T>
inline Direction<T>::~Direction()
{}

template<typename T>
inline void Direction<T>::setDirection(const T & t)
{
	m_dir = t;
}

template<typename T>
inline T Direction<T>::getDirection() const
{
	return m_dir;
}
