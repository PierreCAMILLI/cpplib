#include "include/vector.hpp"

// ------------------ VECTOR2 ------------------ //

template<typename T>
Vector2_t<T>& Vector2_t<T>::operator()(const T _x, const T _y){
	x = _x;
	y = _y;
	return (*this);
}

template<typename T>
Vector2_t<T>& Vector2_t<T>::operator+=(const Vector2_t<T>& _v){
	x += _v.x;
	y += _v.y;
	return (*this);
}

template<typename T>
Vector2_t<T>& Vector2_t<T>::operator+=(const T& n){
	x += n;
	y += n;
	return (*this);
}

template<typename T>
Vector2_t<T>& Vector2_t<T>::operator-=(const Vector2_t<T>& _v){
	return (*this) += (-_v);
}

template<typename T>
Vector2_t<T>& Vector2_t<T>::operator-=(const T& n){
	return (*this) += (-n);
}

template<typename T>
Vector2_t<T>& Vector2_t<T>::operator*=(const Vector2_t<T>& _v){
	x *= _v.x;
	y *= _v.y;
	return (*this);
}

template<typename T>
Vector2_t<T>& Vector2_t<T>::operator*=(const T& n){
	x *= n;
	y *= n;
	return (*this);
}

template<typename T>
Vector2_t<T>& Vector2_t<T>::operator/=(const T& n){
	return (*this) *= (1/n);
}

template<typename T>
bool Vector2_t<T>::operator==(const Vector2_t<T>& _v){
	return (x == _v.x && y == _v.y);
}

template<typename T>
bool Vector2_t<T>::operator!=(const Vector2_t<T>& _v){
	return !((*this) == _v);
}

template<typename T>
T Vector2_t<T>::operator[](const unsigned int& i) const{
	assert(i < 2);
	return (&x)[i];
}

template<typename T>
T& Vector2_t<T>::operator[](const unsigned int& i){
	assert(i < 2);
	return (&x)[i];
}

template<typename T>
T Vector2_t<T>::SquaredLength() const{
	return (x * x) + (y * y);
}

template<typename T>
T Vector2_t<T>::Length() const{
	return sqrt(SquaredLength());
}

template<typename T>
T Vector2_t<T>::Dot(const Vector2_t<T>& _v) const{
	return (x * _v.x) + (y * _v.y);
}

template<typename T>
Vector2_t<T> Vector2_t<T>::Normalized() const{
	T kk = 1/Length();
	return (*this) * kk;
}

template<typename T>
void Vector2_t<T>::Display(){
	std::cout << x << "\t" << y << std::endl;
}

// ------------------ VECTOR3 ------------------ //

template<typename T>
Vector3_t<T>& Vector3_t<T>::operator()(const T _x, const T _y, const T _z){
	x = _x;
	y = _y;
	z = _z;
	return (*this);
}

template<typename T>
Vector3_t<T>& Vector3_t<T>::operator+=(const Vector3_t<T>& _v){
	x += _v.x;
	y += _v.y;
	z += _v.z;
	return (*this);
}

template<typename T>
Vector3_t<T>& Vector3_t<T>::operator+=(const T& n){
	x += n;
	y += n;
	z += n;
	return (*this);
}

template<typename T>
Vector3_t<T>& Vector3_t<T>::operator-=(const Vector3_t<T>& _v){
	return (*this) += (-_v);
}

template<typename T>
Vector3_t<T>& Vector3_t<T>::operator-=(const T& n){
	return (*this) += (-n);
}

template<typename T>
Vector3_t<T>& Vector3_t<T>::operator*=(const Vector3_t<T>& _v){
		x *= _v.x;
		y *= _v.y;
		z *= _v.z;
		return (*this);
}

template<typename T>
Vector3_t<T>& Vector3_t<T>::operator*=(const T& n){
	x *= n;
	y *= n;
	z *= n;
	return (*this);
}

template<typename T>
Vector3_t<T>& Vector3_t<T>::operator/=(const T& n){
	return (*this) *= (1/n);
}

template<typename T>
bool Vector3_t<T>::operator==(const Vector3_t<T>& _v){
	return (x == _v.x && y == _v.y && z == _v.z);
}

template<typename T>
bool Vector3_t<T>::operator!=(const Vector3_t<T>& _v){
	return !((*this) == _v);
}

template<typename T>
T Vector3_t<T>::operator[](const unsigned int& i) const{
	assert(i < 3);
	return (&x)[i];
}

template<typename T>
T& Vector3_t<T>::operator[](const unsigned int& i){
	assert(i < 3);
	return (&x)[i];
}

template<typename T>
T Vector3_t<T>::SquaredLength() const{
	return (x * x) + (y * y) + (z * z);
}

template<typename T>
T Vector3_t<T>::Length() const{
	return sqrt(SquaredLength());
}

template<typename T>
T Vector3_t<T>::Dot(const Vector3_t<T>& _v) const{
	return (x * _v.x) + (y * _v.y) + (z * _v.z);
}

template<typename T>
Vector3_t<T> Vector3_t<T>::Cross(const Vector3_t<T>& _v) const{
	return Vector3_t<T>(
		(y * _v.z) - (z * _v.y),
		(z * _v.x) - (x * _v.z),
		(x * _v.y) - (y * _v.x)
		);
}

template<typename T>
Vector3_t<T> Vector3_t<T>::Normalized() const{
	T kk = 1/Length();
	return (*this) * kk;
}

template<typename T>
void Vector3_t<T>::Display(){
	std::cout << x << "\t" << y << "\t" << z << std::endl;
}

// ------------------ POINT ------------------ //

template<typename T>
Point_t<T>& Point_t<T>::operator()(const T _x, const T _y, const T _z){
	x = _x;
	y = _y;
	z = _z;
	return (*this);
}

template<typename T>
Point_t<T>& Point_t<T>::operator+=(const Vector3_t<T>& _v){
	x += _v.x;
	y += _v.y;
	z += _v.z;
	return (*this);
}

template<typename T>
Point_t<T>& Point_t<T>::operator+=(const T& n){
	x -= n;
	y -= n;
	z -= n;
	return (*this);
}

template<typename T>
Point_t<T>& Point_t<T>::operator-=(const Vector3_t<T>& _v){
	return (*this) += (-_v);
}

template<typename T>
Point_t<T>& Point_t<T>::operator-=(const T& n){
	return (*this) += (-n);
}

template<typename T>
Point_t<T>& Point_t<T>::operator*=(const Vector3_t<T>& _v){
	x *= _v.x;
	y *= _v.y;
	z *= _v.z;
	return (*this);
}

template<typename T>
Point_t<T>& Point_t<T>::operator*=(const T& n){
	x *= n;
	y *= n;
	z *= n;
	return (*this);
}

template<typename T>
Point_t<T>& Point_t<T>::operator/=(const T& n){
	return (*this) *= (1/n);
}

template<typename T>
Vector3_t<T> Point_t<T>::operator-(const Point_t<T>& _p) const{
	return Vector3_t<T>(x - _p.x, y - _p.y, z - _p.z);
}

template<typename T>
bool Point_t<T>::operator==(const Point_t<T>& _p){
	return (x == _p.x && y == _p.y && z == _p.z);
}

template<typename T>
bool Point_t<T>::operator!=(const Point_t<T>& _p){
	return !((*this) == _p);
}

template<typename T>
T Point_t<T>::operator[](const unsigned int& i) const{
	assert(i < 3);
	return (&x)[i];
}

template<typename T>
T& Point_t<T>::operator[](const unsigned int& i){
	assert(i < 3);
	return (&x)[i];
}

template<typename T>
T Point_t<T>::Distance(const Point_t<T>& _p) const{
	return (Vector3_t<T>(_p) - Vector3_t<T>(*this)).Length();
}

template<typename T>
Point_t<T> Point_t<T>::Center(const Point_t<T>& _p) const{
	return Point_t<T>(x + _p.x, y + _p.y, z + _p.z) / 2.0f;
}

template<typename T>
void Point_t<T>::Display(){
	std::cout << x << "\t" << y << "\t" << z << std::endl;
}

// ------------------ VECTOR4 --------------------- //

template<typename T>
Vector4_t<T>& Vector4_t<T>::operator()(const T _x, const T _y, const T _z, const T _w){
	x = _x;
	y = _y;
	z = _z;
	w = _w;
	return (*this);
}

template<typename T>
Vector4_t<T>& Vector4_t<T>::operator+=(const Vector4_t<T>& _v){
	x += _v.x;
	y += _v.y;
	z += _v.z;
	w += _v.w;
	return (*this);
}

template<typename T>
Vector4_t<T>& Vector4_t<T>::operator+=(const T& n){
	x += n;
	y += n;
	z += n;
	w += n;
	return (*this);
}

template<typename T>
Vector4_t<T>& Vector4_t<T>::operator-=(const Vector4_t<T>& _v){
	return (*this) += (-_v);
}

template<typename T>
Vector4_t<T>& Vector4_t<T>::operator-=(const T& n){
	return (*this) += (-n);
}

template<typename T>
Vector4_t<T>& Vector4_t<T>::operator*=(const Vector4_t<T>& _v){
	x *= _v.x;
	y *= _v.y;
	z *= _v.z;
	w *= _v.w;
	return (*this);
}

template<typename T>
Vector4_t<T>& Vector4_t<T>::operator*=(const T& n){
	x *= n;
	y *= n;
	z *= n;
	w *= n;
	return (*this);
}

template<typename T>
Vector4_t<T>& Vector4_t<T>::operator/=(const T& n){
	return (*this) *= (1/n);
}

template<typename T>
bool Vector4_t<T>::operator==(const Vector4_t<T>& _v){
	return (x == _v.x && y == _v.y && z == _v.z && w == _v.w);
}

template<typename T>
bool Vector4_t<T>::operator!=(const Vector4_t<T>& _v){
	return !((*this) == _v);
}

template<typename T>
T Vector4_t<T>::operator[](const unsigned int& i) const{
	assert(i < 4);
	return (&x)[i];
}

template<typename T>
T& Vector4_t<T>::operator[](const unsigned int& i){
	assert(i < 4);
	return (&x)[i];
}

template<typename T>
T Vector4_t<T>::SquaredLength() const{
	return (x * x) + (y * y) + (z * z) + (w * w);
}

template<typename T>
T Vector4_t<T>::Length() const{
	return sqrt(SquaredLength());
}

template<typename T>
T Vector4_t<T>::Dot(const Vector3_t<T>& _v) const{
	return (x * _v.x) + (y * _v.y) + (z * _v.z) + (w * _v.w);
}

template<typename T>
Vector4_t<T> Vector4_t<T>::Normalized() const{
	T kk = 1/Length();
	return (*this) * kk;
}

template<typename T>
void Vector4_t<T>::Display(){
	std::cout << x << "\t" << y << "\t" << z << "\t" << w << std::endl;
}



template class Vector2_t<double>;
template class Vector2_t<float>;
template class Vector2_t<int>;

template class Vector3_t<double>;
template class Vector3_t<float>;
template class Vector3_t<int>;

template class Point_t<double>;
template class Point_t<float>;
template class Point_t<int>;