
#include "Tungsten.h"

int main() {
    Tungsten::Logger::Init();



    TUNGSTEN_WARN("Dumbass");
    TUNGSTEN_ASSERT(false, "ERROR: FALSE IS NOT TRUE");

    return 0;
}
