

#include <iostream>
#include <string>
#include <tcl.h>

namespace {
const std::string invalidClockCommand = {R"__(clock format [clock seconds] -format "%Y-%m-%dT%H:%M:%S")__"};

void executeCommand(Tcl_Interp* tclInterpreter, const std::string& tclCommand) {
    Tcl_Eval(tclInterpreter, tclCommand.c_str());
    std::cout << "> " << Tcl_GetStringResult(tclInterpreter) << '\n';
}

}  // namespace

int main(int, const char* argv[]) {
    Tcl_FindExecutable(argv[0]);
    auto tclInterpreter = Tcl_CreateInterp();
    if (nullptr == tclInterpreter) {
        std::cerr << "Failed to create TCL interpreter\n";
        return EXIT_FAILURE;
    }
    executeCommand(tclInterpreter, invalidClockCommand);
    Tcl_Finalize();
    return EXIT_SUCCESS;
}
