#define DUCKDB_EXTENSION_MAIN

#include "dlx_extension.hpp"
#include "duckdb.hpp"

namespace duckdb {

// Forward declaration from dlx_function.cpp
void RegisterDLXFunctions(ExtensionLoader &loader);

void DlxExtension::Load(ExtensionLoader &loader) {
    RegisterDLXFunctions(loader);
}

std::string DlxExtension::Version() const {
#ifdef EXT_VERSION_DLX
    return EXT_VERSION_DLX;
#else
    return "0.0.1";
#endif
}

} // namespace duckdb

// ─────────────────────────────────────────────────────────────
// Entry point for loadable extension
// ─────────────────────────────────────────────────────────────
extern "C" {

DUCKDB_CPP_EXTENSION_ENTRY(dlx, loader) {
    duckdb::DlxExtension ext;
    ext.Load(loader);
}

} // extern "C"