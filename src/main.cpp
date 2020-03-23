

#include <iostream>
#include <string>
#include <tcl.h>

namespace {
const std::string invalidClockCommand = {R"__(clock format [clock seconds] -format "%Y-%m-%dT%H:%M:%S")__"};

void printTclResult(Tcl_Interp* interpreter) {
    std::cout << "> " << Tcl_GetStringResult(interpreter) << '\n';
}

void executeCommand(Tcl_Interp* tclInterpreter, const std::string& tclCommand) {
    Tcl_Eval(tclInterpreter, tclCommand.c_str());
    printTclResult(tclInterpreter);
}

}  // namespace

int main(int, const char* argv[]) {
    Tcl_FindExecutable(argv[0]);
    auto tclInterpreter = Tcl_CreateInterp();
    if (nullptr == tclInterpreter) {
        std::cerr << "Failed to create TCL interpreter\n";
        return EXIT_FAILURE;
    }

    Tcl_Init(tclInterpreter);
    printTclResult(tclInterpreter);

    executeCommand(tclInterpreter, invalidClockCommand);
    Tcl_Finalize();
    return EXIT_SUCCESS;
}
