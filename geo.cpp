#include "include/geo.hpp"

// ------------------------- LINE --------------------------//

template<typename T>
T Line_t<T>::length() const{
	return a.distance(b);
}

template<typename T>
T Line_t<T>::crossProduct(const Point_t<T>& _p) const{
	return (((b.x - a.x) * (_p.y - a.y)) - ((b.y - a.y) * (_p.x - a.x)));
}

template<typename T>
T Line_t<T>::distance(const Point_t<T>& _p) const{
	T X = b.x - a.x;
	T Y = b.y - a.y;
	T d1 = abs((Y * _p.x) - (X * _p.y) + (b.x * a.y) - (b.y * a.x));
	T d2 = sqrt((Y * Y) + (X * X));
	return d1 / d2;
}

template<typename T>
bool Line_t<T>::isUpside(const Point_t<T>& _p){
	return crossProduct(_p) > 0;
}

template<typename T>
bool Line_t<T>::isDownside(const Point_t<T>& _p){
	return crossProduct(_p) < 0;
}

template<typename T>
bool Line_t<T>::isOn(const Point_t<T>& _p){
	return crossProduct(_p) == 0;
}

template<typename T>
bool Line_t<T>::areInSameSide(const Point_t<T>& _p1, const Point_t<T>& _p2){
	return crossProduct(_p1) * crossProduct(_p2) > 0;
}

template<typename T>
bool Line_t<T>::cross(const Line_t<T>& _l, Point_t<T>& _p){
	double div = (a.x - b.x) * (_l.a.y - _l.b.y)
				- (a.y - b.y) * (_l.a.x - _l.b.x);
  	if(div == 0)
      	return false;

  	double &&tmp1 = (a.x * b.y - a.y * b.x) ;
  	double &&tmp2 = (_l.a.x * _l.b.y - _l.a.y * _l.b.x);

  	_p.x = (tmp1 * (_l.a.x - _l.b.x) - (a.x - b.y) * tmp2) / div;
  	_p.y = (tmp1 * (_l.a.y - _l.b.y) - (a.x - b.y) * tmp2) / div;

  	return true;
}

// ------------------------- PLAN --------------------------//

template<typename T>
T Plane_t<T>::distance(const Point_t<T>& _p) const{
	// TODO
	return 0.0f;
}

template<typename T>
bool Plane_t<T>::isAbove(const Point_t<T>& _p){
	return n.dot(Vector3_t<T>(_p)) > 0;
}

template<typename T>
bool Plane_t<T>::isBelow(const Point_t<T>& _p){
	return n.dot(Vector3_t<T>(_p)) < 0;
}

template<typename T>
bool Plane_t<T>::isIn(const Point_t<T>& _p){
	return n.dot(Vector3_t<T>(_p)) == 0;
}

template<typename T>
bool Plane_t<T>::areInSameSide(const Point_t<T>& _p1, const Point_t<T>& _p2){
	return n.dot(Vector3_t<T>(_p1)) * n.dot(Vector3_t<T>(_p2)) > 0;
}

// ------------------------- TRIANGLE --------------------------//

template<typename T>
bool Triangle_t<T>::areCollinear(){
	return ((b.y - a.y) * (c.x - b.x)) == ((c.y - b.y) * (b.x - a.x));
}

template<typename T>
T Triangle_t<T>::distance(const Point_t<T>& _p) const{
	// TODO
	return 0.0f;
}

template<typename T>
Vector3_t<T> Triangle_t<T>::normal() const{
	return (b - a) * (c - a);
}

template<typename T>
bool Triangle_t<T>::isInside(const Point_t<T>& _p){
	return 		Line_t<T>(a,b).areInSameSide(_p,c)
			&& 	Line_t<T>(b,c).areInSameSide(_p,a)
			&&	Line_t<T>(c,a).areInSameSide(_p,b);
}

template<typename T>
Point_t<T> Triangle_t<T>::circumscribedCenter() const{
	Point_t<T> 	ab = a.center(b),
				ac = a.center(c);

	// Gestion des erreurs
	Triangle_t<T> t_temp = (*this);
	if(t_temp.b.y == t_temp.a.y){
		Point_t<T>	temp = t_temp.c;
					t_temp.c = t_temp.a;
					t_temp.a = temp;
	}
	if(t_temp.c.y == t_temp.a.y){
		Point_t<T>	temp = t_temp.b;
					t_temp.b = t_temp.a;
					t_temp.a = temp;
	}

	Vector3_t<T>	vAB = t_temp.b - t_temp.a,
					vAC = t_temp.c - t_temp.a;
	T 	coefAB = - vAB.x / vAB.y,
		coefAC = - vAC.x / vAC.y,

		ordAB = ab.y - coefAB * ab.x,
		ordAC = ac.y - coefAC * ac.x,

		X = (ordAC - ordAB) / (coefAB - coefAC);

	return Point_t<T>(X , (coefAB * X + ordAB));
}

template<typename T>
Point_t<T> Triangle_t<T>::inscribedCenter() const{
	// TODO
	return Point_t<T>();
}

// ------------------------- CIRCLE --------------------------//

template<typename T>
T Circle_t<T>::distance(const Point_t<T>& _p) const{
	// TODO
	return 0.0f;
}

template<typename T>
bool Circle_t<T>::isInside(const Point_t<T>& _p){
	T 	X = (_p.x - c.x),
		Y = (_p.y - c.y),
		dist = sqrt((X * X) + (Y * Y));
	return dist < r;
}

// ------------------------- DISC --------------------------//

template<typename T>
T Disc_t<T>::distance(const Point_t<T>& _p) const{
	// TODO
	return 0.0f;
}

template<typename T>
bool Disc_t<T>::isInside(const Point_t<T>& _p){
	T 	X = (_p.x - c.x),
		Y = (_p.y - c.y),
		dist = sqrt((X * X) + (Y * Y));
	return dist < r;
}

// ------------------------- SPHERE --------------------------//

template<typename T>
T Sphere_t<T>::distance(const Point_t<T>& _p) const{
	T dist = _p.distance(c);
	return (dist > r ? dist - r : 0.0f);
}

template<typename T>
bool Sphere_t<T>::isInside(const Point_t<T>& _p){
	return c.distance(_p) < r;
}

// ------------------------- BOX --------------------------//

template<typename T>
Box_t<T>::Box_t(const T x1, const T y1, const T z1, const T x2, const T y2, const T z2){
	if(x1 < x2){
		min.x = x1;
		max.x = x2;
	}else{
		min.x = x2;
		max.x = x1;
	}

	if(y1 < y2){
		min.y = y1;
		max.y = y2;
	}else{
		min.y = y2;
		max.y = y1;
	}

	if(z1 < z2){
		min.z = z1;
		max.z = z2;
	}else{
		min.z = z2;
		max.z = z1;
	}
}

template<typename T>
Box_t<T>::Box_t(const Point_t<T>& _min, const Point_t<T>& _max){
	if(_min.x < _max.x){
		min.x = _min.x;
		max.x = _max.x;
	}else{
		min.x = _max.x;
		max.x = _min.x;
	}

	if(_min.y < _max.y){
		min.y = _min.y;
		max.y = _max.y;
	}else{
		min.y = _max.y;
		max.y = _min.y;
	}

	if(_min.z < _max.z){
		min.z = _min.z;
		max.z = _max.z;
	}else{
		min.z = _max.z;
		max.z = _min.z;
	}
}

template<typename T>
T Box_t<T>::distance(const Point_t<T>& _p) const{
	// TODO
	return 0.0f;
}

template<typename T>
bool Box_t<T>::isInside(const Point_t<T>& _p){
	return 		(_p.x > min.x) && (_p.y > min.y)
			&&	(_p.x < max.x) && (_p.y < max.y);
}

// ---------------------------- RAY ------------------------------- //

template<typename T>
void Ray_t<T>::orderHits(VectorHit_t<T>& hits){
	bool ordered;
	do{
		ordered = true;
		for(unsigned int i = 0; i < hits.size() - 1; i++){
			if(hits[i].d > hits[i+1].d){
				Hit_t<T> h_temp = hits[i];
				hits[i] = hits[i+1];
				hits[i+1] = h_temp;
				ordered = false; 
			}
		}
	}while(!ordered);
}

template<typename T>
bool Ray_t<T>::operator()(const Plane_t<T>& _p, Hit_t<T>& _h){
	/* From gKit */
	T t = (o - _p.a).dot(_p.n) / d.dot(_p.n);
	if(t < 0)
		return false;
	_h.d = t;
	_h.p = o + (d * t);
	_h.n = _p.n;
	return true;
}

template<typename T>
bool Ray_t<T>::operator()(const Triangle_t<T>& _t, Hit_t<T>& _h){
	/* From gKit */
	// Find vectors for two edges sharing _t.a
	Vector3_t<T> edge1 = (_t.a - _t.b);
	Vector3_t<T> edge2 = (_t.a - _t.c);

	// Begin calculating determinant - also used to calculate U parameter
	Vector3_t<T> pvec = d * edge2;

	// If determinant is near zero, ray lies in plane of triangle
	T det = edge1.dot(pvec);

	if(det > -EPSILON && det < EPSILON)
		return false;
	T inv_det = 1/det;

	// Calculate distance from triangle.p1 to ray origin
	Vector3_t<T> tvec = _t.a - o;

	// Calculate U parameter and test bounds
	T u = tvec.dot(pvec) * inv_det;
	if(u < 0.0f || u > 1.0f)
		return 0.0f;

	// Prepare to test V parameter
	Vector3_t<T> qvec = tvec * edge1;

	// Calculate V parameter and test bounds
	T v = d.dot(qvec) * inv_det;
	if(v < 0.0f || u+v > 1.0f)
		return false;

	// Calculate T, ray intersects triangle
	T dist = - edge2.dot(qvec) * inv_det;
	_h.d = dist;
	_h.p = o + (d * dist);
	_h.n = _t.normal();

	return true;
}

template<typename T>
bool Ray_t<T>::operator()(const Disc_t<T>& _d, Hit_t<T>& _h){
	// TODO
	return false;
}

template<typename T>
bool Ray_t<T>::operator()(const Sphere_t<T>& _s, Hit_t<T>& _h){
	/* From gKit */
	T a = d.dot(d);
	T b = 2 * d.dot(o - _s.c);
	T c = (o - _s.c).dot(o - _s.c) - (_s.r * _s.r);
	T delta = (b * b) - (4 * a * c);
	if(delta <= 0)
		return false;
	T t1 = (-b + sqrtf(delta))/(2 * a);
	T t2 = (-b - sqrtf(delta))/(2 * a);
	T dist = (t1 < t2 ? t1 : t2);
	_h.d = dist;
	_h.p = o + (d * dist);
	_h.n = _h.p - _s.c;
	return true;
}

template<typename T>
bool Ray_t<T>::operator()(const Box_t<T>& _b, Hit_t<T>& _h){
	// TODO
	return false;
}

template<typename T>
bool Ray_t<T>::operator()(const VectorPlane_t<T>& _p, Hit_t<T>& _h){
	T dmax = Hit_t<T>::infinity();
	bool touched = false;
	for(unsigned int i = 0; i < _p.size(); i++){
		Hit_t<T> htemp;
		Plane_t<T> p_temp = _p[i];
		if((*this)(p_temp, htemp) && htemp.d < dmax){
			_h = htemp;
			touched = true;
		}
	}
	return touched;
}

template<typename T>
bool Ray_t<T>::operator()(const VectorTriangle_t<T>& _t, Hit_t<T>& _h){
	T dmax = Hit_t<T>::infinity();
	bool touched = false;
	for(unsigned int i = 0; i < _t.size(); i++){
		Hit_t<T> htemp;
		Triangle_t<T> t_temp = _t[i];
		if((*this)(t_temp, htemp) && htemp.d < dmax){
			_h = htemp;
			touched = true;
		}
	}
	return touched;
}

template<typename T>
bool Ray_t<T>::operator()(const VectorDisc_t<T>& _d, Hit_t<T>& _h){
	T dmax = Hit_t<T>::infinity();
	bool touched = false;
	for(unsigned int i = 0; i < _d.size(); i++){
		Hit_t<T> htemp;
		Disc_t<T> d_temp = _d[i];
		if((*this)(d_temp, htemp) && htemp.d < dmax){
			_h = htemp;
			touched = true;
		}
	}
	return touched;
}

template<typename T>
bool Ray_t<T>::operator()(const VectorSphere_t<T>& _s, Hit_t<T>& _h){
	T dmax = Hit_t<T>::infinity();
	bool touched = false;
	for(unsigned int i = 0; i < _s.size(); i++){
		Hit_t<T> htemp;
		Sphere_t<T> s_temp = _s[i];
		if((*this)(s_temp, htemp) && htemp.d < dmax){
			_h = htemp;
			touched = true;
		}
	}
	return touched;
}

template<typename T>
bool Ray_t<T>::operator()(const VectorBox_t<T>& _b, Hit_t<T>& _h){
	T dmax = Hit_t<T>::infinity();
	bool touched = false;
	for(unsigned int i = 0; i < _b.size(); i++){
		Hit_t<T> htemp;
		Box_t<T> b_temp = _b[i];
		if((*this)(b_temp, htemp) && htemp.d < dmax){
			_h = htemp;
			touched = true;
		}
	}
	return touched;
}

template<typename T>
bool Ray_t<T>::operator()(const Geo_Scene_t<T>& _sc, Hit_t<T>& _h){
	Hit_t<T> h_temp;
	bool touched = false;
	// Planes
	touched = (touched ? true : (*this)(_sc.planes, h_temp));
	if(h_temp.d < _h.d)
		_h = h_temp;
	// Triangles
	touched = (touched ? true : (*this)(_sc.triangles, h_temp));
	if(h_temp.d < _h.d)
		_h = h_temp;
	// Discs
	touched = (touched ? true : (*this)(_sc.discs, h_temp));
	if(h_temp.d < _h.d)
		_h = h_temp;
	// Sphere
	touched = (touched ? true : (*this)(_sc.spheres, h_temp));
	if(h_temp.d < _h.d)
		_h = h_temp;
	// Boxes
	touched = (touched ? true : (*this)(_sc.boxes, h_temp));
	if(h_temp.d < _h.d)
		_h = h_temp;
	return false;
}

template<typename T>
VectorHit_t<T> Ray_t<T>::operator()(const VectorPlane_t<T>& _p){
	VectorHit_t<T> hits;
	for(unsigned int i = 0; i < _p.size(); i++){
		Hit_t<T> htemp;
		Plane_t<T> p_temp = _p[i];
		if((*this)(p_temp, htemp)){
			hits.push_back(htemp);
		}
	}
	orderHits(hits);
	return hits;
}

template<typename T>
VectorHit_t<T> Ray_t<T>::operator()(const VectorTriangle_t<T>& _t){
	VectorHit_t<T> hits;
	for(unsigned int i = 0; i < _t.size(); i++){
		Hit_t<T> h_temp;
		Triangle_t<T> t_temp = _t[i];
		if((*this)(t_temp, h_temp))
			hits.push_back(h_temp);
	}
	orderHits(hits);
	return hits;
}

template<typename T>
VectorHit_t<T> Ray_t<T>::operator()(const VectorDisc_t<T>& _d){
	VectorHit_t<T> hits;
	for(unsigned int i = 0; i < _d.size(); i++){
		Hit_t<T> h_temp;
		Disc_t<T> d_temp = _d[i];
		if((*this)(d_temp, h_temp))
			hits.push_back(h_temp);
	}
	orderHits(hits);
	return hits;
}

template<typename T>
VectorHit_t<T> Ray_t<T>::operator()(const VectorSphere_t<T>& _s){
	VectorHit_t<T> hits;
	for(unsigned int i = 0; i < _s.size(); i++){
		Hit_t<T> h_temp;
		Sphere_t<T> s_temp = _s[i];
		if((*this)(s_temp, h_temp))
			hits.push_back(h_temp);
	}
	orderHits(hits);
	return hits;
}

template<typename T>
VectorHit_t<T> Ray_t<T>::operator()(const VectorBox_t<T>& _b){
	VectorHit_t<T> hits;
	for(unsigned int i = 0; i < _b.size(); i++){
		Hit_t<T> h_temp;
		Box_t<T> b_temp = _b[i];
		if((*this)(b_temp, h_temp))
			hits.push_back(h_temp);
	}
	orderHits(hits);
	return hits;
}

template<typename T>
VectorHit_t<T> Ray_t<T>::operator()(const Geo_Scene_t<T>& _sc){
	VectorHit_t<T> 	hits,
					h_temp = (*this)(_sc.planes);
	hits.insert(hits.end(), h_temp.begin(), h_temp.end());
	h_temp = (*this)(_sc.triangles);
	hits.insert(hits.end(), h_temp.begin(), h_temp.end());
	h_temp = (*this)(_sc.discs);
	hits.insert(hits.end(), h_temp.begin(), h_temp.end());
	h_temp = (*this)(_sc.spheres);
	hits.insert(hits.end(), h_temp.begin(), h_temp.end());
	h_temp = (*this)(_sc.boxes);
	hits.insert(hits.end(), h_temp.begin(), h_temp.end());
	return hits;
}

template class Line_t<double>;
template class Line_t<float>;
template class Line_t<int>;

template class Triangle_t<double>;
template class Triangle_t<float>;
template class Triangle_t<int>;

template class Circle_t<double>;
template class Circle_t<float>;
template class Circle_t<int>;

template class Disc_t<double>;
template class Disc_t<float>;
template class Disc_t<int>;

template class Sphere_t<double>;
template class Sphere_t<float>;
template class Sphere_t<int>;

template class Box_t<double>;
template class Box_t<float>;
template class Box_t<int>;

template class Plane_t<double>;
template class Plane_t<float>;
template class Plane_t<int>;

template class Hit_t<double>;
template class Hit_t<float>;
template class Hit_t<int>;

template class Ray_t<double>;
template class Ray_t<float>;
template class Ray_t<int>;