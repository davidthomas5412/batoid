#ifndef batoid_paraboloid_h
#define batoid_paraboloid_h

#include <sstream>
#include <limits>
#include "surface.h"
#include "ray.h"
#include <Eigen/Dense>

using Eigen::Vector3d;

namespace batoid {

    class Paraboloid : public Surface {
    public:
        Paraboloid(double R);
        virtual double sag(double, double) const;
        virtual Vector3d normal(double, double) const;
        virtual Ray intersect(const Ray&) const;
        virtual void intersectInPlace(Ray&) const;

        double getR() const {return _R;}
        std::string repr() const;

    private:
        const double _R;  // Radius of curvature

        bool timeToIntersect(const Ray& r, double& t) const;
    };

    inline bool operator==(const Paraboloid& p1, const Paraboloid& p2)
        { return p1.getR() == p2.getR(); }
    inline bool operator!=(const Paraboloid& p1, const Paraboloid& p2)
        { return p1.getR() != p2.getR(); }

}
#endif
