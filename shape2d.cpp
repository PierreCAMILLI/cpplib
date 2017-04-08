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
bool Line_t<T>::IsUpside(const Vector2_t<T> & point) const{
	Vector2_t<T> 	A = Vector(),
					B = point - a;
	return (A.x * B.y - A.y * B.x) > T(0);
}

template<typename T>
bool Line_t<T>::AreInSameSide(const Vector2_t<T> & p1, const Vector2_t<T> & p2) const{
	return IsUpside(p1) == IsUpside(p2);
}

template<typename T>
bool Line_t<T>::Cross(const Line_t<T>& line, Vector2_t<T>& point) const{
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
	if(squaredLength == T(0))	return a;

	const T t = std::max(T(0), std::min(T(1), Vector2_t<T>::Dot(point - a,v) / squaredLength));
	return a + (v) * t;
}

template<typename T>
bool Line_t<T>::Contains(const Vector2_t<T>& point) const{
	Vector2_t<T> 	A(point - a),
					B(b - a);
	T 	deltaX = (A.x / B.x),
		deltaY = (A.y / B.y);
	return (deltaX >= T(0) && deltaX <= T(1) &&
			deltaY >= T(0) && deltaY <= T(1) &&
			deltaX == deltaY);
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
	// Gestion de la distance avec la touchée précédente

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
			hit.normal *= T(-1);
		}
		hit.hit = true;
		return hit.hit;
	}

	return false;
}

template class Line_t<double>;
template class Line_t<float>;
template class Line_t<int>;

template<typename T>
T Circle_t<T>::Area() const{
	return SHAPE_PI * radius * radius;
}

template<typename T>
bool Circle_t<T>::Contains(const Vector2_t<T>& point) const{
	return Vector2_t<T>::SquaredDistance(point,center) <= (radius * radius);
}

template<typename T>
void Circle_t<T>::Translate(const Vector2_t<T>& translation){
	center += translation;
}

template<typename T>
void Circle_t<T>::Resize(const Vector2_t<T>& size){
	center *= size;
	radius *= size.Length();
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
	// Optimisation
	if(ray.maxDistance >= T(0) && Vector2_t<T>::SquaredDistance(ray.origin, center) > (ray.maxDistance * ray.maxDistance)){
		return false;
	}

	// Calcul des points d'intersection
	const Vector2_t<T> distance(ray.origin - center);
	T	a = Vector2_t<T>::Dot(ray.direction, ray.direction),
		b = T(2) * Vector2_t<T>::Dot(ray.direction, distance),
		c = Vector2_t<T>::Dot(distance, distance) - (radius * radius),
		delta = (b * b) - (T(4) * a * c);

	if(delta <= T(0)){		// 0 intersections
		return false;
	}else{
		T dist;

		if (delta == T(0)){	// 1 intersection
			dist = -b / (T(2) * a);
		}else{				// 2 intersections
			T	t1 = (-b + std::sqrt(delta))/(T(2) * a),
				t2 = (-b - std::sqrt(delta))/(T(2) * a);
				dist = (t1 < t2 ? t1 : t2);
		}

		// Check de distance
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

template class Circle_t<double>;
template class Circle_t<float>;
template class Circle_t<int>;

template<typename T>
T Triangle2D_t<T>::Area() const{
	Vector2_t<T> BC = Line_t<T>(b,c).Projection(a);
	return (Vector2_t<T>::Distance(b,c) * Vector2_t<T>::Distance(a,BC)) / T(2);
}

template<typename T>
Vector2_t<T> Triangle2D_t<T>::Circumcenter() const{
	// Peut-être un moyen d'avoir quelque chose de plus opti...
	Vector2_t<T>	BC = Line_t<T>(b,c).Projection(a),
					CA = Line_t<T>(c,a).Projection(b),
					point;
	Line_t<T>::Cross(Line_t<T>(a,BC),Line_t<T>(b,CA), point);
	return point;
}

template<typename T>
Vector2_t<T> Triangle2D_t<T>::Incenter() const{
	T 	A = Vector2_t<T>::Distance(b,c),
		B = Vector2_t<T>::Distance(c,a),
		C = Vector2_t<T>::Distance(a,b),
		P = A + B + C;
	return Vector2_t<T>((Vector2_t<T>(a * A) + Vector2_t<T>(b * B) + Vector2_t<T>(c * C)) / P);
}

template<typename T>
Vector2_t<T> Triangle2D_t<T>::Centroid() const{
	// Peut-être un moyen d'avoir quelque chose de plus opti...
	Vector2_t<T>	BC = Vector2_t<T>::Middle(b,c),
					CA = Vector2_t<T>::Middle(c,a),
					point;
	Line_t<T>::Cross(Line_t<T>(a,BC),Line_t<T>(b,CA), point);
	return point;
}

template<typename T>
T Triangle2D_t<T>::AspectRatio() const{
	// Absolument pas du tout optimisé...
	Vector2_t<T>	incenter = Incenter(),
					circumcenter = Circumcenter();
	T	incenterRadius = Vector2_t<T>::Distance(Line_t<T>(a,b).Projection(incenter), incenter),
		circumcenterRadius = Vector2_t<T>::Distance(circumcenter, a);
	return incenterRadius / circumcenterRadius;
}

template<typename T>
bool Triangle2D_t<T>::Contains(const Vector2_t<T>& point) const{
	Vector2_t<T> 	A = b - a,
					B = point - a;
	bool check1 = (A.x * B.y - A.y * B.x) >= T(0);
	A = c - b;
	B = point - b;
	bool check2 = (A.x * B.y - A.y * B.x) >= T(0);
	A = a - c;
	B = point - c;
	bool check3 = (A.x * B.y - A.y * B.x) >= T(0);
	return (check1 == check2) && (check2 == check3);
}

template<typename T>
void Triangle2D_t<T>::Translate(const Vector2_t<T>& translation){
	a += translation;
	b += translation;
	c += translation;
}

template<typename T>
void Triangle2D_t<T>::Resize(const Vector2_t<T>& size){
	a *= size;
	b *= size;
	c *= size;
}

template<typename T>
T Triangle2D_t<T>::Distance(const Vector2_t<T>& point) const{
	if(Contains(point))	return T(0);
	T	d1 = Line_t<T>(a,b).Distance(point),
		d2 = Line_t<T>(b,c).Distance(point),
		d3 = Line_t<T>(c,a).Distance(point);
	return (d1 <= d2 ? d1 : d2 <= d3 ? d2 : d3);
}

template<typename T>
void Triangle2D_t<T>::Bounds(Vector2_t<T>& min, Vector2_t<T>& max){
	min(std::min(std::min(a.x, b.x), c.x), std::min(std::min(a.y, b.y), c.y));
	max(std::max(std::max(a.x, b.x), c.x), std::max(std::max(a.y, b.y), c.y));
}

template<typename T>
bool Triangle2D_t<T>::operator()(const Raycast2D_t<T> & ray, RaycastHit2D_t<T>& hit){
	// A optimiser...
	RaycastHit2D_t<T> hit1, hit2, hit3;
	Line_t<T>(a,b)(ray, hit1),
	Line_t<T>(b,c)(ray, hit2),
	Line_t<T>(c,a)(ray, hit3);

	// Gestion de l'intersection avec le segment le plus proche
	T	dist_temp_,
		dist_temp = std::numeric_limits<T>::max();
	// Gestion de la distance au premier segment
	if(hit1){
		hit = hit1;
		dist_temp = Vector2_t<T>::SquaredDistance(hit.origin, hit.point);
	}
	// Gestion de la distance au second segment
	if(hit2){
		dist_temp_ = Vector2_t<T>::SquaredDistance(hit2.origin, hit2.point);
		if(dist_temp_ < dist_temp){
			hit = hit2;
			dist_temp = dist_temp_;
		}
	}
	// Gestion de la distance au troisième segment
	if(hit3){
		dist_temp_ = Vector2_t<T>::SquaredDistance(hit3.origin, hit3.point);
		if(dist_temp_ < dist_temp){
			hit = hit3;
		}
	}

	return hit1 || hit2 || hit3;
}

template class Triangle2D_t<double>;
template class Triangle2D_t<float>;
template class Triangle2D_t<int>;