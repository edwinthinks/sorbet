#ifndef SORBET_CORE_PROTO_H
#define SORBET_CORE_PROTO_H
// have to go first as they violate our poisons
#include "proto/File.pb.h"
#include "proto/Loc.pb.h"
#include "proto/Name.pb.h"
#include "proto/Symbol.pb.h"
#include "proto/Type.pb.h"
#include "proto/pay-server/SourceMetrics.pb.h"
#include <google/protobuf/util/json_util.h>

#include "core/core.h"
#include <fstream>

namespace sorbet::core {
class Proto {
public:
    Proto() = delete;

    static com::stripe::rubytyper::Name toProto(const GlobalState &gs, NameRef name);

    static com::stripe::rubytyper::Symbol toProto(const GlobalState &gs, SymbolRef sym);
    static com::stripe::rubytyper::Symbol toProtoNoChildren(const GlobalState &gs, SymbolRef sym);

    static com::stripe::rubytyper::Type::Literal toProto(const GlobalState &gs, const LiteralType &lit);
    static com::stripe::rubytyper::Type toProto(const GlobalState &gs, TypePtr typ);

    static com::stripe::rubytyper::Loc toProto(const GlobalState &gs, Loc loc);
    static com::stripe::rubytyper::FileTable filesToProto(const GlobalState &gs);

    static com::stripe::payserver::events::cibot::SourceMetrics toProto(const CounterState &counters,
                                                                        std::string_view prefix);

    static std::string toJSON(const google::protobuf::Message &message);
    static void toJSON(const google::protobuf::Message &message, std::ostream &out);

    // Serialize a single proto field
    static void serializeField(int field_number, const google::protobuf::Message &message, std::ostream &out);
};
} // namespace sorbet::core

#endif
