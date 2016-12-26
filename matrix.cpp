#include "include/matrix.hpp"

template<typename T,unsigned int U>
inline Matrix_<T,U>::Matrix_(){
	m = (T*) malloc(sizeof(T)*U*U);
	setToIdentity();
}

template<typename T,unsigned int U>
inline Matrix_<T,U>::Matrix_(const T& n){
	m = (T*) malloc(sizeof(T)*U*U);
	fill(n);
}

template<typename T,unsigned int U>
inline Matrix_<T,U>::Matrix_(const T* const _t){
	m = (T*) malloc(sizeof(T)*U*U);
	fill(_t);
}

template<typename T,unsigned int U>
inline Matrix_<T,U>::Matrix_(T* const _t){
	m = (T*) malloc(sizeof(T)*U*U);
	fill(_t);
}

template<typename T,unsigned int U>
inline Matrix_<T,U>::Matrix_(T** const _t){
	m = (T*) malloc(sizeof(T)*U*U);
	fill(_t);
}

template<typename T,unsigned int U>
inline Matrix_<T,U>::Matrix_(const Matrix_<T,U>& _m){
	m = (T*) malloc(sizeof(T)*U*U);
	for(unsigned int i = 0; i < U*U; i++){
		m[i] = _m.m[i];
	}
}

template<typename T,unsigned int U>
Matrix_<T,U>::~Matrix_<T,U>(){
	//	release();
}

template<typename T,unsigned int U>
Matrix_<T,U> Matrix_<T,U>::copy() const{
	Matrix_<T,U> res;
	for(unsigned int i = 0; i < U*U; i++)
		res.m[i] = m[i];
	return res;
}

template<typename T,unsigned int U>
void Matrix_<T,U>::release(){
	free(m);
}

template<typename T,unsigned int U>
Matrix_<T,U> Matrix_<T,U>::Identity(){
	return Matrix_<T,U>();
}


template<typename T,unsigned int U>
T& Matrix_<T,U>::operator()(const unsigned int& x, const unsigned int& y){
	assert(x < U);
	assert(y < U);
	return m[x + y*U];
}

template<typename T,unsigned int U>
T Matrix_<T,U>::operator()(const unsigned int& x, const unsigned int& y) const{
	assert(x < U);
	assert(y < U);
	return m[x + y*U];
}

template<typename T,unsigned int U>
Matrix_<T,U> Matrix_<T,U>::operator*(const Matrix_<T,U>& _m) const{
	Matrix_<T,U> res;
	for(unsigned int i = 0; i < U; i++){
		for(unsigned int j = 0; j < U; j++){
			T val = 0.0f;
			for(unsigned int k = 0; k < U; k++){
				val += (*this)(k,i) * _m(j,k);
			}
			res(j,i) = val;
		}
	}
	return res;
}

template<typename T,unsigned int U>
Matrix_<T,U> Matrix_<T,U>::operator*(const T& n) const{
	Matrix_<T,U> res;
	for(unsigned int i = 0; i < U; i++){
		for(unsigned int j = 0; j < U; j++){
			res(i,j) = (*this)(i,j) * n;
		}
	}
	return res;
}

template<typename T,unsigned int U>
Matrix_<T,U> Matrix_<T,U>::operator+(const Matrix_<T,U>& _m) const{
	Matrix_<T,U> res;
	for(unsigned int i = 0; i < U; i++){
		for(unsigned int j = 0; j < U; j++){
			res(i,j) = (*this)(i,j) + _m(i,j);
		}
	}
	return res;
}

template<typename T,unsigned int U>
Matrix_<T,U> Matrix_<T,U>::operator+(const T& n) const{
	Matrix_<T,U> res;
	for(unsigned int i = 0; i < U; i++){
		for(unsigned int j = 0; j < U; j++){
			res(i,j) = (*this)(i,j) + n;
		}
	}
	return res;
}

template<typename T,unsigned int U>
Matrix_<T,U> Matrix_<T,U>::operator-() const{
	Matrix_<T,U> res;
	for(unsigned int i = 0; i < U; i++){
		for(unsigned int j = 0; j < U; j++){
			res(i,j) = -(*this)(i,j);
		}
	}
	return res;
}

template<typename T,unsigned int U>
Matrix_<T,U> Matrix_<T,U>::operator-(const Matrix_<T,U>& _m) const{
	Matrix_<T,U> res;
	for(unsigned int i = 0; i < U; i++){
		for(unsigned int j = 0; j < U; j++){
			res(i,j) = (*this)(i,j) - _m(i,j);
		}
	}
	return res;
}

template<typename T,unsigned int U>
Matrix_<T,U> Matrix_<T,U>::operator-(const T& n) const{
	return (*this) + (-n);
}

template<typename T,unsigned int U>
Matrix_<T,U> Matrix_<T,U>::operator/(const T& n) const{
	return (*this) * (1/n);
}

template<typename T,unsigned int U>
bool Matrix_<T,U>::operator==(const Matrix_<T,U>& _m){
	for(unsigned int i = 0; i < U; i++){
		for(unsigned int j = 0; j < U; j++){
			if((*this)(i,j) != _m(i,j))
				return false;
		}
	}
	return true;
}

template<typename T,unsigned int U>
bool Matrix_<T,U>::operator!=(const Matrix_<T,U>& _m){
	return !((*this) == _m);
}


template<typename T,unsigned int U>
const T* Matrix_<T,U>::constData() const{
	return m;
}

template<typename T,unsigned int U>
T* Matrix_<T,U>::data() const{
	return m;
}

template<typename T,unsigned int U>
T** Matrix_<T,U>::data2D() const{
	T** res = (T**) malloc(U * sizeof(T*));
	for(unsigned int i = 0; i < U; i++){
		res[i] = (T*) malloc(U * sizeof(T));
		for(unsigned int j = 0; j < U; j++){
			res[i][j] = (*this)(j,i);
		}
	}
	return res;
}


template<typename T,unsigned int U>
void Matrix_<T,U>::fill(const T& n) {
	for(unsigned int i = 0; i < U * U; i++){
		m[i] = n;
	}
}

template<typename T,unsigned int U>
void Matrix_<T,U>::fill(const T* const _t) {
	for(unsigned int i = 0; i < U * U; i++){
		m[i] = _t[i];
	}
}

template<typename T,unsigned int U>
void Matrix_<T,U>::fill(T* const _t) {
	for(unsigned int i = 0; i < U * U; i++){
		m[i] = _t[i];
	}
}

template<typename T,unsigned int U>
void Matrix_<T,U>::fill(T** const _t) {
	for(unsigned int i = 0; i < U; i++){
		for(unsigned int j = 0; j < U; j++){
			(*this)(i,j) = _t[j][i];
		}
	}
}

template<typename T,unsigned int U>
void Matrix_<T,U>::fillRow(const unsigned int& r, const T& n) {
	for(unsigned int i = 0; i < U; i++){
			(*this)(i,r) = n;
	}
}

template<typename T,unsigned int U>
void Matrix_<T,U>::fillRow(const unsigned int& r, const T* const _t) {
	for(unsigned int i = 0; i < U; i++){
			(*this)(i,r) = _t[i];
	}
}

template<typename T,unsigned int U>
void Matrix_<T,U>::fillRow(const unsigned int& r, T* const _t) {
	for(unsigned int i = 0; i < U; i++){
			(*this)(i,r) = _t[i];
	}
}

template<typename T,unsigned int U>
void Matrix_<T,U>::fillColumn(const unsigned int& c, const T& n) {
	for(unsigned int i = 0; i < U; i++){
			(*this)(c,i) = n;
	}
}

template<typename T,unsigned int U>
void Matrix_<T,U>::fillColumn(const unsigned int& c, const T* const _t) {
	for(unsigned int i = 0; i < U; i++){
			(*this)(c,i) = _t[i];
	}
}

template<typename T,unsigned int U>
void Matrix_<T,U>::fillColumn(const unsigned int& c, T* const _t) {
	for(unsigned int i = 0; i < U; i++){
			(*this)(c,i) = _t[i];
	}
}

template<typename T,unsigned int U>
void Matrix_<T,U>::switchPositions(const unsigned int& x1, const unsigned int& y1, const unsigned int& x2, const unsigned int& y2){
	T temp = (*this)(x1,y1);
	(*this)(x1,y1) = (*this)(x2,y2);
	(*this)(x2,y2) = temp;
}

template<typename T,unsigned int U>
void Matrix_<T,U>::setToIdentity(){
	fill(0.0f);
	for(unsigned int i = 0; i < U; i++){
		(*this)(i,i) = 1;
	}
}

template<typename T,unsigned int U>
Matrix_<T,U-1> Matrix_<T,U>::reduce(const unsigned int& x, const unsigned int& y) const{
	Matrix_<T,U-1> res;
	for(unsigned int i = 0; i < U-1; i++){
		for(unsigned int j = 0; j < U-1; j++){
			unsigned int xx = i + (i >= x ? 1 : 0);
			unsigned int yy = j + (j >= y ? 1 : 0);
			res(i,j) = (*this)(xx,yy);
		}
	}
	return res;
}

template<typename T,unsigned int U>
T Matrix_<T,U>::determinant() const{
	// Cas où la matrice est de taille 1 ou 2
	if(U == 1)
		return m[0];
	if(U == 2)
		return m[0]*m[3] - m[1]*m[2];
	T res = 0.0f;
	for(unsigned int i = 0; i < U; i++){
		Matrix_<T,U-1> mat = reduce(i,0);
		res += ((i&1) == 1 ? -1 : 1) * m[i] * mat.determinant();
	}
	return res;
}

template<typename T,unsigned int U>
Matrix_<T,U> Matrix_<T,U>::transpose() const{
	Matrix_<T,U> res;
	for(unsigned int i = 0; i < U; i++){
		for(unsigned int j = 0; j < U; j++){
			res(j,i) = (*this)(i,j);
		}
	}
	return res;
}

template<typename T,unsigned int U>
Matrix_<T,U> Matrix_<T,U>::invert() const{
	T det = determinant();
	// On vérifie si la matrice est inversible
	if(det == 0.0f)
		return *this;
	Matrix_<T,U> res;
	for(unsigned int i = 0; i < U; i++)
		for(unsigned int j = 0; j < U; j++){
			res(j,i) = (((i+j)&1) == 1 ? -1 : 1) * reduce(j,i).determinant();
		}
	return res.transpose() / det;
}

template<typename T,unsigned int U>
Matrix_<T,U> Matrix_<T,U>::normale() const{
	return invert().transpose();
}


template<typename T,unsigned int U>
void Matrix_<T,U>::display(){
	for(unsigned int j = 0; j < U; j++){
		for(unsigned int i = 0; i < U; i++){
			std::cout << (*this)(i,j) << "\t";
		}
		std::cout << std::endl;
	}
}

template<typename T,unsigned int U>
void Matrix_<T,U>::display(const unsigned int& x, const unsigned int& y){
	std::cout << (*this)(x,y) << std::flush;
}

template<typename T,unsigned int U>
void Matrix_<T,U>::displayColumn(const unsigned int& x){
	for(unsigned int i = 0; i < U; i++){
		std::cout << (*this)(x,i) << std::endl;
	}
	std::cout << std::endl;
}

template<typename T,unsigned int U>
void Matrix_<T,U>::displayRow(const unsigned int& y){
	for(unsigned int i = 0; i < U; i++){
		std::cout << (*this)(i,y) << "\t";
	}
	std::cout << std::endl;
}

template<typename T>
Vector2_t<T> operator*(const Matrix_<T,2>& _m, const Vector2_t<T>& _v){
	return Vector2_t<T>(
		(_m(0,0) * _v.x) + (_m(1,0) * _v.y),
		(_m(0,1) * _v.x) + (_m(1,1) * _v.y));
}

template<typename T>
Vector2_t<T> operator*(const Vector2_t<T>& _v, const Matrix_<T,2>& _m){
	return Vector2_t<T>(
		(_m(0,0) * _v.x) + (_m(0,1) * _v.y),
		(_m(1,0) * _v.x) + (_m(1,1) * _v.y));
}

template<typename T>
Vector3_t<T> operator*(const Matrix_<T,3>& _m, const Vector3_t<T>& _v){
	return Vector3_t<T>(
		(_m(0,0) * _v.x) + (_m(1,0) * _v.y) + (_m(2,0) * _v.z),
		(_m(0,1) * _v.x) + (_m(1,1) * _v.y) + (_m(2,1) * _v.z),
		(_m(0,2) * _v.x) + (_m(1,2) * _v.y) + (_m(2,2) * _v.z));
}

template<typename T>
Vector3_t<T> operator*(const Vector3_t<T>& _v, const Matrix_<T,3>& _m){
	return Vector3_t<T>(
		(_m(0,0) * _v.x) + (_m(0,1) * _v.y) + (_m(0,2) * _v.z),
		(_m(1,0) * _v.x) + (_m(1,1) * _v.y) + (_m(1,2) * _v.z),
		(_m(2,0) * _v.x) + (_m(2,1) * _v.y) + (_m(2,2) * _v.z));
}

template class Matrix_<double,2>;
template class Matrix_<int,2>;
template class Matrix_<float,2>;

template class Matrix_<double,3>;
template class Matrix_<int,3>;
template class Matrix_<float,3>;

template class Matrix_<double,4>;
template class Matrix_<int,4>;
template class Matrix_<float,4>;