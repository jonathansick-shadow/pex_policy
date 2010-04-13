/**
 * @file PAFBadSyntax.cc
 *
 * This test exercises PAF parsing of all variations of expressing values
 */

#include <stdexcept>
#include "lsst/pex/policy.h"

using namespace std;
using lsst::pex::policy::Policy;

#define Assert(b, m) tattle(b, m, __LINE__)

void tattle(bool mustBeTrue, const string& failureMsg, int line) {
    if (! mustBeTrue) {
        ostringstream msg;
        msg << __FILE__ << ':' << line << ":\n" << failureMsg << ends;
        throw runtime_error(msg.str());
    }
}

int main(int argc, char** argv) {

    try {
        Policy p = Policy("tests/PAFBadSyntax_1.paf");
        throw runtime_error("Failed to detect bad PAF syntax (comma delimiters)");
    }
    catch (lsst::pex::policy::FormatSyntaxError) {   }

    try {
        Policy p = Policy("tests/PAFBadSyntax_2.paf");
        throw runtime_error("Failed to detect bad PAF syntax (parameter w/spaces)");
    }
    catch (lsst::pex::policy::FormatSyntaxError) {   }

    try {
        Policy p = Policy("tests/PAFBadSyntax_3.paf");
        throw runtime_error("Failed to detect bad PAF syntax (bad sub-policy)");
    }
    catch (lsst::pex::policy::FormatSyntaxError) {   }

    try {
        Policy p = Policy("tests/PAFBadSyntax_4.paf");
        throw runtime_error("Failed to detect bad PAF syntax (mixed types)");
    }
    catch (lsst::pex::policy::FormatSyntaxError) {   }

    try {
        Policy p = Policy("tests/PAFBadSyntax_4.paf");
        throw runtime_error("Failed to detect bad PAF syntax (bad sub-policy)");
    }
    catch (lsst::pex::policy::FormatSyntaxError) {   }
}
