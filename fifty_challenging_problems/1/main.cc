#include <stdio.h>
#include <math.h>

static void solve_polynom(double p[3], double s[2])
{
  // s the solutions, -1 for invalid
  s[0] = -1.f;
  s[1] = -1.f;

  // b^2 - 4ac
  const double d = p[1] * p[1] - 4 * p[0] * p[2];

  // sols: -b +- sqrt(d) / 2a
  if (d >= 0.f)
  {
    const double aa = 2 * p[0];
    if (d == 0.f)
    {
      s[0] = (p[1] * -1.f) / aa;
    }
    else
    {
      const double sqrtd = sqrt(d);
      s[0] = (p[1] * -1.f + sqrtd) / aa;
      s[1] = (p[1] * -1.f - sqrtd) / aa;
    }
  }
}

static void make_polynom(double p[3], double b)
{
  p[0] = -1.f;
  p[1] = 2 * b + 1.f;
  p[2] = b * b - b;
}

static bool is_valid(double s)
{
  if (s <= 0.f) return false;
  if ((s - ((int)s)) < 0.0001) return true;
  return false;
}

int main(int ac, char** av)
{
  for (double b = 0; b < 1000000; b += 1)
  {
    double p[3], s[2];
    make_polynom(p, b);
    solve_polynom(p, s);

    if (is_valid(s[0])) printf("b=%lf, r=%lf\n", b, s[0]);
    if (is_valid(s[1])) printf("b=%lf, r=%lf\n", b, s[1]);
  }

  return 0;
}
