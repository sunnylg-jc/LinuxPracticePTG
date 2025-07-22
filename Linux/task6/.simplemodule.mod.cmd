savedcmd_simplemodule.mod := printf '%s\n'   simplemodule.o | awk '!x[$$0]++ { print("./"$$0) }' > simplemodule.mod
