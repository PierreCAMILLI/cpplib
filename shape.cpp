#include "include/shape.hpp"

template<typename T>
Vector3_t<T> Projection(const Vector3_t<T>& point){
	return Vector3_t<T>();
}

template<typename T>
bool Plane_t<T>::Contains(const Vector3_t<T>& point){
	return false;
}

template<typename T>
void Plane_t<T>::Translate(const Vector3_t<T>& translation){
	origin += translation;
}

template<typename T>
void Plane_t<T>::Resize(const Vector3_t<T>& size){
	origin *= size;
}

template<typename T>
T Plane_t<T>::Distance(const Vector3_t<T>& point) const{
	return T(0);
}

template<typename T>
void Plane_t<T>::Bounds(Vector3_t<T>& min, Vector3_t<T>& max){

}

template<typename T>
bool Plane_t<T>::operator()(const Raycast_t<T> & ray, RaycastHit_t<T>& hit){
	// Code piqué et adapté de gKit
	T dotProduct = Vector3_t<T>::Dot(ray.direction, normal);
	if(dotProduct == T(0))
		return false;

	T t = Vector3_t<T>::Dot(origin - ray.origin, normal) / dotProduct;

	if( t < T(0) ){
		return false;
	}else{
		hit.hit = true;
		hit.origin = ray.origin;
		hit.normal = normal;
		hit.point = ray.origin + (ray.direction * t);
		return true;
	}

	return false;
}

template class Plane_t<double>;
template class Plane_t<float>;
template class Plane_t<int>;

template<typename T>
bool Sphere_t<T>::Contains(const Vector3_t<T>& point){
	return Vector3_t<T>::SquaredDistance(point,center) <= (radius * radius);
}

template<typename T>
void Sphere_t<T>::Translate(const Vector3_t<T>& translation){
	center += translation;
}

template<typename T>
void Sphere_t<T>::Resize(const Vector3_t<T>& size){
	center *= size;
	radius *= size.Length();
}

template<typename T>
T Sphere_t<T>::Distance(const Vector3_t<T>& point) const{
	return abs(Vector3_t<T>::Distance(point, center) - radius);
}

template<typename T>
void Sphere_t<T>::Bounds(Vector3_t<T>& min, Vector3_t<T>& max){
	min = center - radius;
	max = center + radius;
}

template<typename T>
bool Sphere_t<T>::operator()(const Raycast_t<T> & ray, RaycastHit_t<T>& hit){
	// Code piqué et adapté de gKit
	const Vector2_t<T> distance(ray.origin - center);
	T	a = Vector3_t<T>::Dot(ray.direction,ray.direction),
		b = T(2) * Vector3_t<T>::Dot(ray.direction,distance),
		c = Vector3_t<T>::Dot(distance,distance) - (radius * radius),
		delta = (b * b) - (T(4) * a * c);
	
	if(delta <= T(0)){
		return false;
	}else{
		T dist;

		if (delta == T(0)){	// 1 intersection
			dist = -b / (2 * a);
		}else{				// 2 intersections
			T	t1 = (-b + std::sqrt(delta))/(T(2) * a),
				t2 = (-b - std::sqrt(delta))/(T(2) * a);
				dist = (t1 < t2 ? t1 : t2);
		}

		if(ray.maxDistance >= T(0) && dist > ray.maxDistance){
			return false;
		}else{
			hit.hit = true;
			hit.origin = ray.origin;
			hit.point = ray.origin + (ray.direction * dist);
			hit.normal = hit.point - center;
			return hit.hit;
		}
	}

	return false;
}

template class Sphere_t<double>;
template class Sphere_t<float>;
template class Sphere_t<int>;

template<typename T>
bool Triangle_t<T>::Contains(const Vector3_t<T>& point){
	return false;
}

template<typename T>
void Triangle_t<T>::Translate(const Vector3_t<T>& translation){
	a += translation;
	b += translation;
	c += translation;
}

template<typename T>
void Triangle_t<T>::Resize(const Vector3_t<T>& size){
	a *= size;
	b *= size;
	c *= size;
}

template<typename T>
T Triangle_t<T>::Distance(const Vector3_t<T>& point) const{
	return T();
}

template<typename T>
void Triangle_t<T>::Bounds(Vector3_t<T>& min, Vector3_t<T>& max){
	min(std::min(std::min(a.x, b.x), c.x), std::min(std::min(a.y, b.y), c.y));
	max(std::max(std::max(a.x, b.x), c.x), std::max(std::max(a.y, b.y), c.y));
}

template<typename T>
bool Triangle_t<T>::operator()(const Raycast_t<T> & ray, RaycastHit_t<T>& hit){
	/* From gKit */
	// Find vectors for two edges sharing a
	Vector3_t<T> 	edge1 = (a - b),
					edge2 = (a - c),

	// Begin calculating determinant - also used to calculate U parameter
					pvec = Vector3_t<T>::Cross(ray.direction,edge2);

	// If determinant is near zero, ray lies in plane of triangle
	T det = Vector3_t<T>::Dot(edge1,pvec);

	/*
	constexpr double EPSILON = 0.000001;
	if(det > -EPSILON && det < EPSILON)
		return false;
	*/
	if(det == T(0))
		return false;
	T inv_det = T(1)/det;

	// Calculate distance from triangle.p1 to ray origin
	Vector3_t<T> tvec = a - ray.origin;

	// Calculate U parameter and test bounds
	T u = Vector3_t<T>::Dot(tvec,pvec) * inv_det;
	if(u < T(0) || u > T(1))
		return false;

	// Prepare to test V parameter
	Vector3_t<T> qvec = Vector3_t<T>::Cross(tvec,edge1);

	// Calculate V parameter and test bounds
	T v = Vector3_t<T>::Dot(ray.direction,qvec) * inv_det;
	if(v < T(0) || u+v > T(1))
		return false;

	// Calculate T, ray intersects triangle
	T dist = - Vector3_t<T>::Dot(edge2,qvec) * inv_det;
	if(ray.maxDistance >= T(0) && dist > ray.maxDistance){
		return false;
	}else{
		hit.hit = true;
		hit.origin = ray.origin;
		hit.point = ray.origin + (ray.direction * dist);
		// hit.normal = Normal();
		hit.normal = Vector3_t<T>::Cross(edge1,edge2);

		return hit.hit;
	}

	return false;
}

template class Triangle_t<double>;
template class Triangle_t<float>;
template class Triangle_t<int>;