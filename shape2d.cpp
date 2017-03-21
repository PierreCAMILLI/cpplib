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

	return false;
}

template<typename T>
Vector2_t<T> Line_t<T>::Projection(const Vector2_t<T>& point) const{
	// Code piqué ici : http://stackoverflow.com/questions/849211/shortest-distance-between-a-point-and-a-line-segment
	Vector2_t<T> v = (b - a);
	const T squaredLength = (v.x * v.x) + (v.y * v.y);
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