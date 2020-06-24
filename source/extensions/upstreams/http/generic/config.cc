#include "extensions/upstreams/http/generic/config.h"

#include "common/router/upstream_request.h"

namespace Envoy {
namespace Extensions {
namespace Upstreams {
namespace Http {
namespace Generic {

Router::GenericConnPoolPtr GenericGenericConnPoolFactory::createGenericConnPool(
    Upstream::ClusterManager& cm, bool is_connect, const Router::RouteEntry& route_entry,
    Envoy::Http::Protocol protocol, Upstream::LoadBalancerContext* ctx) const {
  if (is_connect) {
    auto ret = std::make_unique<Router::TcpConnPool>(cm, route_entry, protocol, ctx);
    return (ret->valid() ? std::move(ret) : nullptr);
  }
  auto ret = std::make_unique<Router::HttpConnPool>(cm, route_entry, protocol, ctx);
  return (ret->valid() ? std::move(ret) : nullptr);
}

REGISTER_FACTORY(GenericGenericConnPoolFactory, Router::GenericConnPoolFactory);

} // namespace Generic
} // namespace Http
} // namespace Upstreams
} // namespace Extensions
} // namespace Envoy
