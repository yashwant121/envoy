#include "extensions/upstreams/http/http/config.h"

#include "common/router/upstream_request.h"

namespace Envoy {
namespace Extensions {
namespace Upstreams {
namespace Http {
namespace Http {

Router::GenericConnPoolPtr HttpGenericConnPoolFactory::createGenericConnPool(
    Upstream::ClusterManager& cm, bool, const Router::RouteEntry& route_entry,
    Envoy::Http::Protocol protocol, Upstream::LoadBalancerContext* ctx) const {
  auto ret = std::make_unique<Router::HttpConnPool>(cm, route_entry, protocol, ctx);
  return (ret->valid() ? std::move(ret) : nullptr);
}

REGISTER_FACTORY(HttpGenericConnPoolFactory, Router::GenericConnPoolFactory);

} // namespace Http
} // namespace Http
} // namespace Upstreams
} // namespace Extensions
} // namespace Envoy
