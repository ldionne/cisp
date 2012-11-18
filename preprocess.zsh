
CC="/opt/local/bin/clang"
INCLUDES="-Iinclude -Iext/joy/include -Iext/chaos"
CFLAGS="-std=c89 -E -P -Wall -Wextra -pedantic -fmacro-backtrace-limit=0"

for file in `ls test/**.c`; do
    ${CC} ${CFLAGS} ${INCLUDES} ${file} -o ${file}.i
    python tools/macroize/macroize.py ${file}.i --check
done
