#ifndef __LIGHTHOUSEHEADER__
#define __LIGHTHOUSEHEADER__

/* macro directive enabling gtests. Should be undefined when not performing TDD */
/* because of destructive test dependencies such as #define private public, */
/* this should be undefined in non-testing situations at all cost!!! */
//#define __TEST__

#ifdef __TEST__
/* header including test related macros and test dependencies */
#include "TestHeader.h"
#endif

/* List of headers used accross the project */
#include <unordered_map>
#include <mutex>
#include <tuple>
#include <string>
#include <memory>
#include "../Lighthouse/protobuf/LighthouseCodeElement.pb.h"
#include "LighthouseDictionary.h"
#include "LighthouseMain.h"
#include "LighthouseInterface.h"
#endif
