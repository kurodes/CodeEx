>https://gperftools.github.io/gperftools/cpuprofile.html
# Coding
yum install gperftools

``` cpp
#include <gperftools/profiler.h>
ProfilerStart("./app.prof"); //profile-filename
ProfilerStop();
```

# Link and build
-lprofiler

# Run and generate profiling file

env CPUPROFILE=app.prof ./app

Modifying behavior: `export CPUPROFILE_FREQUENCY=100`

# Analyzing the profiling file
``` bash
pprof -h
pprof ./app ./app.prof
 - interactive mode
pprof ./app ./app.prof --text
pprof ./app ./app.prof --pdf >> app.pdf
pprof ./app ./app.prof --callgrind > app.callgrind
```

# Focus and Ignore
``` bash
--focus=myprocedure
--focus=vsnprintf
``` bash