#include "include/shape2d.hpp"

template<typename T>
T Line_t<T>::Length() const{
	return (a - b).Length();
}

template<typename T>
bool Line_t<T>::IsUpside(const Vector2_t<T> & point){
	return ((b.x - a.x) * (point.y - a.y) - (b.y - a.y) * (point.x - a.x)) > 0;

}

template<typename T>
bool Line_t<T>::Cross(const Line_t<T>& line, Vector2_t<T>& point){
	Vector2_t<T> 	A(b - a),
					B(line.b - line.a);
	T 	s = (-A.y * (a.x - line.a.x) + A.x * (a.y - line.a.y)) / ((-B.x * A.y) + (A.x * B.y)),
		t = ( B.x * (a.y - line.a.y) - B.y * (a.x - line.a.x)) / ((-B.x * A.y) + (A.x * B.y));

	if(s >= (T)0.0 && s <= (T)1.0 && t >= (T)0.0 && t <= (T)1.0){
		point(a.x + (t * A.x), a.y + (t * A.y));
		return true;
	}

	return false;
}

template<typename T>
Vector2_t<T> Line_t<T>::Projection(const Vector2_t<T>& point) const{
	// Code piqué ici : http://stackoverflow.com/questions/849211/shortest-distance-between-a-point-and-a-line-segment
	const T squaredLength = (b - a).SquaredLength();
	if(squaredLength == 0.0f)	return a;

	const T t = std::max((T)0.0, std::min((T)1.0, (point - a).Dot(b - a) / squaredLength));
	return a + (b - a) * t;
}

template<typename T>
void Line_t<T>::Translate(const Vector2_t<T>& translation){
	a += translation;
	b += translation;
}

template<typename T>
void Line_t<T>::Resize(const Vector2_t<T>& size){
	a *= size;
	b *= size;
}

template<typename T>
T Line_t<T>::Distance(const Vector2_t<T>& point) const{
	return (point - Projection(point)).Length();
}

template<typename T>
void Line_t<T>::Bounds(Vector2_t<T>& min, Vector2_t<T>& max){
	min(std::min(a.x, b.x), std::min(a.y, b.y));
	max(std::max(a.x, b.x), std::max(a.y, b.y));
}

template<typename T>
bool Line_t<T>::operator()(const Raycast2D_t<T>& ray, RaycastHit2D_t<T>& hit){
	return false;
}

template class Line_t<double>;
template class Line_t<float>;
template class Line_t<int>;