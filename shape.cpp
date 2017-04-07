#include "include/shape.hpp"

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
	T t = Vector3_t<T>::Dot(ray.origin - origin, normal) / Vector3_t<T>::Dot(ray.direction, normal);

	if( t < T(0) ){
		return false;
	}else{
		hit.hit = true;
		hit.origin = ray.origin;
		hit.normal = normal;
		hit.point = ray.direction * t;
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
	return Vector3_t<T>::Distance(point, center) - radius;
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

		if(ray.maxDistance >= T(0) && dist * ray.direction.Length() > ray.maxDistance){
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