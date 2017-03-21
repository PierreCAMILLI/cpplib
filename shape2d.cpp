#include "include/shape2d.hpp"

template<typename T>
Vector2_t<T> Line_t<T>::Vector() const{
	return b - a;
}

template<typename T>
T Line_t<T>::Length() const{
	return Vector().Length();
}

template<typename T>
bool Line_t<T>::IsUpside(const Vector2_t<T> & point){
	return ((b.x - a.x) * (point.y - a.y) - (b.y - a.y) * (point.x - a.x)) > T(0);
}

template<typename T>
bool Line_t<T>::AreInSameSide(const Vector2_t<T> & p1, const Vector2_t<T> & p2){
	return IsUpside(p1) == IsUpside(p2);
}

template<typename T>
bool Line_t<T>::Cross(const Line_t<T>& line, Vector2_t<T>& point){
	// Code piqué ici : http://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect
	Vector2_t<T> 	A(Vector()),
					B(line.Vector());
	T 	crossProduct = (-B.x * A.y) + (A.x * B.y),
		s = (-A.y * (a.x - line.a.x) + A.x * (a.y - line.a.y)) / crossProduct,
		t = ( B.x * (a.y - line.a.y) - B.y * (a.x - line.a.x)) / crossProduct;

	if(s >= T(0) && s <= T(1) && t >= T(0) && t <= T(1)){
		point(a.x + (t * A.x), a.y + (t * A.y));
		return true;
	}

	return false;
}

template<typename T>
Vector2_t<T> Line_t<T>::Projection(const Vector2_t<T>& point) const{
	// Code piqué ici : http://stackoverflow.com/questions/849211/shortest-distance-between-a-point-and-a-line-segment
	Vector2_t<T> v = Vector();
	const T squaredLength = v.SquaredLength();
	if(squaredLength == 0.0f)	return a;

	const T t = std::max((T)0.0, std::min((T)1.0, (point - a).Dot(v) / squaredLength));
	return a + (v) * t;
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
	Vector2_t<T> 	A(Vector()),
					B(ray.direction);
	T 	crossProduct = (-B.x * A.y) + (A.x * B.y),
		s = (-A.y * (a.x - ray.origin.x) + A.x * (a.y - ray.origin.y)) / crossProduct,
		t = ( B.x * (a.y - ray.origin.y) - B.y * (a.x - ray.origin.x)) / crossProduct;

	// Test de respect de distance
	bool distanceCheck = true;
	Vector2_t<T> point(a.x + (t * A.x), a.y + (t * A.y));
	if(ray.maxDistance >= T(0)){
		T distance = (point - ray.origin).SquaredLength();
		distanceCheck = (distance <= (ray.maxDistance * ray.maxDistance));
	}

	// On checke si le rayon touche la ligne
	if(s >= T(0) && t >= T(0) && t <= T(1) && distanceCheck){
		hit.origin = ray.origin;
		hit.point = point;

		// Gestion de la normale
		hit.normal(-A.y, A.x);
		if(!AreInSameSide(ray.origin, hit.point + hit.normal)){
			hit.normal *= -1;
		}
		hit.hit = true;
	}

	return hit.hit;
}

template class Line_t<double>;
template class Line_t<float>;
template class Line_t<int>;

template<typename T>
bool Circle_t<T>::IsInside(const Vector2_t<T>& point){
	return (point - center).SquaredLength() <= (radius * radius);
}

template<typename T>
void Circle_t<T>::Translate(const Vector2_t<T>& translation){
	center += translation;
}

template<typename T>
void Circle_t<T>::Resize(const Vector2_t<T>& size){
	T r = size.x * size.y;
	radius *= r;
}

template<typename T>
T Circle_t<T>::Distance(const Vector2_t<T>& point) const{
	T dist = (center - point).Length();
	return std::max(T(0), dist - radius);
}

template<typename T>
void Circle_t<T>::Bounds(Vector2_t<T>& min, Vector2_t<T>& max){
	min = center - radius;
	max = center + radius;
}

template<typename T>
bool Circle_t<T>::operator()(const Raycast2D_t<T> & ray, RaycastHit2D_t<T>& hit){
	// Code piqué et adapté de gKit
	Vector2_t<T> distance(ray.origin - center);
	T	a = ray.direction.Dot(ray.direction),
		b = T(2) * ray.direction.Dot(distance),
		c = distance.Dot(distance) - (radius * radius),
		delta = (b * b) - (T(4) * a * c);

	if(delta <= T(0)){		// 0 intersections
		hit.hit = false;
	}else{
		T dist;

		if (delta == T(0)){	// 1 intersection
			dist = -b / (2 * a);
		}else{				// 2 intersections
			T	t1 = (-b + sqrtf(delta))/(T(2) * a),
				t2 = (-b - sqrtf(delta))/(T(2) * a);
			dist = (t1 < t2 ? t1 : t2);
		}

		// Check de distance
		if(ray.maxDistance >= 0 && dist * ray.direction.Length() > ray.maxDistance){
			hit.hit = false;
		}else{
			hit.hit = true;
			hit.origin = ray.origin;
			hit.point = ray.origin + (ray.direction * dist);
			hit.normal = hit.point - center;
		}
	}
	return hit.hit;
}

template class Circle_t<double>;
template class Circle_t<float>;
template class Circle_t<int>;