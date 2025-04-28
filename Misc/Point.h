#pragma once

namespace math {
	template<typename T>
	class Point {
	public:
		Point() = default;
		Point(T x, T y) :
			m_x{ x },
			m_y{ y }
		{
		}

		Point<T> operator + (const Point<T>& other) const {
			return Point<T>(m_x + other.m_x, m_y + other.m_y);
		}

		Point<T> operator - (const Point<T>& other) const {
			return Point<T>(m_x - other.m_x, m_y - other.m_y);
		}

		bool operator == (const Point<T>& other) const {
			return (this->m_x == other.m_x && this->m_y == other.m_y);
		}

		bool operator != (const Point<T>& other) const {
			return !(*this == other);
		}

		Point<T> Add(const Point<T>& other) const {
			return Point<T>(m_x + other.m_x, m_y + other.m_y);
		}

		T getX() const { return m_x; }
		T getY() const { return m_y; }

	private:
		int m_x = 0;
		int m_y = 0;
	};

	using ipoint_t = Point<int>;
	using ipoint_f = Point<float>;
} 