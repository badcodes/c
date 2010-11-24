#include "utils.h"
#include "modpath.h"
#include "cmd.h"

DEFINE_CMD_INFO(
    modpath,
    "1.0",
    "add or remove parts of PATH",
    "[+/-] (PathString) (index)" \
        "\n  +      Add PathString to PATH" \
        "\n  -      Remove PathString from PATH" \
        "\n  index  Position of Path for adding",
    NULL
)

DEFINE_CMD_MAIN(modpath,int argc,char** argv) {
    return printarg("modpath get follow arguments:",argc,argv);    
}

