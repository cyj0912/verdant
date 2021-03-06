#pragma once
#include "Scene.h"

namespace verdant {
/**
 * @brief Whitted path tracing integrator
 * @note This class is not meant to be long-lived.
 */
class PathIntegrator {
public:
  PathIntegrator(const Scene &scene, UniformSampler &sampler,
                 float pr_continue = 0.9f);

  float3 Lo_from_ray(const Ray &ray);

private:
  // These references are declared as member fields so that passing a pointer to
  // the integrator is enough
  const Scene &scene;
  UniformSampler &sampler;
  // Russian roulette termination probability
  float pr_continue;
};
} // namespace verdant
