P=myprobe
perf probe -d "$P:*"

perf probe -x ./test --add "$P:_Z1ai=_Z1ai" --no-demangle
perf probe -x ./test --add "$P:_Z1bi=_Z1bi" --no-demangle
perf probe -x ./test --add "$P:main=main" --no-demangle

perf probe -x ./test --add "$P:_Z1ai=_Z1ai%return" --no-demangle
perf probe -x ./test --add "$P:_Z1bi=_Z1bi%return" --no-demangle
perf probe -x ./test --add "$P:main=main%return" --no-demangle

perf record -e "$P:*" ./test
chmod 0555 perf.data
