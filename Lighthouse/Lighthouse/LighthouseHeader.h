#ifndef __LIGHTHOUSEHEADER__
#define __LIGHTHOUSEHEADER__

/* List of headers used accross the project */
#include <unordered_map>
#include <mutex>
#include <string>
#include <memory>
#include "ProtobufFiles/LighthouseCodeElement.pb.h"

#define __TEST__

#ifdef __TEST__
#include "TestHeader.h"
#endif

#endif
