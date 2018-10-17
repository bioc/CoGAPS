#include "Math.h"
#include "VectorMath.h"
#include "SIMD.h"

static float dot_helper(const float *v1, const float *v2, unsigned size)
{
    gaps::simd::PackedFloat pp1, pp2, sum(0.f);
    gaps::simd::Index i(0);
    for (; i < size; ++i)
    {
        pp1.load(v1 + i);
        pp2.load(v2 + i);
        sum += pp1 * pp2;
    }
    return sum.scalar();
}

float gaps::min(const Vector &v)
{
    float mn = 0.f;
    for (unsigned i = 0; i < v.size(); ++i)
    {
        if (v[i] < mn)
        {
            mn = v[i];
        }
    }
    return mn;
}

float gaps::min(const HybridVector &v)
{
    float mn = 0.f;
    for (unsigned i = 0; i < v.size(); ++i)
    {
        if (v[i] > mn)
        {
            mn = v[i];
        }
    }
    return mn;
}

float gaps::max(const Vector &v)
{
    float mx = 0.f;
    for (unsigned i = 0; i < v.size(); ++i)
    {
        if (v[i] > mx)
        {
            mx = v[i];
        }
    }
    return mx;
}

float gaps::max(const HybridVector &v)
{
    float mx = 0.f;
    for (unsigned i = 0; i < v.size(); ++i)
    {
        if (v[i] > mx)
        {
            mx = v[i];
        }
    }
    return mx;
}

bool gaps::isVectorZero(const Vector &v)
{
    for (unsigned i = 0; i < v.size(); ++i)
    {
        if (v[i] > 0.f)
        {
            return false;
        }
    }
    return true;
}

bool gaps::isVectorZero(const HybridVector &v)
{
    return v.empty();
}

float gaps::dot(const Vector &v1, const Vector &v2)
{
    GAPS_ASSERT(v1.size() == v2.size());

    return dot_helper(v1.ptr(), v2.ptr(), v1.size());
}

float gaps::dot(const HybridVector &v1, const HybridVector &v2)
{
    GAPS_ASSERT(v1.size() == v2.size());

    return dot_helper(v1.densePtr(), v2.densePtr(), v1.size());
}

float gaps::sum(const Vector &v)
{
    float sum = 0.f;
    for (unsigned i = 0; i < v.size(); ++i)
    {
        sum += v[i];
    }
    return sum;
}

float gaps::sum(const HybridVector &v)
{
    float sum = 0.f;
    for (unsigned i = 0; i < v.size(); ++i)
    {
        sum += v[i];
    }
    return sum;
}

Vector gaps::elementSq(Vector v)
{
    for (unsigned i = 0; i < v.size(); ++i)
    {
        v[i] *= v[i];
    }
    return v;
}

Vector operator*(Vector v, float f)
{
    for (unsigned i = 0; i < v.size(); ++i)
    {
        v[i] *= f;
    }
    return v;
}

Vector operator/(Vector v, float f)
{
    for (unsigned i = 0; i < v.size(); ++i)
    {
        v[i] /= f;
    }
    return v;
}

Vector operator*(const HybridVector &hv, float f)
{
    Vector v(hv.size());
    for (unsigned i = 0; i < hv.size(); ++i)
    {
        v[i] = hv[i] * f;
    }
    return v;
}

Vector operator/(const HybridVector &hv, float f)
{
    Vector v(hv.size());
    for (unsigned i = 0; i < hv.size(); ++i)
    {
        v[i] = hv[i] / f;
    }
    return v;
}

Vector gaps::pmax(Vector v, float p)
{
    for (unsigned i = 0; i < v.size(); ++i)
    {
        v[i] = gaps::max(v[i] * p, p);
    }
    return v;
}